#include <iostream>
#include <vector>
using namespace std;

string S;
vector<int> v;
int a=0, b=0;

int main() {
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		int x = S[i] - '0';
		v.push_back(x);
	}
	for (int i = 1; i < S.size(); i++) {
		if (v[i] == 0 && v[i] != v[i - 1]) a++;
		if (v[i] == 1 && v[i] != v[i - 1]) b++;
		if (i == S.size()-1) {
			if (v[i] == 0) b++;
			if (v[i] == 1) a++;
		}
	}
	
	if (a == 0 && b == 0) cout << 0 << '\n';
	else if (a < b) cout << a << '\n';
	else if (b <= a) cout << b << '\n';
}
