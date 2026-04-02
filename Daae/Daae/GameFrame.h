#pragma once
#include <iostream>
#include <windows.h>
#include <vector>
class GameFrame
{
public:
	void GameMain();

	void AddLog(std::string name, std::string msg);
	void PrintRawLog(std::string fullMsg, int line);

	void setColor(int color);
	void gotoxy(int x, int y);

private:
	std::vector<std::string> logList;
	const int maxLog = 6;
};