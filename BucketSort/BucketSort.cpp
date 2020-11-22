#include <iostream>
#include <vector>

using namespace std;

class  Solution {
private:
  int getNum(int d, int pos) {
    int i=1;
    while (d >= 10 && i <= pos) {
      if (i == pos) return d % 10;
      d = d / 10;
      i++;
    }
    if (i == pos) return d % 10;
    return 0;
  }
  void rawBucketSort(vector<int>& data, int numWidth) {
    vector<int> backup(data);
    for (int i=1; i<=numWidth; i++) {
      vector<int> count(10+1);

      for (int j=0; j<data.size(); j++) {
        int t = getNum(data[j], i);
        count[t]++;
      }


      for (int j=1; j<=9; j++) {
        count[j] = count[j] + count[j-1];
      }

      for (int j=data.size()-1; j>=0; j--) {
        int t = getNum(data[j], i);
        backup[count[t]-1] = data[j];
        count[t]--;
      }
      data = backup;
    }
  }

public:
  void bucketSort(vector<int>& data) {
    if (data.size() <= 1) return;
    int max = data[0];
    for (auto n : data) {
      if (n > max) max = n;
    }

    int bitWidth  = 1;
    while (max > 10) {
      bitWidth++;
      max = max / 10;
    }
    return rawBucketSort(data, bitWidth);
  }

  int test(int a, int b) {
    return getNum(a, b);
  }
};

int main () {
  Solution s;

  vector<int> data;
  int N; int i=0;
  int n;
  cin>>N;
  while (i++ < N) {
    cin>>n;
    data.push_back(n);
  }

  s.bucketSort(data);
  for (auto m : data) {
    cout<<m<<" ";
  }
  cout<<endl;
  return 0;
}