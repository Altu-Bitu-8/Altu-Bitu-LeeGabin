#include <iostream>
#include <vector>

using namespace std;

// 후위순회
int postorder(const vector<int> &preorder, int start, int end, vector<int> &result)
{
    if (start >= end)
    {
        return 0;
    }

    int root = preorder[start];
    int right = start + 1;

    // 오르쪽 트리 시작지점
    while (right < end && preorder[right] < root)
    {
        right++;
    }

    // left subtree
    int l = postorder(preorder, start + 1, right, result);

    // right subtree
    int r = postorder(preorder, right, end, result);

    // 현재 루트 저장
    result.push_back(root);
    return (l + r + 1);
}

int main()
{
    vector<int> preorder;
    int x;

    // 입력
    while (cin >> x)
    {
        preorder.push_back(x);
    }

    // 연산
    vector<int> result;
    postorder(preorder, 0, preorder.size(), result);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << "\n";
    }

    return 0;
}