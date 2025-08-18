class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProductAnswer = nums[0];
        int maxProduct = nums[0];
        int minProduct = nums[0];

        for(int i = 1; i<nums.size(); i++){
            if(nums[i]<0){
                swap(maxProduct, minProduct);
            }

            minProduct = min(nums[i], minProduct * nums[i]);
            maxProduct = max(nums[i], maxProduct * nums[i]);


            maxProductAnswer = max(maxProductAnswer, maxProduct);

        }

        return maxProductAnswer;
    }
};