#include <iostream>

// 再帰関数
template <class T,class... Args>
auto sumAll(T first, Args... args) {
	if constexpr(sizeof...(args)!= 0) {
		return first + sumAll(args...);
	}
	else {
		return first;
	}
}

int main() {
	auto a1 = sumAll(1, 2.1, 3.2f, 4, 5);
	auto a2 = sumAll(1, 2.05f, 3, 4, 5.99, 6, 7, 8.2, 9, 10);

	std::cout << a1 << std::endl;
	std::cout << a2 << std::endl;

	return 0;
}