class MyCircularQueue {
public:
    vector<int> v;
    int capacity;
    int currsize;
    int front;
    int rear;
    MyCircularQueue(int k) {
        v.resize(k,-1);
        front=0;
        rear=-1;
        capacity=k;
        currsize=0;
    }
    
    bool enQueue(int value) {
        if(!isFull())
        {
          rear=(rear+1)%capacity;
          v[rear]=value;
          currsize++;
          return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(!isEmpty())
        {
          front=(front+1)%capacity;
          currsize--;
          return true;
        }
        return false;
    }
    
    int Front() {
        if(isEmpty())
        {
            return -1;
        }
        return v[front];
    }
    
    int Rear() {
        if(isEmpty())
        {
            return -1;
        }
        return v[rear];
    }
    
    bool isEmpty() {
        if(currsize==0)
        {
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(currsize==capacity)
        {
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
