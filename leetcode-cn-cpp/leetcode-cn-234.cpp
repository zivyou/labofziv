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
    bool isPalindrome(ListNode* head) {
        ListNode* h = head;
        vector<int> v;
        while (h){
            v.push_back(h->val);
            h = h->next;
        }

        int j = v.size()-1;
        int i = 0;
        while (i < j){
            if (v[i] != v[j])
                return false;
            i++; j--;
        }

        return true;
    }
};

int main(){

    return 0;
}