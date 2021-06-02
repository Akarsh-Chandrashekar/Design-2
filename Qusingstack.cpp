class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> instack;
    stack<int> outstack;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        instack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        int temp;
        if(!outstack.empty())
        {
            temp=outstack.top();
            outstack.pop();
        }
        else
        {
            while(!instack.empty())
            {
                outstack.push(instack.top());
                instack.pop();
            }
            temp=outstack.top();
            outstack.pop();
        }
        return temp;
    }
    
    /** Get the front element. */
    int peek() {
        int temp;
        if(!outstack.empty())
        {
            temp=outstack.top();
        }
        else
        {
            while(!instack.empty())
            {
                outstack.push(instack.top());
                instack.pop();
            }
             temp=outstack.top();
        }
        return temp;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if((instack.empty())&&(outstack.empty()))
            {
                return true;
            }
        else
            {
                return false;
            }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */