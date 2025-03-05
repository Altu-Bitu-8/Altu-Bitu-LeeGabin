#include <iostream>
#include <string>
#include <set>

using namespace std;

int getSubs(string s)
{
    set<string> subs;
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n - i; j++)
            subs.insert(s.substr(i, j));
    }

    return subs.size();
}

int main()
{
    string s;

    cin >> s;
    cout << getSubs(s) << "\n";
    return 0;
}