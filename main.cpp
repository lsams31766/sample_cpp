/*
 * main.cpp
 *
 *  Created on: Mar 3, 2019
 *      Author: lawrencesamuels
 */

#include <iostream>
using namespace std;


class Demo
{
private:
	int* ptr;
public:
	Demo(int a);
	~Demo();
	void set(int a);
	int get() const;
	// copy constructor
	Demo(const Demo& d);
};
Demo::Demo(int a)
{
	this->ptr = new int(a);
}
Demo::~Demo()
{
	delete this->ptr;
}
void Demo::set(int a)
{
	*ptr = a;
}
int Demo::get() const
{
	return *this->ptr;
}

// copy constructor
Demo::Demo(const Demo& d)
{
	// get the value in source
	int a = *d.ptr;
	// create a new pointer, to point to this value
	this->ptr = new int(a);
}

void passByValue(Demo d)
{
}


int main()
{
	Demo dog(8);
	Demo cat(dog);

	cout << dog.get() << "\t" << cat.get() << endl;
	dog.set(10);
	cout << dog.get() << "\t" << cat.get() << endl;
	dog.set(10);
	// other copy constructors
	Demo cat2(dog); // pass as argument
	passByValue(dog); // makes a copy

	return 0;
}
