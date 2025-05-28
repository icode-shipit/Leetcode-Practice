class Solution {
public:
TreeNode* BuildBST(TreeNode* root,int data)
{
   if(root==NULL)
   {
     TreeNode* newnode=new TreeNode(data);
     return newnode;
   }
   else if(data>root->val)
   {
     root->right=BuildBST(root->right,data);
   }
   else if(data<root->val)
   {
    root->left=BuildBST(root->left,data);
   }
   return root;
}
TreeNode* Binarysearchrec(TreeNode* root,vector<int> v,int start,int end)
{
    if(start<=end)
{
  int mid=start+(end-start)/2;
  root=BuildBST(root,v[mid]);
  root= Binarysearchrec(root,v,mid+1,end);
  root= Binarysearchrec(root,v,start,mid-1);
}
    return root;
}
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* temp=head;
        vector<int> v;
        while(temp!=NULL)
        {
          v.push_back(temp->val);
          temp=temp->next;
        }
        delete temp;
        TreeNode* root=NULL;
        root=Binarysearchrec(root,v,0,v.size()-1);
        return root;
    }
};
