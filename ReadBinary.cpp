// ReadBinary.cpp : This file contains the 'main' function. Program execution begins and ends there.
// A small tool for reading binary files

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	//you can set the file path here c:\\test\\myfile.t" 
	const char* infilename="myfile.x";
	int size = 0;
	short* indata;
	int i = 0;
	short tmp = 0;
	

	ifstream inf(infilename, std::ifstream::in | std::ifstream::binary);
	if (inf.good())
	{
		inf.seekg(0, std::ifstream::end);
		size = (int)inf.tellg()/sizeof(short) ;		
	}
	cout << "this file has " << size << " values in it.\n Enter any key to see the values!\n";
	//added just for pause 
	getchar();
	indata = new short[size];
	inf.seekg(0);
	while (inf.good() && !inf.eof() && i < size)
	{
		//if your file has double / int or other types just change short to that one 
		//you have to chage line 12 (the array definition) and line 25 for the new statement and line 22 for calculation of number of items in the file
		
		inf.read((char*)&tmp, sizeof(short));
		indata[i++] = tmp ;	
		cout << tmp << "\t";
	}
	inf.close();
    cout << "\n\n\nI have read "<<i<<" values; " << "\n End of the reading process.\nPress any key to exit!\n\n\n";
	//added just for pause 
	getchar();
	return 0;
}

