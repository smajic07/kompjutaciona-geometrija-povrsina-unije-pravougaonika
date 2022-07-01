//---------------------------------------------------------------------------

#pragma hdrstop

#include "pomocna.h"

void Tacka::Crtaj(TImage* slika) {
    //slika->Canvas->Brush->Color = clRed;
    slika->Canvas->Ellipse(Rect(x-3,y-3,x+3, y+3));
}

/////////////////////////////////////////////////////////////

/// ZA PROJEKAT:

Cvor::Cvor(const int &pocetak, const int &kraj, double *X) {
    this->pocetak = pocetak;
	this->kraj = kraj;
	this->X = X;
	lijevi = nullptr;
	desni = nullptr;
	brojac = 0;
	ukupno = 0;
}

//---------------------------------------------------------------------------

int Cvor::dajIndeksSredine() {
	return pocetak + (kraj - pocetak) / 2;
}

//---------------------------------------------------------------------------

Cvor* Cvor::dajLijevi() {
	if (lijevi == nullptr)
		lijevi = new Cvor(pocetak, dajIndeksSredine(), X);
	return lijevi;
}

//---------------------------------------------------------------------------

Cvor* Cvor::dajDesni() {
	if (desni == nullptr)
		desni = new Cvor(dajIndeksSredine(), kraj, X);
	return desni;
}

//---------------------------------------------------------------------------

long double Cvor::azuriraj(const int &i, const int &j, const int &tip) {
	if (i >= j)
		return 0;
	if (pocetak == i && kraj == j)
		brojac += tip;
	else {
		dajLijevi()->azuriraj(i, min(dajIndeksSredine(), j), tip);
		dajDesni()->azuriraj(max(dajIndeksSredine(), i), j, tip);
	}

	if (brojac > 0)
		ukupno = X[kraj] - X[pocetak];
	else
		ukupno = dajLijevi()->ukupno + dajDesni()->ukupno;

	return ukupno;
}

//---------------------------------------------------------------------------

void Pravougaonik::Crtaj(TImage* slika) {

	Tacka donjaDesna(gornjaDesna.x, donjaLijeva.y);
	Tacka gornjaLijeva(donjaLijeva.x, gornjaDesna.y);

	slika->Canvas->MoveTo(donjaLijeva.x, donjaLijeva.y);

	slika->Canvas->LineTo(donjaDesna.x, donjaDesna.y);
	slika->Canvas->LineTo(gornjaDesna.x, gornjaDesna.y);
	slika->Canvas->LineTo(gornjaLijeva.x, gornjaLijeva.y);
	slika->Canvas->LineTo(donjaLijeva.x, donjaLijeva.y);

}

//---------------------------------------------------------------------------

#pragma package(smart_init)
