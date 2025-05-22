#include <iostream>
#include <vector>

using namespace std;

int getMaxType(const vector<int> &belt, int n, int d, int k, int c)
{
    vector<int> chobab_type(d + 1, 0);
    int cnt = 0;

    // 처음 k개 초밥 종류 세기
    for (int i = 0; i < k; i++)
    {
        if (chobab_type[belt[i]] == 0)
        {
            cnt++;
        }
        chobab_type[belt[i]]++;
    }

    // 초기 최대값
    int max_cnt = cnt + (chobab_type[c] == 0 ? 1 : 0);

    // 나머지 초밥 종류 세기
    for (int i = 1; i < n; i++)
    {
        // 이전 초밥 제거
        chobab_type[belt[i - 1]]--;
        if (chobab_type[belt[i - 1]] == 0)
        {
            cnt--;
        }

        // 새로운 초밥 추가
        int new_chobab = belt[(i + k - 1) % n];
        if (chobab_type[new_chobab] == 0)
        {
            cnt++;
        }
        chobab_type[new_chobab]++;

        // 쿠폰 초밥 확인
        int coupon = cnt + (chobab_type[c] == 0 ? 1 : 0);
        max_cnt = max(max_cnt, coupon);
    }

    return max_cnt;
}

int main()
{
    // 입력
    int n, d, k, c;
    cin >> n >> d >> k >> c;

    vector<int> belt(n);
    for (int i = 0; i < n; i++)
    {
        cin >> belt[i];
    }

    // 연산 & 출력
    int result = getMaxType(belt, n, d, k, c);
    cout << result << "\n";

    return 0;
}