#include <iostream>
using namespace std;

int N, M;
int arr[10];
bool isUsed[10];

void func(int k) { // 현재 K개 까지 수를 택했음
	if(k==M){ // M개까지 모두 택했으면
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' '; //arr에 기록해둔 수 출력
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) { // 1부터 N까지의 수에 대해
		if (!isUsed[i]) { // 아직 i가 사용 되지 않았다면
			arr[k] = i; // k번째 수를 i로 정함
			isUsed[i] = true; // i를 사용되었다고 표시
			func(k + 1); // 다음수를 정하러 한 단계 더 들어감
			isUsed[i] = 0; // k번째 수를 i로 정한 모든 경우에 대해 다 확인했으니 i를 이제 사용되지 않았다고 명시함.
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	func(0);

}