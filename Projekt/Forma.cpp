//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Forma.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include <string>

/// ZA PROJEKAT:

#include <unordered_map>

TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
  Slika->Canvas->FillRect(Rect(0,0,Slika->Width, Slika->Height));
}
//---------------------------------------------------------------------------
void __fastcall TForm4::SlikaMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	if(DodavanjePravougaonika->Checked) {
		if(dodajemDonjuLijevu){
			donjaLijeva = Tacka(X,Y);
			donjaLijeva.Crtaj(Slika);
			dodajemDonjuLijevu = false;
		}
		else{
			gornjaDesna = Tacka(X,Y);
			gornjaDesna.Crtaj(Slika);

			Tacka donjaDesna(gornjaDesna.x, donjaLijeva.y);
			Tacka gornjaLijeva(donjaLijeva.x, gornjaDesna.y);

			Pravougaonik pravougaonik(gornjaLijeva, donjaDesna);
			pravougaonici.push_back(pravougaonik);
			pravougaonik.Crtaj(Slika);

			dodajemDonjuLijevu = true;
		}
	}
}

//---------------------------------------------------------------------------

void __fastcall TForm4::povrsinaUnijeDugmeClick(TObject *Sender)
{
	int brojPravougaonika(pravougaonici.size());
	vector<vector<double>> dogadjaji(brojPravougaonika*2);

	int redniBrojDogadjaja(0);

	int brojDogadjaja(dogadjaji.size());
	double *X(new double[brojDogadjaja]);
	int indeks(0);

    for (auto pravougaonik : pravougaonici) {
		dogadjaji[redniBrojDogadjaja++] = { pravougaonik.donjaLijeva.y, 1,
									pravougaonik.donjaLijeva.x, pravougaonik.gornjaDesna.x };
		dogadjaji[redniBrojDogadjaja++] = { pravougaonik.gornjaDesna.y, -1,
									pravougaonik.donjaLijeva.x, pravougaonik.gornjaDesna.x };

		X[indeks++] = pravougaonik.donjaLijeva.x;
		X[indeks++] = pravougaonik.gornjaDesna.x;
    }

	sort(dogadjaji.begin(), dogadjaji.end(), [](const vector<double> &a, const vector<double> &b) -> bool {
												 return a[0] < b[0];
											 });

	sort(X, X + brojDogadjaja);

	unordered_map<double, int> Xi; // Heš mapa bez duplikata
	for (int i = 0; i < brojDogadjaja; ++i)
        Xi.insert({X[i], i});

    Cvor *aktivni(new Cvor(0, brojDogadjaja - 1, X));
    long double povrsina(0);
    long double trenutna_x_suma(0);
    double trenutni_y(dogadjaji[0][0]);

    for (auto dogadjaj : dogadjaji) {
        double y = dogadjaj[0], tip = dogadjaj[1], x1 = dogadjaj[2], x2 = dogadjaj[3];
        povrsina += trenutna_x_suma * (y - trenutni_y);
		trenutna_x_suma = aktivni->azuriraj((Xi.find(x1))->second, (Xi.find(x2))->second,
											tip);
        trenutni_y = y;
    }

	ShowMessage((int)(povrsina));

}

//---------------------------------------------------------------------------
