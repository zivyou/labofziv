#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *myHead = new ListNode(-1);
        ListNode * re = new ListNode(-1);
        myHead->next = head;

        while (myHead->next){
            ListNode *n = myHead->next;
            myHead->next = n->next;
            n->next = re->next;
            re->next = n;
        }
        return re->next;
    }
};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
