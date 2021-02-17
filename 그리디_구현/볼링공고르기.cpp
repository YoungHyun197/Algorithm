#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int K;
		cin >> K;
		v.push_back(K);
	}
	int count = 0;
	for (int i = 0; i < N-1; i++) {
		for (int j = i+1; j < N; j++) {
			if (v[i] != v[j]) count++;
		}
	}
	cout << count << '\n';
}