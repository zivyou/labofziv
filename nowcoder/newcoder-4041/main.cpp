/*https://www.nowcoder.com/pat/6/problem/4041*/
#include <iostream>

using namespace std;

int L;
int H;

struct student{
  int d; //得
  int c;  //才
  int sid; //准考证号
  int pass; // 0:d>H && c>H（才德全尽）;  1:d>H && L<c<H（德胜才）; 2:L< d <H && L<c<H && c<d(才德兼亡但尚有德胜才); 3: L < d < H && L<c<H && c>=d 4: other
  struct student *next;
};



int higher(student a, student b){
    if (a.pass < b.pass) return 1;
    else if (a.pass > b.pass) return 0;
    else {
        if (a.pass == 0){
            if (a.d > b.d)
                return 1;
            else if (a.d == b.d)
                return a.sid < b.sid ? 1 :0;
            else
                return 0;
        }
        if (a.d + a.c > b.d + b.c)
            return 1;
        else if (a.d + a.c == b.d + b.c){
            if (a.d > b.d) return 1;
            else if (a.d < b.d) return 0;
            else{
                if (a.sid < b.sid)
                    return 1;
                else
                    return 0;
            }
        }else
            return 0;
    }
}

int main()
{
    int passed = 0;
    int N;
    cin>>N>>L>>H;
    student *list_head = NULL;
    student *list_tail = NULL;
    int i = 0;
    while (i++<N){
        student *st = new student;
        st->next = NULL;
        cin >> st->sid >> st->d >>st->c;
        if (st->d < L && st->c < L){
            delete st;
            continue;
        }
        if (st->d >= H && st->c >= H)
            st->pass = 0;
        else if (st->d >= H && st->c >= L && st->c <= H)
            st->pass = 1;
        else if (st->d >= L && st->c >= L && st->d < H && st->c < H && st->d >= st->c)
            st->pass = 2;
        else if (st->d < H && st->d >= L && st->c < H && st->c >= L)
            st->pass = 3;
        else if (st->d < H && st->d >= L && st->c >= H)
            st->pass = 4;
        else
            st->pass = 5;
        if (st->pass <= 4){
            passed++;
            if (list_head == list_tail){
                if (list_head == NULL)
                    list_head = list_tail = st;
                else{
                    if (higher(*list_head, *st)){
                        list_head->next = st;
                        list_tail = st;
                    }else{
                        st->next = list_head;
                        list_head = st;
                    }
                }
            }else{
                student *t = list_head;
                if (higher(*st, *list_head)){
                    st->next = list_head;
                    list_head = st;
                }else if (!higher(*st, *list_tail)){
                    list_tail->next = st;
                    list_tail = st;
                }else{
                    while (t->next){
                        if (higher(*t, *st) && higher(*st, *(t->next))){
                            break;
                        }else
                            t = t->next;
                    }
                    st->next = t->next;
                    t->next = st;
                }
            }
        }else{
            delete st;
        }
    }
    cout<<passed<<endl;
    student *t = list_head;
    while (t){
        student *tmp = t;
        cout<<t->sid<<" "<<t->d<<" "<<t->c<<endl;
        t=t->next;
        delete tmp;
    }
    return 0;
}
