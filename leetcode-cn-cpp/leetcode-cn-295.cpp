#include <algorithm>
#include <cstdio>
#include <functional>
#include <vector>

using namespace std;

class MedianFinder {
private:
    int count = 0;
    vector<int> datas;
public:
    MedianFinder() {

    }

    void addNum(int num) {
        if (datas.empty()) {
            datas.push_back(num);
            count++;
            return;
        }
        auto it = datas.begin();
        while (it != datas.end() && *it < num) {
            it++;
        }
        datas.insert(it, num);
        count++;
    }

    double findMedian() {
        if (count % 2 == 0) {
            int left = count/2-1; int right = left+1;
            return (datas[left]*1.0/2)+(datas[right]*1.0/2);
        } else {
            int pos = count / 2;
            return datas[pos];
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {

    MedianFinder medianFinder;
    medianFinder.addNum(10);
    printf("%f\n", medianFinder.findMedian());
    medianFinder.addNum(6);
    printf("%f\n", medianFinder.findMedian());
    medianFinder.addNum(2);
    printf("%f\n", medianFinder.findMedian());

    // MedianFinder medianFinder;
    // medianFinder.addNum(1);
    // printf("%f\n", medianFinder.findMedian());
    // medianFinder.addNum(2);
    // printf("%f\n", medianFinder.findMedian());
    // medianFinder.addNum(3);
    // printf("%f\n", medianFinder.findMedian());
}