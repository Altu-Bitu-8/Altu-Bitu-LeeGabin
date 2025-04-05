#include <iostream>
#include <vector>

using namespace std;

int getMaxPeople(vector<int> &people, vector<int> &burgers, int k)
{
    int cnt = 0;
    int i = 0;
    int j = 0;

    while (i < people.size() && j < burgers.size())
    {
        // 현재 사람이 먹을 수 있는 거리 내에 햄버거가 있으면 먹음
        if (abs(people[i] - burgers[j]) <= k)
        {
            cnt++;
            i++;
            j++;
        }
        else if (people[i] > burgers[j])
        {
            // 사람이 햄버거보다 오른쪽에 있으면 다음 햄버거 확인
            j++;
        }
        else
        {
            // 햄버거가 오른쪽에 있으므로 다음 사람 확인
            i++;
        }
    }

    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // 입력
    int n, k;
    cin >> n >> k;

    string table;
    cin >> table;

    vector<int> people, burgers;

    // 사람 / 햄버거 위치 나눠서 저장
    for (int i = 0; i < n; i++)
    {
        if (table[i] == 'P')
        {
            people.push_back(i);
        }
        else if (table[i] == 'H')
        {
            burgers.push_back(i);
        }
    }

    // 연산 & 출력
    cout << getMaxPeople(people, burgers, k);

    return 0;
}