#include <iostream>
#include <stack>

using namespace std;

void getOken(int n)
{
    int a[1000001];
    int b[1000001];
    stack<int> stk;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = n - 1; i >= 0; i--)
    {
        while (!stk.empty() && stk.top() <= a[i])
            stk.pop();
        if (stk.empty())
            b[i] = -1;
        else
            b[i] = stk.top();
        stk.push(a[i]);
    }
    for (int i = 0; i < n; i++)
        cout << b[i] << ' ';
}

int main()
{
    int n;
    cin >> n;

    getOken(n);

    return 0;
}