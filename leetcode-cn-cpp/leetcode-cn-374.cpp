// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 0; int r = n;

        while (l < r) {
            int mid = l / 2 + r / 2;
            if (l % 2 && r % 2) mid++;
            int tmp = guess(mid);
            if (tmp == 1) {
                l = mid+1;
            } else if (tmp == -1) {
                r = mid - 1;
            } else {
                return mid;
            }
        }
        return 0;
    }
};

int main() {

    return 0;
}