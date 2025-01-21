#include <iostream>
#include <optional>
#include <tuple>

std::tuple<int, int, int> extended_gcd(int a, int b) {
	if (b == 0) return {a, 1, 0};
	auto [g, x, y] = extended_gcd(b, a%b);
	return {g, y, x - y*(a/b)};
}

template<int N>
requires (N > 1)
class Zmod {
public:
	int value;

	Zmod(int z) : value{(z%N + N) % N} {}

	Zmod operator+(const Zmod& z) const { return value + z.value; }
	Zmod operator-(const Zmod& z) const { return value - z.value; }
	Zmod operator*(const Zmod& z) const { return value * z.value; }

	std::optional<Zmod> inverse() const {
		auto [g, a, _] = extended_gcd(value, N);
		return g == 1 ? Zmod(a) : std::optional<Zmod>{};
	}

	std::optional<Zmod> operator/(const Zmod& d) const {
		auto i = d.inverse();
		return i ? (*this) * i.value() : i;
	}

	std::optional<Zmod> operator/=(const Zmod& d) {
		auto q = *this / d;
		return q ? (*this = q.value()) : q;
	}
};

int main() {
	Zmod<57> x(34);
	Zmod<57> y(11);

	std::cout << "34 * 11 = " << (x * y).value << " (mod 57)" << std::endl;

	if (auto inv = y.inverse(); inv)
		std::cout << "11 * " << inv.value().value << " = 1 (mod 57)" << std::endl;
	else
		std::cout << "11 is not invertible in Z/57Z" << std::endl;


	// Contrary to zmodn-1.cpp, the following line does not compile at all
	Zmod<0> z(157);

	return 0;
}
