#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int sum = 0;
	vector<int> vec;
	for (int i = 0; i < 5; i++) {
		int x;
		cin >> x;
		sum += x;
		vec.push_back(x);
	}
	sort(vec.begin(), vec.end());
	cout << sum / 5 << "\n" << vec[2];

}