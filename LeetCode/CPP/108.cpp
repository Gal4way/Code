// 给定二叉搜索树的中序遍历，是否可以唯一地确定二叉搜索树？答案是否定的。
// 如果没有要求二叉搜索树的高度平衡，则任何一个数字都可以作为二叉搜索树的根节点，
// 因此可能的二叉搜索树有多个。
// 每次插入都是从根节点开始比较

// 递归 -> 两个条件，一个结束条件，一个过程中返回的条件   a1   an+1 = f(an)

// 对数组进行操作，给left数和right数就可以操作数组相应的片段

//  Definition for a binary tree node.

// 递归一定要递归到尽头才返回终止条件

// 二叉搜索树新插入的结点一定是一个新添加的叶子结点
// 二叉搜索树的删除 -> 左子树中的最大值/右子树的最小值 代替这个值
// 删除节点 -> 找最小的后继（右子树最小，如无右子树，就不找后继，转而去左子树找前驱，即最大的前驱），再转而删去该后继（前驱

// 二叉平衡树 -> AVL树

// 一棵AVL树有如下必要条件：

// 条件一：它必须是二叉查找树。
// 条件二：每个节点的左子树和右子树的高度差至多为1。

// 解决一个回溯问题，实际上就是一个决策树的遍历过程。
// 1、路径：也就是已经做出的选择。

// 2、选择列表：也就是你当前可以做的选择。

// 3、结束条件：也就是到达决策树底层，无法再做选择的条件。

// 迭代 -> 不断更新root

// 递归 -> 边界，终止递归 终止->满足条件 递归->不满足

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    static TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sort(nums, 0, nums.size() - 1);
    }
    
    static TreeNode* sort(vector<int>& nums, int left, int right)
    {
        if (left == right)
        {
            return new TreeNode(nums[left]);
        }
        int mid = (left + right)/2;
        TreeNode* rootNode = new TreeNode(nums[mid]);
        rootNode->left = sort(nums, left, mid - 1);
        rootNode->right = sort(nums, mid + 1, right);
        return rootNode;
    }
};

int main()
{
    vector<int> a = {1,2,3,4,5,6,7,8,9};
    TreeNode* test = Solution::sortedArrayToBST(a);
}

