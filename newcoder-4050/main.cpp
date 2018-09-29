#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin>>s;
    int sign, e_sign;
    if (s[0] == '+')
        sign = 1;
    else
        sign = 0;
    if (s[0]=='-')
        cout<<s[0];
    s = s.substr(1, s.length());
    int e_pos = (int)s.find_first_of('E');
    if (s[e_pos+1] == '+')
        e_sign = 1;
    else if(s[e_pos+1] == '-')
        e_sign = 0;
    else
        e_sign = -1;
    string p1, p2;
    p1 = s.substr(0, e_pos);
    p2 = s.substr(e_pos+2, s.length());
    //cout<<p1<<"====="<<p2<<endl;
    int cnt = std::stoi(p2);
    if (e_sign == 0){
        int i = 0;
        cout<<"0.";
        for (i = 1;i<cnt;i++)
            cout<<'0';
        i=0;
        for (i=0;p1[i];i++)
            if (p1[i]!='.')
                cout<<p1[i];
        cout<<endl;
    }else if (e_sign == 1){
        int dot_pos = (int)p1.find_first_of('.');
        int i = 0;
        int p1_len = p1.length();
        for (i=0;i<dot_pos;i++)
            cout<<p1[i];
        if (dot_pos + cnt <= p1_len+1)
            for (i = dot_pos+1; p1[i]; i++){
                if (i==dot_pos+cnt+1)
                    cout<<'.';
                cout<<p1[i];
            }
        else
            for (i=dot_pos+1; i<cnt+dot_pos+1;i++){
                if (i-dot_pos == cnt+1)
                    cout<<".";
                if (i < p1_len)
                    cout<<p1[i];
                else
                    cout<<"0";
            }
        cout<<endl;

    }else
        return -1;

    return 0;
}