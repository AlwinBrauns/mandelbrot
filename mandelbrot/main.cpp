#include "CMandelbrot.h"
#include "CFilehandler.h"

int main()
{
	double zoom = 500;

	//Ausgangspunkt
	double x = -1.0999999; // (-)links/(+)rechts
	double y = -0.2313999842; // (-)oben/(+)unten

	//double x = 0.0; // (-)links/(+)rechts
	//double y = 0.0; // (-)oben/(+)unten


	//Ausdehnung
	double offsetMax = 2 / zoom;
	double offsetMin = 2 / zoom;

	CMandelbrot mandelbrot = CMandelbrot(
		(x - offsetMin), (x+offsetMax), // Realteil bereich
		(y - offsetMin), (y+offsetMax), // Imaginearteil bereich
		255 // auflösung
	);
	CFilehandler filehandler = CFilehandler(
		"mandelbrot.ppm",
		500, 500
	);
	filehandler.schreibeDatei(mandelbrot);
	return 0;
}