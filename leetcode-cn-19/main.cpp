#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *myHead = new ListNode(0);
        myHead->next = head;

        ListNode *back = myHead;
        ListNode *front = myHead;
        for (int i=0; i<n; i++){
            front = front->next;
        }
        ListNode *t = back;
        while (front){
            front = front->next;
            t = back;
            back = back->next;
        }

        t->next = t->next->next;
        delete back;
        ListNode *re = myHead->next;
        delete myHead;
        return re;
    }
};
int main() {
    vector<int> array = {1, 2, 3, 4, 5};
    ListNode *h=NULL;
    ListNode *t=NULL;
    for (int i=0; i<array.size(); i++){
        if (!h){
            h = new ListNode(array[i]);
            h->next = NULL;
            t=h;
        }else{
            t->next = new ListNode(array[i]);
            t=t->next;
        }
    }
    t = h;
    while (t) {
        std::cout << t->val << "->";
        t = t->next;
    }
    cout<<endl;
    ListNode *re;
    Solution s;
    re = s.removeNthFromEnd(h, 6);
    while (re) {
        std::cout << re->val << "->";
        re = re->next;
    }
    cout<<endl;
    return 0;
}