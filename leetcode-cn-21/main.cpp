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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *myHead = new ListNode(0);
        ListNode *t = myHead;
        while (l1 || l2){
            if (l1 &&l2) {
                if (l1->val < l2->val) {
                    t->next = l1;
                    t = t->next;
                    l1=l1->next;
                }else{
                    t->next = l2;
                    t= t->next;
                    l2=l2->next;
                }
            }else if(l1){
                t->next = l1;
                break;
            }else{
                t->next = l2;
                break;
            }
        }
        t=myHead->next;
        delete myHead;
        return t;
    }
};

int main() {
    vector<int> array1 = {5};
    ListNode *h1=NULL;
    ListNode *t=NULL;
    for (int i=0; i<array1.size(); i++){
        if (!h1){
            h1 = new ListNode(array1[i]);
            h1->next = NULL;
            t=h1;
        }else{
            t->next = new ListNode(array1[i]);
            t=t->next;
        }
    }

    vector<int> array2 = {5};
    ListNode *h2=NULL;
    t=NULL;
    for (int i=0; i<array2.size(); i++){
        if (!h2){
            h2 = new ListNode(array2[i]);
            h2->next = NULL;
            t=h2;
        }else{
            t->next = new ListNode(array2[i]);
            t=t->next;
        }
    }

    ListNode *re;
    Solution s;
    re = s.mergeTwoLists(h1, h2);
    while (re) {
        std::cout << re->val << "->";
        re = re->next;
    }
    cout<<endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}