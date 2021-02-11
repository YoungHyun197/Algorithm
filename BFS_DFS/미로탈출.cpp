#include<iostream>
#include <queue>
using namespace std;

int N, M;

// 이동할 네 가지 방향 정의 (상, 하, 좌, 우)
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int graph[201][201];


int bfs(int x, int y) {
	// 큐(Queue) 구현을 위해 queue 라이브러리 사용
	queue<pair<int, int>> q;
	q.push({ x, y });
	// 큐가 빌 때까지 반복하기
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		// 현재 위치에서 4다지 방향으로 위치 확인
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			// 미로 찾기 공간을 벗어난 경우 무시
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			// 벽인 경우 무시
			if (graph[nx][ny] == 0) continue;
			// 해당 노드를 처음 방문하는 경우에만 최단 거리 기록
			if (graph[nx][ny] == 1) {
				graph[nx][ny] = graph[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}
	// 가장 오른족 아래까지의 최단 거리 반환
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