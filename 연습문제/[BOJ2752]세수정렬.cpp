#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> vec;
	int a = 3;
	while (a--) {
		int n;
		cin >> n;
		vec.push_back(n);
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < 3; i++) {
		cout << vec[i] << " ";
	}
	
	
}