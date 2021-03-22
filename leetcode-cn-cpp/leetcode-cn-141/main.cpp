#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
class Solution {
public:
    bool hasCycle(ListNode *head) {
        vector<ListNode *> visited;
        ListNode* h = head;

        while (h){
            bool found = false;
            for (int i=0; i<visited.size(); i++){
                if (h == visited[i]){
                    found = true;
                    break;
                }
            }
            if (found){
                break;
            }else{
                h = h->next;
                visited.push_back(h);
            }
        }

        ListNode * newh = head;
        int re = 1;
        while (newh != h){
            newh = newh->next;
            re++;
        }

        return re;
    }
};
*/


class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head)
            return false;
        ListNode *slower = head;
        ListNode *quicker = head->next;

        while (slower && quicker && quicker->next){
            if (slower == quicker){
                return true;
            }
            slower = slower->next;
            quicker = quicker->next->next;
        }
        return false;
    }
};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
