#include <iostream>
#include <vector>
using namespace std;

int X;
int d[30001];
int main() {
	cin >> X;
	d[1] = 1;
	d[2] = 1;
	d[3] = 1;
	d[4] = 2;
	d[5] = 1;
	for (int i = 6; i <= X; i++) {
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0) d[i] = min(d[i], d[i / 2] + 1);
		if (i % 3 == 0) d[i] = min(d[i], d[i / 3] + 1);
		if (i % 5 == 0) d[i] = min(d[i], d[i / 5] + 1);
	}

	cout << d[X];
}