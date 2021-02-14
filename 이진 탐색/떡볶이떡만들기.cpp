#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v;
int result = 0;

int main() {
	cin >> N >> M;
	while (N--) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	
	int start = 0;
	int end = v[v.size()-1];
	
	while (start<=end) {
		int total = 0;
		int mid = (start + end) / 2;
		for (int i = 0; i < v.size(); i++) {
			// �߶��� ���� ���� �� ���
			if (v[i] > mid) total += v[i] - mid;
		}
		// ���� ���� ������ ��� �� ���� �ڸ��� (���� �κ� Ž��)
		if (total < M) end = mid - 1;
		// ���� ���� ����� ��� �� �ڸ��� (������ �κ� Ž��)
		else {
			result = mid; // �ִ��� �� �߶��� ���� �����̹Ƿ�, result ���
			start = mid + 1;
		}
	}
	cout << result << '\n';
}