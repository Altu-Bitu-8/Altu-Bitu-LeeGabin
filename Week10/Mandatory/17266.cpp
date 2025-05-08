#include <iostream>
#include <vector>

using namespace std;

// height로 0~n 까지 다 밝힐 수 있는지
bool isBright(int height, vector<int> &light, int n)
{
    int cnt = 0;

    for (int i = 0; i < light.size(); i++)
    {
        // 왼쪽으로 비추는 범위
        int left = light[i] - height;
        // 오른쪽으로 비추는 범위
        int right = light[i] + height;

        // 범위 벗어나면 false
        if (left > cnt)
        {
            return false;
        }

        cnt = max(cnt, right);

        if (cnt >= n)
        {
            return true;
        }
    }
    // 반복문 다 돌았는데 cnt가 n보다 작으면 false
    return cnt >= n;
}

int main()
{
    // 입력
    int n, m;
    cin >> n >> m;

    vector<int> light(m);

    for (int i = 0; i < m; i++)
    {
        cin >> light[i];
    }

    // 연산
    // 이분탐색범위 0~n
    int low = 0;
    int high = n;
    int result = n;

    // 이분탐색
    while (low <= high)
    {
        int height = (low + high) / 2;

        // heignt로 0~n 까지 다 밝힐 수 있는 경우
        if (isBright(height, light, n))
        {
            // result 업뎃해주고 더 낮은 높이 탐색
            result = height;
            high = height - 1;
        }
        else
        {
            // 너무 낮으면 더 높은 높이 탐색
            low = height + 1;
        }
    }

    // 출력
    cout << result;

    return 0;
}