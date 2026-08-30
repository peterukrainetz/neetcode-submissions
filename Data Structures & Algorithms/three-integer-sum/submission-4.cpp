class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;

        sort(nums.begin(), nums.end());

        int l = 0;
        int r = nums.size() - 1;

        for (int i = 0; i < (int)nums.size() - 2; i++)
        {
            if (i == 0 || nums[i] != nums[i - 1])
            {
                l = i + 1;
                r = nums.size() - 1;

                while (l < r)
                {
                    if (nums[i] + nums[l] + nums[r] == 0)
                    {
                        answer.push_back({nums[i], nums[l], nums[r]});

                        l++;
                        r--;

                        while (nums[l] == nums[l - 1] && l < r)
                            l++;

                        while (nums[r] == nums[r + 1] && l < r)
                            r--;
                    }
                    else if (nums[i] + nums[l] + nums[r] < 0)
                        l++;
                    else
                        r--;
                }
            }
        }

        return answer;
    }
};
