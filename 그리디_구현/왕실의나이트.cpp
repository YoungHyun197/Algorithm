#include <iostream>
using namespace std;

// ����� ���� ������ ���Ͽ�
// ���»� ������ ���� ����� 
int dx[8] = {-2, -2, 2, 2, -1, 1, -1, 1};
int dy[8] = {-1, 1, -1, 1, -2, -2, 2, 2};

string S;

int main() {
	int count = 0;

	// a�� �ƽ�Ű�ڵ�� 97
	cin >> S;
	int x = (int)S[0] - 96;
	int y = (int)S[1]-'0';
	cout << x << y;

	for (int i = 0; i < 8; i++) {
		int nx = x;
		int ny = y;
		nx = nx + dx[i];
		ny = ny + dy[i];
		if (nx < 1 || nx > 8 || ny < 1 || ny > 8) continue;
		else { count++; }
	}
	
	cout << count << '\n';
}