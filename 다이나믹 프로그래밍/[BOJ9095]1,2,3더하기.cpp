#include <iostream>
using namespace std;

int T, N;


int main() {
	cin >> T;
	while (T--) {
		cin >> N;
		int d[11];
		d[1] = 1;
		d[2] = 2;
		d[3] = 4;
		for (int i = 4; i <= N; i++) {
			d[i] = d[i - 1] + d[i - 2] + d[i - 3];
		}
		
		
		
		cout << d[N] << '\n';
	}
}