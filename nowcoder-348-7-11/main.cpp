#include <iostream>
#include <queue>

using namespace std;

class Family {
public:
  int s;
  int a;

  Family(int arg1, int arg2) {
    s = arg1; a = arg2;
  }
};

class Compare {
public:
  int max;
  Compare() {
    max = INT_MIN;
  }
  Compare(int arg) {
    max = arg;
  }
  bool operator() (const Family&lhs, const Family&rhs) const {
    if (max == INT_MIN) {
      return (2*rhs.s+rhs.a) > (2*lhs.s+lhs.a);
    }
    if (lhs.s <= max && rhs.s <= max) return lhs.a < rhs.a;
    if (lhs.s >= max && rhs.s <= max) {
      return ((lhs.s-max)*2+lhs.a) > (rhs.a);
    }
    if (lhs.s <= max && rhs.s >= max) {
      return (lhs.a > ((rhs.s-max)*2+rhs.a));
    }
    return ((lhs.s-max)*2+lhs.a) > ((rhs.s-max)*2+rhs.a);
  }
};

int main() {
  std::priority_queue<Family, std::vector<Family>, Compare> pq;
  std::cout << "Hello, World!" << std::endl;
  int N;
  cin>>N;
  int A[100000+3];
  int S[100000+3];
  int i=0;
  while (i < N) {
    cin>>S[i];
    i++;
  }
  i=0;
  while (i < N) {
    cin>>A[i];
    i++;
  }
  i=0;
  while (i<N) {
    pq.push(Family(S[i], A[i]));
    i++;
  }
  int farest = pq.top().s;
  std::cout<<"farest: "<<farest<<std::endl;
  int max = farest;
  i=0;
  int result = 0;
  while (i < N) {
    Family f = pq.top();
    pq.pop();
    if (f.s < max) {
      result += f.a;
    } else if (f.s == max){
      result += (f.s)*2 + f.a;
    } else {
      result = result - (max)*2 + f.s*2 + f.a;
    }
    cout<<result<<endl;
    i++;
  }

  return 0;
}
