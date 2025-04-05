
#include <iostream>
#include <vector>
#include <deque>

// 2025-04-05 (sat) : 수정 완료

using namespace std;

// 도도와 수연의 덱을 저장하는 벡터 선언
typedef vector<deque<int>> cards;
// 0: 도도, 1: 수연
const int DO = 0, SU = 1;

// 현재 덱의 상태를 보고 누가 종을 치는지 판단
// 파라미터로 들어오는 deck은 각 플레이어의 덱을 저장한 벡터
string judge(cards &deck)
{
    // 도도의 덱에 남아있는 카드 수와 수연의 덱에 남아있는 카드 수
    int do_deck = deck[DO].size(), su_deck = deck[SU].size();
    // 카드를 더 많이 갖고있는 사람이 이긴다
    if (do_deck > su_deck)
    {
        // 도도가 더 많이 가진 경우 do 리턴
        return "do";
    }
    else if (do_deck < su_deck)
    {
        // 수연이 더 많이 가진 경우 su 리턴
        return "su";
    }
    // 무승부인 경우 dosu 리턴
    return "dosu";
}

// 그라운드에 있는 카드들을 본인의 덱으로 가져가는 함수
// 파라미터로 들어오는 deck은 각 플레이어의 덱을 저장한 벡터
// ground는 각 플레이어의 그라운드에 있는 카드들을 저장한 벡터
void groundToDeck(deque<int> &deck, deque<int> &ground)
{
    // 뒤집어서 넣어야 하므로 그라운드의 카드들을 하나씩 덱의 뒤에 넣음
    while (!ground.empty())
    {
        // 카드들을 뒤집어서 덱에 넣기
        deck.push_back(ground.back());
        // 그라운드에서는 삭제해주기
        ground.pop_back();
    }
}

// 종을 치게 되는 경우 그라운드에 있는 카드들을 덱으로 가져가는 함수
// 파라미터로 들어오는 player는 종을 친 사람의 번호 (아까 위에서 DO, SU 정의해준거)
// deck은 각 플레이어의 덱을 저장한 벡터
// ground는 각 플레이어의 그라운드에 있는 카드들을 저장한 벡터
void ringTheBell(int player, cards &deck, cards &ground)
{
    // 카드 가져가기 (상대 그라운드 -> 본인 덱)
    groundToDeck(deck[player], ground[!player]);
    // 카드 가져가기 (본인 그라운드 -> 본인 덱)
    groundToDeck(deck[player], ground[player]);
}

// 누가 종을 칠 수 있는지 정하는 함수
// 파라미터로 들어오는 deck은 각 플레이어의 덱을 저장한 벡터
// ground는 각 플레이어의 그라운드에 있는 카드들을 저장한 벡터
// 리턴값은 종을 칠 수 있는 사람의 번호 (아까 위에서 DO, SU 정의해준거)
// 종을 칠 수 없는 경우 -1 리턴
int whoCanRingTheBell(cards &deck, cards &ground)
{
    // 도도의 그라운드에 카드가 있고 그 카드가 5인 경우
    if (!ground[DO].empty() && ground[DO].front() == 5)
    { // 도도 승
        return DO;
    }
    // 수연의 그라운드에 카드가 있고 그 카드가 5인 경우
    else if (!ground[SU].empty() && ground[SU].front() == 5)
    { // 도도 승
        return DO;
    }
    // 도도의 그라운드와 수연의 그라운드 둘 다에 카드가 있고 두 카드의 합이 5인 경우
    else if (!ground[DO].empty() && !ground[SU].empty() && (ground[DO].front() + ground[SU].front() == 5))
    { // 수연 승
        return SU;
    }
    // 종을 칠 수 없는 경우
    return -1;
}

// 게임 진행 함수
// 파라미터로 들어오는 m은 게임 진행 횟수
// deck은 각 플레이어의 덱을 저장한 벡터
// ground는 각 플레이어의 그라운드에 있는 카드들을 저장한 벡터
string game(int m, cards &deck, cards &ground)
{
    // 게임 시작은 도도부터
    bool turn = DO;
    // m번 반복
    while (m--)
    {
        // 덱의 맨 앞 카드를 그라운드에 올려놓음
        ground[turn].push_front(deck[turn].front());
        // 덱에서 사용한 카드 삭제해주기
        deck[turn].pop_front();
        // 턴 끝났는데 덱이 비어있으면 게임 종료
        if (deck[turn].empty())
        {
            // while문 깨고 나감
            break;
        }
        // 누가 종을 칠 수 있는지
        int bell = whoCanRingTheBell(deck, ground);
        if (bell != -1)
        { // 종을 울린 경우
            ringTheBell(bell, deck, ground);
        }
        // 턴 변경
        turn = !turn;
    }
    // 게임 종료 후 덱의 상태를 보고 누가 이겼는지 판단
    return judge(deck);
}

/**
 * 도도, 수연이 각각 덱과 그라운드를 가짐
 * 도도->수연->도도->수연... 순으로 차례를 바꿔가며 게임 진행 (game 함수)
 * 1. 카드를 덱에서 한 장 내려놓음
 * 2. 어떤 플레이어가 종을 칠 수 있는지 판단 (whoCanRingTheBell 함수)
 * 3. 종을 친 경우 그라운드의 카드를 덱으로 이동(ringTheBell, groundToDeck 함수)
 * 종료 조건 만족 시 승리한 사람 리턴(judge 함수)
 */

// main 함수
int main()
{
    // 사용할 변수들 선언
    int n, m, card1, card2;
    // 도도, 수연의 덱과 그라운드
    // 0: 도도, 1: 수연
    cards deck(2), ground(2);

    // 입력
    cin >> n >> m;
    // n번 반복
    while (n--)
    {
        // 카드 2장씩 입력받고
        cin >> card1 >> card2;
        // 각 플레이어의 덱에 넣기
        deck[DO].push_front(card1);
        deck[SU].push_front(card2);
    }

    // 출력 & 연산
    cout << game(m, deck, ground);

    return 0;
}