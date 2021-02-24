#include <iostream>
#include <vector>
using namespace std;

int arr[1002][4];
int N;
int dp[1002][4];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> arr[i][j];
		}
	}
	// R = 1, G = 2, B = 3
	dp[1][1] = arr[1][1]; dp[1][2] = arr[1][2]; dp[1][3] = arr[1][3];
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= 3; j++) {
			if (j == 1) {
				dp[i][j] = min(dp[i-1][2], dp[i-1][3]) + arr[i][j];
			}
			else if (j == 2) {
				dp[i][j] = min(dp[i - 1][1], dp[i - 1][3]) + arr[i][j];
			}
			else {
				dp[i][j] = min(dp[i - 1][2], dp[i - 1][1]) + arr[i][j];
			}
		}
	}
	cout << min(dp[N][1], min(dp[N][2], dp[N][3]));
}