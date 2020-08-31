#ifndef Masina_H
#define Masina_H
#include "Obiect.h"

class Masina : public Obiect
{
private:
	
	double rotireMasina;
public:
	Masina(double a, double b, double c, double rotireMasina);
	Masina();

	void setRotireMasina(double);

	double getRotireMasina();
	void Draw();
};

#endif