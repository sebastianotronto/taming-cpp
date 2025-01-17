#include <array>
#include <iostream>

int main() {
	std::array<double, 5> a {1.0, 1.1, 1.2};
	std::cout << "Capacity of a: " << a.size() << std::endl;

	a[3] = 1.3;
	a[4] = 1.4;

	for (auto x : a)
		std::cout << x << " ";
	std::cout << std::endl;

	return 0;
}
