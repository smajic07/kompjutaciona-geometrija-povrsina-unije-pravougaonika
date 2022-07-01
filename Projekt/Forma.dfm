object Form4: TForm4
  Left = 0
  Top = 0
  Caption = 'Form4'
  ClientHeight = 588
  ClientWidth = 993
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Slika: TImage
    Left = 8
    Top = 8
    Width = 833
    Height = 545
    OnMouseDown = SlikaMouseDown
  end
  object povrsinaUnijeDugme: TButton
    Left = 859
    Top = 287
    Width = 126
    Height = 25
    Caption = 'Povr'#353'ina unije'
    TabOrder = 0
    OnClick = povrsinaUnijeDugmeClick
  end
  object DodavanjePravougaonika: TRadioButton
    Left = 859
    Top = 256
    Width = 126
    Height = 17
    Caption = 'Dodaji pravougaonike'
    TabOrder = 1
  end
end
