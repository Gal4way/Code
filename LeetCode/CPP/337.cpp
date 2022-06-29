// 在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。
// 这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。
// 一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 
// 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

// 计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

// 暴力
#include <vector>
#include <unordered_map>
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
//     int rob(TreeNode* root)
//     {
//         if (root == nullptr) return 0;
//         if (root->left == nullptr && root->right == nullptr) return root->val;

//         int val1 = root->val;
//         if (root->left) val1 += rob(root->left->left) + rob(root->left->right);

//     }
// };


// 记忆化搜索
// class Solution
// {
// public:
//     unordered_map<TreeNode* , int> umap;
//     int rob(TreeNode* root)
//     {
//         if (root == nullptr) return 0;
//         if (root -> left == NULL && root->right == nullptr) return root->val;
//         if (umap[root]) return umap[root];
//         int val1 = root->val;
//         if (root->left) val1 += rob(root->left->left) + rob(root->left->right);
//         if (root->right) val1 += rob(root->right->left) + rob(root->right->right);
//         int val2 = rob(root->left) + rob(root->right);
//         umap[root] = max(val1, val2);
//         return max(val1, val2);
//     }
// };

class Solution
{
public:
    int rob(TreeNode* root)
    {
        vector<int> result = robTree(root);
        return max(result[0], result[1]);
    }

    vector<int> robTree(TreeNode* cur)
    {
        if (cur == nullptr) return vector<int> {0, 0};
        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);
        vector<int> returnVec (2);
        returnVec[0] = max(left[0],left[1]) + max(right[0],right[1]);
        returnVec[1] = cur->val + left[0] + right[0];
        return returnVec;
    }
};
