#pragma once

//キャラパラメーター
struct Parameter
{
	int hp_; //体力
	int attack_; //攻撃力
};

//キャラクタークラス
class Character
{
public:
	//コンストラクタ
	Character() = default;
	//デストラクタ(基底クラスなので仮想関数)
	virtual ~Character() = default;

public:
	//攻撃力を設定する
	virtual void setAttack();

	//HPを設定する
	void setHp();

	//攻撃する(自身の攻撃力を返すのみ)
	int attack();

	//ダメージを受ける(攻撃してきたキャラの攻撃を受け取ってHPを減算)
	void damage(int power);

	//死んだかどうか
	bool isDead() const;

	//パラメータを返す関数(情報を教える)
	Parameter getParameter() const;



protected:
	Parameter param_; //キャラクターのパラメーター

};


