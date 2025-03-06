#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX = 1000000;

// 소수 여부 벡터에 저장
void isPrime(vector<bool> &prime)
{
    prime[0] = false;
    prime[1] = false;
    prime[2] = true;

    // 짝수는 소수가 될 수 없으므로 미리 연산
    for (int i = 4; i <= MAX; i += 2)
    {
        prime[i] = false;
    }
    for (int i = 3; i * i <= MAX; i += 2)
    {
        if (prime[i])
        {
            // 홀수의 배수 제거
            for (int j = i * i; j <= MAX; j += i * 2)
            {
                prime[j] = false;
            }
        }
    }
}

// 골드바흐의 추측 검증
string isGoldbachRight(int n, vector<bool> &prime)
{
    int a, b;

    // 홀수인 소수만 고려
    for (a = 3; a <= n / 2; a += 2)
    {
        b = n - a;
        if (prime[a] && prime[b])
        {
            string result = to_string(n) + " = " + to_string(a) + " + " + to_string(b);
            return result;
        }
    }
    return "Goldbach's conjecture is wrong.";
}

int main()
{
    // 시간초과 해결하려면 넣어야함,,,
    // 사유: 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<bool> prime(MAX + 1, true);

    // 소수 판별
    isPrime(prime);

    while (1)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;

        cout << isGoldbachRight(n, prime) << "\n";
    }
    return 0;
}