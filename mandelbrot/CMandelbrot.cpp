#include "CMandelbrot.h"

double quad(double a) {
    return a * a;
}

Daten CMandelbrot::inMandelbrotmenge(double c_realteil, double c_imaginearteil, size_t detail)
{
    size_t iteration = 0;
    double z_realteil = 0.0, z_imaginearteil = 0.0;
    double temp = 0.0; //Für zwischen Ergebnis
    /*
        Mandelbrot-Menge befindet sich nur zwischen den Bereich: -2 ... 2 Real und -2 ... 2 Imaginear
            => deshalb < 4.0
    */
    while (iteration < detail && (quad(z_realteil) + quad(z_imaginearteil)) < 16.0 ) 
    {
        temp = quad(z_realteil) - quad(z_imaginearteil) + c_realteil;
        z_imaginearteil = 2.0 * z_realteil * z_imaginearteil + c_imaginearteil;
        z_realteil = temp;
        iteration++;
    }

    Daten daten = Daten();

    daten.iterations = iteration;
    daten.z_imaginearteil = z_imaginearteil;
    daten.z_realteil = z_realteil;

    return daten;
}

double CMandelbrot::koordinateZuRealteil(int x, int bildBreite)
{
    double breite = maxRealteil - minRealteil; //z.B -1 minRealteil, 2 maxRealteil => 3 Einheiten Breit
    double skalierung = (breite / bildBreite);
    return minRealteil + ( x * skalierung ); // Koordinate wird zu Realer Zahl
}

double CMandelbrot::koordinateZuImaginearteil(int y, int bildHeohe)
{
    double hoehe = maxImaginearteil - minImaginearteil; //z.B -1 minImaginearteil, 2 maxImaginearteil => 3 Einheiten Hoch
    double skalierung = (hoehe / bildHeohe);
    return minImaginearteil + (y * skalierung); // Koordinate wird zu Imaginearer Zahl
}

size_t CMandelbrot::getDetail()
{
    return detail;
}

CMandelbrot::CMandelbrot(double minRealteil, double maxRealteil, double minImaginearteil, double maxImaginearteil, size_t detail)
{
    this->minRealteil = minRealteil;
    this->maxRealteil = maxRealteil;
    this->minImaginearteil = minImaginearteil;
    this->maxImaginearteil = maxImaginearteil;
    this->detail = detail;
}

double Daten::getZIntensiteatReal(CMandelbrot mandelbrot)
{
    double range = mandelbrot.maxRealteil - mandelbrot.minRealteil;
    double value = (this->z_realteil) / range;
    return 1 - value;
}

double Daten::getZIntensiteatImag(CMandelbrot mandelbrot)
{
    double range = mandelbrot.maxImaginearteil - mandelbrot.minImaginearteil;
    double value = (this->z_imaginearteil) / range;
    return 1 - value;
}
