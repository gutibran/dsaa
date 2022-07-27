class MyQueue {
public:
    vector<int> q;
    MyQueue() {
        cout << "constructed" << endl;
    }
    
    void push(int x) {
       this->q.push_back(x);
    }
    
    int pop() {
       int popper = this->q.front();
       this->q.erase(this->q.begin());
        return popper;
    }
    
    int peek() {
        return this->q.front(); 
    }
    
    bool empty() {
       return this->q.empty(); 
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