// 테케 통과가 안됩니다~~~
// 조금 더 고민해보고 추가 제출하겠습니다

#include <iostream>
#include <deque>

using namespace std;

// 종 치고 카드 합치는 함수
void hitTheBell(deque<int> &winner_deck, deque<int> &loser_ground, deque<int> &winner_ground)
{
    // 상대방의 그라운드 카드 자기 덱 아래에 뒤집어서 추가
    while (!loser_ground.empty())
    {
        winner_deck.push_back(loser_ground.front());
        loser_ground.pop_front();
    }
    // 자신의 그라운드 카드 자기 덱 아래에 뒤집어서 추가
    while (!winner_ground.empty())
    {
        winner_deck.push_back(winner_ground.front());
        winner_ground.pop_front();
    }
}

// 도도 승 == 0
// 수연 승 == 1
// 무승부 == 2
int whoWon(int m, deque<int> &dd_deck, deque<int> &sy_deck)
{
    deque<int> dd_ground, sy_ground;

    for (int i = 0; i < m; i++)
    {

        // 도도차례
        if (i % 2 == 0)
        {
            // 도도 패
            if (dd_deck.empty())
            {
                return 1;
            }
            dd_ground.push_back(dd_deck.front());
            dd_deck.pop_front();
        }
        // 수연차례
        else
        {
            // 수연 패
            if (sy_deck.empty())
            {
                return 0;
            }
            sy_ground.push_back(sy_deck.front());
            sy_deck.pop_front();
        }

        // 어느 쪽의 그라운드도 비어있으면 안된다
        if (!dd_ground.empty() && !sy_ground.empty())
        {
            // 도도가 종치는 경우
            if (dd_ground.back() == 5 || sy_ground.back() == 5)
            {
                hitTheBell(dd_deck, sy_ground, dd_ground);
                i--;
                continue;
            }
            // 수연이가 종치는 경우
            else if (dd_ground.back() + sy_ground.front() == 5)
            {
                hitTheBell(sy_deck, dd_ground, sy_ground);
                i--;
                continue;
            }
        }
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
        dd_deck.push_back(dodo);
        sy_deck.push_back(suyeon);
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