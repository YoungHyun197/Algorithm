#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x, y, z;
	cin >> x >> y >> z;
	vector<int> vec;
	vec.push_back(x);
	vec.push_back(y);
	vec.push_back(z);
	sort(vec.begin(), vec.end());
	if (x == y && y== z) {
		cout << 10000 + (x * 1000);
	}
	else if (x == y && x != z) {
		cout << 1000 + (x * 100);
	}
	else if (x == z && x != y) {
		cout << 1000 + (x * 100);
	}
	else if (y == z && x != y) {
		cout << 1000 + (y * 100);
	}
	else {
		cout << vec[2] * 100;
	}
}