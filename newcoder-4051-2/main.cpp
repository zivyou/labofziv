#include <iostream>
using namespace std;
struct node{
    int pre;
    int data;
    int next;
};

void swap(char &a, char &b){
    char c = b;
    b = a;
    a = c;
}

void dump(node *link, int head){
    cout<<"===================="<<endl;
    int addr = head;
    while(addr != -1){
        cout<<addr << " "<<link[addr].data<<" "<<link[addr].next<<endl;
        addr = link[addr].next;
    }
    cout<<"--------------------"<<endl;
}

static int true_head;
void raw_reverse(node *link, int head, int tail){

    int h = head;
    int t = tail;
    if ( head == tail) return;

    if (link[head].pre != -1) {
        link[link[head].pre].next = tail;
    }else {
        true_head = tail;
        link[tail].pre = -1;
    }

    while (t!=h){
        if (t == head)
            link[t].next = link[tail].next;
        link[t].next = link[t].pre;
        t = link[t].pre;
    }



    dump(link, true_head);
}

void no_reverse(void){};



int main() {
    node *link = new node[100000];
    int head;
    int N, cnt;
    string s;
    cin>>s>>N>>cnt;
    head = std::stoi(s);
    int i = 0;
    int addr, next;
    int data;
    int raw_pre = -1;
    true_head = head;
    while (i<N){
        cout<<"i="<<i<<endl;
        cin>>s>>data>>next;
        addr = std::stoi(s);
        link[addr].data = data;
        link[addr].next = next;
        i++;
    }
    addr = head;
    while (addr != -1){
        link[addr].pre = raw_pre;
        raw_pre = addr;
        addr = link[addr].next;
    }
    dump(link, true_head);


    i = 0;
    int h = head;
    int t = head;
    while (1) {
        int j = 0;
        t = h;
        while (j < cnt  && t != -1) {
            t = link[t].next;
            j++;
        }

        if (t == -1 && j < cnt )
            break;
        if (j == cnt ) {
            raw_reverse(link, h, link[t].pre);
        }
        h = t;
    }


    dump(link, true_head);
    std::cout << "Hello, World!" << std::endl;
    delete[] link;
    return 0;
}