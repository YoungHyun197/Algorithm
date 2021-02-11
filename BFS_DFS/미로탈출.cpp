#include<iostream>
#include <queue>
using namespace std;

int N, M;

// �̵��� �� ���� ���� ���� (��, ��, ��, ��)
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int graph[201][201];


int bfs(int x, int y) {
	// ť(Queue) ������ ���� queue ���̺귯�� ���
	queue<pair<int, int>> q;
	q.push({ x, y });
	// ť�� �� ������ �ݺ��ϱ�
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		// ���� ��ġ���� 4���� �������� ��ġ Ȯ��
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			// �̷� ã�� ������ ��� ��� ����
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			// ���� ��� ����
			if (graph[nx][ny] == 0) continue;
			// �ش� ��带 ó�� �湮�ϴ� ��쿡�� �ִ� �Ÿ� ���
			if (graph[nx][ny] == 1) {
				graph[nx][ny] = graph[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}
	// ���� ������ �Ʒ������� �ִ� �Ÿ� ��ȯ
	return graph[N - 1][M - 1];
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf_s("%1d", &graph[i][j]);
		}
	}

	cout << bfs(0, 0) << '\n';
	
}