#include <iostream>
#include <vector>

using namespace std;

// 매개변수가 너무 많아져서 구조체 사용
// 바퀴 상태 저장 구조체
struct WheelState
{
    vector<char> wheel;
    vector<bool> used;
    int pointer;
    int n;

    // 멤버 init
    WheelState(int size)
        : wheel(size, '?'), used(26, false), pointer(0), n(size) {}
};

// 바퀴 돌리는 함수
int roll(WheelState &ws, const int s, const char c)
{
    // 화살표가 가리키는 곳
    ws.pointer = (ws.pointer + s) % ws.n;

    // 중복인 경우 -1
    if (ws.wheel[ws.pointer] == '?' && ws.used[c - 'A'])
    {
        return -1;
    }

    // 이미 다른 문자가 들어가 있는 경우 -1
    if (ws.wheel[ws.pointer] != '?' && ws.wheel[ws.pointer] != c)
    {
        return -1;
    }

    ws.wheel[ws.pointer] = c;
    ws.used[c - 'A'] = true;

    return 0;
}

int main()
{
    int n, k;
    cin >> n >> k;

    WheelState ws(n);

    for (int i = 0; i < k; i++)
    {
        int s;
        char c;
        cin >> s >> c;

        if (roll(ws, s, c) != 0)
        {
            cout << "!";
            return 0;
        }
    }

    // 바퀴 출력
    for (int i = 0; i < ws.n; i++)
    {
        cout << ws.wheel[(ws.pointer - i + ws.n) % ws.n];
    }
    return 0;
}