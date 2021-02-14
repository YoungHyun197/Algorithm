#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C;
vector<int> v;

int main() {
	cin >> N >> C;
	for (int i = 0;i < N; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	// ���� ��ǥ���� �߿� ���� ���� ��
	int start = v[1] - v[0];
	// ���� ��ǥ���� �߿� ���� ū ��
	int end = v[N - 1] - v[0];
	int result = 0;

	while (start <= end) {
		// mid �� ���� ������ �� ������ ������ �Ÿ��� �ǹ�
		int mid = (start + end) / 2;
		int value = v[0];
		int count = 1;

		// ���� mid���� �̿��� ������ ��ġ
		for (int i = 1; i < N; i++) {
			// �տ������� �������� ��ġ
			if (v[i] >= value + mid) {
				value = v[i];
				count++;
			}
		}
		if (count >= C) {// C�� �̻��� �����⸦ ��ġ�� �� �ִ°�� �Ÿ��� ����
			start = mid + 1;
			result = mid; // ���� ����� ����
		}
		else end = mid - 1; // C�� �̻��� �����⸦ ��ġ�� �� ���� ���, �Ÿ��� ����
	}
	cout << result << '\n';

}
