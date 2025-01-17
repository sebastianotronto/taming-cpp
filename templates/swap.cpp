#include <iostream>

template<typename S, typename T>
void swap(S& a, T& b) {
	S tmp = a;
	a = b;
	b = tmp;
}

int main() {
	int x = 3;
	std::string y = "1.0";
	swap(x, y);
	std::cout << "x: " << x << std::endl;
	std::cout << "y: " << y << std::endl;
}
