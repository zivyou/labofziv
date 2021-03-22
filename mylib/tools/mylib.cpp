#include "mylib.h"

ListNode * vectorToLink(vector<int> v){
    ListNode *myHead = new ListNode(-1);
    ListNode *re = myHead;

    for (int i=0; i<v.size(); i++){
        re->next = new ListNode(v[i]);
        re = re->next;
    }

    re = myHead->next;
    delete myHead;

    return re;
}




