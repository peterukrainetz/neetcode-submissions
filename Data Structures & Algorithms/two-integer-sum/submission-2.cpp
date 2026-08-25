class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> uniqueNums;

        for (int i = 0; i < nums.size(); i++)
        {
            int diff = target - nums[i];

            if (uniqueNums.contains(diff))
                return {uniqueNums[diff], i};
            else
                uniqueNums[nums[i]] = i;
        }

        return {-1, -1};
    }
};
