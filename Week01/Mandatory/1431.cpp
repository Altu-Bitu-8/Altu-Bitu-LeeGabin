#include <iostream>
#include <algorithm>

using namespace std;

int numberSum(const string s)
{
    int n = s.length();
    int result = 0;

    for (int i = 0; i < n; i++)
    {
        if (isdigit(s[i]))
            result += s[i] - '0';
    }

    return result;
}

bool compare(string a, string b)
{
    int a_len = a.length();
    int b_len = b.length();

    if (a_len != b_len)
        return (a_len < b_len);
    else
    {
        int a_result = numberSum(a);
        int b_result = numberSum(b);

        if (a_result != b_result)
            return (a_result < b_result);
        else
            return (a < b);
    }
}

int main()
{
    int n;
    cin >> n;

    string guitars[50];

    for (int i = 0; i < n; i++)
        cin >> guitars[i];

    sort(guitars, guitars + n, compare);

    for (int i = 0; i < n; i++)
        cout << guitars[i] << endl;

    return 0;
}