#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool judge(vector<int> v){
        for (int i=0; i<v.size()-1; i++){
            if (v[i] == v[i+1])
                return false;
        }

        return true;
    }

    vector<int> dfs(vector<int>& barcodes, vector<int>& tmpRe, int *used){
        if (tmpRe.size() == barcodes.size()){
            return tmpRe;
        }

        //cout<<"tmpRe.size()="<<tmpRe.size()<<endl;
        for (int i=0; i<barcodes.size(); i++){
            if (used[i])
                continue;
            
            if (tmpRe.size() != 0){
                if (tmpRe[tmpRe.size()-1] == barcodes[i] && !used[i])
                    continue;
            }
            
            /*
            if (i-1>=0 && barcodes[i] == barcodes[i-1] && used[i-1])
                continue;
                */

            tmpRe.push_back(barcodes[i]);
            used[i] = 1;
            vector<int> re = dfs(barcodes, tmpRe, used);
            if (re.size())
                return re;
            tmpRe.pop_back();
            used[i] = 0;
        }


        return vector<int>();
    }

    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        sort(barcodes.begin(), barcodes.end());
        int used[barcodes.size()];
        for (int i=0; i<barcodes.size(); i++){
            used[i] = 0;
        }

        vector<int> tmpRe;
        return dfs(barcodes, tmpRe, used);
    }
};

int main(){
    Solution s;
    vector<int> output ;
    vector<int> input = {51,83,51,40,51,40,51,40,83,40,83,83,51,40,40,51,51,51,40,40,40,83,51,51,40,51,51,40,40,51,51,40,51,51,51,40,83,40,40,83,51,51,51,40,40,40,51,51,83,83,40,51,51,40,40,40,51,40,83,40,83,40,83,40,51,51,40,51,51,51,51,40,51,83,51,83,51,51,40,51,40,51,40,51,40,40,51,51,51,40,51,83,51,51,51,40,51,51,40,40};
    //vector<int> input = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
    cout<<"input.size()="<<input.size()<<endl;
    output = s.rearrangeBarcodes(input);
    for (auto v: output){
        cout<<v<<" ";
    }
    cout<<endl;
    return 0;
}