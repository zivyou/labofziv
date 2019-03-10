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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode * myHead = new ListNode(-1);
        myHead->next = head;
        int i=1;
        ListNode *t = myHead;
        ListNode *myReverseHead;
        ListNode *myReverseTail = NULL;
        while (t->next){
            if (i == m){
                myReverseHead = t;
            }
            if (i-1 == n){
                myReverseTail  = t;
            }
            t = t->next;
            i++;
        }
       
        if (myReverseTail == NULL)
            myReverseTail = t;
        ListNode *remaind = myReverseTail->next;
        
        // cout<<"myReverseHead->val="<<myReverseHead->val<<", ";
        //  cout<<"!!!!!!!!!!!!!"<<endl;
        // cout<<"myReverseTail->val="<<myReverseTail->val<<", ";
        //cout<<"remaind->val="<<remaind->val<<endl;
        t = myReverseHead->next;
        ListNode * tt = NULL;
        while (t!=remaind){
            ListNode *temp = t->next;
            t->next = tt;
            tt = t;
            t = temp;
        }
        myReverseHead->next->next = remaind;
        myReverseHead->next = tt;
        return myHead->next;
    }
};

int main(){
    vector<int> v({1,2,3,4,5});
    ListNode *myHead = new ListNode(-1);
    ListNode *t = myHead;
    for (int i=0; i<v.size(); i++){
        t->next = new ListNode(v[i]);
        t = t->next;
    }
    Solution s;
    ListNode *re = s.reverseBetween(myHead->next, 1, 2);
    t = re;
    while (t){
        cout<<t->val<<" ";
        t = t->next;
    } 
    cout<<endl;
    return 0;
}