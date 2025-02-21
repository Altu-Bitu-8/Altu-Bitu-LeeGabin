#include <iostream>
#include <map>

using namespace std;

int combination(map<string, int> closet)
{
    int result = 1;

    for (auto c : closet)
    {
        result *= (c.second + 1);
    }

    return result - 1;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        map<string, int> closet;

        for (int i = 0; i < n; i++)
        {
            string cloth, type;
            cin >> cloth >> type;
            closet[type]++;
        }

        int result = combination(closet);
        cout << result << "\n";
    }

    return 0;
}