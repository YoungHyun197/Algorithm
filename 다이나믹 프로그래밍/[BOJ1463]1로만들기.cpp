#include <iostream>
#include <vector>
using namespace std;

int X;
int d[1000002];

int main() {
	cin >> X;
	
	d[1] = 0;
	
	for (int i = 2; i <= X; i++) {
		d[i] = d[i - 1] + 1;
		if (i % 3 == 0) d[i] = min(d[i], d[i / 3] + 1);
		if (i % 2 == 0) d[i] = min(d[i], d[i / 2] + 1);
	
	}

	cout << d[X];
}