class MyQueue {
public:
    stack<int> input, output;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        
        if(not output.empty()) {
            int top_element = output.top();
            output.pop();
            return top_element;
        } else {
            while(not input.empty()) {
                output.push(input.top());
                input.pop();
            }
            int new_top_element = output.top();
            output.pop();
            return new_top_element;
        }
        
               
    }
    
    int peek() {
        
        if(not output.empty()) {
            return output.top();
        } else {
            while(not input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    bool empty() {
        if(output.empty() and input.empty()) return true;
        else return false;
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