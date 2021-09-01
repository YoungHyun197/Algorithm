#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int X;
	cin >> X;
	if (X >= 90) cout << "A";
	else if (X >= 80 && X <= 89) {
		cout << "B";
	}
	else if (X >= 70 && X <= 79) {
		cout << "C";
	}
	else if (X >= 60 && X <= 69) {
		cout << "D";
	}
	else cout << "F";
}