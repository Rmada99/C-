#pragma once

//数値を保持するクラス
class Number
{
public:
	//
	void getValue(int* v, int size) const;


protected:
	int value_[4];//0~9までの４つの数値(継承先でも使えるように)
};

