#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<pair<int, int>> vec;
	for (int i = 0; i < 9; i++) {
		int x;
		cin >> x;
		vec.push_back({ x,i + 1 });
	}
	sort(vec.begin(), vec.end());
	cout << vec[8].first << "\n" << vec[8].second;
}