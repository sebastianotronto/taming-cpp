class BadType {
public:
	BadType() {
		BadType recursion_hell;
	}
};

int main() {
	BadType x;
	return 0;
}
