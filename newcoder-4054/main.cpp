#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

class people{
public:
    string name;
    int year;
    int month;
    int day;
public:
    bool elder(people a){
        if (this->year < a.year) return true;
        else if (this->year > a.year) return false;
        else{}
        if (this->month < a.month) return true;
        else if (this->month > a.month) return false;
        else{}
        if (this->day < a.day) return true;
        else if (this->day > a.day) return false;
        else {}
        return false;
    }

    bool normal(){
        //2014.9.6
        if (this->year > 2014) return false;
        if (this->year == 2014){
            if (this->month > 9) return false;
            if (this->month == 9)
                if (this->day > 6) return false;
        }

        if (this->year < 2014-200) return false;
        if (this->year == 2014-200){
            if (this->month < 9) return false;
            if (this->month == 9)
                if (this->day < 6) return false;
        }
        return true;
    }

    void init(string n, int y, int m, int d){
        name = n;
        year = y;
        month = m;
        day = d;
    }
};


int main() {
    int N;
    cin>>N;
    int i = 0;
    people oldest, youngest;
    oldest.init("oldest man", 2014, 9, 6);
    youngest.init("youngest man", 2014-200, 9, 6);
    int cnt = 0;
    while (i<N){
        string name;
        int year, month, day;
        string date;
        cin>>name;
        scanf("%4d/%2d/%2d", &year, &month, &day);
        people p;
        p.init(name, year, month, day);
        if (p.normal()){
            if (p.elder(oldest)){
                oldest.init(p.name, p.year, p.month, p.day);
            }

            if (!p.elder(youngest)){
                youngest.init(p.name, p.year, p.month, p.day);
            }
            cnt++;
        }
        i++;
    }
    cout<<cnt<<" "<<oldest.name<<" "<<youngest.name<<endl;
    return 0;
}