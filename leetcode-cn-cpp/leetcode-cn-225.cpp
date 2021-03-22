#include <iostream>
#include <queue>

using namespace std;

class MyStack {
private:
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int size = q.size();
        int re = q.back();
        queue<int> tmp;
        for (int i=0; i<size-1; i++){
            int t = q.front();
            tmp.push(t);
            q.pop();
        }

        while (!q.empty())
            q.pop();
        for (int i=0; i<size-1; i++){
            int t = tmp.front();
            q.push(t);
            tmp.pop();
        }
        return re;
    }
    
    /** Get the top element. */
    int top() {
        return q.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main(){

}