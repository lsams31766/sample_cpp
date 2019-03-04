/*
 * templates.cpp
 *
 *  Created on: Mar 3, 2019
 *      Author: lawrencesamuels
 */

#include <iostream>

using namespace std;


// function templates
// NOTE can replace class T with typename T
template <typename T>
T addValues(T a, T b)
{
	return a+b;
}

template <class T, class U>
T smaller(T a, U b)
{
	return ( a<b ? a : b);
}

// class templates
template <class T>
class Big
{
	T first, second;
public:
	Big(T a, T b)
	{
		first = a;
		second = b;
	}
	T bigger();
};

template <class T>  // function outside class, need template type
T Big<T>::bigger()
{
	return (first > second ? first : second);
}

// template specialization
template <class T>
class Special
{
public:
	Special(T x)
	{
		cout << x << " is not a character" << endl;
	}
};

template <>
class Special<char>
{
public:
	Special(char x)
	{
		cout << x << " is a character" << endl;
	}
};

int main()
{
	int a=20, b= 30, c;
	c = addValues(a,b);
	cout << c << endl;

	float d=3.14, e=5.21, f;
	f = addValues(d,e);
	cout << f << endl;

	int x = 89;
	double y = 56.78;
	cout << smaller(x,y) << endl;

	int m = 20;
	int n = 21;
	Big<int> big(m,n);
	cout << "bigger " <<  big.bigger() << endl;

	Special <int> s(3);
	Special <float> s2(5.555);
	Special <char> t('Z');

	return 0;

}


