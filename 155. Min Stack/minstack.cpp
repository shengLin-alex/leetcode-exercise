// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// getMin() -- Retrieve the minimum element in the stack.
 

// Example:

// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin();   --> Returns -3.
// minStack.pop();
// minStack.top();      --> Returns 0.
// minStack.getMin();   --> Returns -2.

#include <vector>
#include <climits>
#include <iostream>

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() : _min(INT_MAX), _refresh(true) {
        std::vector<int> arr;
        _arr = arr;
    }
    
    void push(int x) {
        this->_arr.push_back(x);

        if (x < this->_min) {
            this->_min = INT_MAX;
            this->_refresh = true;
        }
    }
    
    void pop() {
        if (this->_min == this->_arr.back()) {
            this->_min = INT_MAX;
            this->_refresh = true;
        } else {
            this->_refresh = false;
        }
        
        this->_arr.erase(this->_arr.end() - 1);
    }
    
    int top() {
        return this->_arr.back();
    }
    
    int getMin() {
        if (this->_refresh || this->_min == INT_MAX) {
            for (auto n : this->_arr) {
                if (n < _min) _min = n;
            }
        }
        
        return this->_min;
    }

private:
    int _min;
    bool _refresh;
    std::vector<int> _arr;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    MinStack* st = new MinStack();
    st->push(512);
    st->push(-1024);
    st->push(-1024);
    st->push(512);

    st->pop();
    std::cout << st->getMin() << std::endl;
    st->pop();
    std::cout << st->getMin() << std::endl;
    st->pop();
    std::cout << st->getMin() << std::endl;

    return 0;
}