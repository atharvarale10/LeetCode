class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;

        long long start = 1, end = x, ans = 0;

        while (start <= end) {
            long long mid = start + (end - start) / 2;

            if (mid * mid == x) {
                return mid;
            } else if (mid * mid < x) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
};
