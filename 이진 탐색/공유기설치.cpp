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

	// 집의 좌표차이 중에 가장 작은 값
	int start = v[1] - v[0];
	// 집의 좌표차이 중에 가장 큰 값
	int end = v[N - 1] - v[0];
	int result = 0;

	while (start <= end) {
		// mid 는 가장 인접한 두 공유기 사이의 거리를 의미
		int mid = (start + end) / 2;
		int value = v[0];
		int count = 1;

		// 현재 mid값을 이용해 공유기 설치
		for (int i = 1; i < N; i++) {
			// 앞에서부터 차근차근 설치
			if (v[i] >= value + mid) {
				value = v[i];
				count++;
			}
		}
		if (count >= C) {// C개 이상의 공유기를 설치할 수 있는경우 거리를 증가
			start = mid + 1;
			result = mid; // 최종 결과를 저장
		}
		else end = mid - 1; // C개 이상의 공유기를 설치할 수 없는 경우, 거리를 감소
	}
	cout << result << '\n';

}
