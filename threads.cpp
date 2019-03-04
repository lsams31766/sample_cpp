/*
 * threads.cpp
 *
 *  Created on: Mar 3, 2019
 *      Author: lawrencesamuels
 */


#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

// deadlock example
mutex _mu;
mutex _mu2;
void shared_print(string id, int value)
{
	lock_guard<mutex> locker(_mu);
	lock_guard<mutex> locker2(_mu2);
	cout << "From " << id << ": " << value << endl;
}

void shared_print2(string id, int value)
{
	// lock_guard<mutex> locker2(_mu2); // out of order causes deadlock
	// lock_guard<mutex> locker(_mu);  //  '''
	lock_guard<mutex> locker(_mu);    // correct order
	lock_guard<mutex> locker2(_mu2);  // '''
	cout << "From " << id << ": " << value << endl;
}

void function_1()
{
	for (int i=0; i>-100; i--)
		shared_print("T1",i);
}

int main()
{
	thread t1(function_1);
	for (int i=0; i<100; i++)
		shared_print2("Main",i);
	t1.join();
	return 0;
}




#ifdef DO_SHARED_PRINT
// using mutex to share cout
mutex mu;

void shared_print(string msg, int id)
{
	lock_guard<mutex> guard(mu); // RAII  when guard out of scope, we unlock
	// mu.lock(); // works, but if exception lock forever
	cout << msg << id << endl;
	// mu.unlock(); // lock forever issue
}

void function_1()
{
	for (int i=0; i>-100; i--)
		shared_print("from T1:",i);
}

int main()
{
	thread t1(function_1);
	for (int i=0; i<100; i++)
		shared_print("from Main:",i);
	t1.join();
	return 0;
}
#endif

#ifdef OLD_PROG

void function_1()
{
	cout << "Beauty is only skin-deep" << endl;
}

// using functor
class Fctor {
public:
	void operator()(string& msg) {
		cout << "t1 says " << msg << endl;
		msg = "Trust in the mother of deceit";
	}
};

int main()
{

	/*
	 *  this fails if an exception occurs
	thread t1(function_1); // t1 starts running
	// t1.join();  // main thread waits for t1 to finish

	t1.detach();  // nothing printed, main finished before t1
	t1.join(); // crash can not join after detached
	*/

	/*  using try catch
	thread t1(function_1); // t1 starts running
	try {
		for (int i=0; i<100; i++)
			cout << "from main: " << i << endl;
	} catch (...) {
		t1.join();
		throw;
	}

	t1.join();
	*/



	// using functor - this is a mess - cout shared wrong
	string s = "Where there is no trust, there is no love";
	//Fctor fct;
	//thread t1(fct()); // t1 starts running
	thread t1((Fctor()),std::ref(s));  // alternate way to do this - note extra () is needed
	                                  // pass by ref is needed
	t1.join();
	try {
			cout << "from main: " << s << endl;
	} catch (...) {
		t1.join();
		throw;
	}
	// t1.join();
	return 0;
}
#endif
