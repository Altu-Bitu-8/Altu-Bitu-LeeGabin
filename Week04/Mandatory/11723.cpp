#include <iostream>

using namespace std;

int bitmask(string operate, int &s, int binary_x)
{
    if (operate == "add")
    {
        // x 위치 1로 설정
        // or 연산
        s |= binary_x;
    }
    else if (operate == "remove")
    {
        // x 위치 0으로 설정
        // x 번째 비트 빼고 나머지가 다 1인 경우랑 and 연산
        s &= ~binary_x;
    }
    else if (operate == "toggle")
    {
        // x 위치 토글 시키기
        // xor 연산
        s ^= binary_x;
    }
    else if (operate == "all")
    {
        // 전부 1로 설정
        s = (1 << 20) - 1;
    }
    else if (operate == "empty")
    {
        // s 공집합 만들기
        s = 0;
    }
    return s;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m, s;

    // 입력
    cin >> m;
    s = 0;

    while (m--)
    {
        string operate;

        cin >> operate;
        int x = 0;

        if (operate == "add" || operate == "remove" || operate == "check" || operate == "toggle")
        {
            cin >> x;

            // 이진수로 만든 x의 x 번째 비트에 1 넣기
            int binary_x = 1 << (x - 1);

            if (operate == "check")
            {
                // 비트 존재 여부 cout - x 위치가 1이면 1, 0이면 0
                if (s & binary_x)
                {
                    cout << 1 << '\n';
                }
                else
                {
                    cout << 0 << '\n';
                }

                continue;
            }

            // 연산
            s = bitmask(operate, s, binary_x);
        }
        else
        {
            // all 이나 empty는 x가 없으니까 0으로 넣음
            s = bitmask(operate, s, 0);
        }
    }

    return 0;
}