#include <iostream>
using namespace std;

int N, M;
int arr[10];
bool isUsed[10];

void func(int k) { // ���� K�� ���� ���� ������
	if(k==M){ // M������ ��� ��������
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' '; //arr�� ����ص� �� ���
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) { // 1���� N������ ���� ����
		if (!isUsed[i]) { // ���� i�� ��� ���� �ʾҴٸ�
			arr[k] = i; // k��° ���� i�� ����
			isUsed[i] = true; // i�� ���Ǿ��ٰ� ǥ��
			func(k + 1); // �������� ���Ϸ� �� �ܰ� �� ��
			isUsed[i] = 0; // k��° ���� i�� ���� ��� ��쿡 ���� �� Ȯ�������� i�� ���� ������ �ʾҴٰ� �����.
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	func(0);

}