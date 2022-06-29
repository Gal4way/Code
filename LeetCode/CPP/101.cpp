// #include <vector>
// #include <stack>
// #include <queue>
// using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

// class Solution
// {
// public:
//     bool isSymmetric(TreeNode* root)
//     {
//         queue<TreeNode*> que;
//         que.push(root->left);
//         que.push(root->right);
        
//         while (!que.empty())
//         {
//             TreeNode* leftNode = que.front(); que.pop();
//             TreeNode* rightNode = que.front(); que.pop();
//             if (!leftNode && !rightNode) continue;

//             if ((!leftNode || !rightNode || (leftNode->val != rightNode->val))) return false;

//             que.push(leftNode->left);
//             que.push(rightNode->right);
//             que.push

//         }
//     }
// }

#include <iostream>
using namespace std;
class a
{
public:
    int v1;
    int v2;
    a() : v1(0), v2(0) {}
    a(int a1, int a2) : v1(a1), v2(a2) {}
};
int main()
{
    for (int a = 1, b = 2; a < 100; a++, b = b + 2)
    {
        cout << ( ( (a + b) / 2 ) == ( a + (b - a) / 2 ) ) << endl;
    }
};