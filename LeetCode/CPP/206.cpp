// 206.反转链表
// 力扣题目链接(opens new window)

// 题意：反转一个单链表。

// 示例: 输入: 1->2->3->4->5->NULL 输出: 5->4->3->2->1->NULL


// using namespace std;

struct ListNode 
{
    int val;
    ListNode* nextNode;
    ListNode() : val(0), nextNode(nullptr) {}
    ListNode(int x) : val(x), nextNode(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), nextNode(next) {}
};

// class Solution
// {
// public:
//     ListNode* reverseList(ListNode* head)
//     {
//         if (head == nullptr)
//         {
//             return nullptr;
//         }
//         ListNode* resultList = new ListNode();
//         ListNode *tmp = head;
//         while ( tmp != nullptr)
//         {
//             ListNode* nextNode = tmp->nextNode;
//             tmp->nextNode = resultList->nextNode;
//             resultList->nextNode = tmp;
//             tmp = nextNode;
//         }
//         return resultList->nextNode;    
//     }
// };

// class Solution
// {
//     ListNode* reverseList(ListNode* head)
//     {
//         if (head == nullptr) return head;

//         ListNode* pre = nullptr;
//         ListNode* cur = head;
//         while (cur != nullptr)
//         {
//             ListNode* tmp = cur->nextNode;
//             cur->nextNode = pre;
//             pre = cur;
//             cur = tmp;
//         }
//         return pre;
//     }
// };

// 后序
class Solution
{
    ListNode* reverseList(ListNode* head)
    {
        if (head == nullptr) return nullptr;
        if (head->nextNode == nullptr) return head;

        ListNode *last = reverseList(head->nextNode);
        head->nextNode->nextNode = head;
        head->nextNode = nullptr;
        return last;
    }
};