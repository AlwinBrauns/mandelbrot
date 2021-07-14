#include "CFilehandler.h"

void CFilehandler::schreibeDatei(CMandelbrot mandelbrot)
{
	using std::ofstream;
	using std::cout;
	using std::endl;

	ofstream dateiAusgabe(DATEI_BILD);
	if (!dateiAusgabe) {
		cout << "Fehler beim erstellen der Datei" << endl;
		return;
	}
	dateiAusgabe << "P3" << endl; //"Magic-Number" für PPM fileformat
	dateiAusgabe << WIDTH << " " << HEIGHT << endl;
	dateiAusgabe << "255" << endl; // Maximale Pixelwerte für RGB

	size_t detail = mandelbrot.getDetail();
	for (int zeile = 0; zeile < HEIGHT; zeile++)
	{
		double imaginearteil = mandelbrot.koordinateZuImaginearteil(zeile, HEIGHT);

		for (int spalte = 0; spalte < WIDTH; spalte++) {
			double realteil = mandelbrot.koordinateZuRealteil(spalte, WIDTH);


			Daten intensiteat = mandelbrot.inMandelbrotmenge(
				realteil,
				imaginearteil,
				detail
			);

			int rot = (intensiteat.iterations % 255 * intensiteat.getZIntensiteatReal(mandelbrot));
			int gruen = (intensiteat.iterations % 255 * intensiteat.getZIntensiteatImag(mandelbrot));
			int blau = (intensiteat.iterations % 255);

			dateiAusgabe << rot << " " << gruen << " " << blau << " ";
		}
		dateiAusgabe << endl;
	}
	dateiAusgabe.close();
}

CFilehandler::CFilehandler(std::string DATEI_BILD, int WIDTH, int HEIGHT)
{
	this->DATEI_BILD = DATEI_BILD;
	this->WIDTH = WIDTH;
	this->HEIGHT = HEIGHT;
}
