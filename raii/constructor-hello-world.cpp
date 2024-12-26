#include <iostream>

class BadType {
public:
	BadType() {
		std::cout << "Variable created!" << std::endl;
	}

	~BadType() {
		std::cout << "Variable destroyed, bye bye" << std::endl;
	}
};

int main() {
	BadType x;
	return 0;
}
