#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> v;
vector<int> check;

int bs(vector<int>& v, int start, int end, int target) {
	while (start <= end) {
		int mid = (start + end) / 2;
		if (v[mid] == target) return mid;
		else if (v[mid] < target) start = mid + 1;
		else end = mid - 1;
	}
	return -1;
}

int main() {
	cin >> N;
	for (int i = 0; i < N;i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int x;
		cin >> x;
		check.push_back(x);
	}
	for (int i = 0; i < M; i++) {
		int value = bs(v, 0, N-1, check[i]);
		if (value == -1) cout << "no ";
		else cout << "yes ";
	}
	
}