#include <iostream>
#include <stack>
#include <string>

using namespace std;

int line(string str)
{
    stack<char> stk;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
            stk.push('(');
        else if (str[i] == '[')
            stk.push('[');
        else if (str[i] == ')')
        {
            if (str.empty())
                return false;
            else if (str.top() != '(')
                return false;
            else
                str.pop();
        }
    }
}

int main()
{
    string str;
    while (1)
    {
        getline(cin, str);
        if (str == ".")
            break;

        line(str);
    }

    return 0;
}