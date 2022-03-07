#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int N, K;
	
	cin >> N >> K;
	int ans = 0;
	while (N != 1) {
		ans++;
		if (N % K == 0) {
			N /= K;
		}
		else {
			N--;
		}
	}
	cout << ans << "\n";
}