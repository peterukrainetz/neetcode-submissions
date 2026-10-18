class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        do
        {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while (slow != fast);

        int start = 0;
        while (start != slow)
        {
            start = nums[start];
            slow = nums[slow];
        }

        return slow;
    }
};
