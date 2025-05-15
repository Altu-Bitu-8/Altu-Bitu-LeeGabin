#include <iostream>
#include <vector>

using namespace std;

// dfs
// 웜 바이러스 감염된 컴퓨터 수 계산하는 함수
int infected(int current, vector<vector<int>> &network, vector<bool> &visited)
{
    visited[current] = true;
    int cnt = 0;

    // 지금 컴퓨터에 연결된 컴퓨터들 전부 탐색
    for (int i = 0; i < network[current].size(); i++)
    {
        int neighbor = network[current][i];

        // 감염X 시
        if (!visited[neighbor])
        {
            // 지금 처음 방문한 컴퓨터 하나 더해줘야함
            cnt++;
            // 재귀 함수로 감염된 컴퓨터 더하기
            cnt += infected(neighbor, network, visited);
        }
    }

    return cnt;
}

int main()
{
    // 입력
    int n, pair;
    cin >> n >> pair;

    // 1부터 시작해서 n + 1
    vector<vector<int>> network(n + 1);

    for (int i = 0; i < pair; i++)
    {
        int a, b;
        cin >> a >> b;
        network[a].push_back(b);
        network[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);

    // 연산 & 출력
    // 1번 컴퓨터에서 시작 -> 1로 넘겨줌
    cout << infected(1, network, visited);

    return 0;
}