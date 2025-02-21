#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int hire(int n, vector<pair<int, int>> rank)
{
    int result = 1;
    int tmp = 0;

    sort(rank.begin(), rank.end());

    for (int i = 1; i < n; i++)
    {
        if (rank[tmp].second > rank[i].second)
        {
            result++;
            tmp = i;
        }
    }
    return result;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        vector<pair<int, int>> rank;

        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            rank.push_back({a, b});
        }

        int result = hire(n, rank);

        cout << result << "\n";
    }

    return 0;
}