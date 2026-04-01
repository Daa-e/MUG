// Title.cpp
#pragma execution_character_set("utf-8")
#include "Title.h"
#include <iostream>
#include <windows.h>
#include <conio.h>


Title::Title() : gameTitle("드래곤 키우기") {}
Title::~Title() {}


// COORD와 static_cast<SHORT>는 정해진 것 외워야 함
void Title::gotoxy(int x, int y)
{
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


// SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) 정해진 것 외워야 함
void Title::setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


void Title::DrawTitle()
{
	UINT oldCP = GetConsoleOutputCP(); // 지금 쓰고있는 유니코드 저장
	SetConsoleOutputCP(65001);		   // 유니코드 6501

	system("mode con cols=120 lines=30");
	system("cls");

	setColor(7);
	gotoxy(25, 7);  std::cout << "	   ██████  ██████   █████   ██████   ██████  ███    ██" << std::endl;
	gotoxy(25, 8);  std::cout << "	   ██   ██ ██   ██ ██   ██ ██       ██    ██ ████   ██" << std::endl;
	gotoxy(25, 9);  std::cout << "	   ██   ██ ██████  ███████ ██   ███ ██    ██ ██ ██  ██" << std::endl;
	gotoxy(25, 10); std::cout << "	   ██   ██ ██   ██ ██   ██ ██    ██ ██    ██ ██  ██ ██" << std::endl;
	gotoxy(25, 11); std::cout << "	   ██████  ██   ██ ██   ██  ██████   ██████  ██   ████" << std::endl;
	gotoxy(25, 13); std::cout << "                                                " << std::endl;
	gotoxy(25, 16); std::cout << "                        Press Enter to Start...                  " << std::endl;

	setColor(14);
	gotoxy(80, 20); std::cout << gameTitle << " by Daae" <<std::endl;

	// 키 입력 대기 (반환값 무시)
	(void)_getch();
	
	system("cls");
	SetConsoleOutputCP(oldCP); // 출력 다했으니 유니코드 원상복구
}



