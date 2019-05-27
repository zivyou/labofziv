#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& barcodes) {
        if (barcodes.size() <= 1)
            return;
        for (int i=0; i<barcodes.size()-1; i++){
            if (i % 2 == 0){
                if (barcodes[i] > barcodes[i+1])
                    swap(barcodes[i], barcodes[i+1]);
            }else{
                if (barcodes[i] < barcodes[i+1])
                    swap(barcodes[i], barcodes[i+1]);
            }
        }
    }
};

int main(){
    Solution s;
    vector<int> input = {6,5,4,3,2,1};
    s.wiggleSort(input);
    for (auto v: input){
        cout<<v<<" ";
    }
    cout<<endl;
    return 0;
}