// ReadBinary.cpp : This file contains the 'main' function. Program execution begins and ends there.
// A small tool for reading binary files

#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, STB_Image" << std::endl;

    string inputPath = "2017.jpg";
    int iw, ih, n;

    // Loading Pictures to Get Wide, High and Color Channel Information
    unsigned char* idata = stbi_load(inputPath.c_str(), &iw, &ih, &n, 0);
    
    for(int i=0;i<50;i++)
        cout << (int)idata[i] << '\t' ;

    stbi_image_free(idata);
    
    return 0;
}