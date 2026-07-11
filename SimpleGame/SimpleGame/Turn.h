#pragma once
#include <memory>
#include "Character.h"

struct Result
{
	int turnCount_ = 0;	//決着までのターン数
	int maxPlayerPower_ = 0;	//プレイヤーが与えた最大ダメージ値
	int maxEnemyPower_ = 0;		//敵側が与えた最大ダメージ値

};

class Turn
{
public:
	//ターンを実行する
	bool exec(std::shared_ptr<Character>player, std::shared_ptr<Character>* enemies,int enemyNum);


private:
	Result result_;//リザルト情報
};

