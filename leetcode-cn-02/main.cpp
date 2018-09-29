#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> carry;
        ListNode* t1=l1;
        ListNode* t2=l2;
        ListNode* ret=NULL;
        ListNode* realRet;
        int i = 0;
        while (t1 || t2){
            int val1, val2;
            if (!t1)
                val1 = 0;
            else {
                val1 = t1->val;
                t1 = t1->next;
            }

            if (!t2){
                val2 = 0;
            }else{
                val2 = t2->val;
                t2 = t2->next;
            }
            if (i == 0) {
                ret = new ListNode((val1 + val2) % 10);
                realRet = ret;
                carry.push_back((val1+val2)/10);
                i++;
            }else{
                ret->next = new ListNode((val1+val2+carry[i-1])%10);
                carry.push_back((val1+val2+carry[i-1])/10);
                i++;
                ret = ret->next;
            }
        }
        if (carry[i-1] != 0){
            ret->next = new ListNode(carry[i-1]);
        }
        return realRet;
    }
};

int main() {
    string input;
    ListNode* l1 = NULL;
    ListNode* l2 = NULL;
    ListNode* ll1 = l1;
    ListNode* ll2 = l2;
    getline(cin, input);
    int i = 0;
    for (i=0; input[i]; i++){
        if (input[i] != ' '){
            if (ll1 == NULL){
                l1 = new ListNode(input[i]-'0');
                ll1 = l1;
            }else{
                l1->next = new ListNode(input[i]-'0');
                l1 = l1->next;
            }
        }
    }
    getline(cin, input);
    for (i=0; input[i]; i++){
        if (input[i] != ' '){
            if (ll2 == NULL){
                l2 = new ListNode(input[i]-'0');
                ll2 = l2;
            }else{
                l2->next = new ListNode(input[i]-'0');
                l2 = l2->next;
            }
        }
    }

    Solution s;
    ListNode* ret = s.addTwoNumbers(ll1, ll2);
    while (ret){
        cout<<ret->val<<" ";
        ret= ret->next;
    }
    cout<<endl;
    return 0;
}