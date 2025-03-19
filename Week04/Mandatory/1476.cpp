#include <iostream>

using namespace std;

int getYear(int e, int s, int m)
{
    int year = 1;

    // 연산 중인 연도에서의 esm
    // 원래 esm 값이랑 비교해야해서 변수 새로 팜
    int tmp_e = 1, tmp_s = 1, tmp_m = 1;

    while (1)
    {
        // 원래 esm과 현재 esm이 같으면 바로 year return
        if (tmp_e == e && tmp_s == s && tmp_m == m)
        {
            return year;
        }

        // 1년씩 올리면서 esm 업데이트 (브루트포스)
        // 근데 걍 28의 최소공배수 구하는 게 더 간단할듯
        if (tmp_e == 15)
        {
            tmp_e = 1;
        }
        else
        {
            tmp_e++;
        }
        if (tmp_s == 28)
        {
            tmp_s = 1;
        }
        else
        {
            tmp_s++;
        }
        if (tmp_m == 19)
        {
            tmp_m = 1;
        }
        else
        {
            tmp_m++;
        }
        year++;
    }

    return year;
}

int main()
{
    // 입력
    int e, s, m;
    cin >> e >> s >> m;

    // 연산 & 출력
    cout << getYear(e, s, m);

    return 0;
}