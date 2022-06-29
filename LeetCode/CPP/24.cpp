struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* swapPairs(ListNode* head) 
    {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* pre = head;
        ListNode* tmp = head->next;
        head = tmp;
        while (tmp != nullptr)
        {
            if (tmp->next != nullptr && tmp->next->next != nullptr) 
            {
                ListNode* nextPre = tmp->next;
                ListNode* nextTmp = tmp->next->next;
                pre->next = tmp->next->next;
                tmp->next = pre;
                pre = nextPre;
                tmp = nextTmp;
                continue;
            }
            else
            {
                pre->next = tmp->next;
                tmp->next = pre;
            }
            break;
        }
        return head;
    }
};

class Solution
{
public:
    ListNode* swapPairs(ListNode* head)
    {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while (cur->next != nullptr && cur->next->next != nullptr)
        {
            ListNode* tmp = cur->next;
            ListNode* tmp1 = cur->next->next->next;
            
            cur->next = cur->next->next;
            cur->next->next = tmp;
            cur->next->next->next = tmp1;

            cur = cur->next->next;
        }
        return dummyHead->next;
    }
};