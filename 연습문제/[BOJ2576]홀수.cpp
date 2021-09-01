#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> vec;
	int vecSum=0;
	for (int i = 0; i < 7; i++) {
		int x;
		cin >> x;
		if (x % 2 == 1) {
			vec.push_back(x);
			vecSum += x;
		}
	}
	sort(vec.begin(), vec.end());
	if (vec.empty()) cout << -1;
	else {
		cout << vecSum << "\n" << vec[0];
	}
}