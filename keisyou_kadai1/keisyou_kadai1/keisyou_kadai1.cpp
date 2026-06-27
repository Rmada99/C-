
#include <iostream>

class Animal{
public:
    Animal(){}
    ~Animal(){}

    virtual void cry() = 0;

};

class Dog :public Animal {
    Dog(){}
    ~Dog(){}

    void cry()override {
        std::cout << "わん" << std::endl;
    }
};

class Cat :public Animal {
    Cat() {}
    ~Cat() {}

    void cry()override {
        std::cout << "にゃん" << std::endl;
    }
};


int main()
{
    //Animal* animals[] = { new Animal,new Dog,new Cat };
}
