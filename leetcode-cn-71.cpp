#include <iostream>
#include <string>

using namespace std;

struct Node {
    string name;
    struct Node *pre;
    struct Node *next;
    Node (string a, Node *b, Node *c){
        name = a;
        pre = b;
        next = c;
    }
};

class Solution {
public:
    string simplifyPath(string path) {
        while (path.find("//") != -1){
            int pos = path.find("//");
            path = path.replace(pos, 2, "/");
        }
        //cout<<path<<endl;
        Node * head = new Node("head", NULL, NULL);
        head->next = new Node("/", NULL, NULL);
        head->next->pre = head;
        Node * tail = head->next;
        int begin = 0; int end = 1;
        while (end < path.length()){
            if (path[begin] == '/' && path[end] == '/'){
                //add new node
                tail->next = new Node(path.substr(begin+1, end-begin-1), NULL, NULL);
                tail->next->pre = tail;
                tail = tail->next;
                begin = end;
                end = end + 1;
            }else{
                end++;
            }
        }

        if (path[path.length()-1] != '/'){
            tail->next = new Node(path.substr(begin+1, path.length()-begin-1), NULL, NULL);
            tail->next->pre = tail;
            tail = tail->next;
        }

        Node *h = head;
        // while (h != NULL){
        //     cout<<h->name<<" ";
        //     h = h->next;
        // }
        // cout<<endl;
        h = head;
        while (h != NULL){
            //cout<<"h->name="<<h->name<<endl;
            if (h->name == "."){
                if (h->next != NULL){
                    Node * p = h->pre;
                    Node * n = h->next;
                    p->next = n;
                    n->pre = p;
                    delete h;
                    h = n;
                }else{
                    Node *p = h->pre;
                    p->next = NULL;
                    delete h;
                    h = NULL;
                }
            }else
            if (h->name == ".."){
                if (h->next != NULL){
                    Node * p = h->pre;
                    Node * pp = p->pre;
                    if (p == head){
                        h->next->pre = p;
                        p->next = h->next;
                        delete h;
                        h = head->next;
                    }else{
                        pp->next = h->next;
                        h->next->pre = pp;
                        delete p;
                        delete h;
                        h = pp->next;
                    }
                }else{
                    Node * p = h->pre;
                    Node * pp = p->pre;
                    if (p == head){
                        delete h;
                        return "/";
                    }else{
                        pp->next = NULL;
                        delete h;
                        delete p;
                        h = NULL;
                    }
                }
            }else
            h = h->next;
        }

        h = head->next;
        if (h == NULL)
            return "/";
        string re;
        re = "";
        while (h != NULL){
            if (h->name != "/" && h->pre->name != "/")
                re = re + "/";
            re = re+h->name;
            h = h->next;
        }
        
        return re;
    }
};

int main(){
    Solution s;
    cout<<s.simplifyPath("/.././tqCEe/..///L/../../././//../../../JGF/../ZUFaY/.///wMzVK//")<<endl;
    return 0;
}