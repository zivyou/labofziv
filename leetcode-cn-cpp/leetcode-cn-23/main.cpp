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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode *myHead = new ListNode(0);
        ListNode *reCur = myHead;
        int reLen = 0;
        for (int i=0; i<lists.size(); i++){
            ListNode *l=lists[i];
            while (l){
                reLen++;
                l=l->next;
            }
        }

        vector<ListNode *> cur;
        for (int i=0; i<lists.size(); i++){
            cur.push_back(lists[i]);
        }


        for (int i=0; i<reLen; i++){
            int pos; int min = INT_MAX;
            ListNode *t=NULL;
            for (int j=0; j<lists.size(); j++){
                if (cur[j] == NULL)
                    continue;
                if (cur[j]->val < min){
                    min = cur[j]->val;
                    t = cur[j];
                    pos = j;
                }
            }

            reCur->next = new ListNode(t->val);
            reCur = reCur->next;
            cur[pos] = cur[pos]->next;
        }

        reCur = myHead->next;
        delete myHead;
        return reCur;
    }
};

int main() {
    vector<ListNode *> data;
    vector<int> array = {3, 4, 5};
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
    data.push_back(h);


    array = {1, 2, 3};
    h=NULL;
    t=NULL;
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
    data.push_back(h);

    array = {2};
    h=NULL;
    t=NULL;
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
    data.push_back(h);

    ListNode *re;
    Solution s;
    re = s.mergeKLists(data);
    while (re) {
        std::cout << re->val << "->";
        re = re->next;
    }
    cout<<endl;

    return 0;
}