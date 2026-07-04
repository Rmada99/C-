#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<random>

//キャラクタークラス
class Chalacter {
public: 
    const char* name = "none";
    int HP = 0;
    int Attack=0;
    virtual void status() {
        Attack = (int)time(nullptr) % 11;
    }
    virtual void die() {
        std::cout << "死亡" << std::endl;
    }
};
//プレイヤー
class Player :public Chalacter {
public:
     const char* name  = "player";
    void status() override{
        Attack = (int)time(nullptr) % 21;
    }

    void die()override {
        std::cout << "プレイヤー死亡" << std::endl;
    }
};
//スライム
class Slime :public Chalacter {
    const char* name = "slime";

    void die()override {
        std::cout << "スライム死亡" << std::endl;
    }
};
//ゴブリン
class Goblin :public Chalacter {
public:
    const char* name = "goblin";
    void status()override {
        Attack= (int)time(nullptr) % 9+8;
    }

    void die()override {
        std::cout << "ゴブリン死亡" << std::endl;
    }
};

//ターンクラス
class Turn {
public:
    int playerAttack(int eHP,int pAttack,const char* pName,const char* eName) {
        int HP= eHP -= pAttack;

        printf("%sの攻撃\n", eName);
        printf("%sに%dのダメージ", eName, pAttack);
        printf("%sの残りHP:%d", eName, eHP);

        return(HP);
    }

    int enemyAttack(int pHP, int eAttack,const char* pName, const char* eName) {
        int HP =pHP -= eAttack;

        printf("%sの攻撃\n", eName);
        printf("%sに%dのダメージ", eName, eAttack);
        printf("%sの残りHP:%d", eName, pHP);

        return(HP);
    }
};

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(50, 100);
    //Player* player = new Player;
    //Slime* slime = new Slime;
    //Goblin* goblin = new Goblin;

    Chalacter* chalacter[] = { new Player,new Slime,new Goblin };
    Turn* turn = new Turn;

    for (int i = 0; i < 3; i++) {
        chalacter[i]->HP = dist(gen);
    }

    while (true) {
        for (int i = 0; i < 3; i++) {
            chalacter[i]->status();
            printf("HP:%d\nAttack%d\n", chalacter[i]->HP, chalacter[i]->Attack);
        }
        //プレイヤーの攻撃
        while (true) {
            int select=0;
            
            printf("攻撃相手を選択：\nスライム:1\nゴブリン:2\n");
            scanf_s("%d\n",&select);
            

            std::printf("%d",select);
            if (select == 1||select==2) {
                chalacter[select]->HP=turn->playerAttack(chalacter[select]->HP, chalacter[0]->Attack,chalacter[0]->name,chalacter[select]->name);
                if (chalacter[select]->HP <= 0) {
                    chalacter[select]->die();

                    delete chalacter[select];
                    chalacter[select] = NULL;
                }
                break;
            }
            else {
                printf("攻撃相手を選んでください");
            }
        }
        //エネミーの攻撃
        for (int f = 1; f < 3; f++) {
            if (chalacter[f] != NULL) {
                chalacter[0]->HP = turn->enemyAttack(chalacter[0]->HP, chalacter[f]->Attack, chalacter[0]->name, chalacter[f]->name);
            }
        }

        if (chalacter[0] == NULL) {
            chalacter[0]->die();
            delete chalacter[0];
            chalacter[0] = NULL;
            printf("エネミーの勝利！\n");
            break;
        }
        if (chalacter[1] == NULL && chalacter[2] == NULL) {
            printf("プレイヤーの勝利！\n");
            break;
        }
    }

    printf("ゲーム終了！");
    return 0;
}
