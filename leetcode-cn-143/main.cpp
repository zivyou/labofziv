#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void rawReorderList(ListNode *head){
        ListNode *h = head;
        if (!h || !h->next || !h->next->next)
            return;
        while (h->next->next)
            h = h->next;
        h->next->next = head->next;
        head->next = h->next;
        h->next = NULL;
        rawReorderList(head->next->next);
    }
    void reorderList(ListNode* head) {
        rawReorderList(head);
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
