class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;

        vector<int> prefix(height.size(), 0);
        vector<int> suffix(height.size(), 0);

        int maxHeight = height[0];

        for (int i = 1; i < height.size(); i++)
        {
            prefix[i] = maxHeight;

            maxHeight = max(maxHeight, height[i]);
        }

        maxHeight = height[height.size() - 1];

        for (int j = height.size() - 2; j >= 0; j--)
        {
            suffix[j] = maxHeight;

            maxHeight = max(maxHeight, height[j]);
        }

        int sum = 0;

        for (int k = 0; k < height.size(); k++)
        {
            if (height[k] < prefix[k] && height[k] < suffix[k])
                sum += min(prefix[k], suffix[k]) - height[k];
        }

        return sum;
    }
};
