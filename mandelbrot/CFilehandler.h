#pragma once
#include <string>
#include <fstream>
#include <iostream>

#include "CMandelbrot.h"

class CFilehandler
{
	std::string DATEI_BILD;
	int WIDTH;
	int HEIGHT;
public:
	void schreibeDatei(CMandelbrot mandelbrot);
	CFilehandler(std::string DATEI_BILD, int WIDTH, int HEIGHT);
};

