#ifndef __MY_LIB__
#define __MY_LIB__

#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

template<typename T>
vector<vector<T> > matrixToVector(T *matrix, int height, int width);

template<typename T>
T test(T a, T b){
    return a+b;
}

template<typename T>
vector<vector<T> > matrixToVector(T *matrix, int height, int width){
    int n = height*width;
    vector<vector<T> > re;
    if (n <= 0 || width <= 0 || height <= 0)
        return re;

    for (int i=0; i<height; i++){
        vector<T > v;
        for (int j=0; j<width; j++)
            v.push_back(matrix[i*width+j]);

        re.push_back(v);
    }

    return re;
}

ListNode * vectorToLink(vector<int> v);

#endif // __MY_LIB__
