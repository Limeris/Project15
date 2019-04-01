#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Note.h"
#include "arduino.cpp"
using namespace std;

// solve chord alignment problem
// location optimization
// predictive note display
// EXPAND NOTE CLASS
/*
0 open
1 C#
2 D
3 D#
4 E
5 F
6 F#
7 G*/

int getBPM(string line)
{
	int end = line.find("</text");
	end -= 50;
	int bpm = 0;
	string temp = line.substr(50, end);
	for (int i = 0; i < temp.length(); i++)
	{
		bpm = (bpm * 10) + temp[i] - 48;
	}
	cout << "bpm is:" << bpm << endl;
	return bpm;
}
double getTempo(string line)
{
	int end = line.find("</tempo>");
	end -= 17;
	double tempo = 0;
	string temp = line.substr(17, end);
	char temp1[10];
	strcpy_s(temp1, temp.c_str());

	tempo = strtod(temp1, NULL);

	cout << "tempo is:" << tempo << endl;
	return tempo;
}
double getDuration(string line) // fill in rest of notes
{
	line = line.substr(24, 4);
	if (!strcmp(line.c_str(), "quar")) return 1;
	else if (!strcmp(line.c_str(), "half")) return 2;
	else if (!strcmp(line.c_str(), "whol")) return 4;
	else if (!strcmp(line.c_str(), "eigh")) return .5;
	else if (!strcmp(line.c_str(), "meas")) return 4; // rest
	else if (!strcmp(line.c_str(), "16th")) return .25;
	else if (!strcmp(line.c_str(), "32nd")) return .125;

}
int getPitch(string line)
{
	line = line.substr(19, 3);
	int pitch = 0;
	for (int i = 0; i <= 2; i++)
	{
		if (line[i] >= 48 && line[i] <= 57) pitch = pitch * 10 + line[i] - 48;
	}
	return pitch;
}
void printsong(vector<Note> song)
{
	for (int i = 0; i < song.size(); i++)
	{
		cout << song[i] << endl;
	}
}
void outputsong(vector<Note> song, string outname);

vector<Note> adjustsong (vector<Note> song){ // 0 is open
	for (int i = 0; i < song.size(); i++)
	{
		if (song[i].pitch < 7) //hard code strings to 6 pos
		{
			song[i].pos = song[i].pitch;
			song[i].string = 1;
		}
		if (song[i].pitch >= 7 && song[i].pitch < 14)
		{
			song[i].pos = song[i].pitch - 7;
			song[i].string = 2;
		}
		if (song[i].pitch >= 14 && song[i].pitch < 21)
		{
			song[i].pos = song[i].pitch - 14;
			song[i].string = 3;
		}
		if (song[i].pitch >= 21) {
			song[i].pos = song[i].pitch - 21;
			song[i].string = 4;
		}
	}


	return song;
}



int main() {
	string filename;
	string line;
	double tempo;
	int bpm = 120;
	int curpitch;
	const size_t no = string::npos;
	double curdur;
	vector <Note> song;
	//*
	cout << "Name: ";
	cin >> filename;
	cout << endl; //*/
	//filename = "test.mscx";
	//*	
	if (filename.find(".mscx") == no) filename += ".mscx";
		//*/
	ifstream infs;
	infs.open(filename);
	if (infs.is_open()) {
		int o = 0;
		while (line.find("</Score>") == no) {
			getline(infs, line);
			o++;
			//cout << line << endl;
			if (line.find("<tempo>") != no)
			{
				tempo = getTempo(line);
				getline(infs, line);
				getline(infs, line);
				bpm = getBPM(line);
			}
			else if (line.find("<Rest>") != no)// get Rest length
			{
				getline(infs, line);
				curdur = getDuration(line);
				curpitch = -1;
				//cout << curdur << endl;
				song.push_back(Note(curpitch, curdur));
			}
			else if (line.find("<durationType>") != no)// get note type
			{
				curdur = getDuration(line); // divided by bpm?
				curdur /= bpm;
				curdur *= 60;
				//cout << curdur << endl;
			}
			else if (line.find("<pitch>") != no)
			{
				curpitch = getPitch(line) - 36; //pitch C is 36
				//cout << curpitch << endl;
				song.push_back(Note(curpitch, curdur));
			}

		}
		song = adjustsong(song);
		//printsong(song);
		outputsong(song, filename);
		system("pause");
		infs.close();
	}
	else {
		cout << "File Not Found" << endl;
		system("pause");
	}
}


void outputsong(vector<Note> song, string outname)
{
	int fingperstring = 7; // LEDS per column (string)
	int numLEDs = fingperstring*4; // total number of LEDs available
	//string outname = "testOut.txt"; 

	//cout << "name of file: ";
	//cin >> outname;
	//*
	if (outname.find(".mscx") != string::npos) {
		outname = outname.substr(0, outname.length() - 5);
		}
		outname += ".ino";
	//*/
	//outname += ".txt";
	ofstream out;
	out.open(outname);

	for (int i = 1; i <= 4; i++) // define the string pins
	{
		out << "int str" << i << " = " << i << ";" << endl;
	}
	for (int i = 1; i <= fingperstring; i++) //name all the LEDs in order 1...n
	{
		out << "int pos" << i << "= " << i+4 << ";" << endl;
	}



	out << endl << "void setup() {" << endl; // write initializer
	for (int i = 1; i <= 4; i++)
	{
		out << "pinMode(str" << i << ", OUTPUT);" << endl;
	}
	for (int i = 1; i <= fingperstring; i++)
	{
		out << "pinMode(pos" << i << ", OUTPUT);" << endl;
	}
	//out << "digitalWrite(str1, HIGH); digitalWrite(str2, HIGH); digitalWrite(str3, HIGH); digitalWrite(str4, HIGH); " << endl;
	for (int i = 1; i <= fingperstring; i++)
	{
		out << "digitalWrite(pos" << i << ", HIGH);";
	}
	out << endl;
	//Str HIGH, Pos LOW for on

	out << "}" << endl << endl << "void loop() {" << endl; //start loop


	for (int i = 0; i < song.size(); i++)
	{				
		if (song[i].pos == 0) //string
		{
			out << "digitalWrite(str" << song[i].string << ", HIGH); //string" << endl;
			for (int j = 1; j <= fingperstring; j++) {
				out << "digitalWrite(pos" << j << ", LOW); //string" << endl;
			}
			out << "delay(" << (song[i].len * 1000) << ");" << endl; //bc ms
			out << "digitalWrite(str" << song[i].string << ", LOW); //string" << endl;
			for (int j = 1; j <= fingperstring; j++) {
				out << "digitalWrite(pos" << j << ", HIGH); //string" << endl;
			}
		}
		
		else if (song[i].pitch != -1) { //note		Consider removing endlines and stacking
			out << "digitalWrite(str" << song[i].string << ", HIGH);" << endl;
			out << "digitalWrite(pos" << (song[i].pos) << ", LOW);" << endl; // turn on if note
			out << "delay(" << (song[i].len * 1000) << ");" << endl;	
			out << "digitalWrite(str" << song[i].string << ", LOW);" << endl;
			out << "digitalWrite(pos" << (song[i].pos) << ", HIGH);" << endl; // turn off
		}
		else {
			out << "delay(" << (song[i].len * 1000) << "); // Rest" << endl;
		}
	}
	out << "}";
	out.close();
}