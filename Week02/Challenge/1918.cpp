#include <iostream>
#include <stack>

using namespace std;

int postfix(string str)
{
    stack<char> stk;

    for (char c : str)
    {
        switch (c)
        {
        case '(':
            stk.push(c);
            break;
        case '*':
        case '/':
            while (!stk.empty() && (stk.top() == '*' || stk.top() == '/'))
            {
                cout << stk.top();
                stk.pop();
            }
            stk.push(c);
            break;

        case '+':
        case '-':
            while (!stk.empty() && stk.top() != '(')
            {
                cout << stk.top();
                stk.pop();
            }
            stk.push(c);
            break;

        case ')':
            while (!stk.empty() && stk.top() != '(')
            {
                cout << stk.top();
                stk.pop();
            }
            if (!stk.empty())
                stk.pop();
            break;
        default:
            if (c >= 'A' && c <= 'Z')
                cout << c;
            break;
        }
    }

    while (!stk.empty())
    {
        cout << stk.top();
        stk.pop();
    }

    return 0;
}

int main()
{
    string str;
    cin >> str;

    postfix(str);

    return 0;
}