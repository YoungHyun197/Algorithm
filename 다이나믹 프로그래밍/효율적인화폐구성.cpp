#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v;
int d[10001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	for (int i = 1; i < 10001; i++) {
		d[i] = 10001;
	}
	for (int i = 0; i < N; i++) {
		for (int j = v[i]; j <= M; j++) {
			if (d[j - v[i]] != 10001) {
				d[j] = min(d[j], d[j - v[i]] + 1);
			}
		}
	}
	if (d[M] == 10001) cout << -1;
	else cout << d[M];
}