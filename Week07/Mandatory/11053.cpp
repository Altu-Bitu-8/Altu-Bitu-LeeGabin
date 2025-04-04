#include <iostream>
#include <vector>

using namespace std;

// 최댓값 찾기
int getMax(const vector<int> &len)
{
    int max = 0;
    int i = 0;

    while (i < len.size())
    {
        if (len[i] > max)
        {
            max = len[i];
        }
        i++;
    }
    return max;
}

int getLongestPart(const int n, vector<int> &arr)
{
    // 가장 긴 증가하는 부분수열 길이 저장하는 벡터
    vector<int> len(n, 1);

    for (int i = 1; i < n; i++)
    {
        // i 전에 있는 모든 원소랑 비교
        for (int j = 0; j < i; j++)
        {
            // 증가하는 부분수열인가요?
            if (arr[j] < arr[i])
            {
                if (len[j] + 1 > len[i])
                {
                    len[i] = len[j] + 1;
                }
            }
        }
    }

    return getMax(len);
}

int main()
{
    // 입력
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr[i] = a;
    }

    // 연상 & 출력
    cout << getLongestPart(n, arr);

    return 0;
}