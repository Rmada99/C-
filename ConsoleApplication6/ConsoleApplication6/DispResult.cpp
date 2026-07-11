#include "DispResult.h"
#include "Result.h"
#include <iostream>

//
void DispResult::disp(const Result& res){
	std::cout << "結果---------------------------" << std::endl;

	std::cout << "ヒット数：" << res.hit << std::endl;
	std::cout << "ブロー数：" << res.blow << std::endl;
	if (res.isClear_) {
		std::cout << "クリア" << std::endl;
	}
}