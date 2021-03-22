#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void rawSortList(ListNode *leftHead){
        if (!leftHead->next)
            return;
        ListNode * rightHead = new ListNode(-1);
        ListNode * sign = leftHead->next;
        leftHead->next = leftHead->next->next;
        sign->next = NULL;

        ListNode * head = leftHead->next;
        while (head){
            ListNode * temp = head->next;
            if (head->val <= sign->val){
                head->next = leftHead->next;
                leftHead->next = head;
            }else{
                head->next = rightHead->next;
                rightHead->next = head;
            }
            head = temp;
                    //cout<<"=============="<<head->val<<endl;
        }

        rawSortList(leftHead);
        rawSortList(rightHead);

        ListNode *t = leftHead;
        while (t->next){
            t = t->next;
        }
        t->next = sign;
        sign->next = rightHead->next;
    }
    ListNode* sortList(ListNode *head){

       ListNode *myHead = new ListNode(-1);
       myHead->next = head;
       rawSortList(myHead);
       return myHead->next;
    }

    void print(ListNode *head){
        while (head){
            cout<<head->val<<" ";
            head = head->next;
        }
        cout<<endl;
    }
};



int main()
{
    int a[] = {4,2,1,3,8,5,7,6};
    ListNode *myHead = new ListNode(-1);
    ListNode *t = myHead;
    for (int i=0; i<sizeof(a)/4; i++){
        t->next = new ListNode(a[i]);
        t = t->next;
    }
    Solution s;
    s.print(myHead->next);
    ListNode *newHead = s.sortList(myHead);
    s.print(newHead);
    return 0;
}
