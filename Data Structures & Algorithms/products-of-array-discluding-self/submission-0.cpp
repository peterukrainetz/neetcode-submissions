class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size(), 0);

        int total = 1;
        int zeroCount = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
                total *= nums[i];
            else
                zeroCount++;
        }

        if (zeroCount > 1)
            return answer;

        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] == 0)
                answer[j] = total;
            else
            {
                if (zeroCount == 1)
                    answer[j] = 0;
                else
                    answer[j] = total / nums[j];
            }
        }

        return answer;
    }
};
