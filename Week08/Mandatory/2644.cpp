#include <iostream>
#include <vector>

using namespace std;

// dfs
int chonsu(int current, int target, const vector<vector<int>> &family_tree, vector<bool> &visited)
{
    visited[current] = true;

    // 지금 사람과 타겟이 같으면 0촌
    if (current == target)
        return 0;

    // 지금 사람이랑 연결된 친척들 전부 탐색
    for (int i = 0; i < family_tree[current].size(); i++)
    {
        int neighbor = family_tree[current][i];

        if (!visited[neighbor])
        {
            // 재귀 함수로 촌수 계산해주고
            int result = chonsu(neighbor, target, family_tree, visited);
            // 촌수 관계 내에 있으면 +1해서 리턴
            if (result != -1)
                return result + 1;
        }
    }

    // 촌수 없는 모르는사람일때
    return -1;
}

int main()
{
    // 입력
    int n;
    cin >> n;

    int a, b;
    cin >> a >> b;

    int m;
    cin >> m;

    vector<vector<int>> family_tree(n + 1);
    vector<bool> visited(n + 1, false);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        family_tree[x].push_back(y);
        family_tree[y].push_back(x);
    }

    // 연산 & 출력
    cout << chonsu(a, b, family_tree, visited);

    return 0;
}