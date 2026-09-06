class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int maxLeft = 0;
        int maxRight = 0;

        int sum = 0;

        while (left < right)
        {
            maxLeft = max(maxLeft, height[left]);
            maxRight = max(maxRight, height[right]);

            if (height[left] > height[right])
            {
                sum += maxRight - height[right];
                right--;
            }
            else
            {
                sum += maxLeft - height[left];
                left++;
            }
        }

        return sum;
    }
};
