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

#include <climits>
#include <iostream>
#include <vector>

class MinStack {
public:
  /** initialize your data structure here. */
  MinStack() : _min(INT_MAX), _refresh(true) {
    std::vector<int> arr;
    _arr = arr;
  }

  // 往 stack 後面塞入一個新值
  void push(int x) {
    this->_arr.push_back(x);

    // 檢查新值是否小於原本 _min 是則更新
    if (x < this->_min) {
      this->_min = INT_MAX;
      this->_refresh = true;
    }
  }

  // 移除 stack 最後一個值
  void pop() {
    if (this->_min == this->_arr.back()) { // _min 剛好是 stack 最後一個值
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

  // 取得 stack 最小值
  int getMin() {
    if (this->_refresh || this->_min == INT_MAX) { // 檢查原本最小值是否已經被移除
      for (auto n : this->_arr) {
        if (n < this->_min)
          this->_min = n;
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
  MinStack *st = new MinStack();
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