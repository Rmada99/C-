#include <iostream>
#include"Player.h"
#include"Goblin.h"
#include"Slime.h"
#include"Turn.h"


int main()
{
    Turn turn;

    //プレイヤー
    std::shared_ptr<Character>player;
    player.reset(new Player());
    player->setHp();

    //敵
    std::shared_ptr<Character>enemies[2];
    enemies[0].reset(new Goblin());
    enemies[1].reset(new Slime());
    for (int i = 0; i < 2; i++) {
        enemies[i]->setHp();
    }

    //ゲームループ
    while (true) {
        bool end = turn.exec(player, enemies, 2);

        if (end) {


            break;
        }
    }
}
