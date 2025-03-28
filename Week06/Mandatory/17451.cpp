#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll getMinSpeed(vector<ll> &v, int n)
{
    // 마지막 속도로 초기화
    ll speed = v[n - 1];

    // 뒤에서부터 하나씩 확인
    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i] >= speed)
        {
            // 앞의 속도가 지금 속도보다 크거나 같으면 그대로 유지
            speed = v[i];
        }
        else if (speed % v[i] != 0)
        {
            // speed가 v[i]의 배수가 아닌 경우
            // v[i]의 배수 중에서 speed를 초과하는 최소값으로 업데이트
            speed = (speed / v[i] + 1) * v[i];
        }
    }
    return speed;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // 입력
    int n;
    cin >> n;

    vector<ll> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // 연산 & 출력
    cout << getMinSpeed(v, n);

    return 0;
}