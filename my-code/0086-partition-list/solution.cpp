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
    ListNode* partition(ListNode* head, int x) {
        // first delete all the nodes which have lower val than x
        // make a new list with lower val nodes with same rel order
        // and later join them to fornt of edited list
        if(head==NULL)
        {
            return head;
        }
        vector<ListNode*> lowlist;
        ListNode* dummy= new ListNode();
        dummy->next=head;
        ListNode* temp=dummy;
        while(temp->next!=NULL)
        {
            if(temp->next->val<x)
            {
                lowlist.push_back(temp->next);
                temp->next=temp->next->next;
                continue;
            }
            temp=temp->next;
        }
        if(lowlist.empty())
        {
            return dummy->next;
        }
        for(int i=0;i<lowlist.size()-1;i++)
        {
           lowlist[i]->next=lowlist[i+1];
        }
        lowlist[lowlist.size()-1]->next=dummy->next;
        return lowlist[0];
    }
};
