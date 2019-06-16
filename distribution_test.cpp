#include "distribution.cpp"

using namespace std;

int main() {
	RV a;
	a.set_Bin(10, 0.5);
	cout<<info(a)->pf(3);
}
