#include <iostream>
#include <queue>
#define X first;
#define Y second;
using namespace std;

int dist[100002];
int N, K;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	fill(dist, dist + 100001, -1);
	cin >> N >> K;
	dist[N] = 0;
	queue<int> Q;
	Q.push(N);

	while (dist[K] == -1) {
		auto cur = Q.front(); Q.pop();
		for (int nxt : {cur-1, cur+1, 2*cur}) {
			if (nxt < 0 || nxt > 100000) continue;
			if (dist[nxt] != -1) continue;
			dist[nxt] = dist[cur] + 1;
			Q.push(nxt);
		}
	}
	cout << dist[K];
}