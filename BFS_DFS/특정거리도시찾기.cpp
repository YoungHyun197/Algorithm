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


	// ��� ���ñ����� �Ÿ��� 0���� ����
	d[X] = 0;
	queue<int> q;
	q.push(X);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		// ���� ���ÿ��� �̵��� �� �ִ� ��� ���ø� Ȯ��
		for (int i = 0; i < graph[now].size(); i++) {
			int nextNode = graph[now][i];
			// ���� �湮���� ���� ���ö��
			if (d[nextNode] == -1) {
				//�ִ� �Ÿ� ����
				d[nextNode] = d[now] + 1;
				q.push(nextNode);
			}
		}
	}


	// �ִ� �Ÿ��� K�� ��� ������ ��ȣ�� ������������ ���
	bool check = false;
	for (int i = 1; i <= N; i ++ ) {
		if (d[i] == K) {
			cout << i << '\n';
			check = true;
		}
	}

	// ���� �ִ� �Ÿ��� K�� ���ð� ���ٸ�, -1 ���
	if (!check) cout << -1 << '\n';
}

