#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	int ans=10001;
	for (int i = 0; i < N; i++) {
		vector<int> v1;
		for (int j = 0; j < M; j++) {
			int x; cin >> x;
			v1.push_back(x);
		}
		sort(v1.begin(), v1.end());
		if (i == 0) {
			ans = v1[0];
		}
		else {
			if (ans < v1[0]) ans = v1[0];
		}
	}
	cout << ans << "\n";

}