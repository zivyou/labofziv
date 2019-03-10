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

    void rawReverse(ListNode *myHead, int length){
        int i=0;
        ListNode *tail = myHead;
        for (i=0; i<length; i++){
            tail = tail->next;
            if (!tail)
                return;
        }
        ListNode *remainList = tail->next;

        ListNode *toReverse = myHead->next;
        ListNode *newTail = remainList;
        while (toReverse != remainList){
            ListNode *toReverseNext = toReverse->next;
            toReverse->next = newTail;
            newTail = toReverse;
            toReverse = toReverseNext;
        }

        myHead->next = newTail;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *myHead = new ListNode(0);
        myHead->next = head;
        ListNode *t = myHead;

        rawReverse(t, k);

        while (true){
            for (int i=0; i<k; i++){
                t = t->next;
                if (!t)
                    goto stop;
            }
            rawReverse(t, k);
        }
        stop:

        ListNode *re = myHead->next;
        delete myHead;
        return re;
    }
};
int main() {
    vector<int> array = {1,2, 3, 4, 5, 6};
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
    ListNode *re;
    Solution s;

    re = s.reverseKGroup(h, 2);
    while (re) {
        std::cout << re->val << "->";
        re = re->next;
    }
    cout<<endl;

    return 0;
}