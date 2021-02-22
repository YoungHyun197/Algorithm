#include <iostream>
#include <vector>

using namespace std;
int T,N, M;


int main() {
	cin >> T;
	cin >> N >> M;
	int array[21][21];
	int dp[21][21];
	while (T--) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int x; cin >> x;
				array[i][j] = x;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				dp[i][j] = array[i][j]; 
			}
		}

		for (int j = 1; j < M; j++) {
			for (int i = 0; i < N; i++) {
				int leftUp, leftDown, left;
				// ���� ������ ���� ���
				if (i == 0) leftUp = 0;
				else leftUp = dp[i - 1][j - 1];
				// ���� �Ʒ����� ���� ���
				if (i == N-1) leftDown = 0;
				else leftDown = dp[i + 1][j - 1];
				// ���ʿ��� ���� ���
				left = dp[i][j - 1];
				dp[i][j] = dp[i][j] + max(leftUp, max(leftDown, left));

			}
		}
		int result = 0;
		for (int i = 0; i < N; i++) {
			result = max(result, dp[i][M - 1]);
		}
		cout << result << '\n';
	}
}
