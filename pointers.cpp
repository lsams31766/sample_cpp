//pointers.cpp
//ccompile on MAC OS using: clang++ -std=c++11 pointers.cpp -o pointers
#include <iostream>

using namespace std;

int main()
{
	// & used for address of a pointer
	int fish = 5;
	cout << &fish << endl;

	int* fishPointer = &fish;
	cout << fishPointer << endl;

	string b = "Ham Sandwich";
	cout << b << endl;
	cout << &b << endl;

 	// reference variable - not a copy, same memory address 
 	// rreference must be initizled, cannot be null, cannot be changed
 	int a = 5;
 	int& my_ref = a;
 	cout << a << endl;
 	cout << my_ref << endl;
	cout << &a << endl;
 	cout << &my_ref << endl;

 	// points to arrays - we point to first object in array 
 	int c[] {1,2,3};
 	int* p1 = &c[0];
 	cout << p1[0] << " " << p1[1] << " " << p1[2] << endl;
	cout << &p1[0] << " " << &p1[1] << " " << &p1[2] << endl;
	cout << c << " " << p1 << endl; 

	// array of pointers
	int a1=5, a2=5, a3=7;
	int* pp1 = &a1;
	int* pp2 = &a2;
	int* pp3 = &a3;
	int* pa[] {pp1, pp2, pp3};
	cout << "array of pointers\n";
	cout << pa << endl;
	cout << *pa << endl;
	cout << **pa << endl;
	cout << pa[0] << endl;
	cout << *pa[0] << endl;
	cout << pa[0][0] << endl;

	cout << "Next pointer\n";
	// next pointer in the list
	cout << pa << endl;
	cout << &pa[1] << endl;
	cout << pa + 1 << endl;





	return 1;
}