#include <iostream>
#include <stack>

using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:

    stack<NestedInteger> st;
    queue<int> data;
    NestedIterator(vector<NestedInteger> &nestedList) {
        data = queue<int>();
        for (int i=nestedList.size()-1; i>=0; i--)
            st.push(nestedList[i]);
        while (!st.empty()){
            if (st.top().isInteger()){
                int re = st.top().getInteger();
                st.pop();
                data.push(re);
            }else{
                while (!st.empty() && !st.top().isInteger()){
                    vector<NestedInteger> nint = st.top().getList();
                    if (!st.empty()) st.pop();
                    for (int i=nint.size()-1; i>=0; i--){
                        
                        st.push(nint[i]);
                    }
                }
                
                if (!st.empty()){
                    
                    int re = st.top().getInteger();
                    st.pop();
                    data.push(re);
                }
            }
        }
        
    }

    int next() {
        if (data.empty())
            return -1;
        int re = data.front();
        data.pop();
        return re;

    }

    bool hasNext() {
        return !data.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main(){
    return 0;
}