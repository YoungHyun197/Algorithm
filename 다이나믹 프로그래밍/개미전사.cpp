#include <iostream>
using namespace std;
int N;
int arr[101];
int d[101];
int main() {
	// ���� N �Է¹ޱ�
	cin >> N;
	// ��� �ķ� ���� �Է� �ޱ�
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	// ���̳��� ���α׷��� ���� (���Ҿ�)
	d[0] = arr[0];
	d[1] = max(arr[0], arr[1]);

	for (int i = 2; i < N; i++) {
		d[i] = max(d[i - 1], d[i - 2] + arr[i]);
	}
	// ������
	cout << d[N - 1];
}