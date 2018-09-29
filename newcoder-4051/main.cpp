#include <iostream>
#include <string.h>
using namespace std;

struct node{
    struct node *pre;
    string addr;
    string data;
    string next_addr;
    struct node *next;

    node(void *pr, string a, string b, string c, void * p){
        pre = (struct node *)pr;
        addr = a;
        data = b;
        next_addr = c;
        next = (struct node *)p;
    }
};
void dump(node *h, node *t){
    cout<<"=========="<<endl;
    node *tt = h;
    while (tt){
        cout<<tt->data<<endl;
        tt=tt->next;

    }
    cout<<"---------------"<<endl;
}

void resort(node *&link_head, string head_addr){

    if (!link_head || !link_head->next)
        return;
    node * t = link_head;
    while (t){
        if (t->addr == head_addr)
            break;
        t = t->next;
    }

    t->pre->next = t->next;
    if(t->next)
        t->next->pre = t->pre;
    t->next = link_head->next;
    if (link_head->next)
        link_head->next->pre = t;
    link_head->next = t;
    t->pre = link_head;

    t=link_head->next;
    while (t){
        node *tt=t->next;
        int found = 0;
        while (tt){
            if (t->next_addr == tt->addr) {
                found = 1;
                break;
            }
            tt = tt->next;
        }

        if (found && t->next != tt){
            node *t_pre = tt->pre;
            node *t_next = tt->next;
            tt->next = t->next;
            t->next->pre = tt;
            t->next = tt;
            tt->pre = t;
            t_pre->next = t_next;
            if (t_next)
                t_next->pre = t_pre;
        }
        t = t->next;
    }
}
void raw_reverse(node *head, node *tail){
    node *t = tail;
    do{
        cout<<t->addr<<" "<<t->data<<" ";
        if (t->pre->addr != "NULL")
            cout<<t->pre->addr<<endl;
        else
            cout<<tail->next->addr<<endl;
        t = t->pre;
    } while (t!=head);
    cout<<t->addr<<" "<<t->data<<" "<<tail->next->addr<<endl;
}

void no_reverse(node *h, node *t){
    node *tt = h;
    while (tt!=t){
        cout<<tt->addr<<" "<<tt->data<<" "<<tt->next_addr<<endl;
        tt = tt->next;
    }
    cout<<tt->addr<<" "<<tt->data<<" "<<tt->next_addr<<endl;
}

void reverse(node *head, node *tail, int cnt){
    int i = 0;
    node *h = head;
    node *t = head;
    if (!head || !head->next)
        return;
    while (1) {
        while (i < cnt-1 && t) {
            i++;
            t = t->next;
        }
        if (!t){
            no_reverse(h->next, tail);
            break;
        }
        if (i == cnt-1) {
            raw_reverse(h, t);
            i = 0;
        }


        h = t;
    }
}

int main() {
    int  N, cnt;
    string head_addr;
    cin>>head_addr>>N>>cnt;
    int i = 0;
    node *link_head = new node(NULL, "NULL", "NULL", "NULL", NULL);
    string a, b, c;
    node *link_tail = link_head;
    node *pre = link_head;
    while (i<N){
        cin>>a>>b>>c;
        node *t_node = new node(pre, a, b, c, NULL);
        link_tail->next = t_node;
        t_node->pre = link_tail;
        link_tail = t_node;
        pre = link_tail;
        i++;
    }
    dump(link_head, link_tail);
    resort(link_head, head_addr);
    dump(link_head, link_tail);
    //reverse(link_head->next, link_tail, cnt);

    node *t = link_head;
    while(t){
        node *tt = t;
        t = t->next;
        delete tt;
    }
    return 0;
}

/**
       1 10 3
       10 10 -1
       9 9 10
       8 8 9
       7 7 8
       6 6 7
       5 5 6
       4 4 5
       3 3 4
       2 2 3
       1 1 2

  */