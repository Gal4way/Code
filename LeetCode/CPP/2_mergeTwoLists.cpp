// /*
// 将两个升序链表合并为一个新的升序链表并返回。
// 新链表是通过拼接给定的两个链表的所有节点组成的。
// 输入：l1 = [1,2,4], l2 = [1,3,4]
// 输出：[1,1,2,3,4,4]
// */
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    void quickGetList(int smaller, int larger)
    {
        ListNode* pointNode = this;
    
        for (int i = smaller; i <= larger; i++)
        {
            ListNode* newListNode = new ListNode(i);
            pointNode->next = newListNode;
            pointNode = pointNode->next;
        }
    }
};

// class Solution
// {
// public:
//     static ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
//     {
//         if (l1 == nullptr)
//         {
//             return l2;
//         }
//         else if (l2 == nullptr)
//         {
//             return l1;
//         }
//         else if (l1->val < l2->val)
//         {
//             l1->next = mergeTwoLists(l1->next, l2);
//             return l1;
//         }
//         else
//         {
//             l2->next = mergeTwoLists(l1, l2->next);
//             return l2;
//         }
//     }
// };


//迭代
class Solution
{
public:
    static ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode* preHead = new ListNode(0);
        ListNode* prev = preHead;
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val < l2->val)
            {
                prev->next = l1;
                l1 = l1->next;
            }
            else
            {
                prev->next = l2;                
                l2 = l2->next;
            }
            prev = prev->next;
        }

        prev->next = l1 == NULL ? l2 : l1;
        return preHead->next;
    }
};



int main()
{
    ListNode* headNode1 = new ListNode(5);
    headNode1->quickGetList(7,10);
    ListNode* headNode2 = new ListNode(6);
    headNode2->quickGetList(7,9);

    ListNode* newListNode = Solution::mergeTwoLists(headNode1, headNode2);

    while (newListNode != NULL)
    {
        cout<<newListNode->val<<" ";
        newListNode = newListNode->next;
    }

    return 0;
}
