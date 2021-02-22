#include <iostream>
#include <vector>

using namespace std;
int N;

vector<int> v;
int dp[2001];
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		v.push_back(x);
	}
	reverse(v.begin(),v.end());
	for (int i = 0; i < N; i++) {
		dp[i] = 1;
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (v[j] < v[i]) dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	// 열외해야 하는 병사의 최소 수를 출력
	int maxValue = 0;
	for (int i = 0; i < N; i++) {
		maxValue = max(maxValue, dp[i]);
	}
	cout << N - maxValue << '\n';
}