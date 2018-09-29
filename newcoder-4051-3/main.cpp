#include <iostream>
#include <string.h>

using namespace std;

struct node{
    string addr;
    int data;
    string next_addr;
    struct node * next;

    node(string a, int b, string c, void *p){
        addr = a;
        data = b;
        next_addr = c;
        next = (node *)p;
    }
};

void dump(node *head){
    //cout<<"==============="<<endl;
    while (head){
        cout<<head->addr<<' '<<head->data<<" "<<head->next_addr<<endl;
        head = head->next;
    }
    //cout<<"----------------"<<endl;
}

void resort(node *head, string first_addr){
    node *n = head;
    if (head->next == NULL) return;
    if (head->addr == first_addr) return;
    if (first_addr == "-1") return;

    while (n->next){
        if (n->next->addr == first_addr) {
            break;
        }
        n = n->next;
    }
    node *first_node = head->next;
    node * t = n->next;
    n->next = n->next->next;
    t->next = head->next;
    head->next = t;
    //dump(head);
    if (head->next)
        resort(head->next, head->next->next_addr);
}



void raw_reverse(node *pre_node, node *start, node *end, node *next_node){
    if (start == end) return;
    node *n1 = start;

    node *n2 = n1->next;
    if (!n2) return;




    while (n1 != end){
        node *n3 = n1;

        n1 = n2;
        n2 = n2->next;
        n1->next = n3;
        start->next = n2;
    }


    pre_node->next = end;
    start->next = next_node;

}

void reverse(node *head, int cnt){
    node *data_node = head->next;
    int i = 1;
    node *data_tail = data_node;
    while (i<cnt && data_tail){
        data_tail = data_tail->next;
        i++;
    }
    if (!data_tail)
        return;
    if (i == cnt){
        //cout<<"data_node->data="<<data_node->data<<"data_tail->data=="<<data_tail->data<<endl;
        raw_reverse(head, data_node, data_tail, data_tail->next);
        //cout<<"data_tail->data == "<<data_tail->data<<endl;
        reverse(data_node, cnt);
    }


}

void re_addr(node *head){
    node *data_node = head->next;
    while (data_node->next){
        data_node->next_addr = data_node->next->addr;
        data_node = data_node->next;
    }
    data_node->next_addr = "-1";
}

int main() {
    node * link_head = new node("", 0, "", NULL);
    string first_addr;
    int N;
    int cnt;
    int i = 0;
    cin>>first_addr>>N>>cnt;
    node *tail = link_head;
    while (i < N){
        string addr;
        int data;
        string next_addr;
        cin>>addr>>data>>next_addr;
        node * new_node = new node(addr, data, next_addr, NULL);
        tail->next = new_node;
        tail = tail->next;
        i++;
    }
    //dump(link_head->next);
    resort(link_head, first_addr);

    reverse(link_head, cnt);

    re_addr(link_head);
    dump(link_head->next);
    while(link_head){
        node * t = link_head;
        link_head = link_head->next;
        delete t;

    }
    return 0;
}
/*
00100 2 2
 12309 2 -1
 00100 1 12309

 */