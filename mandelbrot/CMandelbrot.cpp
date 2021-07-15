#include "CMandelbrot.h"

double quad(double a) {
    return a * a;
}

double qubic(double a) {
    return a * a * a;
}

double zhoch2(double &z_realteil, double &z_imaginearteil, double &c_realteil, double &c_imaginearteil) {
    double betrag;
    double temp;
    temp = quad(z_realteil) - quad(z_imaginearteil) + c_realteil;
    z_imaginearteil = 2 * z_realteil * z_imaginearteil + c_imaginearteil;
    z_realteil = temp;
    return quad(z_realteil) + quad(z_imaginearteil);
}

double zhoch3(double &z_realteil, double &z_imaginearteil, double &c_realteil, double &c_imaginearteil) {
    double betrag;
    double temp;
    temp = qubic(z_realteil) // a³
        - quad(z_imaginearteil) * z_realteil // b²a
        - 2 * z_realteil * quad(z_imaginearteil) // 2ab²
        + c_realteil;
    z_imaginearteil = quad(z_realteil) * z_imaginearteil // a²bi
        - qubic(z_imaginearteil) // b³i
        + 2 * quad(z_realteil) * z_imaginearteil // 2a²bi
        + c_imaginearteil;
    z_realteil = temp;
    return quad(z_realteil) + quad(z_imaginearteil);
}

Daten CMandelbrot::inMandelbrotmenge(double c_realteil, double c_imaginearteil, size_t detail)
{
    size_t iteration = 0;
    double betrag = 0.0;
    double z_realteil = 0.0, z_imaginearteil = 0.0;
    double temp = 0.0; //Für zwischen Ergebnis
    size_t boost = 1;
    /*
        Mandelbrot-Menge befindet sich nur zwischen den Bereich: -2 ... 2 Real und -2 ... 2 Imaginear
            => deshalb < 4.0
    */
    while (iteration < detail*boost && betrag < 4.0 ) 
    {
        betrag = zhoch2(z_realteil, z_imaginearteil, c_realteil, c_imaginearteil);
        iteration++;
    }

    Daten daten = Daten();

    daten.iterations = iteration / boost;
    daten.z_imaginearteil = z_imaginearteil;
    daten.z_realteil = z_realteil;
    daten.betrag = betrag;

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

double Daten::getZIntensiteatAll(CMandelbrot mandelbrot)
{
    double irange = mandelbrot.maxImaginearteil - mandelbrot.minImaginearteil;
    double rrange = mandelbrot.maxRealteil - mandelbrot.minRealteil;
    double range = irange + rrange;
    double value = (this->z_imaginearteil+this->z_realteil) / range;
    return value;
}
