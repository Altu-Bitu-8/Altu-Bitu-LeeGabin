#include <iostream>
#include <vector>

using namespace std;

int getLongestLength(int n, int k, vector<int> &a)
{
    // 1~1000000
    vector<int> count(100001, 0);
    int start = 0;
    int end = 0;
    int len = 0;

    while (end < n)
    {
        count[a[end]]++;

        // k개 초과한 경우 start 움직여서 k 이하로 조정
        while (count[a[end]] > k)
        {
            count[a[start]]--;
            start++;
        }
        len = max(len, end - start + 1);
        end++;
    }

    return len;
}

int main()
{
    // 입력
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // 연산 & 출력
    int result = getLongestLength(n, k, a);
    cout << result << "\n";

    return 0;
}