#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Title.h"
#include "Creadit.h"
#include "GameFrame.h"

int main(void)
{
	system("mode con cols=180 lines=60");
	system("cls");

	Title title;
	title.DrawTitle();

	GameFrame gameFrame;
	gameFrame.GameMain();

	gameFrame.AddLog("시스템", "전투가 시작되었습니다!");
	Sleep(800); // 0.8초 대기

	gameFrame.AddLog("슬라임", "몸통 박치기!");
	Sleep(800);

	gameFrame.AddLog("시스템", "회피 성공!");
	Sleep(800);

	gameFrame.AddLog("슬라임", "1부르르 떨고 있다...");
	Sleep(1200);

	gameFrame.AddLog("슬라임", "2부르르 떨고 있다...");
	Sleep(1200);

	gameFrame.AddLog("슬라임", "3부르르 떨고 있다...");
	Sleep(1200);

	gameFrame.AddLog("슬라임", "4부르르 떨고 있다...");
	Sleep(1200);

	gameFrame.AddLog("슬라임", "5부르르 떨고 있다...");
	Sleep(1200);

	gameFrame.AddLog("시스템", "당신의 차례입니다.");
	gameFrame.AddLog("시스템", "공격하시겠습니까?");
	(void)_getch();

	Creadit creadit;
	creadit.DrawCreadit();

	return 0;
}