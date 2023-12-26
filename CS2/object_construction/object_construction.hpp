// object construction header file
//
// Nathan Fleet

#ifndef OBJECT_CONSTRUCTION_HPP_
#define OBJECT_CONSTRUCTION_HPP_

class ABC {
public:
	ABC(); //default constructor
	~ABC(); //destructor
	ABC(const ABC&); //copy constructor
	ABC& operator=(ABC); //assignment operator

};


#endif // !OBJECT_CONSTRUCTION_HPP_
