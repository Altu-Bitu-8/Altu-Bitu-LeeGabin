#include <iostream>
#include <vector>

using namespace std;

struct position
{
    int row, col;
    int color;

    // 밑에 current에서 호출할때 non const로 호출 못하니까 const 달아주기
    bool isValid() const
    {
        return row >= 1 && row <= 19 && col >= 1 && col <= 19;
    }

    position next(int dx, int dy) const
    {
        return {row + dx, col + dy, color};
    }

    position prev(int dx, int dy) const
    {
        return {row - dx, col - dy, color};
    }
};

// 인덴트가 너무 깊어져서 함수분리..
// 방향 돌면서 이기는 조건 체크
bool checkDirection(const vector<vector<position>> &board, const position &current, const int dx[], const int dy[], int &winner, position &start)
{
    for (int dir = 0; dir < 4; dir++)
    {
        // 이전 칸이랑 색깔이 같으면 패스
        position prev = current.prev(dx[dir], dy[dir]);
        if (prev.isValid() && board[prev.row][prev.col].color == current.color)
        {
            continue;
        }

        int cnt = 1;
        position next = current;

        // 같은 방향으로 색 같은 돌 있는지 4칸 탐색
        for (int k = 1; k < 5; k++)
        {
            next = next.next(dx[dir], dy[dir]);

            if (!next.isValid())
            {
                break;
            }
            if (board[next.row][next.col].color != current.color)
            {
                break;
            }

            cnt++;
        }

        // 승리 조건
        if (cnt == 5)
        {
            // 6개 연속인 경우는 제외하기
            position six = next.next(dx[dir], dy[dir]);
            if (six.isValid() && board[six.row][six.col].color == current.color)
            {
                continue;
            }

            winner = current.color;
            start = current;
            return true;
        }
    }

    // 승자 없는 경우
    return false;
}

// 누가 이겼는지 확인
// 리턴값은 승자가 있는지 없는지
bool whoWon(const vector<vector<position>> &board, int &winner, position &start)
{
    // 4방향 (가로, 세로, 대각선, 반대 대각선)
    int dx[4] = {0, 1, 1, -1};
    int dy[4] = {1, 0, 1, 1};

    for (int i = 1; i <= 19; i++)
    {
        for (int j = 1; j <= 19; j++)
        {
            const position &current = board[i][j];
            // 빈칸이면 패스
            if (current.color == 0)
            {
                continue;
            }

            if (checkDirection(board, current, dx, dy, winner, start))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    // 1~19
    // 19로 넣으면 세그폴트 난다
    vector<vector<position>> board(20, vector<position>(20));

    // 입력
    for (int i = 1; i <= 19; i++)
    {
        for (int j = 1; j <= 19; j++)
        {
            int c;
            cin >> c;
            board[i][j].row = i;
            board[i][j].col = j;
            board[i][j].color = c;
        }
    }

    int winner;
    position start;

    // 연산
    if (whoWon(board, winner, start))
    {
        // 승자가 있는 경우 출력
        cout << winner << "\n";
        cout << start.row << " " << start.col;
    }
    else
    {
        // 아직 승부 결정 X인 경우 출력
        cout << "0";
    }

    return 0;
}
