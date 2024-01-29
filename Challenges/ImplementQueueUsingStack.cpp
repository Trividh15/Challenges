#include <stack>

class MyQueue {
public:
    MyQueue() {
        stack<int> stacken;
        stack<int> stackde;
    }
    
    void push(int x) {
        stacken.push(x);
    }
    
    int pop() {
        if (stackde.empty()) {
            while (!stacken.empty()) {
                stackde.push(stacken.top());
                stacken.pop();
            }
        }

        if (!stackde.empty()) {
            int front = stackde.top();
            stackde.pop();
            return front;
        } else {
            return -1;
        }
    }
    
    int peek() {
        if (stackde.empty()) {
            while (!stacken.empty()) {
                stackde.push(stacken.top());
                stacken.pop();
            }
        }

        if (!stackde.empty()) {
            return stackde.top();
        } else {
            return -1;
        }
    }
    
    bool empty() {
        return stacken.empty() && stackde.empty();
    }

private:
    std::stack<int> stacken;
    std::stack<int> stackde;
};



