#pragma execution_character_set("utf-8")
#include "GameFrame.h"
#include <iostream>

void GameFrame::setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void GameFrame::gotoxy(int x, int y)
{
    COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void GameFrame::PrintRawLog(std::string fullMsg, int line)
{
    int startX = 16;
    int startY = 32;

    gotoxy(startX, startY + line);
    for (int i = 0; i < 145; i++)
    {
        std::cout << " ";
    }

    gotoxy(startX, startY + line);
    if (fullMsg.find("[시스템]") != std::string::npos) setColor(14);
    else setColor(7);

    std::cout << fullMsg;
    setColor(7);
}

void GameFrame::AddLog(std::string name, std::string msg)
{
    std::string currentMsg = "[" + name + "] " + msg;
    logList.push_back(currentMsg);

    if (logList.size() > maxLog + 1)
    {
        logList.erase(logList.begin());
    }

    for (int i = 0; i < logList.size(); i++)
    {

        PrintRawLog(logList[i], i);
    }
}

void GameFrame::GameMain()
{
    UINT oldCP = GetConsoleOutputCP();
    SetConsoleOutputCP(65001);

    setColor(7);

    int startX = 10;
    int endX = 170;
    int midX = 50;

    // --- 상단 로그 박스 1 ~ 40라인 ---
    gotoxy(startX, 1);
    std::cout << "╔";
    //                    경계값 빼기위한 -1
    for (int i = 0; i < (endX - startX - 1); i++) std::cout << "═";
    std::cout << "╗";

    // 세로 길이 40 라운드 패널을 위해 구간 분리
    for (int i = 2; i <= 29; i++)
    {
        gotoxy(startX, i);   std::cout << "║";
        gotoxy(endX, i);     std::cout << "║";
    }

    // 30번 라인 패널 이음새
    gotoxy(startX, 30);  std::cout << "╣";
    gotoxy(endX, 30);    std::cout << "╠";

    for (int i = 31; i <= 40; i++)
    {
        gotoxy(startX, i);   std::cout << "║";
        gotoxy(endX, i);     std::cout << "║";
    }

    // --- 하단 라운드 BATTLE LOG 패널 31 ~ 39라인 ---
    int logStartX = startX + 4;
    int logEndX = endX - 4;

    setColor(9);
    gotoxy(logStartX, 31);
    std::cout << "╭";
    for (int i = 0; i < (logEndX - logStartX - 1); i++) std::cout << "═";
    std::cout << "╮";

    for (int i = 32; i <= 38; i++)
    {
        gotoxy(logStartX, i); std::cout << "║";
        gotoxy(logEndX, i);   std::cout << "║";
    }

    gotoxy(logStartX, 39);
    std::cout << "╰";
    for (int i = 0; i < (logEndX - logStartX - 1); i++) std::cout << "═";
    std::cout << "╯";

    // --- 중간 구분선 41번 라인 ---
    setColor(7); // 다시 기본색으로
    gotoxy(startX, 41);
    std::cout << "╠";
    for (int i = 0; i < (midX - startX - 1); i++) std::cout << "═";
    std::cout << "╦";
    for (int i = 0; i < (endX - midX - 1); i++) std::cout << "═";
    std::cout << "╣";

    // --- 하단 스탯 & 커맨드 영역 42 ~ 55라인 ---
    for (int i = 42; i <= 55; i++) {
        gotoxy(startX, i);   std::cout << "║"; // 왼쪽 끝
        gotoxy(midX, i);     std::cout << "║"; // 중간 구분벽
        gotoxy(endX, i);     std::cout << "║"; // 오른쪽 끝
    }

    // --- 최하단 선 56번 라인 ---
    gotoxy(startX, 56);
    std::cout << "╚";
    for (int i = 0; i < (midX - startX - 1); i++) std::cout << "═";
    std::cout << "╩";
    for (int i = 0; i < (endX - midX - 1); i++) std::cout << "═";
    std::cout << "╝";

    // --- 타이틀 텍스트 입히기 ---
    setColor(15);
    gotoxy(startX + 4, 1);   std::cout << "╣ Battle Screen ╠";

    setColor(9);
    gotoxy(logStartX + 4, 31); std::cout << "╣ BATTLE LOG ╠";

    setColor(15);
    gotoxy(startX + 4, 41);  std::cout << "╣ STATUS ╠";
    gotoxy(midX + 4, 41);    std::cout << "╣ COMMAND ╠";

    setColor(7);
    SetConsoleOutputCP(oldCP);
}