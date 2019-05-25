#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Solution {
public:
    bool rawVerify(vector<int>& preorder, int begin, int end, int min, int max){
        if (end - begin < 1)
            return true;

        int root = preorder[begin];
        if (root < min || root > max) return false;
        int right = end+1;
        for (int i=begin+1; i <= end; i++){
            if (preorder[i] < root)
                continue;
            else{
                right = i;
                break;
            }
        }

        for (int i=right; i<= end; i++){
            if (preorder[i] <= root)
                return false;
        }
        return rawVerify(preorder, begin+1, right-1, min, root) && rawVerify(preorder, right, end, root, max);
    }
    bool verifyPreorder(vector<int>& preorder) {
        return rawVerify(preorder, 0, preorder.size()-1, INT_MIN, INT_MAX);
    }
};

int main(){
    Solution s;
    vector<int> v;
    ifstream fin("input.txt");
    string str;
    while (fin>>str){
        v.push_back(std::stoi(str));
    }
    fin.close();

    for (int i=0; i<v.size()-1; i++){
        if (v[i] <= v[i+1]){
            cout<<"v["<<i<<"]="<<v[i]<<endl;
            cout<<" test failed!!!!..."<<endl;
            break;
        }
    }
    cout<<s.verifyPreorder(v)<<endl;
    return 0;
}