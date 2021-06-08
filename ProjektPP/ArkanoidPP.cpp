//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "ArkanoidPP.h"
#include <vector>
#include <MMSystem.h>
#include <Windows.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;
int x = -8;
int y = -8;
bool stop = true;
int score_counter = 0;
int end_score = 0;
AnsiString fileName = "readme.txt";
String musicName = "sounds/break.wav";


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BallTimerTimer(TObject *Sender)
{
	 Ball->Left += x;
	 Ball->Top += y;
	 if(Ball->Left <= Background->Left) {
		x = -x;
	 }
	 if (Ball->Top <= Background->Top) {
		y = -y;
	 }
	 if (Ball->Left >= Background->Left + Background->Width - Ball->Width) {
        x = -x;
	 }
	 //Hitting the ball
	 if(Ball->Top >= Player->Top && Ball->Top <= Player->Top + Player->Height) {
		if (Ball->Left >= Player->Left - 15 && Ball->Left <= Player->Left + Player->Width + 10){
		if(y>0){
			y = -y;
		}
		}
	 }
	 //GAME OVER
	 if(Ball->Top >= Background->Height){
		if(stop == false){
			  end_score = score_counter;
		}
		PlaySound(TEXT("C:/Users/Piotr/Desktop/ProjektPP/Win32/Debug/gameover.wav"), NULL, SND_ASYNC);
		String score_str = IntToStr(end_score);
		GAMEOVER->Visible = True;
		stop = true;
		Replay->Visible = True;
		Replay->Enabled = True;
		EndScore->Caption = "Your Score: " + score_str;
		EndScore->Visible = True;
		score_counter = 0;

	 }

	 //Score display
	 String howManyScores = IntToStr(score_counter);
	 Score->Caption = "Score: " + howManyScores;

	 //Hitting Bricks
	 fillArray();

	 //Checking Win
	 winCheck();



}
//---------------------------------------------------------------------------


void __fastcall TForm1::PlayerLeftTimer(TObject *Sender)
{
	if(Player->Left >= 10) {
	   Player->Left -= 10;
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::PlayerRightTimer(TObject *Sender)
{
	if(Player->Left + Player->Width <= Background->Width - 13){
	   Player->Left += 10;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if(Key == VK_LEFT && stop == false){
		if(Player->Left > Background->Left){
			PlayerLeft->Enabled = True;
		}
	}
	if(Key == VK_RIGHT && stop == false){
		PlayerRight->Enabled = True;
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if(Key == VK_LEFT){
		PlayerLeft->Enabled = False;
	}
	if(Key == VK_RIGHT){
		PlayerRight->Enabled = False;
	}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::PlayButtonClick(TObject *Sender)
{
	BallTimer->Enabled = True;
	stop = false;
	PlayButton->Enabled = False;
	PlayButton->Visible = False;
	Button1->Visible = False;
	Button1->Enabled = False;
	PlaySound(TEXT("C:/Users/Piotr/Desktop/ProjektPP/Win32/Debug/play.wav"), NULL, SND_ASYNC);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ReplayClick(TObject *Sender)
{
	//Replay
	Ball->Left = 480;
	Ball->Top = 544;
	stop = false;
	if(x >= 0){
		x = -x;
	}
	if(y >= 0){
		y = -y;
	}
	Player->Left = 448;
	GAMEOVER->Visible = False;
	Replay->Visible = False;
	Replay->Enabled = False;
	EndScore->Visible = False;
	Win->Visible = False;
	BallTimer->Enabled = True;
	makeVisibleTrue();
	PlaySound(TEXT("C:/Users/Piotr/Desktop/ProjektPP/Win32/Debug/play.wav"), NULL, SND_ASYNC);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::fillArray(){
	TImage* array[50] = {Image1, Image2, Image3, Image4, Image5, Image6, Image7, Image8, Image9, Image10,
						Image11, Image12, Image13, Image14, Image15, Image16, Image17, Image18, Image19, Image20,
						Image21, Image22, Image23, Image24, Image25, Image26, Image27, Image28, Image29, Image30,
						Image31, Image32, Image33, Image34, Image35, Image36, Image37, Image38, Image39, Image40,
						Image41, Image42, Image43, Image44, Image45, Image46, Image47, Image48, Image49, Image50,};

	TImage* array2[32] = {         Image52, Image53, Image54, Image55, Image56, Image57, Image58, Image59, Image60,
						  Image61, Image62, Image63, Image64, Image65, Image66, Image67, Image68, Image69, Image70,
						  Image71, Image72, Image73, Image74, Image75, Image76, Image77, Image78, Image79, Image80,
						  Image81, Image82, Image83};

	bool disappeared = false;

	for(int i=0; i<50; i++) {
		//Odbicie od lewego boku



		if(Ball->Left + 20 >= array[i]->Left &&
		   Ball->Left + 20 <= array[i]->Left + 10 &&
		   Ball->Top <= array[i]->Top + 20 &&
		   Ball->Top >= array[i]->Top - array[i]->Height &&
		   array[i]->Visible == True){
				if(x>0){
					x = -x;
				} else {

				}
				array[i]->Visible = False;
				PlaySound(TEXT("C:/Users/Piotr/Desktop/ProjektPP/Win32/Debug/break.wav"), NULL, SND_ASYNC);
				for(int j=0; j<32; j++) {
					if(array2[j]->Left == array[i]->Left && array2[j]->Top == array[i]->Top) {
						array2[j]->Visible = True;
						disappeared = true;
					}
				}
				score_counter++;
				break;
		   }
		   //Odbicie od prawego boku
		if(Ball->Left <= array[i]->Left + array[i]->Width &&
		   Ball->Left >= array[i]->Left + array[i]->Width - 10 &&
		   Ball->Top <= array[i]->Top + 20&&
		   Ball->Top >= array[i]->Top - array[i]->Height &&
		   array[i]->Visible == True){
				if(x<0){
					x = -x;
				} else {

				}
				array[i]->Visible = False;
				PlaySound(TEXT("C:/Users/Piotr/Desktop/ProjektPP/Win32/Debug/break.wav"), NULL, SND_ASYNC);
				for(int j=0; j<32; j++) {
					if(array2[j]->Left == array[i]->Left && array2[j]->Top == array[i]->Top) {
						array2[j]->Visible = True;
						disappeared = true;
					}
				}
				score_counter++;
				break;
		   }
		   //Odbicie od gory i od dolu
		if(Ball->Left + 20 > array[i]->Left + 10 &&
		   Ball->Left - 10 < array[i]->Left + array[i]->Width - 10 &&
		   Ball->Top <= array[i]->Top + 20 &&
		   Ball->Top >= array[i]->Top - array[i]->Height &&
		   array[i]->Visible == True){
				y = -y;
				array[i]->Visible = False;
				PlaySound(TEXT("C:/Users/Piotr/Desktop/ProjektPP/Win32/Debug/break.wav"), NULL, SND_ASYNC);
				for(int j=0; j<32; j++) {
					if(array2[j]->Left == array[i]->Left && array2[j]->Top == array[i]->Top) {
						array2[j]->Visible = True;
						disappeared = true;
					}
				}
				score_counter++;
				break;
		   }

	}


	if(!disappeared)
	{
	for(int i=0; i<32; i++) {
		//Odbicie od lewego boku
		if(Ball->Left + 20 >= array2[i]->Left &&
		   Ball->Left + 20 <= array2[i]->Left + 10 &&
		   Ball->Top <= array2[i]->Top + 20 &&
		   Ball->Top >= array2[i]->Top - array2[i]->Height &&
		   array2[i]->Visible == True){
				if(x>0){
					x = -x;
				} else {

				}
				array2[i]->Visible = False;
				PlaySound(TEXT("C:/Users/Piotr/Desktop/ProjektPP/Win32/Debug/break.wav"), NULL, SND_ASYNC);
				score_counter++;
				break;
		   }
		   //Odbicie od prawego boku
		if(Ball->Left <= array2[i]->Left + array2[i]->Width &&
		   Ball->Left >= array2[i]->Left + array2[i]->Width - 10 &&
		   Ball->Top <= array2[i]->Top + 20&&
		   Ball->Top >= array2[i]->Top - array2[i]->Height &&
		   array2[i]->Visible == True){
				if(x<0){
					x = -x;
				} else {

				}
				array2[i]->Visible = False;
				PlaySound(TEXT("C:/Users/Piotr/Desktop/ProjektPP/Win32/Debug/break.wav"), NULL, SND_ASYNC);
				score_counter++;
				break;
		   }
		   //Odbicie od gory i od dolu
		if(Ball->Left + 20 > array2[i]->Left + 10 &&
		   Ball->Left - 10 < array2[i]->Left + array2[i]->Width - 10 &&
		   Ball->Top <= array2[i]->Top + 20 &&
		   Ball->Top >= array2[i]->Top - array2[i]->Height &&
		   array2[i]->Visible == True){
				y = -y;
				array2[i]->Visible = False;
				PlaySound(TEXT("C:/Users/Piotr/Desktop/ProjektPP/Win32/Debug/break.wav"), NULL, SND_ASYNC);
				score_counter++;
				break;
		   }

	}
	}


}


void __fastcall TForm1::winCheck(){
	TImage* array[82] = {Image1, Image2, Image3, Image4, Image5, Image6, Image7, Image8, Image9, Image10,
						Image11, Image12, Image13, Image14, Image15, Image16, Image17, Image18, Image19, Image20,
						Image21, Image22, Image23, Image24, Image25, Image26, Image27, Image28, Image29, Image30,
						Image31, Image32, Image33, Image34, Image35, Image36, Image37, Image38, Image39, Image40,
						Image41, Image42, Image43, Image44, Image45, Image46, Image47, Image48, Image49, Image50,
								 Image52, Image53, Image54, Image55, Image56, Image57, Image58, Image59, Image60,
						Image61, Image62, Image63, Image64, Image65, Image66, Image67, Image68, Image69, Image70,
						Image71, Image72, Image73, Image74, Image75, Image76, Image77, Image78, Image79, Image80,
						Image81, Image82, Image83};

	bool check = true;

	for(int i=0; i<82; i++){
		if(array[i]->Visible == True) {
			check = false;
		}
	}

	if(check == true){
		stop = true;
		BallTimer->Enabled = False;
		Win->Visible = True;
		EndScore->Visible = True;
		Replay->Visible = True;
		Replay->Enabled = True;
	}
}


void __fastcall TForm1::makeVisibleTrue(){
    TImage* array[50] = {Image1, Image2, Image3, Image4, Image5, Image6, Image7, Image8, Image9, Image10,
						Image11, Image12, Image13, Image14, Image15, Image16, Image17, Image18, Image19, Image20,
						Image21, Image22, Image23, Image24, Image25, Image26, Image27, Image28, Image29, Image30,
						Image31, Image32, Image33, Image34, Image35, Image36, Image37, Image38, Image39, Image40,
						Image41, Image42, Image43, Image44, Image45, Image46, Image47, Image48, Image49, Image50,};

	for(int i=0; i<50; i++){
		array[i]->Visible = True;
	}
}


void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Memo1->Lines->LoadFromFile(fileName);
	Memo1->Visible = True;
	PlaySound(TEXT("C:/Users/Piotr/Desktop/ProjektPP/Win32/Debug/play.wav"), NULL, SND_ASYNC);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Memo1Click(TObject *Sender)
{
	Memo1->Visible = False;
}
//---------------------------------------------------------------------------

