#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 이분 탐색
bool binarySearch(const vector<int> &card, int target)
{
    int left = 0;
    int right = card.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (card[mid] == target)
        {
            return true;
        }
        else if (card[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return false;
}

int main()
{
    // 시간초과
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 입력
    int n;
    cin >> n;

    vector<int> card(n);
    for (int i = 0; i < n; i++)
    {
        cin >> card[i];
    }

    // 카드 정렬 먼저 하고
    sort(card.begin(), card.end());

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int target;
        cin >> target;

        // 이분탐색 연산 & 출력
        if (binarySearch(card, target))
        {
            cout << 1 << " ";
        }
        else
        {
            cout << 0 << " ";
        }
    }
    return 0;
}