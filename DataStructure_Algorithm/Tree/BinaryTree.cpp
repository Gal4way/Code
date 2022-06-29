

#include <vector>
#include <queue>

using namespace std;



struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

//前序遍历
// class Solution
// {
// public:
//     void traversal(TreeNode* cur, vector<int>& vec)
//     {
//         if (cur == nullptr) return;

//         vec.push_back(cur->val);
//         traversal(cur->left, vec);
//         traversal(cur->right, vec);
//     }
//     vector<int> preorderTraversal(TreeNode* root)
//     {
//         vector<int> result;
//         traversal(root, result);
//         return result;
//     }
// };

// 中序遍历
// class Solution
// {
// public:
//     void traversal(TreeNode* cur, vector<int>& vec)
//     {
//         if (cur == NUll) return;
//         traversal(cur->left, vec);
//         vec.push_back(cur->val);
//         traversal(cur->right, vec);
//     }
// };

//后序遍历
// class Solution
// {
// public:
//     void traversal(TreeNode* cur, vector<int>& vec)
//     {
//         if (cur == NULL) return;
//         traversal(cur->left, vec);
//         traversal(cur->right, vec);
//         vec.push_back(cur->val);
//     }
// };

// 层序遍历

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        vector<vector<int>> result;
        while (!que.empty())
        {
            vector<int> vec;
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
                vec.push_back(node->val);
            }
            result.push_back(vec);
        }

    }
};