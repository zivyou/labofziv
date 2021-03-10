#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int N;
  std::priority_queue<unsigned  int, std::vector<unsigned int>, std::greater<unsigned int>> pq;
  int cnt = 0; int d;
  cin>>N;
  for(int i=0;i<N;i++){
    int x;
    cin>>x;
    pq.push(x);
  };
  if (pq.size() <= 0) {
    std::cout<<"0"<<std::endl;
    return 0;
  }

  unsigned int result = 0;
  while(!pq.empty()&&pq.size()!=1){
    int x=pq.top();
    pq.pop();
    int y=pq.top();
    pq.pop();
    result=result+x+y;
    pq.push(x+y);
  };
  /*
  while (!pq.empty() && pq.size() != 1 ) {
    unsigned int r1 = pq.top(); pq.pop();
    unsigned int r2 = pq.top(); pq.pop();
    result += r1 + r2;
    pq.push(result);
  }
   */
  cout<<result<<endl;

  return 0;
}
