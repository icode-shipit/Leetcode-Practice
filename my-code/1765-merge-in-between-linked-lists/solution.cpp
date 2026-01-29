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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp=list1;
        ListNode* blink;
        int curr=0;
        while(temp!=NULL)
        {
            if(a-curr==1)
            {
                ListNode* temp1=temp->next;
                temp->next=list2;
                temp=temp1;
                curr++;
                continue;
            }
            if(curr-b==0)
            {
                blink=temp->next;
                break;
            }
           temp=temp->next;
           curr++;
        }
        ListNode* i=list2;
        while(i->next!=NULL)
        {
            i=i->next;
        }
        i->next=blink;
        return list1;
    }
};
