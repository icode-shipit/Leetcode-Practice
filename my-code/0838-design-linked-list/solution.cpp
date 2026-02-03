class MyLinkedList {
public:
    int size;
    ListNode* head;
    ListNode* tail;
    MyLinkedList() {
        size=0;
        head=tail=NULL;
    }
    
    int get(int index) {
        if(index>=size)
        {
            return -1;
        }
        ListNode* temp=head;
        int idx=0;
        while(idx<index)
        {
            idx++;
            temp=temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        ListNode* newnode= new ListNode(val);
        size++;
        if(head==NULL)
        {
            head=tail=newnode;
        }
        else
        {
            newnode->next=head;
            head=newnode;
        }
    }
    
    void addAtTail(int val) {
        ListNode* newnode= new ListNode(val);
        size++;
        if(tail==NULL)
        {
            head=tail=newnode;
        }
        else
        {
            tail->next=newnode;
            tail=newnode;
        }
    }
    
    void addAtIndex(int index, int val) {
        if(index==0)
        {
            addAtHead(val);
            return;
        }
        else if(index==size)
        {
            addAtTail(val);
            return;
        }
        else if(index>size)
        {
            return;
        }
        size++;
        ListNode* temp=head;
        int idx=0;
        while(idx<index-1)
        {
            idx++;
            temp=temp->next;
        }
        ListNode* newnode= new ListNode(val);
        ListNode* nextnode= temp->next;
        temp->next=newnode;
        newnode->next=nextnode;
        return;
    }
    
    void deleteAtIndex(int index) {
        if(index>=size)
        {
            return;
        }
        ListNode* temp=head;
        int idx=0;
        if(index==0)
        {
            head=head->next;
            size--;
            return;
        }
        while(idx<index-1)
        {
            idx++;
            temp=temp->next;
        }
        temp->next=temp->next->next;
        if(index==size-1)
        {
            tail=temp;
        }
        size--;
        return;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
