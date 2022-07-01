//---------------------------------------------------------------------------

#ifndef FormaH
#define FormaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <vector>
#include <list>
#include "pomocna.h"
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
	TImage *Slika;

    /// ZA PROJEKAT:

	TButton *povrsinaUnijeDugme;
	TRadioButton *DodavanjePravougaonika;

	void __fastcall SlikaMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y);

	void __fastcall povrsinaUnijeDugmeClick(TObject *Sender);
private:

  /// ZA PROJEKAT:

  vector<Pravougaonik> pravougaonici;
  bool dodajemDonjuLijevu = true;
  Tacka donjaLijeva;
  Tacka gornjaDesna;

  public:
	__fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
