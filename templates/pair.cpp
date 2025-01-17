#include <iostream>

template <typename S, typename T>
class Pair {
public:
	S first;
	T second;

	Pair(S s, T t) : first{s}, second{t} {}

	void print() const {
		std::cout << "(" << first << ", " << second << ")";
	}
};

int main() {
	Pair<int, char> p(42, 'x');
	p.second = 'y';

	std::cout << "p =";
	p.print();
	std::cout << std::endl;

	Pair q(1.23, 7); // template argument deduction

	std::cout << "q =";
	q.print();
	std::cout << std::endl;

	std::cout << "int type name: " << typeid(7).name() << std::endl;
	std::cout << "char type name: " << typeid('x').name() << std::endl;
	std::cout << "double type name: " << typeid(1.23).name() << std::endl;
	std::cout << "Type of p: " << typeid(p).name() << std::endl;
	std::cout << "Type of q: " << typeid(q).name() << std::endl;
}
