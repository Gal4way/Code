#include <iostream>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while (cur->next != nullptr)
        {
            while (cur->next != nullptr && cur->next->val == val) 
            {
                ListNode* tmp = cur->next; 
                cur->next = cur->next->next; 
                delete tmp; 
            }
            if (cur->next != nullptr) cur = cur->next;
        }
        return dummyHead->next;
    }
};

int main()
{
    int a = 0;
    while (a < 10) {a++; a++; cout<<a<<endl;} 

}