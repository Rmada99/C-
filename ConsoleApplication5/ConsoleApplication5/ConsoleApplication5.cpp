#include <iostream>
#include<string>

//
template<class T>
class Data {
public:
    void set(T data);
    T get()const;

private:
    T value_ = 0;
};

template<class T>
void Data<T>::set(T data) {
    value_ = data;
}

template<class T>
T Data<T>::get()const {
    return value_;
}

//
int main()
{
    Data<int> data;
    data.set(100);
    int d = data.get();

    Data<float> data2;
    data2.set(100.0f);
    int d2 = data2.get();
}
