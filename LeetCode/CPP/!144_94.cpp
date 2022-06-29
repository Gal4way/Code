// //给你二叉树的根节点 root ，返回它节点值的 前序 遍历。


#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class TreeNode
{
public:
    TreeNode *leftSon;
    TreeNode *rightSon;
    int value;
    TreeNode() : value(0), leftSon(nullptr), rightSon(nullptr) {}
    TreeNode(int val) : value(val), leftSon(nullptr), rightSon(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : value(val), leftSon(left), rightSon(right) {}
};

// class Solution
// {
// public:
//     static vector<int> preorderTraversal(TreeNode* root)
//     {
//         if (root == nullptr)
//         {
//             return {};
//         }
//         vector<int> Traversal;
//         stack<TreeNode*> rightNode;

//         TreeNode *ptNode = root;

//         while (true)
//         {
//             Traversal.push_back(ptNode->value);

//             if (ptNode->rightSon) rightNode.push(ptNode->rightSon);

//             if (ptNode->leftSon) 
//             {
//                 ptNode = ptNode->leftSon;
//                 continue;
//             }

//             if (!rightNode.empty())
//             {
//                 ptNode = rightNode.top();
//                 rightNode.pop();
//                 continue;
//             }

//             break;
//         }
//         return Traversal;
//     }
// };

// int main()
// {
//     TreeNode a(1), b(2), c(3);
//     a.rightSon = &b;
//     b.leftSon = &c;
//     for (int i : Solution::preorderTraversal(&a))
//     {
//         cout<<i<<endl;
//     }
// }

// //给定一个二叉树的根节点 root ，返回它的 中序 遍历。

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        if (root == nullptr)
        {
            return {};
        }

        vector<int> traversal;
        stack<TreeNode*> middle;

        TreeNode* ptNode = root;

        while (true)
        {
            if (ptNode != nullptr)
            {
                middle.push(ptNode);
            }

            if (ptNode->leftSon)
            {
                ptNode = ptNode->leftSon;
                continue;
            }            

            if (ptNode->rightSon)
            {
                ptNode = ptNode->rightSon;
                continue;
            }

            if (!middle.empty())
            {
                ptNode = middle.top();
                middle.pop();
                traversal.push_back(ptNode->value);
            }




        }

    }
};