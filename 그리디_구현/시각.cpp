#include <iostream>
#include <time.h>

using namespace std;

int N;
int h = 1;


int main() {
	// 00~59 ���� 3�� 1���̶� �� �� 15��
	// 3�̵��� 15��, �ȵ� �� 45��
	// 15 * 45 + 15 * 60 = 1575
	// h�� 3�ǹ���̸� 60 * 60 = 3600
	cin >> N;
	int count = 0;
	for (int i = 0; i < N; i++) {
		if (i == 0) count += 1575;
		if ((h % 3) == 0) {
			count += 3600;
		}
		else {
			count += 1575;
		}
		h++;
	}

	cout << count << '\n';
}