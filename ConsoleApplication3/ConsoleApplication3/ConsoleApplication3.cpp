#include <iostream>
#include <memory>

// クラス定義
class MyClass final
{
public:
    ~MyClass() {
        std::cout << "デストラクタ" << std::endl;
    }

public:
    std::weak_ptr<MyClass> ptr_ = {};
    int                      value_ = 0;
};

// メイン関数
int main()
{
    {
        std::shared_ptr<MyClass> a = std::make_shared<MyClass>();
        std::shared_ptr<MyClass> b = std::make_shared<MyClass>();

        a->ptr_ = b;
        b->ptr_ = a;
    }

    return 0;
}