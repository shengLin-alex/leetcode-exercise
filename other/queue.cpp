#include <string>

template <typename T>
class queue {
private:
  template <typename U>
  class queue_node {
  public:
    queue_node(U data) : _next(nullptr), _data(data) {}
    ~queue_node() {}
    U _data;
    queue_node<U> *_next;
  };

  queue::queue_node<T> *_front;
  queue::queue_node<T> *_back;
  int _size;

public:
  queue() : _front(nullptr), _back(nullptr), _size(0) {}
  ~queue() {}

  void push(T data) {
    if (this->empty()) {
      this->_front = new queue::queue_node<T>(data);
      this->_back = this->_front;
      this->_size++;
      return;
    }

    // always push to back
    queue::queue_node<T> *new_node = new queue::queue_node<T>(data);
    this->_back->_next = new_node;
    this->_back = new_node;
    this->_size++;
  }

  void pop() {
    if (this->empty())
      return;

    // always delete from front
    queue::queue_node<T> *deleting = this->_front;
    this->_front = this->_front->_next;
    delete deleting;
    deleting = nullptr;
    this->_size--;
  }

  bool empty() {
    return this->_front == nullptr && this->_back == nullptr;
  }

  T front() {
    if (this->empty())
      throw "accessing empty queue.";

    return this->_front->_data;
  }

  T back() {
    if (this->empty())
      throw "accessing empty queue.";

    return this->_back->_data;
  }

  int size() {
    return this->_size;
  }
};

int main() {
  queue<std::string> qu;
  qu.push("1");
  qu.push("2");
  auto a = qu.front();
  qu.pop();
  auto b = qu.front();

  return 0;
}