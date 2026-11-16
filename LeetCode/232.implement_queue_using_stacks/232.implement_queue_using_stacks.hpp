#include <stack>

class MyQueue
{
  private:
    std::stack<int> in;
    std::stack<int> out;

    void transferIfNeeded()
    {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
    }

  public:
    void push(int _x) { in.push(_x); }

    int pop()
    {
        transferIfNeeded();
        int front = out.top();
        out.pop();
        return front;
    }

    int peek()
    {
        transferIfNeeded();
        return out.top();
    }

    bool empty() { return in.empty() && out.empty(); }
};
