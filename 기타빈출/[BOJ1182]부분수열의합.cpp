#include <iostream>
using namespace std;

bool isused[21];
int arr[21];
int N, S;
int cnt = 0;

void func(int cur, int sum) {
	if (cur == N) {
		if(sum == S) cnt++;
		return;
	}
	func(cur + 1, sum);
	func(cur + 1, sum + arr[cur]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	func(0, 0);
	if (S == 0) cnt--;
	cout << cnt;

}