#include "Random.h"
#include "Input.h"
#include "Judge.h"
#include "DispResult.h"
#include "Result.h"
#include <iostream>

int main()
{
	Random random;
	Input Input;
	Judge judge;
	DispResult dispResult;

	// ランダムの値を生成
	random.generate();

	//ゲームループ
	while (true)
	{
		//入力値
		Input.set();

		//判定
		Result res=judge.compare(random, Input);

		//結果表示
		dispResult.disp(res);

		//クリア判定
		if (res.isClear_) {
			break;
		}
	}
}
