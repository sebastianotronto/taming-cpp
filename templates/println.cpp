#include <iostream>

template<auto X> void println() { std::cout << X << std::endl; }

int main() {
	println<1.23>();
	println<42>();

	// The following attempts to print a string do not work
	// uncomment to see why
	// 1.
	// println<"Hello!">();
	// 2.
	// constexpr std::string_view hello = "Hello!";
	// println<hello>();

	return 0;
}
