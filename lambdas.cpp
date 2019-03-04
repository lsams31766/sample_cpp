/*
 * lambdas.cpp
 *
 *  Created on: Mar 3, 2019
 *      Author: lawrencesamuels
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	auto printHello = [](){ cout << "Hello" << endl;};
	printHello();

	auto product = [](int a, int b)
		{
			return a*b;
		};
	cout << product(4,3) << endl;

	int total = 3;
	auto addTotal = [&](int a)
		{
			total += a;
		};
	addTotal(20);
	cout << "Total is " << total << endl;

	// summing a vector
	vector<int> v{3,2,1,4,5};
	int sum;
	for_each (v.begin(), v.end(), [&](int &n)
		{
			sum += n;
		});
	cout << "sum is " << sum << endl;

	// reverse sorting a vector
	sort(v.begin(), v.end(), [](int &a, int &b)
			{
				return a > b;
			});

	// print vector with lambda
	for_each(v.begin(), v.end(), [](int n)
			{
				cout << n << " ";
			});
	cout << endl;





	return 0;
}



