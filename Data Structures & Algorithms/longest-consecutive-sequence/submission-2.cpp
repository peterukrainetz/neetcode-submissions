class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> table;

        if (nums.size() == 0)
            return 0;

        int sequenceSize = 0;
        int maxSize = 1;

        for (int i = 0; i < nums.size(); i++)
            table[nums[i]]++;
        
        for (int j = 0; j < nums.size(); j++)
        {
            sequenceSize = 0;
            int currNum = nums[j];

            if (!table.contains(currNum - 1))
            {
                while (table.contains(currNum))
                {
                    currNum++;
                    sequenceSize++;
                    maxSize = max(maxSize, sequenceSize);
                }
            }
        }

        return maxSize;
    }
};
