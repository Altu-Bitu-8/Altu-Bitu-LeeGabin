#include <iostream>
#include <vector>

using namespace std;

int runConveyorBelt(int n, int k, vector<int> &belt)
{
    // 로봇 위치 bool로 저장
    vector<bool> robot(n, false);
    int step = 0;

    while (true)
    {
        step++;

        // 1. 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
        int last = belt[2 * n - 1];
        for (int i = 2 * n - 1; i > 0; i--)
        {
            // q벨트 회전
            belt[i] = belt[i - 1];
        }
        belt[0] = last;

        for (int i = n - 1; i > 0; i--)
        {
            // 로봇 회전
            robot[i] = robot[i - 1];
        }
        robot[0] = false;
        // n-1에 있는 로봇은 벨트가 회전하면서 떨어짐!!!!
        robot[n - 1] = false;

        // 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다.
        // 만약 이동할 수 없다면 가만히 있는다.
        for (int i = n - 2; i >= 0; i--)
        {
            // 로봇이 이동하기 위해서는 이동하려는 칸에 로봇이 없으며 그 칸의 내구도가 1 이상 남아있어야 한다.
            if (robot[i] && !robot[i + 1] && belt[i + 1] > 0)
            {
                robot[i + 1] = true;
                robot[i] = false;
                belt[i + 1]--;
            }
        }

        // 3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
        if (!robot[0] && belt[0] > 0)
        {
            robot[0] = true;
            belt[0]--;
        }

        // 4. 내구도가 0인 칸의 개수가 k개 이상이라면 과정을 종료한다.
        // 그렇지 않다면 1번으로 돌아간다.
        int zero = 0;
        for (int i = 0; i < 2 * n; i++)
        {
            if (belt[i] == 0)
            {
                zero++;
            }
        }

        if (zero >= k)
        {
            break;
        }
    }

    return step;
}

int main()
{
    // 입력
    int n, k;
    cin >> n >> k;

    vector<int> belt(2 * n);

    // 벨트 내구도
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> belt[i];
    }
    // 연산 & 출력
    cout << runConveyorBelt(n, k, belt);

    return 0;
}