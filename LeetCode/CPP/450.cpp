
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution
{
public:
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if (root->left == nullptr && root->right == nullptr || root == nullptr)
        {
            return nullptr;
        }
        TreeNode *keyNode = findNode(root, key);
        if (keyNode == nullptr)
        {
            return nullptr;
        }
        
        if (keyNode)



    }

    TreeNode* findNode(TreeNode* pre, TreeNode* root, int key)
    {
        TreeNode* preNode = pre;
        if (root == nullptr)
        {
            return nullptr;
        }
        if (root->val == key)
        {
            return pre, root;
        }
        TreeNode *left = findNode(root, root->left, key);
        if (left != nullptr)
        {
            return left;
        }

        TreeNode *right = findNode(root, root->right, key);
        if(right != nullptr)
        {
            return right;
        }
        return nullptr;
    }
};