#include <queue>
#include <vector>
using namespace std;



  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
// class Solution
// {
// public:
//     TreeNode* invertTree(TreeNode* root)
//     {
//         queue<TreeNode*> que;

//         if (!(root == nullptr)) que.push(root);

//         while (!que.empty())
//         {
//             TreeNode* cur = que.front();
//             que.pop();
//             TreeNode* tmp = cur->left;
//             cur->left = cur->right;
//             cur->right = tmp;
//             if (cur->left) que.push(cur->left);
//             if (cur->right) que.push(cur->right);
//         }
//         return root;
//     }
// };

class Solution
{
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if (root == NULL) return root;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};