/*
 * inheritance.cpp
 *
 *  Created on: Mar 4, 2019
 *      Author: lawrencesamuels
 */

#include <iostream>

using namespace std;

enum BREED {YORKIE, CAIRN, DAINDE};

class Mammal
{
public:
	Mammal() {itsAge = 1;};
	Mammal(int age) {itsAge = age; };
	~Mammal() {};
	int GetAge() {return itsAge; };
	void SetAge(int age) {itsAge = age;};
	void Speak() const { cout << "Mammal sound\n";};
protected:
	int itsAge;
};

class Dog : public Mammal
{
public:
	Dog() :Mammal() ,itsBreed(YORKIE) {};
	Dog(int age) : Mammal(age), itsBreed(YORKIE) {};
	Dog(int age, BREED breed) :Mammal(age), itsBreed(breed) {};
	void setBreed(BREED breed) { itsBreed = breed; };
	BREED getBreed() const {return itsBreed;};
private:
	BREED itsBreed;
};



using namespace std;

int main()
{
	Dog fido;
	Dog rover(5);
	Dog dainde(3,DAINDE);
	fido.Speak();
	cout << "dainde is " << dainde.GetAge() << endl;
	cout << "dainde type is " << dainde.getBreed() << endl;
	return 0;
}

