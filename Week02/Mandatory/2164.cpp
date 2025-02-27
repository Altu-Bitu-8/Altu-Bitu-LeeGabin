#include <iostream>
#include <queue>

using namespace std;

void card(int n)
{
    if (n <= 0)
        return;

    queue<int> q;

    for (int i = 1; i <= n; i++)
        q.push(i);

    while (q.size() > 1)
    {
        q.pop();
        q.push(q.front());
        q.pop();
    }

    cout << q.front();
}

int main()
{
    int n;
    cin >> n;

    card(n);

    return 0;
}