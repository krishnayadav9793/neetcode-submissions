class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sum = 1, count = 0;
        for (auto& i : nums) {
            if (i)
                sum *= i;
            else
                count++;
            // i=0;
        }
        if (count >= 2) {
            for (auto& i : nums) {
               i=0;
            }
            return nums;
        } else if (count == 1) {
            for (auto& i : nums) {
                if (i==0) i=sum;
                else i=0;
            }
            return nums;
        }
        for (auto& i : nums) {
            i=sum/i;
        }
        return nums;
    }
};
