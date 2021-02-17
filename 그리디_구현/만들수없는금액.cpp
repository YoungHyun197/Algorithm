#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int  N;
vector<int> v;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	int target = 1;
	for (int i = 0; i < N; i++) {
		if (target < v[i]) break;
		target += v[i];
	}

	cout << target << '\n';
}