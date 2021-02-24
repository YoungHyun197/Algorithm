#include <iostream>
#include <vector>
#define INF 1e9

using namespace std;

int N, M;
int graph[101][101];

int main() {
	cin >> N >> M;

	//�ִ� �Ÿ� ���̺��� ��� �������� �ʱ�ȭ
	for (int i = 0; i < 101; i++) {
		fill(graph[i], graph[i] + 101, INF);
	}

	// �ڱ� �ڽſ��� �ڱ� �ڽ����� ���� ����� 0���� �ʱ�ȭ
	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= N; b++) {
			if (a == b) graph[a][b] = 0;
		}
	}


	// �� ������ ���� ������ �Է� �޾� �� ������ �ʱ�ȭ
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	// ���İ� ��� X�� ���� ������ ��� K�� �Է¹ޱ�
	int x, k;
	cin >> x >> k;


	// ��ȭ�Ŀ� ���� �÷��̵� ���� �˰����� ����
	for (int k = 1; k <= N; k++) {
		for (int a = 1; a <= N; a++) {
			for (int b = 1; b <= N; b++) {
				graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
			}
		}
	}

	int dist = graph[1][k] + graph[k][x];

	// ������ �� ���� ��� -1�� ���
	if (dist >= INF) cout << -1;
	else cout << dist;
}