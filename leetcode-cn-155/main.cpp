#include <iostream>
#include <vector>

using namespace std;

class MinStack {
private:
    int minNum;
    vector<int> data;
public:
    /** initialize your data structure here. */
    MinStack() {
        minNum = INT_MAX;
    }

    void push(int x) {
        data.push_back(x);
        if (x < minNum)
            minNum = x;
    }

    void pop() {
        data.pop_back();
        minNum = INT_MAX;
        for (int i=0; i<data.size(); i++)
            if (minNum > data[i])
                minNum = data[i];
    }

    int top() {
        return data[data.size()-1];
    }

    int getMin() {
        return minNum;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
