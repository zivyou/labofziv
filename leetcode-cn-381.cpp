#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
private:
  ListNode* myHead;
  int length;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
      myHead = new ListNode(-1);
      myHead->next = head;
      ListNode* t = myHead;
      length = 0;
      while (t->next) {
        length++;
        t = t->next;
      }
      srand(time(NULL));
    }
    
    /** Returns a random node's value. */
    int getRandom() {
      int num = rand() % length;
      int i = 0;
      ListNode* t = myHead;
      while (i++ <= num) {
        t = t->next;
      }
      return t->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

int main() {
  return 0;
}