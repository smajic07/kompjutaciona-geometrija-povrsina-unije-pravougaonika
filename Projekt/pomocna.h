//---------------------------------------------------------------------------

#ifndef pomocnaH
#define pomocnaH
#include <algorithm>
using namespace std;

struct Tacka {
	double x,y;
	Tacka(double X = 0, double Y = 0):x(X),y(Y) {}
    void Crtaj(TImage*);
};

/// ZA PROJEKAT:

class Cvor {
private:
	int pocetak;
	int kraj;
	double *X;
	Cvor *lijevi;
	Cvor *desni;
	int brojac;
	long double ukupno;

public:
	Cvor(const int &pocetak, const int &kraj, double *X);
	int dajIndeksSredine();
	Cvor* dajLijevi();
	Cvor* dajDesni();
	long double azuriraj(const int &i, const int &j, const int &tip);
};

struct Pravougaonik {
	Tacka donjaLijeva, gornjaDesna;
	Pravougaonik(Tacka A, Tacka B) : donjaLijeva(A), gornjaDesna(B) {
		if(B.x < A.x){
			swap(donjaLijeva, gornjaDesna);
		}
	}
    void Crtaj(TImage*);
};

//---------------------------------------------------------------------------
#endif
