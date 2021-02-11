#include <iostream>

using namespace std;

int N, M;
int graph[1001][1001];

bool dfs(int x, int y) {
	if (x <= -1 || x >= N || y <= -1 || y >= M) {
		return false;
	}
	if (graph[x][y] == 0) {
		graph[x][y] = 1;
		dfs(x - 1, y);
		dfs(x + 1, y);
		dfs(x, y - 1);
		dfs(x, y + 1);
		return true;
	}
	return false;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf_s("%1d", &graph[i][j]);
		}
	}

	int result = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (dfs(i, j)) {
				result++;
			}
		}
		
	}
	cout << result << '\n';
}