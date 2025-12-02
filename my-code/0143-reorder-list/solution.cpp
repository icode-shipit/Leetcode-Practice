/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
      ListNode* prev=NULL;
      ListNode* current=head;
      ListNode* succ=head->next;
      while(succ!=NULL)
      {
        current->next=prev;
        prev=current;
        current=succ;
        succ=succ->next;
      }
      current->next=prev;
      return current;
    }

    void reorderList(ListNode* head) {
    if (!head || !head->next || !head->next->next) return;

    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // split the list: slow is end of first half
    ListNode* second = slow->next;
    slow->next = nullptr;               // <-- important: terminate first half

    // reverse second half
    ListNode* p2 = reverseList(second);
    ListNode* p1 = head;

    // merge
    while (p2) {
        ListNode* n1 = p1->next;
        ListNode* n2 = p2->next;
        p1->next = p2;
        p2->next = n1;
        p1 = n1;
        p2 = n2;
    }
    // final guard (safe)
    if (p1) p1->next = nullptr;
}

};
