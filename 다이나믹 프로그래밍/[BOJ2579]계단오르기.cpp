#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> v;
int d[301][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		v.push_back(x);
	}
	d[1][0] = v[0]; d[1][1] = v[0];
	d[2][0] = v[1]; d[2][1] = v[1]+v[0];
	for (int i = 3; i <= N; i++) {
		for (int j = 0; j < 2; j++) {
			if (j == 0) {
				d[i][j] =  max(d[i - 2][1], d[i - 2][0]) + v[i - 1];
			}
			else {
				d[i][j] = d[i-1][0] + v[i - 1];
			}
		}
	}
	cout << max(d[N][0], d[N][1]);
}