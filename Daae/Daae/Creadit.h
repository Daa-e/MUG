// Creadit.h

#pragma once
#include<iostream>

class Creadit
{
public:
	Creadit();
	~Creadit();

	void DrawCreadit();

private:

	std::string text;
	void gotoxy(int x, int y);

	// 공식: (배경색 숫자 × 16) + 글자색 번호
	void setColor(int color);
};

