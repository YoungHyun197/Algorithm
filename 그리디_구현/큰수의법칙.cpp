#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, K;
int main() {
	cin >> N >> M >> K;
	vector<int> v;
	for (int i= 0; i < N; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	int tmp1 = v[N-1];
	int tmp2 = v[N - 2];
	int cnt = 0;
	int ans = 0;
	for (int i = 0; i < M; i++) {
		if (cnt == K) {
			cnt = 0;
			ans += tmp2;
		}
		else {
			cnt++;
			ans += tmp1;
		}
	}
	cout << ans << "\n";
}