#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// 결정된 방향에 따라서 돌리는 함수
void rotate(vector<deque<char>> &wheels, const vector<int> &directions)
{
    for (int i = 0; i < wheels.size(); i++)
    {
        if (directions[i] == 1)
        {
            // 시계 방향 회전
            // 마지막 거 맨 앞으로 옮기기
            wheels[i].push_front(wheels[i].back());
            wheels[i].pop_back();
        }
        else if (directions[i] == -1)
        {
            // 반시계 방향 회전
            // 첫 번째 거 맨 뒤로 옮기기
            wheels[i].push_back(wheels[i].front());
            wheels[i].pop_front();
        }
    }
}

// 어느 방향으로 회전할지 결정
void whichWay(const vector<deque<char>> &wheels, vector<int> &directions, int wheel_num, int way)
{
    directions[wheel_num] = way;
    int rev_clock_way = wheel_num;
    int clock_way = wheel_num;
    int tmp = way;

    // 반시계방향 회전
    while (rev_clock_way > 0)
    {
        if (wheels[rev_clock_way - 1][2] == wheels[rev_clock_way][6])
        {
            // 톱니바퀴 왼쪽이랑 극이 같으면 깨고 나감
            break;
        }
        // 극이 다르면 반대로 만들어주기
        directions[rev_clock_way - 1] = -way;
        rev_clock_way--;
        way = -way;
    }

    // 시계방향 회전
    while (clock_way < wheels.size() - 1)
    {
        if (wheels[clock_way + 1][6] == wheels[clock_way][2])
        {
            // 톱니바퀴 오른쪽이랑 극이 같으면 깨고 나감
            break;
        }
        // 극이 다르면 반대로
        directions[clock_way + 1] = -tmp;
        clock_way++;
        tmp = -tmp;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // 입력
    int t;
    cin >> t;

    // 런타임 에러 발생... 미리 크기 정해주기
    vector<deque<char>> wheels(t);

    for (int i = 0; i < t; i++)
    {
        string s;
        cin >> s;
        // 문자열 to 덱
        wheels[i] = deque<char>(s.begin(), s.end());
    }

    int k;
    cin >> k;

    // 연산
    for (int i = 0; i < k; i++)
    {
        int wheel_num, way;
        cin >> wheel_num >> way;
        wheel_num--;

        // 방향 저장 벡터 0으로 초기화
        vector<int> directions(t, 0);

        whichWay(wheels, directions, wheel_num, way);
        rotate(wheels, directions);
    }

    int cnt = 0;

    for (int i = 0; i < t; i++)
    {
        if (wheels[i][0] == '1')
        {
            cnt++;
        }
    }

    // 출력
    cout << cnt;

    return 0;
}