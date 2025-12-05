class Listnode
{
    public:
    int key;
    int value;
    Listnode* next;
    Listnode* prev;

    Listnode(int key,int val)
    {
        this->key=key;
        value=val;
        prev=NULL;
        next=NULL;
    }
};

class LRUCache {
public:
unordered_map<int,Listnode*> m;
Listnode* leftdummy; // Node right after leftdummy will be LRU node
Listnode* rightdummy; // Node just left of rightdummy will be MRU node
int currsize;
int maxcap;
    LRUCache(int capacity) {
        maxcap=capacity;
        currsize=0;
        leftdummy= new Listnode(-1,-1);
        rightdummy= new Listnode(-1,-1);
        leftdummy->prev=NULL;
        leftdummy->next=rightdummy;
        rightdummy->next=NULL;
        rightdummy->prev=leftdummy; // first linking dummynodes and then we add new nodes in b/w them
    }
    
    int get(int key) {
        if(m.contains(key))
        {
        Listnode* temp=m[key];
        // Now we remove this node and place it at the end of list before rightdummy
        // first lets remove its place and stitch remaining nodes
        Listnode* prevnode=temp->prev;
        Listnode* nextnode=temp->next;
        prevnode->next=nextnode;
        nextnode->prev=prevnode;
        // Lets now add this node at the end
        Listnode* tempprev=rightdummy->prev;
        tempprev->next=temp;
        temp->prev=tempprev;
        rightdummy->prev=temp;
        temp->next=rightdummy;
        
        return temp->value; // after positions changed now return the value in the node
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(currsize<maxcap && !m.contains(key))
        {
        Listnode* newnode = new Listnode(key,value);
        m[key]=newnode; // adding new node address to map

        Listnode* temp=rightdummy->prev;
        temp->next=newnode;
        newnode->prev=temp;
        newnode->next=rightdummy;
        rightdummy->prev=newnode;
        currsize++;
        return;
        }
        if(m.contains(key)) // maxcap is fulled
        {
        // change the value in the node and move it to the end of list
        Listnode* temp =m[key];
        temp->value=value;
        
        // Now we remove this node and place it at the end of list before rightdummy
        // first lets remove its place and stitch remaining nodes
        Listnode* prevnode=temp->prev;
        Listnode* nextnode=temp->next;
        prevnode->next=nextnode;
        nextnode->prev=prevnode;
        // Lets now add this node at the end
        Listnode* tempprev=rightdummy->prev;
        tempprev->next=temp;
        temp->prev=tempprev;
        rightdummy->prev=temp;
        temp->next=rightdummy;

        return;
        }
            // Here we remove LRU node and add new node at the end
            m.erase(leftdummy->next->key); // eraing LRU node from map
            Listnode* LRUnode=leftdummy->next;
            Listnode* temp=LRUnode->next; // points to node after LRU node
            leftdummy->next=temp;
            temp->prev=leftdummy;
            delete LRUnode;
            //Now add newnode at the end of list 
            Listnode* newnode= new Listnode(key,value);
            m[key]=newnode; // add address of newnode into the list
            Listnode* temp1=rightdummy->prev;
            temp1->next=newnode;
            newnode->prev=temp1;
            newnode->next=rightdummy;
            rightdummy->prev=newnode;
            
            return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
