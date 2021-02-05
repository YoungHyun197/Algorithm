#include <iostream>
#include <time.h>

using namespace std;

int N;
int h = 1;


int main() {
	// 00~59 까지 3이 1번이라도 들어간 수 15개
	// 3이들어간수 15개, 안들어간 수 45개
	// 15 * 45 + 15 * 60 = 1575
	// h가 3의배수이면 60 * 60 = 3600
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