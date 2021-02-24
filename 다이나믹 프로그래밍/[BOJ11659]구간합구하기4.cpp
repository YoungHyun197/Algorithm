#include<iostream>
#include<vector>
using namespace std;

int N, M;

int table[100001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		sum += x;
		table[i+1] = sum;
	}
	
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << table[b] - table[a - 1] << '\n';

	}
}