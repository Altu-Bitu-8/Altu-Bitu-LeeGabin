#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // 입력
    int n, number;
    cin >> n;

    // min heap 선언 -> 가장 큰 n개만 저장
    priority_queue<int, vector<int>, greater<int>> min_heap;

    // 필요한 값만 저장하기 위해 입력 + 연산 로직 합침
    for (int i = 0; i < n * n; i++)
    {
        cin >> number;

        if (min_heap.size() < n)
        {
            // heap 크기가 n보다 작으면 그냥 넣음
            min_heap.push(number);
        }
        else if (number > min_heap.top())
        {
            // 최솟값 pop하고 입력된 값으로 바꿈
            min_heap.pop();
            min_heap.push(number);
        }
        // 아니라면 그냥 무시 (작은 수니까 필요 없음)
    }

    // n번째 큰 값 출력
    cout << min_heap.top();

    return 0;
}