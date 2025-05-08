#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 과자를 m개로 나눌 수 있는지
bool canDivide(const vector<int> &cookie, int n, int m, int length)
{
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        cnt += cookie[i] / length;
    }

    return cnt >= m;
}

// 이분탐색
// 최대 길이 찾고 result에 저장
void binarySearch(const vector<int> &cookie, int n, int m, int left, int right, int &result)
{
    if (left > right)
    {
        return;
    }

    int mid = (left + right) / 2;

    // 재귀로 이분탐색
    if (canDivide(cookie, n, m, mid))
    {
        // 최대 길이 저장
        result = mid;
        // 더 긴 길이
        binarySearch(cookie, n, m, mid + 1, right, result);
    }
    else
    {
        // 더 짧은 길이
        binarySearch(cookie, n, m, left, mid - 1, result);
    }
}

int main()
{
    // 시간초과
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 입력
    int m, n;
    cin >> m >> n;

    vector<int> cookie(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cookie[i];
    }

    sort(cookie.begin(), cookie.end());

    // 연산
    int result = 0;
    binarySearch(cookie, n, m, 1, cookie[n - 1], result);

    // 출력
    cout << result;

    return 0;
}