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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> s;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            if(s.empty())
            {
                s.push(temp);
                temp=temp->next;
            }
            else
            {
                while(!s.empty() && s.top()->val<temp->val)
                {
                    s.pop();
                }
                s.push(temp);
                temp=temp->next;
            }
        }
        stack<ListNode*> s1;
        while(!s.empty())
        {
            s1.push(s.top());
            s.pop();
        }
        ListNode* prev=NULL;
        while(!s1.empty())
        {
            if(prev==NULL)
            {
                head=s1.top();
                prev=head;
                s1.pop();
            }
            else
            {
                prev->next=s1.top();
                prev=prev->next;
                s1.pop();
            }
        }
        prev->next=NULL;
        return head;
    }
};
