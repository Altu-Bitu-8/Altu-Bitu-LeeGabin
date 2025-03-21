#include <iostream>
#include <vector>

using namespace std;

// 알파벳 사용 횟수 카운트한 배열 만들기
vector<int> getAlphabetCnt(string s)
{
    vector<int> alphabet_cnt(26, 0);

    for (int i = 0; i < s.size(); i++)
    {
        alphabet_cnt[s[i] - 'A']++;
    }

    return alphabet_cnt;
}

// 메인 연산 - 비슷한 단어인지 확인
// 0 == 비슷하지 않음
// 1 == 한 문자를 더하거나 빼는 경우
// 2 == 한 문자를 다른 문자로 바꾸는 경우
int isSimilar(const string &word, const string &another_word)
{
    // 두 단어의 길이 차이
    int length_gap = abs((int)word.length() - (int)another_word.length());

    // 길이 차이가 2 이상이면 바로 0
    if (length_gap >= 2)
    {
        return 0;
    }

    // 사용된 알파벳 개수 카운트
    vector<int> cnt = getAlphabetCnt(word);
    vector<int> another_cnt = getAlphabetCnt(another_word);

    // 두 벡터 간 차이 계산
    int cnt_gap = 0;
    for (int i = 0; i < 26; i++)
    {
        cnt_gap += abs(cnt[i] - another_cnt[i]);
    }

    // 길이가 다르고
    if (length_gap == 1 && cnt_gap == 1)
    {
        // 한 문자를 더하거나 빼는 경우
        return 1;
    }

    // 길이가 같고
    if (length_gap == 0 && cnt_gap == 2)
    {
        // 한 문자를 다른 문자로 바꾸는 경우
        return 2;
    }

    // 아예 똑같은 단어인 경우도 고려해주기...
    if (length_gap == 0 && cnt_gap == 0)
    {
        return 3;
    }

    // 비슷하지 않음
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // 입력
    int n;
    cin >> n;

    string word, another_word;
    cin >> word;

    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> another_word;
        // 연산
        // 연산값이 1 이상일 때만 카운트
        if (isSimilar(word, another_word) >= 1)
        {
            cnt++;
        }
    }

    // 출력
    cout << cnt;

    return 0;
}