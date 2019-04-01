#include<string>
#include<iostream>
#include "Note.h"

Note::Note(int pitch, double len)
{
	this->pitch = pitch;
	this->len = len;
}
double Note::getLength() const
{
	return this->len;
}
int Note::getPitch() const
{
	return this->pitch;
}
ostream& operator<<(ostream& os, Note a)
{
	os << a.pitch << " ";
	os << a.len;
	return os;
}