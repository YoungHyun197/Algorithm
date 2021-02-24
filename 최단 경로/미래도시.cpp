#include <iostream>
#include <vector>
#define INF 1e9

using namespace std;

int N, M;
int graph[101][101];

int main() {
	cin >> N >> M;

	//최단 거리 테이블을 모두 무한으로 초기화
	for (int i = 0; i < 101; i++) {
		fill(graph[i], graph[i] + 101, INF);
	}

	// 자기 자신에서 자기 자신으로 가는 비용은 0으로 초기화
	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= N; b++) {
			if (a == b) graph[a][b] = 0;
		}
	}


	// 각 간선에 대한 정보를 입력 받아 그 값으로 초기화
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	// 거쳐갈 노드 X와 최종 목적지 노드 K를 입력받기
	int x, k;
	cin >> x >> k;


	// 점화식에 따라 플로이드 워셜 알고리즘을 수행
	for (int k = 1; k <= N; k++) {
		for (int a = 1; a <= N; a++) {
			for (int b = 1; b <= N; b++) {
				graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
			}
		}
	}

	int dist = graph[1][k] + graph[k][x];

	// 도달할 수 없는 경우 -1을 출력
	if (dist >= INF) cout << -1;
	else cout << dist;
}