#include <iostream>
#include <vector>

using namespace std;

// dfs
bool dfs(int current, int target, int distance, vector<bool> &visited, const vector<pair<int, int>> tree[], int &result)
{
    // current == target이면 true 리턴
    if (current == target)
    {
        result = distance;
        return true;
    }

    visited[current] = true;

    for (int i = 0; i < tree[current].size(); i++)
    {
        int next_node = tree[current][i].first;
        int next_distance = tree[current][i].second;

        // visited가 false인 것들 재귀로 돌림
        if (!visited[next_node])
        {
            if (dfs(next_node, target, distance + next_distance, visited, tree, result))
            {
                return true;
            }
        }
    }

    return false;
}

int getDistance(int u, int v, int n, const vector<pair<int, int>> tree[])
{
    vector<bool> visited(n + 1, false);
    int result = 0;
    // dfs로 거리 계산
    dfs(u, v, 0, visited, tree, result);

    return result;
}

int main()
{
    // 입력
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> tree[1001];

    for (int i = 0; i < n - 1; i++)
    {
        int a, b, d;
        cin >> a >> b >> d;
        tree[a].push_back({b, d});
        tree[b].push_back({a, d});
    }

    // 노드간거리 계산
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        // 출력
        int result = getDistance(u, v, n, tree);
        cout << result << "\n";
    }
    return 0;
}