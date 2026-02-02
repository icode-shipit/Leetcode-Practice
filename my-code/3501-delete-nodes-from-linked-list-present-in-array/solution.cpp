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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        ListNode* dummy= new ListNode();
        dummy->next=head;
        ListNode* temp= dummy;
        while(temp->next!=NULL)
        {
            if(s.contains(temp->next->val))
            {
                temp->next=temp->next->next;
                continue;
            }
            temp=temp->next;
        }
        return dummy->next;
    }
};
