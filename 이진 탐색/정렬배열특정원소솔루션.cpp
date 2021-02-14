#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// ���� [left_value, right_value]�� �������� ������ ��ȯ�ϴ� �Լ�
int countByRange(vector<int>& v, int leftValue, int rightValue) {
    vector<int>::iterator rightIndex = upper_bound(v.begin(), v.end(), rightValue);
    vector<int>::iterator leftIndex = lower_bound(v.begin(), v.end(), leftValue);
    return rightIndex - leftIndex;
}

int n, x;
vector<int> v;

int main() {
    // �������� ���� N, ã���� �ϴ� �� x �Է¹ޱ�
    cin >> n >> x;

    // ��ü ������ �Է� �ޱ�
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    // ���� [x, x] ������ �ִ� �������� ���� ���
    int cnt = countByRange(v, x, x);

    // ���� x�� ���Ұ� �������� �ʴ´ٸ�
    if (cnt == 0) {
        cout << -1 << '\n';
    }
    //  ���� x�� ���Ұ� �����Ѵٸ�
    else {
        cout << cnt << '\n';
    }
}