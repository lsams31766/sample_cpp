/*
 * basic_cpp.cpp
 *
 *  Created on: Mar 4, 2019
 *      Author: lawrencesamuels
 */

#include <iostream>

using namespace std;

typedef unsigned short int USHORT;

class SimpleCat
{
public:
	SimpleCat();
	~SimpleCat();
	int getAge();
private:
	int itsAge;
};

SimpleCat::SimpleCat()
{
	cout << "Constructor called" << endl;
	itsAge = 1;
}

SimpleCat::~SimpleCat()
{
	cout << "Destructor called" << endl;
}

int SimpleCat::getAge()
{
	return itsAge;
}

int main()
{
	// pointers
	USHORT myAge = 5;
	USHORT* pAge = 0;
	pAge = &myAge;
	cout << "myAge " << myAge << " *pAge " << *pAge << endl;
	// change age with *
	*pAge = 7;
	cout << "myAge " << myAge << " *pAge " << *pAge << endl;
	// change age with myAge
	myAge = 9;
	cout << "myAge " << myAge << " *pAge " << *pAge << endl;

	// allocating pointers
	int localVariable = 5;
	int* pLocal = &localVariable;
	int* pHeap = new int;
	if (pHeap == NULL)
	{
		cout << "Error - No memory for pHeap" << endl;
		return 0;
	}
	*pHeap = 7;
	cout << "local " << localVariable << " pLocal " << *pLocal << " pHeap " << *pHeap << endl;
	delete pHeap;

	// free store
	cout << "SimpleCat Frisky...\n";
	SimpleCat Frisky;
	cout << "SimpleCat* pRags = new SimpleCat...\n";
	SimpleCat* pRags = new SimpleCat;
	cout << "delete pRags...\n";
	delete pRags;
	cout << "Exiting, watch Frisky go...\n";

	//references
	SimpleCat& rCat = Frisky;
	cout << "rCat age is " << rCat.getAge() << endl;


	return 0;
}


