#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define X first
#define Y second
using namespace std;


int board[9][9];
int editboard[9][9];
bool vis[9][9];
int N, M;
vector<pair<int, int>> v;
vector<pair<int, int>> none;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1, 0, -1 };

int countZone() {
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (editboard[i][j] == 0) count++;
		}
	}
	return count;
}
// 보드 복사함수
void copyBoard(int board[9][9], int editboard[9][9]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			editboard[i][j] = board[i][j];
			vis[i][j] = false;
		}
	}
}
void BFS() {
	queue<pair<int, int>> Q;
	for (int i = 0; i < v.size(); i++) {
		Q.push({ v[i].X, v[i].Y });
		vis[v[i].X][v[i].Y] = 1;
	}
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (vis[nx][ny] || editboard[nx][ny] == 1) continue;
			editboard[nx][ny] = 2; vis[nx][ny] = true;
			Q.push({ nx, ny });
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) v.push_back({ i, j });
			else if (board[i][j]==0) {
				none.push_back({ i,j });
			}
		}
	}
	int wall = 0;
	
	copyBoard(board, editboard);
	int mx = 0;
	int size = none.size();
	for (int i = 0; i < size; i++) {
		
		for (int j = i + 1; j < size; j++) {
			
			for (int k = j + 1; k < size; k++) {
				editboard[none[i].X][none[i].Y] = 1;
				editboard[none[j].X][none[j].Y] = 1;
				editboard[none[k].X][none[k].Y] = 1;
				BFS();
				mx = max(mx, countZone());
				copyBoard(board, editboard);
			}
		}
	}

	cout << mx;
	
}