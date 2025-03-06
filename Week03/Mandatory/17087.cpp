#include <iostream>
#include <vector>

using namespace std;

// 최대공약수 함수
int getGcd(int a, int b)
{
    int tmp;
    while (b != 0)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int whatIsD(const int s, const int n, vector<int> &a)
{
    // 첫째동생 - 수빈 거리
    int d = abs(a[0] - s);

    // 동생마다 수빈이와의 거리 구하고 GCD 계산
    for (int i = 1; i < n; i++)
    {
        d = getGcd(d, abs(a[i] - s));
    }

    return d;
}

int main()
{
    int n, s;
    vector<int> a;

    cin >> n >> s;

    for (int i = 0; i < n; i++)
    {
        int dongsaeng;
        cin >> dongsaeng;
        a.push_back(dongsaeng);
    }

    cout << whatIsD(s, n, a);

    return 0;
}