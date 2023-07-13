#include "Common.h"
#include <conio.h>
#pragma once
void Common::fixConsoleWindow(){
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style &~(WS_MAXIMIZEBOX)&~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void Common::setConsoleWindow(int w, int h){
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	MoveWindow(console, r.left, r.top, w, h, TRUE);
}
void Common::gotoXY(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Common::showCur(){
    CONSOLE_CURSOR_INFO Info;
    Info.bVisible = TRUE;
    Info.dwSize = 20;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void Common::hideCur(){
    CONSOLE_CURSOR_INFO Info;
    Info.bVisible = FALSE;
    Info.dwSize = 20;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void Common::color(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Common::playSound(int i) {
    // static vector<const wchar_t*> soundFile{ L"beep.wav", L"move.wav",
    //    L"tick.wav", L"error.wav", L"win.wav", L"draw.wav", L"nhaccho.wav" };
    //if (isSoundOn == true && SOUND_ON == 1) {
    //    PlaySound(soundFile[i], NULL, SND_FILENAME | SND_ASYNC);
    //}
    // tắt nhạc 
    //PlaySound(0, 0, 0);
}
int Common::getConsoleInput() {
    int c = _getch();
    if (c == 0 || c == 224){
        switch (_getch()){
        case 72:	return 2;			//move up
        case 75:	return 3;			//move left
        case 77:	return 4;			//move right
        case 80:	return 5;			//move down
        default:    return 0; 
        }
    } else {
        if (c == 27)                  return 1;       //esc
        else if (c == 87 || c == 119) return 2;       //W, w
        else if (c == 65 || c == 97)  return 3;       //A, a
        else if (c == 68 || c == 100) return 4;       //D, d
        else if (c == 83 || c == 115) return 5;       //S, s  
        else if (c == 13)             return 6;       //Enter
        else if (c == 77 || c == 109) return 10;      //M, m ON/OFF sound
        else if (c == 69 || c == 101) return 13;      //E, e setting 	
        else if (c == 72 || c == 104) return 14;      //H, h gợi í
        else                          return 0;       
    }
}
void Common::clearConsole(){
    system("cls");
}
Common::Common(){}

Common::~Common(){}