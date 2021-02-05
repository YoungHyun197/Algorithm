#include <iostream>
#include <string>
#include <time.h>
using namespace std;

clock_t start, finish;
double duration;

int N;
string str;

int x = 1, y = 1;

int main() {
	start = clock();
	cin >> N;
	cin.ignore();
	getline(cin, str);
	
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'L') {
			if (y -1 >= 1) y -= 1;
		}
		else if (str[i] == 'R') {
			if (y + 1 <= str.size()) y += 1;
		}
		else if (str[i] == 'U') {
			if (x -1 >= 1) x -= 1;
		}
		else if (str[i] == 'D') {
			if (x + 1 <= str.size()) x += 1;
		}
	}
	cout << x << ' ' << y << '\n';
	
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << duration << '\n'; // 0.389초
}
//
//#include <iostream>
//#include <string>
//#include <time.h>
//using namespace std;
//
//clock_t start, finish;
//double duration;
//
//int n;
//string plans;
//int x = 1, y = 1;
//
//// l, r, u, d에 따른 이동 방향
//int dx[4] = { 0, 0, -1, 1 };
//int dy[4] = { -1, 1, 0, 0 };
//char movetypes[4] = { 'l', 'r', 'u', 'd' };
//int main() {
//	start = clock();
//	
//	cin >> n;
//	cin.ignore(); // 버퍼 비우기
//	getline(cin, plans);
//
//	// 이동 계획을 하나씩 확인하기
//	for (int i = 0; i < plans.size(); i++) {
//		char plan = plans[i];
//		// 이동 후 좌표 구하기
//		int nx = -1, ny = -1;
//		for (int j = 0; j < 4; j++) {
//			if (plan == movetypes[j]) {
//				nx = x + dx[j];
//				ny = y + dx[j];
//			}
//		}
//		// 공간을 벗어나는 경우 무시
//		if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
//		x = nx;
//		y = ny;
//	}
//
//	cout << x <<' ' << y << '\n';
//
//	finish = clock();
//	duration = (double)(finish - start) / clocks_per_sec;
//	cout << duration << '\n'; // 0.415초
//}