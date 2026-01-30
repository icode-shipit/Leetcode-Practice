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
    int pairSum(ListNode* head) {
        int n=1;
        ListNode* temp1=head; // points to last node in the linked list
        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
            n++;
        }
        // now we will move temp2 from start to middle and start reversing the list from there to end
        ListNode* temp2=head;
        ListNode* prev=NULL;
        int curr=1;
        while(curr<=n/2)
        {
            prev=temp2;
            temp2=temp2->next;
            curr++;
        }
        prev->next=NULL; // splitting the list for referencing the end of twins
        ListNode* next;
        while(temp2!=NULL)
        {
            next=temp2->next;
            temp2->next=prev;
            prev=temp2;
            temp2=next;
        }
        int ans=INT_MIN;
        while(head!=NULL)
        {
            ans=max(ans,head->val+temp1->val);
            temp1=temp1->next;
            head=head->next;
        }
        return ans;
    }
};
