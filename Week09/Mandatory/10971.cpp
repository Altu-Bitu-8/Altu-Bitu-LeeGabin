// DP, 비트마스킹
// curr에서 출발해서 visited 도시 다 돌고 다시 curr로 돌아오는 최소비용 구하기

#include <iostream>
#include <vector>

using namespace std;

const int MAX_VALUE = 2147483647;

// 최소 비용
int getLeastCost(int curr, int visited, int n, const vector<vector<int>> &graph, vector<vector<int>> &dp)
{

    // 이미 계산된 경우 바로 리턴
    if (dp[visited][curr] != -1)
    {
        return dp[visited][curr];
    }

    // visited가 다 1일 경우
    if (visited == (1 << n) - 1)
    {
        int returnCost = (graph[curr][0] == 0 ? MAX_VALUE : graph[curr][0]);
        return returnCost;
    }

    int minCost = MAX_VALUE;

    for (int next = 0; next < n; next++)
    {
        // 아직 다음 도시 가기 전 && 가는 길이 있는 경우
        if ((visited & (1 << next)) == 0 && graph[curr][next] != 0)
        {
            // visited | (1<<next)
            int cost = getLeastCost(next, visited | (1 << next), n, graph, dp);

            if (cost != MAX_VALUE)
            {
                minCost = min(minCost, cost + graph[curr][next]);
            }
        }
    }

    dp[visited][curr] = minCost;

    return minCost;
}

int getTravelRoute(int n, const vector<vector<int>> &graph)
{
    vector<vector<int>> dp(1 << n, vector<int>(1 << n, -1));
    // 0번 도시만 방문햇다고 치고 시작
    return getLeastCost(0, 1, n, graph, dp);
}

int main()
{
    // 입력
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    // 연산 & 출력
    cout << getTravelRoute(n, graph);

    return 0;
};