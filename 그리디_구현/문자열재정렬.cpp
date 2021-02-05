#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string S;
vector<char> str;
int sum = 0;

int main() {
	// A의 아스키넘버 65
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] >= 65) {
			str.push_back(S[i]);
		}
		else {
			sum += (int)S[i] - '0';
		}
	}
	sort(str.begin(), str.end());
	for (int i = 0; i < str.size(); i++) {
		cout << str[i];
	}
	if (sum != 0) cout << sum << '\n';

}