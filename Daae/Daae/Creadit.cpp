#pragma execution_character_set("utf-8")
#include "Creadit.h"
#include <iostream>
#include <windows.h>
#include <conio.h>

Creadit::Creadit() : text(" "){}
Creadit::~Creadit() {}

void Creadit::gotoxy(int x, int y)
{
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Creadit::setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Creadit::DrawCreadit()
{
    UINT oldCP = GetConsoleOutputCP(); // 지금 쓰고있는 유니코드 저장
    SetConsoleOutputCP(65001);		// 유니코드 6501

    system("cls");

    setColor(1);
    gotoxy(65, 21); std::cout << "████████╗██╗  ██╗███████╗    ███████╗███╗   ██╗██████╗ " << std::endl;
    gotoxy(65, 22); std::cout << "╚══██╔══╝██║  ██║██╔════╝    ██╔════╝████╗  ██║██╔══██╗" << std::endl;
    gotoxy(65, 23); std::cout << "   ██║   ███████║█████╗      █████╗  ██╔██╗ ██║██║  ██║" << std::endl;
    gotoxy(65, 24); std::cout << "   ██║   ██╔══██║██╔══╝      ██╔══╝  ██║╚██╗██║██║  ██║" << std::endl;
    gotoxy(65, 25); std::cout << "   ██║   ██║  ██║███████╗    ███████╗██║ ╚████║██████╔╝" << std::endl;
    gotoxy(65, 26); std::cout << "   ╚═╝   ╚═╝  ╚═╝╚══════╝    ╚══════╝╚═╝  ╚═══╝╚═════╝ " << std::endl;

    setColor(14);
    gotoxy(75, 30); std::cout << text << std::endl;

    setColor(7);
    gotoxy(82, 34); std::cout << "[ Thanks for Playing! ]" << std::endl;

    (void)_getch();

    system("cls");
    SetConsoleOutputCP(oldCP); // 출력 다했으니 유니코드 원상복구
}