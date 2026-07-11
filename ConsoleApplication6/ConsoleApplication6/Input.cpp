#include "input.h"
#include <iostream>

//
void Input::set() {
	std::cout << "入力開始---------------------------" << std::endl;
	for (int i=0;i<4; i++) {
		std::cout << i << "番の数値を入力：" ;
		std::cin >>value_[i];
	}
}


