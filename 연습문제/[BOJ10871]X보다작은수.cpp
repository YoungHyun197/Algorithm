#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, X;
	
	cin >> N >> X;
	vector<int> A;

	int cnt = 0;
	while (N--) {
		int tmp;
		cin >> tmp;
		if (tmp < X) {
			A.push_back(tmp);
			cnt++;
		}
	}
	for (int i = 0; i < cnt; i++) {
		cout << A[i] << " ";
	}
	
}