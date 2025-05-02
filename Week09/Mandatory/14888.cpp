#include <iostream>
#include <vector>

using namespace std;

void dfs(int idx, int value, const vector<int> &numbers, vector<int> &operators, int &maxValue, int &minValue)
{
    // 연산자 다 썼을 경우
    if (idx == numbers.size())
    {
        maxValue = max(maxValue, value);
        minValue = min(minValue, value);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (operators[i] > 0)
        {
            // 연산자 사용
            operators[i]--;
            // 연산자에 따라 연산
            // 0 == +
            // 1 == -
            // 2 == *
            // 3 == /
            switch (i)
            {
            case 0:
                dfs(idx + 1, value + numbers[idx], numbers, operators, maxValue, minValue);
                break;
            case 1:
                dfs(idx + 1, value - numbers[idx], numbers, operators, maxValue, minValue);
                break;
            case 2:
                dfs(idx + 1, value * numbers[idx], numbers, operators, maxValue, minValue);
                break;
            case 3:
                dfs(idx + 1, value / numbers[idx], numbers, operators, maxValue, minValue);
                break;
            }
            operators[i]++;
        }
    }
}

// 수식 결과 최솟값 최댓값 구하는 함수
pair<int, int> getMinMax(const vector<int> &numbers, const vector<int> &operators)
{
    int maxValue = -2147483647;
    int minValue = 2147483647;
    vector<int> op = operators;

    dfs(1, numbers[0], numbers, op, maxValue, minValue);

    return {minValue, maxValue};
}

int main()
{
    // 입력
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    // 사칙연산자 +-*/
    vector<int> operators(4);
    for (int i = 0; i < 4; i++)
    {
        cin >> operators[i];
    }

    // 연산
    pair<int, int> result = getMinMax(numbers, operators);

    // 출력
    cout << result.second << "\n";
    cout << result.first << "\n";

    return 0;
};