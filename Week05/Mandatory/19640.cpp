#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 사원 구조체
struct employee
{
    int order;   // 줄 선 순서
    int period;  // 근무일수
    int urgency; // 급한 정도
};

// 각 줄의 맨 앞에 있는 사원
struct front_employee
{
    employee emp;
    int q_num;
};

// 비교함수 구조체
struct compare
{
    bool operator()(const front_employee &e1, const front_employee &e2)
    {
        // 근무일수 많은 사람 먼저
        if (e1.emp.period != e2.emp.period)
        {
            return e1.emp.period < e2.emp.period;
        }
        // 급한 정도가 큰 사람 먼저
        if (e1.emp.urgency != e2.emp.urgency)
        {
            return e1.emp.urgency < e2.emp.urgency;
        }
        // 다 같은 경우 경우 줄 번호가 더 낮은 사람 먼저
        return e1.q_num > e2.q_num;
    }
};

// 앞으로 몇 명 남았는지?
int howManyPeopleLeft(vector<queue<employee>> &queues, int k)
{
    priority_queue<front_employee, vector<front_employee>, compare> pq;

    // 각 줄의 맨 앞에 있는 사람 pq에 push
    for (int i = 0; i < queues.size(); i++)
    {
        if (queues[i].size() != 0)
        {
            pq.push({queues[i].front(), i});
            // 사용하면 queues에서는 지워주기
            queues[i].pop();
        }
    }

    int cnt = 0;

    // 데카 순서가 올 때까지 반복
    while (true)
    {
        front_employee front = pq.top();
        pq.pop();

        // 데카이면 반복문 깨고 나감
        if (front.emp.order == k)
        {
            break;
        }

        cnt++;

        // 사람이 남아 있는 경우
        // 맨 앞에 있는 사람 pq에 push
        if (queues[front.q_num].size() != 0)
        {
            pq.push({queues[front.q_num].front(), front.q_num});
            queues[front.q_num].pop();
        }
    }

    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // 입력
    int n, m, k;
    cin >> n >> m >> k;

    vector<employee> employee_list(n);

    for (int i = 0; i < n; i++)
    {
        employee_list[i].order = i;
        cin >> employee_list[i].period >> employee_list[i].urgency;
    }

    // m개의 줄로 나눠서기
    vector<queue<employee>> queues(m);
    for (int i = 0; i < n; i++)
    {
        queues[i % m].push(employee_list[i]);
    }

    // 연산 & 출력
    cout << howManyPeopleLeft(queues, k);

    return 0;
}