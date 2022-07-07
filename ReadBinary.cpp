// ReadBinary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	const char* infilename="data\\ESP_TESTCPC001(HI).H";
	int size = 0;
	double* indata;
	int i = 0;
	short tmp = 0;
	

	ifstream inf(infilename, std::ifstream::in | std::ifstream::binary);
	if (inf.good())
	{
		inf.seekg(0, std::ifstream::end);
		size = (int)inf.tellg() / 2;		
	}
	cout << "this file has " << size << " values in it.\n Enter any key to see the values!\n";
	getchar();
	indata = new double[size];
	inf.seekg(0);
	while (inf.good() && !inf.eof() && i < size)
	{
		inf.read((char*)&tmp, sizeof(short));
		indata[i++] = tmp ;	
		cout << tmp << "\t";
	}
	inf.close();
    cout << "\n End of the values!\n";
	return 0;
}

