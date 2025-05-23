#include <iostream>
#include <vector>
#include <map>
#include <deque>

using namespace std;

// 방향
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

// 게임이라 snake 객체 만드는게 깔끔할거같아서
class Snake
{
    // 뱀
    deque<pair<int, int>> body;
    // 방향
    int dir;
    // 보드 크기
    int n;

public:
    Snake(int size) : dir(1), n(size)
    {
        body.push_back(make_pair(1, 1));
    }

    pair<int, int> getHead() const
    {
        return body.front();
    }

    void changeDirection(char c)
    {
        if (c == 'L')
        {
            dir = (dir + 3) % 4;
        }
        else if (c == 'D')
        {
            dir = (dir + 1) % 4;
        }
    }

    // 이동 함수
    // 충돌하면 false
    bool move(vector<vector<int>> &board)
    {
        pair<int, int> head = body.front();
        int x = head.first;
        int y = head.second;
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        // 충돌
        if (nx < 1 || ny < 1 || nx > n || ny > n || board[nx][ny] == 2)
        {
            return false;
        }

        // 사과 있어서 머리만 이동
        if (board[nx][ny] == 1)
        {
            board[nx][ny] = 2;
            body.push_front(make_pair(nx, ny));
        }
        // 빈칸이라 머리 이동 + 꼬리 자름
        else
        {
            board[nx][ny] = 2;
            body.push_front(make_pair(nx, ny));
            pair<int, int> tail = body.back();
            body.pop_back();
            board[tail.first][tail.second] = 0;
        }

        return true;
    }

    void initBoard(vector<vector<int>> &board)
    {
        pair<int, int> head = body.front();
        board[head.first][head.second] = 2;
    }
};

// 게임 함수
int DummyGame(int n, vector<vector<int>> board, map<int, char> &change)
{
    Snake snake(n);
    snake.initBoard(board);

    int time = 0;
    while (true)
    {
        time++;

        if (!snake.move(board))
        {
            break;
        }

        if (change.count(time))
        {
            snake.changeDirection(change[time]);
        }
    }

    return time;
}

int main()
{
    // 입력
    int n;
    cin >> n;

    int k;
    cin >> k;

    vector<vector<int>> board(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < k; i++)
    {
        int r, c;
        cin >> r >> c;
        board[r][c] = 1;
    }

    int l;
    cin >> l;
    map<int, char> change;

    for (int i = 0; i < l; i++)
    {
        int t;
        char c;
        cin >> t >> c;
        change[t] = c;
    }

    // 연산 & 출력
    cout << DummyGame(n, board, change) << "\n";

    return 0;
}