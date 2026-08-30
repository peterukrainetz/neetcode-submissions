class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;

        int maxSize = 0;

        while (l < r)
        {
            int size = (r - l) * min(heights[l], heights[r]);
            maxSize = max(maxSize, size);

            if (heights[r] < heights[l])
                r--;
            else if (heights[l] < heights[r])
                l++;
            else
            {
                l++;
                r--;
            }
        }

        return maxSize;
    }
};
