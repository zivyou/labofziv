#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> result;
        if (matrix.size() <= 0) 
            return result;
        if (matrix.size() == 1)
            return matrix[0];
        if (matrix[0].size() == 1){
            for (int i=0; i<matrix.size(); i++)
                result.push_back(matrix[i][0]);
            return result;
        }
        vector<vector<int> > map(matrix.size(), vector<int>(matrix[0].size(), 0));
        int width = matrix[0].size()-1;
        int height = matrix.size()-1;
        int k=0;
        int w=width+1; int h=height+1;
        while (1){
            //cout<<"k="<<k<<endl;
            switch(k%4){
                case 0:
                //top
                    for (int i=0; i<w; i++){
                        if (!map[k/4][k/4+i]){
                            result.push_back(matrix[k/4][k/4+i]);
                            map[k/4][k/4+i] = 1;
                        }
                    }
                    k++;
                    break;
                case 1:
                //right
                    for (int i=0; i<h; i++){
                        if (!map[i+k/4][width-k/4]){
                            result.push_back(matrix[i+k/4][width-k/4]);
                            map[i+k/4][width-k/4] = 1;
                        }
                    }
                    k++;
                    break;
                case 2:
                //bottom
                    for (int i=w-1; i>=0; i--){
                        //cout<<height-k/4<<", "<<i+k/4<<endl;
                        if (!map[height-k/4][i+k/4]){
                            result.push_back(matrix[height-k/4][i+k/4]);
                            map[height-k/4][i+k/4] = 1;
                        }
                    }
                    k++;
                    break;
                case 3:
                //left
                    for (int i=h-1; i>=0; i--){
                        if (!map[i+k/4][k/4]){
                            result.push_back(matrix[i+k/4][k/4]);
                            map[i+k/4][k/4] = 1;
                        }
                    }
                    k++;
                    w = w - 2;
                    h = h - 2;
                    break;
                default:
                    break;
            }
            if (w < 0 || h < 0)
                break;
            if (k >= (width+1)*(height+1)){
                break;
            }

        }
                    
        return result;
    }
};

int main(){
    int a[2][5] ={{1,2,3,4, 5}, {6,7,8, 9, 10}};
    vector<vector<int> > matrix;
    for (int i=0; i<2; i++){
        vector<int> v(a[i], a[i]+5);
        matrix.push_back(v);
    }

    for (int i=0; i<2; i++){
        for (int j=0; j<5; j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    Solution s;
    vector<int> result = s.spiralOrder(matrix);
    for (int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}