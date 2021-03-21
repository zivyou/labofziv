#include <iostream>
#include <vector>

using namespace std;



class ZigzagIterator {
public:
    vector<int>::iterator cur1;
    vector<int>::iterator cur2;
    vector<int> data1;
    vector<int> data2;
    int pos;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        data1 = v1;
        data2 = v2;
        cur1 = data1.begin();
        cur2 = data2.begin();
        pos = 1;
    }

    int next() {
        if (cur1 == data1.end())
            pos = 2;
        if (cur2 == data2.end())
            pos = 1;

        int re;
        if (pos == 1){
            re = *cur1;
            cur1++;
            pos = 2;
        }else{
            re = *cur2;
            cur2++;
            pos = 1;
        }

        return re;
    }

    bool hasNext() {
        return (cur1 != data1.end() || cur2 != data2.end());
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */

int main(){
    vector<int> v = {1,2,3,4,5};
    vector<int>::iterator it = v.begin();
    while (it != v.end()){
        cout<<*it<<" ";
        it++;
    }
    return 0;
}