// Taken from https://en.wikipedia.org/wiki/Template_metaprogramming

#include <iostream>

template<long long N>
class factorial {
public:
	static constexpr long long value = N * factorial<N-1>::value;
};

template<>
class factorial<0> {
public:
	static constexpr long long value = 1;
};

int main() {
	constexpr long long X = 12;
	std::cout << factorial<X>::value << std::endl;

	return 0;
}
