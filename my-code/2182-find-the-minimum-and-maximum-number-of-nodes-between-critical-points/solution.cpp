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
    vector<int> v;
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp=head;
        int curr=0;
        ListNode* prev=NULL;
        while(temp!=NULL)
        {
            if(prev!=NULL && temp->next!=NULL)
            {
               if(temp->val>prev->val && temp->val>temp->next->val)
               {
                  v.push_back(curr);
               }
               else if(temp->val<prev->val && temp->val<temp->next->val)
               {
                  v.push_back(curr);
               }
            }
            prev=temp;
            temp=temp->next;
            curr++;
        }
        if(v.size()<2)
        {
            return {-1,-1};
        }
        int mindif=INT_MAX;
        for(int i=0;i<v.size()-1;i++)
        {
            mindif=min(mindif,v[i+1]-v[i]);
        }
        return {mindif,v[v.size()-1]-v[0]};
    }
};
