class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> indices;
        vector<int> answer;

        int left = 0;

        for (int right = 0; right < nums.size(); right++)
        {
            while (!indices.empty() && nums[right] > nums[indices.back()])
                indices.pop_back();

            indices.push_back(right);

            if (right - left + 1 == k)
            {
                answer.push_back(nums[indices.front()]);
                left++;

                if (indices.front() < left)
                    indices.pop_front();
            }
        }

        return answer;
    }
};
