#include "Judge.h"
#include "Random.h"
#include "Input.h"
#include "Result.h"

//
Result Judge::compare(const Number& rand, const Number& input) {

	int in[4];
	int rn[4];
	//ランダムの値を取得
	rand.getValue(rn, 4);
	//入力の値を取得
	input.getValue(in, 4);
	
	bool isHit[4] = {};
	int hitNum = 0;
	for (int i = 0; i < 4; i++) {
		if (rn[i] == in[i]) {
			//ヒット
			hitNum++;
			isHit[i] = true;
		}
	}

	//ブローの数
	int blowNum = 0;
	for(int i = 0; i < 4; i++) {
		if(isHit[i]) {
			//ヒットしている場合はブローの判定をしない
			continue;
		}

		int inputNum = in[i];

		//rn用のループ
		for (int j = 0; j < 4; j++) {
			if(isHit[j]) {
				//ヒットしている場合はブローの判定をしない
				continue;
			}

			if(rn[j] == inputNum) {
				//ブロー
				blowNum++;
			}
		}
	}

	//
	Result res;
	res.hit = hitNum;
	res.blow = blowNum;
	res.isClear_ = (hitNum == 4);
	
	return res;
}