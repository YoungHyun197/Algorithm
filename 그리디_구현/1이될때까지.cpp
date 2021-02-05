#include <iostream>
using namespace std;
// <문제> 1이 될 때까지
int main() {
	int N, K;
	cin >> N >> K;
	int count = 0;
	while (N != 1) {
		if (N % K == 0) {
			N = N / K;
			count++;
		}
		else {
			N--;
			count++;
		}
	}
	cout << count << endl;
}