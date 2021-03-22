#include <unordered_set>
#include <iostream>
#include <vector>
#include <queue>

using namespace  std;


static std::unordered_set<int> mySelected;
static std::unordered_set<int> computerSelected;

struct Node {
  int a, b, value;

  Node(int i1, int i2, int i3) {
    a = i1; b=i2; value = i3;
  }

  bool include(int i) {
    return a == i || b == i;
  }

  bool operator == (Node& n) {
    if (this->a == n.b && this->b == n.a) return true;
    if (this->a==n.a && this->b == n.b) return true;
    return false;
  }
};

class MyCompare {
public:
  MyCompare() {}
  bool operator()(const Node& lhs, const Node& rhs) const {
    return lhs.value < rhs.value;
  }

};

bool compare(const Node& l, const Node& r) {
  return l.value - r.value;
}

int main() {
  int N;
  cin>>N;
  int** value = new int*[N+1];
  int i=0;
  while (i<N+1) {
    value[i] = new int[N+1];
    i++;
  }
 
  MyCompare mc;
  std::vector<Node> pq;
  for (i = 1; i<N+1; i++) {
    for (int j = i+1; j<N+1; j++) {
      int v; cin>>v;
      pq.push_back(Node(i,j, v));
      value[i][j] = v;
      value[j][i] = v;
    }
  }

  std::make_heap(pq.begin(), pq.end(), mc); 
  
  for (auto n : pq) {
    std::cout<<n.a<<", "<<n.b<<", "<<n.value<<endl;
  }
 
  
  while (!pq.empty()) {
    Node node = pq[0]; 
    cout<<"heap top: "<<node.value<<endl;
    pq.erase(pq.begin());
    if (mySelected.find(node.b) != mySelected.end()) {
      mySelected.insert(node.a);
      
    }
    mySelected.insert(node.b);
    computerSelected.insert(node.a);
    for (int k=0; k<pq.size(); k++) {
      if (pq[k] == node || pq[k].include(node.a)) {
        pq.erase(pq.begin()+k);
        k--;
      }
    }
    std::make_heap(pq.begin(), pq.end(),mc);
  }
  
  cout<<"my selected: ";
  for (auto m : mySelected) {
    cout<<m<<" ";
  }

  cout<<endl;


  cout<<"computer selected: ";
  for (auto m : computerSelected) {
    cout<<m<<" ";
  }
  cout<<endl;

  i = 0; int j=0;
  int myMax = 0;
  for (auto ii = mySelected.begin(); ii != mySelected.end(); ii++) {
    for (auto jj = mySelected.begin(); jj != ii; jj++) {
      if (value[*ii][*jj] > myMax) myMax = value[*ii][*jj];
    }
  }

  int cMax = 0;
  for (auto ii = computerSelected.begin(); ii != computerSelected.end(); ii++) {
    for (auto jj = computerSelected.begin(); jj != ii; jj++) {
      if (value[*ii][*jj] > cMax) cMax = value[*ii][*jj];
    }
  }

  cout<<"myMax: "<<myMax<<", cMax: "<<cMax<<endl;
  if (myMax > cMax) {
    cout<<1<<endl;
    cout<<myMax<<endl;
  } else {
    cout<<0<<endl;
  }
  i = 0;
  while (i < N+1) {
    delete[] value[i];
    i++;
  }
  return 0;
}

/*
 *
 4
256032391 44492372 820892564
72613801 404834202
13297961
*/
