//stl_tutorial.cpp
// compile on MAC OS using: clang++ -std=c++11 stl_tutorial.cpp -o stl_tutorial

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;
typedef vector<int> INTVEC;
typedef vector<int>::iterator  INTVEC_IT;

/*
// OLD style
 void PrintVec(INTVEC A)
 {
 	INTVEC_IT it;
 	for (it = A.begin(); it != A.end(); it++)
 		cout << *it << " ";
 	cout << endl;
 }
*/

 // using auto in C++11 
void PrintVec(INTVEC A)
 {
 	for (int x: A)
 		cout << x << " ";
 	cout << endl;
 }

// increment values in vector using c++11 style
 void IncVec(INTVEC &A)
 {
 	for (int &x: A)
 		x++;
 }


 bool f(int x, int y)
 {
 	// reverse sort algorith
 	return x > y;
 }

 void CheckPresent(INTVEC A, int x)
 {
 	bool present = binary_search(A.begin(), A.end(), x);
 	if (present)
 		cout << x << " IS present" << endl;
 	else
 		cout << x << " IS NOT present" << endl;
 }

 void vectorDemo()
 {
 	INTVEC A{ 11,2,3,14};
	cout << A[1] << endl;

	CheckPresent(A,3);
	CheckPresent(A,4);

	// sorting
	cout << "Before Sort ";
	PrintVec(A);
	sort(A.begin(), A.end());
	cout << "After Sort ";
	PrintVec(A);

	// add using pushback
	for (int i=0; i<4; i++)
		A.push_back(100);
	A.push_back(123);
	PrintVec(A);
	// count number of 100's 
	INTVEC_IT it = lower_bound(A.begin(), A.end(), 100); // >=
	INTVEC_IT it2 = upper_bound(A.begin(), A.end(), 100); // >
	cout << *it << " " << *it2 << endl;
	cout << it2 - it << endl; // 4

	// revsers sort with custom function 
	sort(A.begin(), A.end(), f);
	PrintVec(A);
	IncVec(A);
	PrintVec(A);	
 }

 void setDemo()
 {
 	set<int> S;
 	S.insert(1);
 	S.insert(2);
 	S.insert(-1);
 	S.insert(-10);

 	for (int x: S)
 		cout << x << " ";
 	cout << endl;

 	// find in set 
 	auto it = S.find(-1);
 	if (it == S.end())
 		cout << -1 << " not present\n";
 	else
 		cout << -1 << " present\n";

 	// upper lower bound 
 	auto it2 = S.upper_bound(-1);
 	auto it3 = S.upper_bound(0);
 	cout << *it2 << " " << *it3 << endl;
 	auto it4 = S.upper_bound(2);
 	if (it4 == S.end())
 		cout << "Oops can not find that\n";
 }

 void mapDemo()
 {
 	map<int,int> A;
 	A[1] = 100;
 	A[2] = -1;
 	A[3] = 200;
 	A[23423423] = 1;
 	for (auto it=A.begin(); it != A.end(); it++)
  	{
  		cout << it->first << ":" << it->second << endl;
  	}

 	// count occurences
 	map<char, int> cnt;
 	string x = "larry samuels";
 	for (char c: x)
 		cnt[c]++;
 	// number of a's 
 	cout << "Nbr a's " << cnt['a'] << endl;
 	// number of z's 
 	cout << "Nbr z's " << cnt['z'] << endl;
 }

 void CheckInterval(set <pair <int, int> > S, int x)
 {
 	auto it = S.upper_bound({ x, INT_MAX});
 	if (it == S.begin())
 	{
 		cout << x << " is not lying in any interval..\n";
 		return;
 	}
 	it--;
 	pair<int, int> current = *it;
 	if (current.first <= x && x <= current.second)
 		cout << x << " is present between " << current.first << " and " 
 	         << current.second << endl;
 	else
 		cout << x << " is not lying in any interval...\n";
 }

 void intervalDemo()
 {
 	set <pair <int, int> > S;
	S.insert({ 401, 450 });
	S.insert({ 10, 20 });
 	S.insert({ 2, 3 });
 	S.insert({ 30, 400 });
 	CheckInterval(S,1);
 	CheckInterval(S,15);
 	CheckInterval(S,400);
 	CheckInterval(S,401);
 	CheckInterval(S,451);
  }

int main()
{
	vectorDemo();
	cout << "-----------\n";
	setDemo();
	cout << "-----------\n";
	mapDemo();
	cout << "-----------\n";
	intervalDemo();
	return 1;
}
