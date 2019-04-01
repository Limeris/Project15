#pragma once
#include <string>
#include <iostream>

using namespace std;
class Note
{
public:
	Note(int pitch, double len);
	double len;
	int pitch;
	int string;
	int pos;
	int getPitch() const;
	double getLength() const;
	friend ostream& operator<<(ostream& os, Note a);
};
