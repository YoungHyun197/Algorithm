#include <iostream>
using namespace std;
// <����> 1�� �� ������
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