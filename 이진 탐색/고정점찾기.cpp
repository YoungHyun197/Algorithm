#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v;


int bs(vector<int>& v, int t, int s, int e) {
	while (s <= e) {
		int m = (s + e) / 2;
		if (v[m] == t) return m;
		else if (v[m] < t) s = m + 1;
		else e = m - 1;
	}
	return -1;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	
	int count = 0;
	for (int i = 0; i < N; i++) {
		
		int value = bs(v, i, 0, N - 1);
		if (value == i) {
			count++;
			cout << i << '\n';
			break;
		}
		
	}
	if ( count == 0) cout << -1 << '\n';
}