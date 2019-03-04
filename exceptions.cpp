/*
 * main.cpp
 *
 *  Created on: Mar 3, 2019
 *      Author: lawrencesamuels
 */

#include <iostream>
#include <exception>
using namespace std;

// custom exception
class MyException: public exception
{
public:
	// override what method - this cannot throw an exception
	virtual const char* what() const throw()
	{
		return "Something really bad happened";
	}
};

class Test {
public:
	void goesWrong() {
		throw MyException();
	}
};


void mightGoWrong()
{
	bool error = false;
	bool error2 = true;

	if (error)
	{
		throw "Something went wrong";
	}

	if (error2)
	{
		throw string("Something else went wrong");
	}
}

class CanGoWrong {
public:
	CanGoWrong()
	{
		char *pMemory = new char[99999999999999999];
		delete [] pMemory;
	}
};


void usesMightGoWrong()
{
	mightGoWrong();  // throws up the call stack
}

int main()
{
	Test test;
	try {
		test.goesWrong();
	} catch (MyException &e)
	{
		cout << e.what() << endl;
	}

	try
	{
		CanGoWrong wrong;
	} catch (bad_alloc &e)
	{
		cout << "Caught exception: " << e.what() << endl;
	}


	try
	{
		usesMightGoWrong();
	} catch (int e)
	{
		cout << "Error code: " << e << endl;
	} catch (char const * e)
	{
		cout << "Error msg: " << e << endl;
	} catch (string &e)
	{
		cout << "String Error msg: " << e << endl;
	}

	cout << "Still Running" << endl;

	return 0;
}


