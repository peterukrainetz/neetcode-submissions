class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> indices;

        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++)
        {
            while (!indices.empty() && heights[i] < heights[indices.top()])
            {
                int poppedIndex = indices.top();
                indices.pop();
                
                int right = i;
                int left = indices.empty() ? -1 : indices.top();
                maxArea = max(maxArea, heights[poppedIndex] * (right - left - 1));
            }

            indices.push(i);
        }

        while (!indices.empty())
        {
            int poppedIndex = indices.top();
            indices.pop();
            
            int right = heights.size();
            int left = indices.empty() ? -1 : indices.top();
            maxArea = max(maxArea, heights[poppedIndex] * (right - left - 1));
        }

        return maxArea;
    }
};
