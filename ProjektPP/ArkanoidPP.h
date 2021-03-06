//---------------------------------------------------------------------------

#ifndef ArkanoidPPH
#define ArkanoidPPH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.MPlayer.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TImage *Ball;
	TTimer *BallTimer;
	TImage *Player;
	TShape *Background;
	TTimer *PlayerLeft;
	TTimer *PlayerRight;
	TImage *Image1;
	TImage *Image2;
	TImage *Image3;
	TImage *Image4;
	TImage *Image5;
	TImage *Image6;
	TImage *Image7;
	TImage *Image8;
	TImage *Image9;
	TImage *Image10;
	TImage *Image11;
	TImage *Image12;
	TImage *Image13;
	TImage *Image14;
	TImage *Image15;
	TImage *Image16;
	TImage *Image17;
	TImage *Image18;
	TImage *Image19;
	TImage *Image20;
	TImage *Image21;
	TImage *Image22;
	TImage *Image23;
	TImage *Image24;
	TImage *Image25;
	TImage *Image26;
	TImage *Image27;
	TImage *Image28;
	TImage *Image29;
	TImage *Image30;
	TImage *Image31;
	TImage *Image32;
	TImage *Image33;
	TImage *Image34;
	TImage *Image35;
	TImage *Image36;
	TImage *Image37;
	TImage *Image38;
	TImage *Image39;
	TImage *Image40;
	TImage *Image41;
	TImage *Image42;
	TImage *Image43;
	TImage *Image44;
	TImage *Image45;
	TImage *Image46;
	TImage *Image47;
	TImage *Image48;
	TImage *Image49;
	TImage *Image50;
	TLabel *GAMEOVER;
	TButton *PlayButton;
	TButton *Replay;
	TLabel *Score;
	TLabel *EndScore;
	TLabel *Win;
	TImage *Image51;
	TImage *Image52;
	TImage *Image53;
	TImage *Image54;
	TImage *Image55;
	TImage *Image56;
	TImage *Image57;
	TImage *Image58;
	TImage *Image59;
	TImage *Image60;
	TImage *Image61;
	TImage *Image62;
	TImage *Image63;
	TImage *Image64;
	TImage *Image65;
	TImage *Image66;
	TImage *Image67;
	TImage *Image68;
	TImage *Image69;
	TImage *Image70;
	TImage *Image71;
	TImage *Image72;
	TImage *Image73;
	TImage *Image74;
	TImage *Image75;
	TImage *Image76;
	TImage *Image77;
	TImage *Image78;
	TImage *Image79;
	TImage *Image80;
	TImage *Image81;
	TImage *Image82;
	TImage *Image83;
	TButton *Button1;
	TMemo *Memo1;
	void __fastcall BallTimerTimer(TObject *Sender);
	void __fastcall PlayerLeftTimer(TObject *Sender);
	void __fastcall PlayerRightTimer(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FormKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall PlayButtonClick(TObject *Sender);
	void __fastcall ReplayClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Memo1Click(TObject *Sender);


private:	// User declarations
public:		// User declarations
	void __fastcall fillArray();
	void __fastcall winCheck();
    void __fastcall makeVisibleTrue();
	__fastcall TForm1(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
