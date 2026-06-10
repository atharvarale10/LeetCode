class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;

        int currMax = 0, maxSum = nums[0];
        int currMin = 0, minSum = nums[0];

        for (int num : nums) {
            totalSum += num;

            // Kadane for maximum subarray
            currMax = max(num, currMax + num);
            maxSum = max(maxSum, currMax);

            // Kadane for minimum subarray
            currMin = min(num, currMin + num);
            minSum = min(minSum, currMin);
        }

        // All elements are negative
        if (maxSum < 0)
            return maxSum;

        return max(maxSum, totalSum - minSum);
    }
};