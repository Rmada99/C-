
#include <iostream>

//構造体「パラメータ型」を定義する
struct Parameter {
    int hp;         // HP
    int mp;         // MP
    char speed;     // 素早さ
    int attack;     // 攻撃力
    int defense;    // 防御力
    float magic;    // 魔法
};

// ---------------------------------------------------------
/**
 * @brief   各パラメータを表示する関数
 * @param   hp      HP
 * @param   mp      MP
 * @param   speed   素早さ
 * @param   attack  攻撃力
 * @param   defense 防御力
 * @param   magic   魔力
 */
void DispParameter(Parameter param)
{
    printf("HP:%d\n", param.hp);
    printf("MP:%d\n", param.mp);
    printf("素早さ:%c\n", param.speed);
    printf("攻撃力:%d\n", param.attack);
    printf("防御力:%d\n", param.defense);
    printf("魔力:%2.1f\n", param.magic);
}

// ---------------------------------------------------------
/**
 * @brief   main 関数
 */
int main()
{
    Parameter player_param = {
        100,
        50,
        'A',
        11,
        15,
        20.5f
    };//パラメータ型の変数を宣言する

    // プレイヤーのパラメータ表示
    DispParameter(player_param);

    Parameter enemy_param = { 110 ,20 ,'B' ,30 ,1,0};

    // 敵のパラメータ表示
    DispParameter(enemy_param);


    Parameter p;
    int parameter_size = sizeof(p);
    printf("Parameter型変数のサイズは %d", parameter_size);

    return 0;
}