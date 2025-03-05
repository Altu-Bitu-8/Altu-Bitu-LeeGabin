#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(string str)
{
    stack<char> stk;

    for (char c : str)
    {
        if (c == '(' || c == '[')
            stk.push(c);
        else if (c == ')')
        {
            if (stk.empty() || stk.top() != '(')
                return false;
            stk.pop();
        }
        else if (c == ']')
        {
            if (stk.empty() || stk.top() != '[')
                return false;
            stk.pop();
        }
    }

    return stk.empty();
}

int main()
{
    string str;
    while (true)
    {
        getline(cin, str);
        if (str == ".")
            break;

        if (isBalanced(str))
            cout << "yes" << "\n";
        else
            cout << "no" << "\n";
    }

    return 0;
}