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
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            pq.push({temp->val,temp});
            temp=temp->next;
        }
        ListNode* prev=NULL;
        while(!pq.empty())
        {
            if(prev==NULL)
            {
                prev=pq.top().second;
                pq.pop();
                head=prev;
            }
            else
            {
                prev->next=pq.top().second;
                prev=prev->next;
                pq.pop();
            }
        }
        prev->next=NULL;
        return head;
    }
};
