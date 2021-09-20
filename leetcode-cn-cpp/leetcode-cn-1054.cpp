#include <iostream>
#include <vector>
#include <map>

using namespace std;
/**
 * 在一个仓库里，有一排条形码，其中第 i 个条形码为 barcodes[i]。

请你重新排列这些条形码，使其中两个相邻的条形码 不能 相等。 你可以返回任何满足该要求的答案，此题保证存在答案。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/distant-barcodes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/**
 * 全排列。
 * 每次从barcodes中挑选一个未被使用过的元素，保证这个元素是和当前的尝试结果tmpRe的末尾不同就行。
 * 理论上来说，就是一个暴力尝试的过程。
 * 最坏的情况下，是最后一轮尝试才找到正确结果，也就是说，前面已经进行过n轮。而每轮都需要复杂度为（n-1）*(n-2)*...*1，所以总的复杂度看起来会是n!
 * 这个和数学中的全排列耗时是一致的。
 * 这样的方法肯定会超时。
 */
class Solution2 {
public:
  void process(vector<int> re, int n, vector<int>& data, map<int, int>& counts, vector<vector<int>>& results) {
    if (n <= 0) {
      results.push_back(re);
      return;
    };
    cout<<"n ================>"<<n<<endl;
    for (int j=0; j<data.size(); j++) {
      if (counts[data[j]] > 0) {
        if ((re.size() > 0 && re.back()!=data[j]) || re.size()==0) {
          // cout<<"elem ============>"<<data[j]<<endl;
          counts[data[j]]--;
          re.push_back(data[j]);
          process(re, n-1, data, counts, results);
          if (results.size() > 0) return;
          re.pop_back();
          counts[data[j]]++;
        }
      }
    }
  }

  vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    sort(barcodes.begin(), barcodes.end());
    map<int, int> counts;
    vector<int> elements;
    // 先数一遍barcodes中各种元素的数量
    for (auto elem:barcodes) {
      if (counts.find(elem) == counts.end()) {
        counts[elem] = 1;
        // 记录所有的数字
        elements.push_back(elem);
      } else {
        counts[elem]++;
      }
    }

    vector<int> re;
    vector<vector<int>> results;
    process(re, barcodes.size(), elements, counts, results);
    return results[0];
  }
};


/**
 * dfs暴力搜索
 * 如果
 */
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
            dfs(barcodes, tmpRe, used);
            if (tmpRe.size() == barcodes.size()){
              return tmpRe;
            }
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
    // vector<int> input = {51,83,51,40,51,40,51,40,83,40,83,83,51,40,40,51,51,51,40,40,40,83,51,51,40,51,51,40,40,51,51,40,51,51,51,40,83,40,40,83,51,51,51,40,40,40,51,51,83,83,40,51,51,40,40,40,51,40,83,40,83,40,83,40,51,51,40,51,51,51,51,40,51,83,51,83,51,51,40,51,40,51,40,51,40,40,51,51,51,40,51,83,51,51,51,40,51,51,40,40};
    // vector<int> input = {37,37,37,52,52,52,52,52,37,37,16,37,52,52,37,37,37,52,52,16,37,52,52,52,16,52,52,37,37,52,37,37,52,16,52,52,37,52,37,52,52,16,52,37,52,37,37,52,52,52,52,37,37,52,52,16,52,37,52,37,52,52,16,52,52,37,52,52,37,52,37,16,37,16,52,37,16,16,16,52,37,16,52,37,52,16,37,37,37,52,37,52,52,16,52,52,37,37,52,37};
    vector<int> input = {2, 2, 2, 1, 5};
    cout<<"input.size()="<<input.size()<<endl;
    output = s.rearrangeBarcodes(input);
    for (auto v: output){
        cout<<v<<" ";
    }
    cout<<endl;
    return 0;
}