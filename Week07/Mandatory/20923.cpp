// 테케 통과가 안됩니다~~~
// 조금 더 고민해보고 추가 제출하겠습니다.

#include <iostream>
#include <deque>

using namespace std;

// 종 치고 카드 합치는 함수
void hitTheBell(deque<int> &winner_deck, deque<int> &loser_ground, deque<int> &winner_ground)
{
    // 상대방의 그라운드 카드 자기 덱 아래에 뒤집어서 추가
    while (!loser_ground.empty())
    {
        winner_deck.push_back(loser_ground.back());
        loser_ground.pop_back();
    }
    // 자신의 그라운드 카드 자기 덱 아래에 뒤집어서 추가
    while (!winner_ground.empty())
    {
        winner_deck.push_back(winner_ground.back());
        winner_ground.pop_back();
    }
}

// 도도 승 == 0
// 수연 승 == 1
// 무승부 == 2
int whoWon(int m, deque<int> &dd_deck, deque<int> &sy_deck)
{
    deque<int> dd_ground, sy_ground;
    // true: 도도, false: 수연
    bool turn = true;

    for (int i = 0; i < m; i++)
    {
        if (turn)
        {
            // 도도 차례
            if (dd_deck.empty())
                return 1;
            dd_ground.push_front(dd_deck.front());
            dd_deck.pop_front();
        }
        else
        {
            // 수연 차례
            if (sy_deck.empty())
                return 0;
            sy_ground.push_front(sy_deck.front());
            sy_deck.pop_front();
        }

        // 종 칠 수 있는지 확인
        if (!dd_ground.empty() && dd_ground.front() == 5)
        {
            hitTheBell(dd_deck, sy_ground, dd_ground);
        }
        else if (!sy_ground.empty() && sy_ground.front() == 5)
        {
            hitTheBell(dd_deck, sy_ground, dd_ground);
        }
        else if (!dd_ground.empty() && !sy_ground.empty() && dd_ground.front() + sy_ground.front() == 5)
        {
            hitTheBell(sy_deck, dd_ground, sy_ground);
        }

        turn = !turn;
    }

    // 도도 승
    if (dd_deck.size() > sy_deck.size())
    {
        return 0;
    }
    // 수연 승
    else if (dd_deck.size() < sy_deck.size())
    {
        return 1;
    }
    // 무승부
    return 2;
}

int main()
{
    // 입력
    int n, m;
    cin >> n >> m;

    deque<int> dd_deck;
    deque<int> sy_deck;

    for (int i = 0; i < n; i++)
    {
        int dodo, suyeon;
        cin >> dodo >> suyeon;
        dd_deck.push_front(dodo);
        sy_deck.push_front(suyeon);
    }

    // 연산
    int result = whoWon(m, dd_deck, sy_deck);

    // 출력
    if (result == 0)
    {
        cout << "do";
    }
    else if (result == 1)
    {
        cout << "su";
    }
    else
    {
        cout << "dosu";
    }

    return 0;
}