// ReadBinary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	//you can set the file path here c:\\test\\myfile.t" 
	const char* infilename="yourfile.tmp";
	int size = 0;
	short* indata;
	int i = 0;
	short tmp = 0;
	

	ifstream inf(infilename, std::ifstream::in | std::ifstream::binary);
	if (inf.good())
	{
		inf.seekg(0, std::ifstream::end);
		size = (int)inf.tellg() / 2;		
	}
	cout << "this file has " << size << " values in it.\n Enter any key to see the values!\n";
	//added just for pause 
	getchar();
	indata = new short[size];
	inf.seekg(0);
	while (inf.good() && !inf.eof() && i < size)
	{
		//if your file has double / int or other types just change short to that one 
		//you have to chage line 12 (the array definition and line 25 for the new statement
		inf.read((char*)&tmp, sizeof(short));
		indata[i++] = tmp ;	
		cout << tmp << "\t";
	}
	inf.close();
    cout << "\n End of the values!\n";
	return 0;
}

