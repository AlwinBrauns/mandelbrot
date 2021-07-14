#include "CMandelbrot.h"
#include "CFilehandler.h"

int main()
{
	double zoom = 500000000;

	//Ausgangspunkt
	double x = -1.0999999; // (-)links/(+)rechts
	double y = -0.2313999842; // (-)oben/(+)unten

	//Ausdehnung
	double offsetMax = 1 / zoom;
	double offsetMin = 1 / zoom;

	CMandelbrot mandelbrot = CMandelbrot(
		(x - offsetMin), (x+offsetMax), // Realteil bereich
		(y - offsetMin), (y+offsetMax), // Imaginearteil bereich
		255 // auflösung
	);
	CFilehandler filehandler = CFilehandler(
		"mandelbrot.ppm",
		7000, 7000
	);
	filehandler.schreibeDatei(mandelbrot);
	return 0;
}