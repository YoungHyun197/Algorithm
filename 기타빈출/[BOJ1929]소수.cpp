#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

bool arr[1000001];

int main() {
	int M, N;
	cin >> M >> N;

	
	for (int i = 0; i < 1000001; i++) {
		arr[i] = true;
	}
	arr[1] = 0;
	for (int i= 2; i <= (int)sqrt(N); i++) {
		if (arr[i] == true) {
			int j = 2;
			while (i * j <= N) {
				arr[i * j] = false;
				j++;
			}
		}
	}

	for (int j = M; j <= N; j++) {
		if (arr[j]) cout << j << '\n';
	}
}