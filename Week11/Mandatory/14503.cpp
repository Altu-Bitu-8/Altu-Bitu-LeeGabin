#include <iostream>
#include <vector>

using namespace std;

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

int howManyRooms(int n, int m, int r, int c, int d, const vector<vector<int>> &room)
{
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int cnt = 0;

    while (true)
    {
        // 현재 위치 청소
        if (!visited[r][c])
        {
            visited[r][c] = true;
            cnt++;
        }

        // 청소할 수 있는 방향 찾기
        bool clean = false;

        for (int i = 0; i < 4; i++)
        {
            d = (d + 3) % 4;
            int new_r = r + dr[d];
            int new_c = c + dc[d];

            if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < m && room[new_r][new_c] == 0 && !visited[new_r][new_c])
            {
                r = new_r;
                c = new_c;
                clean = true;
                break;
            }
        }

        // 후진
        if (!clean)
        {
            int back_r = r - dr[d];
            int back_c = c - dc[d];

            if (back_r < 0 || back_r >= n || back_c < 0 || back_c >= m || room[back_r][back_c] == 1)
            {
                break;
            }
            else
            {
                r = back_r;
                c = back_c;
            }
        }
    }

    return cnt;
}

int main()
{
    // 입력
    int n, m;
    cin >> n >> m;

    int r, c, d;
    cin >> r >> c >> d;

    vector<vector<int>> room(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> room[i][j];
        }
    }

    // 연산 & 출력
    int result = howManyRooms(n, m, r, c, d, room);
    cout << result << "\n";

    return 0;
}