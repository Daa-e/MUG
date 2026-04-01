// Title.h

#pragma once
#include<iostream>

class Title
{
public:
	Title();
	~Title();

	void DrawTitle();

private:

	std::string gameTitle;
	void gotoxy(int x, int y);

	// 공식: (배경색 숫자 × 16) + 글자색 번호
	void setColor(int color);
};

