#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int getNthNumber(const vector<int> &numbers, int n)
{
    // min heap 선언
    priority_queue<int, vector<int>, greater<int>> min_heap;

    // heap 크기 n으로 설정
    for (int i = 0; i < n; i++)
    {
        min_heap.push(numbers[i]);
    }

    // 나머지 요소 확인하면서 가장 큰 값 n개 유지
    for (int i = n; i < numbers.size(); i++)
    {
        // heap의 최솟값보다 클 경우
        if (numbers[i] > min_heap.top())
        {
            // 최솟값 pop하고 입력된 값으로 바꿈
            min_heap.pop();
            min_heap.push(numbers[i]);
        }
    }
    // n번째 큰 값 리턴
    return min_heap.top();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // 입력
    int n;
    cin >> n;

    vector<int> numbers(n * n);
    for (int i = 0; i < n * n; i++)
    {
        cin >> numbers[i];
    }

    // 연산 & 출력
    cout << getNthNumber(numbers, n);

    return 0;
}