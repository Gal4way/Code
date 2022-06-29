// 给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，
// 这条路径上所有节点值相加等于目标和。

// 说明: 叶子节点是指没有子节点的节点。

// 示例:  给定如下二叉树，以及目标和 sum = 22，
// 返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。

struct treenode
{
    int val;
    treenode* left;
    treenode* right;
};


class Solution
{
    private:
        bool traversal(treenode* cur, int count)
        {
            if (!cur->left && !cur->right && count == 0) return true;
            if (!cur->left && !cur->right) return false;

            if (cur->left)
            {
                count -= cur->left->val;
                if (traversal(cur->left, count)) return true;
                count += cur->left->val;
            }
            if (cur->right)
            {
                count -= cur->right->val;
                if (traversal(cur->right, count)) return true;
                count += cur->right->val;
            }
            return false;
        }

    public:
        bool haspathsum(treenode* root, int sum)
        {
            if (root == nullptr) return false;
            return traversal(root, sum - root -> val);
        }
};