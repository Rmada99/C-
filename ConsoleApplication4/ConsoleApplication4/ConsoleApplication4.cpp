#include <iostream>

//コンストラクタ、デストラクタは省略

// 自動車クラス
class Car
{
public:
    virtual void carry() {
        std::cout << "何かを運ぶ" << std::endl;
    }
};

// タンクローリークラス
class Tank : public Car
{
public:
    void tankCarry() {
        std::cout << "燃料を運ぶ" << std::endl;
    }
};

// ダンプカークラス
class Dump : public Car
{
public:
    void dumpCarry() {
        std::cout << "土砂を運ぶ" << std::endl;
    }
};

// エントリー関数
int main()
{
    //
    Car* car[] = { new Car(),new Tank(),new Dump(),};

    //
    for (int i = 0; i < 3; i++) {
        car[i]->carry();
    }

    for (int i = 0; i < 3; i++) {
        delete car[i];
    }
}
