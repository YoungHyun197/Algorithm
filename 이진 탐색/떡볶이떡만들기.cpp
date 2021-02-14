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
			// 잘랐을 때의 떡의 양 계산
			if (v[i] > mid) total += v[i] - mid;
		}
		// 떡의 양이 부족한 경우 더 많이 자르기 (왼쪽 부분 탐색)
		if (total < M) end = mid - 1;
		// 떡의 양이 충분한 경우 덜 자르기 (오른쪽 부분 탐색)
		else {
			result = mid; // 최대한 덜 잘랐을 때가 정답이므로, result 기록
			start = mid + 1;
		}
	}
	cout << result << '\n';
}