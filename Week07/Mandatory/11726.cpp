#include <iostream>
#include <vector>

using namespace std;

// bottom up 방식
int howManyCases(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }

    // 또 런타임에러
    vector<int> v(n + 1);

    v[1] = 1;
    v[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        v[i] = (v[i - 1] + v[i - 2]) % 10007;
    }

    return v[n];
}

int main()
{
    // 입력
    int n;
    cin >> n;

    // 연산 & 출력
    cout << howManyCases(n);

    return 0;
}