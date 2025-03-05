#include <iostream>
#include <string>

using namespace std;

void sum(string a, string b)
{
    string sum;
    int digit, carry = 0;

    if (a.length() > b.length())
        digit = a.length();
    else
        digit = b.length();

    a = string(digit - a.length(), '0') + a;
    b = string(digit - b.length(), '0') + b;

    for (int i = digit - 1; i >= 0; i--)
    {
        int s = (a[i] - '0') + (b[i] - '0') + carry;
        carry = s / 10;
        sum += (s % 10) + '0';
    }

    if (carry > 0)
        sum += carry + '0';

    int n = sum.length();

    while (n--)
        cout << sum[n];

    return;
}

int main()
{
    string a, b;
    cin >> a >> b;

    sum(a, b);

    return 0;
}