#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

// ����� ����(N), ������ ����(M), ���۳���ȣ(Start)
int N, M, Start;
// �� ��忡 ����Ǿ� �ִ� ��忡 ���� ������ ��� �迭
vector<pair<int, int>> graph[30001];
// �ִ� �Ÿ� ���̺� �����
int d[30001];

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	// ���� ���� ���� ���� �ִ� ��δ� 0���� �����Ͽ�, ť�� ����
	pq.push({ 0, start });
	d[start] = 0;
	while (!pq.empty()) { // ť�� ������� �ʴٸ�
		// ���� �ִ� �Ÿ��� ª�� ��忡 ���� ���� ������
		int dist = -pq.top().first; // ���� �������� ���
		int now = pq.top().second; // ������
		pq.pop();
		// ���� ��尡 �̹� ó���� ���� �ִ� ����� ����
		if (d[now] < dist) continue;
		// ���� ���� ����� �ٸ� ������ ������ Ȯ��
		for (int i = 0; i < graph[now].size(); i++) {
			int cost = dist + graph[now][i].second;
			if (cost < d[graph[now][i].first]) {
				d[graph[now][i].first] = cost;
				pq.push(make_pair(-cost, graph[now][i].first));
			}
		}
	}

}

int main() {
	cin >> N >> M >> Start;

	// ��� ���� ������ �Է¹ޱ�
	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		// x�� ��忡�� y�� ���� ���� ����� z��� �ǹ�
		graph[x].push_back({ y, z });
	}
	
	// �ִ� �Ÿ� ���̺��� ��� �������� �ʱ�ȭ
	fill(d, d + 30001, INF);

	// ���ͽ�Ʈ�� �˰����� ����
	dijkstra(Start);

	// ������ �� �ִ� ����� ����
	int count = 0;
	// ������ �� �ִ� ��� �߿���, ���� �ָ� �ִ� ������ �ִ� �Ÿ�
	int maxDistance = 0;
	for (int i = 1; i <= N; i++) {
		// ������ �� �ִ� ����� ���
		if (d[i] != INF) {
			count += 1;
			maxDistance = max(maxDistance, d[i]);
		}
	}

	// ���� ���� �����ؾ� �ϹǷ� count-1�� ���
	cout << count - 1 << ' ' << maxDistance << '\n';
}