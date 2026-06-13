
#include <iostream>

class IntPtr {
public:
	IntPtr(int* ptr) {
		//
		ptr_ = ptr;
		std::cout << "生成" << std::endl ;
	}

	~IntPtr() {
		//
		delete ptr_;
		std::cout << "破棄" << std::endl;
	}

	void set(int value) {
		//
		*ptr_ = value;
	}

	int get() const {
		//
		return *ptr_;
	}

private:
	int* ptr_ = nullptr;
};

int main() {
	IntPtr ptr(new int);

	ptr.set(3);

	int a = ptr.get();

	std::make_unique<int>(5);
}