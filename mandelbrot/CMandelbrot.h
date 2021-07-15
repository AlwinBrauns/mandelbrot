#pragma once
class CMandelbrot;

struct Daten {
	int iterations;
	double z_realteil;
	double z_imaginearteil;
	double betrag;
	double getZIntensiteatReal(CMandelbrot mandelbrot);
	double getZIntensiteatImag(CMandelbrot mandelbrot);
	double getZIntensiteatAll(CMandelbrot mandelbrot);
};

class CMandelbrot
{
public:
	double minRealteil;
	double maxRealteil;
	double minImaginearteil;
	double maxImaginearteil;
	size_t detail;
	/**
		Um so höher der Rückgegebene Wert destso eher in der Mandelbrotmenge (maximal detail)
	*/
	Daten inMandelbrotmenge(double c_realteil, double c_imaginearteil, size_t detail); 
	double koordinateZuRealteil(int x, int bildBreite);
	double koordinateZuImaginearteil(int y, int bildHeohe);
	size_t getDetail();
	CMandelbrot(double minRealteil, double maxRealteil, double minImaginearteil, double maxImaginearteil, size_t detail);
};