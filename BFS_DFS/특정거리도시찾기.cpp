#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, K, X;
vector<int> graph[300001];
vector<int> d(300001, -1);



int main() {
	

	cin >> N >> M >> K >> X;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}


	// 출발 도시까지의 거리는 0으로 설정
	d[X] = 0;
	queue<int> q;
	q.push(X);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		// 현재 도시에서 이동할 수 있는 모든 도시를 확인
		for (int i = 0; i < graph[now].size(); i++) {
			int nextNode = graph[now][i];
			// 아직 방문하지 않은 도시라면
			if (d[nextNode] == -1) {
				//최단 거리 갱신
				d[nextNode] = d[now] + 1;
				q.push(nextNode);
			}
		}
	}


	// 최단 거리가 K인 모든 도시의 번호를 오름차순으로 출력
	bool check = false;
	for (int i = 1; i <= N; i ++ ) {
		if (d[i] == K) {
			cout << i << '\n';
			check = true;
		}
	}

	// 만약 최단 거리가 K인 도시가 없다면, -1 출력
	if (!check) cout << -1 << '\n';
}

