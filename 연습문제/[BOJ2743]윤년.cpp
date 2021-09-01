#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	if (N % 400 == 0) cout << 1;
	else if (N % 100 != 0 && N % 4 == 0) cout << 1;
	else cout << 0;

}