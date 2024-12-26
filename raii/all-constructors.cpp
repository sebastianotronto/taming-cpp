#include <iostream>

class T {
public:
	T(const std::string& a) : name{a} {
		std::cout << "Called constructor for " << name
		          << " (" << this << ")" << std::endl;
	}

	~T() {
		std::cout << "Called destructor for " << name
		          << " (" << this << ")" << std::endl;
	}

	T(T& other) : name{other.name} {
		std::cout << "Copy constructor called for " << name
		          << " (" << this << " copied from "
		          << &other << ")" << std::endl;
	}

	T& operator=(T& other) {
		name = other.name;
		std::cout << "Copy assignment called for " << name
		          << " (" << this << " copied from "
		          << &other << ")" << std::endl;
		return *this;
	}

	T(T&& other) : name{other.name} {
		std::cout << "Move constructor called for " << name
		          << " (" << this << " moved from "
		          << &other << ")" << std::endl;
	}

	T& operator=(T&& other) {
		name = other.name;
		std::cout << "Move assignment called for " << name
		          << " (" << this << " moved from "
		          << &other << ")" << std::endl;
		return *this;
	}
private:
	std::string name;
};

T do_nothing_and_return(T x) {
	return x;
}

T create(const std::string& str) {
	return T(str);
}

int main() {
	//T bad; // Compile-time error: no default constructor.

	std::cout << "---------- Declaring a simple variable ----------" << std::endl;
	T a("A");
	std::cout << std::endl;

	// Now we can see that objects are indeed scope-bound: they
	// are destroyed when they go out of scope.
	std::cout << "--- Declaring a variable in a temporary scope ---" << std::endl;
	{
		std::cout << "Entering temporary scope" << std::endl;
		T b("short-lived");
		std::cout << "Exiting temporary scope" << std::endl;
	}
	std::cout << "Out of temporary scope" << std::endl;
	std::cout << std::endl;

	std::cout << "------------ Constructing by copying ------------" << std::endl;
	T b("B");
	T c(b);
	T d = b; // This is also a copy constructor, not a copy assignment
	std::cout << std::endl;

	// Copy assignment operators differ from copy constructors in that they
	// should also clean up the resources for the copied-to object.
	std::cout << "---------------- Copy assignment ----------------" << std::endl;
	c = b;
	std::cout << std::endl;

	std::cout << "------------ Constructing by moving -------------" << std::endl;
	T e(do_nothing_and_return(b));
	std::cout << std::endl;

	std::cout << "---------------- Move assignment ----------------" << std::endl;
	e = create("E");
	std::cout << std::endl;
	
	std::cout << "------------- Destroying everything -------------" << std::endl;
	return 0;
}
