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
    ListNode* swapPairs(ListNode* head) {
        if (!head)
            return head;
        ListNode *myHead = new ListNode(0);
        ListNode *pre = myHead;
        myHead->next = head;
        ListNode *h1 = head;
        ListNode *h2 = h1->next;

        while (h1 && h2){
            pre->next = h2;
            h1->next = h2->next;
            h2->next = h1;
            pre = h1;

            ListNode *t = h1;
            h1 = h2;
            h2 = t;
            h1=h1->next;
            if (!h1->next)
                break;
            h1=h1->next;
            if (!h1)
                break;
            h2=h1->next;
        }

        pre = myHead->next;
        delete myHead;
        return pre;
    }
};

int main() {
    vector<int> array = {};
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
    re = s.swapPairs(h);
    while (re) {
        std::cout << re->val << "->";
        re = re->next;
    }
    cout<<endl;


    return 0;
}