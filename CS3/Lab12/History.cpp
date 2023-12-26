// Combining memento and command design patterns for Checkpointed History
// Nathan Fleet
// 11/09/2023

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using std::vector; using std::string; using std::to_string;
using std::cout; using std::cin; using std::endl;

// reciever
class Document {
public:
    Document(vector <string> lines={}): lines_(lines){}

    // actions
    void insert(int line, const string &str) {
        const int index = line-1;

        if (index <= lines_.size())
            lines_.insert(lines_.begin() + index, str); 
        else
            cout << "line out of range" << endl; 
    }

    const string remove(int line) {
        const int index = line-1;
        string deletedLine="";

        if(index < lines_.size()){
            deletedLine = lines_[index];
            lines_.erase(lines_.begin() + index); 
        }else {
            cout << "line out of range" << endl; 
        }
        return deletedLine;
    } 

    void show() {
        for(int i = 0; i < lines_.size(); ++i)
            cout << i + 1 << ". " << lines_[i] << endl; 
    }

private:
    vector<string> lines_; 
};

class Command{
public:
    Command(Document *doc) : doc_(doc){}
    virtual void execute() = 0; 
    virtual void unexecute() = 0; 
    virtual void show() = 0; // command to display insertions/erases for history
    virtual ~Command(){}
protected:
    Document *doc_; 
}; 

class InsertCommand : public Command {
public:
    InsertCommand(Document *doc, int line, const string &str)
    : Command(doc), line_(line),  str_(str) {}
    void execute() override { doc_->insert(line_, str_);}
    void unexecute() override {doc_->remove(line_);}
    void show() override { cout << "insert \"" << str_ << "\" at line " << to_string(line_) << endl; }
private:
    int line_; 
    string str_; 
}; 

class EraseCommand : public Command {
public:
    EraseCommand(Document *doc, int line)
    : Command(doc), line_(line), str_("") {}
    void execute() override {str_ = doc_->remove(line_);}
    void unexecute() override {doc_->insert(line_, str_);}
    void show() override { cout << "erase line " << to_string(line_) << endl; }
private:
    int line_;
    string str_;
};

class DocumentWithHistory{
public:
    DocumentWithHistory(const vector<string> & text={}) : doc_(text){}

    void insert(int line, string str) {
        Command *com = new InsertCommand(&doc_, line, str); 
        com->execute(); 
        doneCommands_.push(com);
        history_.push_back(com);
    }

    void erase(int line){
        Command *com = new EraseCommand(&doc_, line);
        com->execute();
        doneCommands_.push(com);
        history_.push_back(com);
    }

    void undo() {
        if(doneCommands_.size() != 0) {
            Command *com = doneCommands_.top(); 
            doneCommands_.pop(); 
            com->unexecute();
            delete com;
        }else
            cout << "no commands to undo" << endl; 
    }

    void history() {
        for(int i = 0; i < history_.size(); ++i) {
            Command *curr = history_[i];
            cout << to_string(i + 1) << ". ";
            curr->show();
        }
        cout << endl;
    }

    void redo(int line) {
        Command *redo = history_[line - 1];
        redo->execute();
        history_.push_back(redo);
    }

    void show() {doc_.show();}

    class Memento *createMemento() const;  
    void rollBack(class Memento *); 

private:
    Document doc_;
    std::stack<Command*> doneCommands_;
    vector<Command*> history_;
};

class Memento {
public:
    Memento(const DocumentWithHistory& doc): doc_(doc) {}
    const DocumentWithHistory& getState() const {return doc_;}  
private:
    const DocumentWithHistory doc_;
};

Memento *DocumentWithHistory::createMemento() const{
    return new Memento(*this); // copying the Document itself
}

void DocumentWithHistory::rollBack(Memento *mem){
    *this = mem->getState();  // copying back
}

int main() {
    DocumentWithHistory doc({
    "Lorem Ipsum is simply dummy text of the printing and typesetting",
    "industry. Lorem Ipsum has been the industry's standard dummy text",
    "ever since the 1500s, when an unknown printer took a galley of",
    "type and scrambled it to make a type specimen book. It has",
    "survived five centuries."});

    char option;

    do{
        static Memento *checkpoint = nullptr;

        doc.show();
        cout << endl;

        cout << "Enter option (i)nsert line (e)rase line (u)ndo last command (c)heckpoint roll(b)ack (h)istory, (r)edo command: ";
        cin >> option;

        int line; string str; 
        switch(option) {
        case 'i': // insert
            cout << "line number to insert: ";
            cin >> line;
            cout << "line to insert: ";
            cin.get();
            getline(cin, str);
            doc.insert(line, str);
            break;
        case 'e': // erase
            cout << "line number to remove: ";
            cin >> line;
            doc.erase(line);
            break;
        case 'u': // undo
            doc.undo();
            break;
        case 'c': // checkpoint
            checkpoint = doc.createMemento();
            break;
        case 'b': // rollback
            if (checkpoint != nullptr){
                doc.rollBack(checkpoint);
                delete checkpoint;
                checkpoint = nullptr;
            } else {
                cout << "No checkpoint created" << endl;
            }
            break;
        case 'h': // history
            doc.history();
            break;
        case 'r': // redo
            cout << "command history number: ";
            cin >> line;
            doc.redo(line);
            break;
        }
    } while(option == 'i' || option == 'e' || option == 'c' || option == 'r' || option == 'h' || option == 'r');
}