#include "bigint.h"

#include <iostream>
#include <optional>
#include <tuple>
#include <type_traits>

template<typename T>
concept Integer = requires(T a, T b, int i) {
	{T(i)};

	{a + b} -> std::same_as<T>;
	{a - b} -> std::same_as<T>;
	{a * b} -> std::same_as<T>;
	{a / b} -> std::same_as<T>;
	{a % b} -> std::same_as<T>;

	{a == b} -> std::same_as<bool>;
	{a != b} -> std::same_as<bool>;
};

template<Integer T>
std::tuple<T, T, T> extended_gcd(T a, T b) {
	if (b == 0) return {a, 1, 0};
	auto [g, x, y] = extended_gcd(b, a%b);
	return {g, y, x - y*(a/b)};
}

template<Integer auto N>
requires (N > 1)
class Zmod {
public:
	decltype(N) value;

	Zmod(decltype(N) z) : value{(z%N + N) % N} {}

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
	constexpr BigInt N("1000000000000000000000000000000");
	Zmod<N> x(BigInt("123456781234567812345678"));
	Zmod<N> y(BigInt("987654321987654321"));

	std::cout << x.value << " * "
	          << y.value << " (mod " << N << ") = "
	          << (x * y).value << std::endl;

	// The following line gives an error when trying to specialize Zmod<M>
	// constexpr double M = 3.14;
	// Zmod<M> z(4);

	return 0;
}
