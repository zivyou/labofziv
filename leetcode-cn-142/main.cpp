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
    ListNode * detectCycle(ListNode *head) {
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
                return h;
            }else{
                visited.push_back(h);
                h = h->next;
            }
        }
        return NULL;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
