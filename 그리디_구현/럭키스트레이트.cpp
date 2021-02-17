#include <iostream>
#include <vector>

using namespace std;

string S;
vector<int> v;
int main() {
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		v.push_back(S[i] - '0');
	}
	int a = v.size() / 2;
	int left = 0;
	int right = 0;
	for (int i = 0; i < a; i++) {
		left += v[i];
	}
	for (int i = a; i < v.size(); i++) {
		right += v[i];
	}
	if (left == right) cout << "LUCKY" << '\n';
	else cout << "READY" << '\n';
}