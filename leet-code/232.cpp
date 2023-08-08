#include <stack>

class MyQueue {
  private:
    using Stack = std::stack<int>;
    Stack stack_;
    Stack buffer_;

    void transfer(Stack &dst, Stack &src, int amnt)
    {
        for (int i = 0; i < amnt; ++i) {
            dst.push(src.top());
            src.pop();
        }
    }

    int getFirst(bool is_pop)
    {
        transfer(buffer_, stack_, stack_.size() - 1);

        auto res = stack_.top();
        if (is_pop)
            stack_.pop();

        transfer(stack_, buffer_, buffer_.size());

        return res;
    }

  public:
    void push(int x) { stack_.push(x); }
    int  pop() { return getFirst(true); }

    int peek() { return getFirst(false); }

    bool empty() { return stack_.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
