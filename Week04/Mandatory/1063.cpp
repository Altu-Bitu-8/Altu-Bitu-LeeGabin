#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 체스판 위치 좌표 구조체 선언
// (row, col) 형태로 쓰려고
struct Position
{
    int row, col;
};

// 체스판 밖으로 나가는지 확인하는 함수
bool isOutOfBoard(Position pos)
{
    return (pos.row < 0 || pos.row >= 8 || pos.col < 0 || pos.col >= 8);
}

// 체스 표기법에서 좌표로 변환
Position toIndex(string pos)
{
    return {8 - (pos[1] - '0'), pos[0] - 'A'};
}

// 좌표에서 체스 표기법으로 변환
string toChess(Position pos)
{
    return string(1, 'A' + pos.col) + to_string(8 - pos.row);
}

// 체스말 움직이는 함수
void move(Position &king, Position &stone, int direction)
{
    // R L B T RT LT RB LB 이동 방향 체스판 기준으로 매핑
    // 그니까 row가 클수록 밑으로 이동하는거임 정신체리
    vector<int> move_x = {1, -1, 0, 0, 1, -1, 1, -1};
    vector<int> move_y = {0, 0, 1, -1, -1, -1, 1, 1};

    Position next_king = {king.row + move_y[direction], king.col + move_x[direction]};

    if (isOutOfBoard(next_king))
    {
        // 킹이 체스판을 벗어나면 무시
        return;
    }

    if (next_king.row == stone.row && next_king.col == stone.col)
    {
        Position next_stone = {stone.row + move_y[direction], stone.col + move_x[direction]};
        if (isOutOfBoard(next_stone))
        {
            // 돌이 체스판을 벗어나면 무시
            return;
        }
        // 돌 이동
        stone = next_stone;
    }

    // 킹 이동
    king = next_king;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 입력
    string king_pos, stone_pos;
    int n;
    cin >> king_pos >> stone_pos >> n;

    // 체스 표기법에서 좌표로 변환
    Position king = toIndex(king_pos);
    Position stone = toIndex(stone_pos);

    // 벡터에 명령어 저장해놓고
    vector<string> commands = {"R", "L", "B", "T", "RT", "LT", "RB", "LB"};

    // 연산
    while (n--)
    {
        string cmd;
        cin >> cmd;

        // commands에서 명령어 인덱스 찾기
        for (int i = 0; i < commands.size(); i++)
        {
            if (cmd == commands[i])
            {
                move(king, stone, i);
                break;
            }
        }
    }

    // 출력
    cout << toChess(king) << "\n";
    cout << toChess(stone) << "\n";

    return 0;
}