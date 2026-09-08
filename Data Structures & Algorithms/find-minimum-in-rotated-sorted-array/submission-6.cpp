class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (nums[r] < nums[mid])
                l = mid + 1;
            else
            {
                if (mid - 1 < 0 || nums[mid - 1] > nums[mid] || mid == 0 || mid == nums.size() - 1)
                    return nums[mid];
                else
                    r = mid - 1;
            }
        }

        return 0;
    }
};
