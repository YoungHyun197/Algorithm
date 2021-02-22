#include <iostream>
using namespace std;
int N;
int arr[101];
int d[101];
int main() {
	// 정수 N 입력받기
	cin >> N;
	// 모든 식량 정보 입력 받기
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	// 다이나믹 프로그래밍 진행 (바텀업)
	d[0] = arr[0];
	d[1] = max(arr[0], arr[1]);

	for (int i = 2; i < N; i++) {
		d[i] = max(d[i - 1], d[i - 2] + arr[i]);
	}
	// 결과출력
	cout << d[N - 1];
}