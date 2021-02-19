#include <iostream>
#include <queue>
#include <algorithm>
#define X first
#define Y second
using namespace std;

int M, N;
char board[1001][1001];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int dist1[1001][1001];
int dist2[1001][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	queue<pair<int, int>> Q1;
	queue<pair<int, int>> Q2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			dist1[i][j] = -1;
			dist2[i][j] = -1;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'F') {
				Q1.push({ i,j });
				dist1[i][j] = 0;
			}
			if (board[i][j] == 'J') {
				Q2.push({ i,j });
				dist2[i][j] = 0;
			}
	
		}
	}
	while (!Q1.empty()) {
		auto cur = Q1.front(); Q1.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
			Q1.push({ nx, ny });
		}
	}
	while (!Q2.empty()) {
		auto cur = Q2.front(); Q2.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
				cout << dist2[cur.X][cur.Y] + 1;
				return 0;
			}
			if (dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1) continue;
			dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
			Q2.push({ nx, ny });
		}
	}
	cout << "IMPOSSIBLE";

}