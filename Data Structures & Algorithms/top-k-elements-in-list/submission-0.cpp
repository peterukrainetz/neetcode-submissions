class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequencies;

        vector<vector<int>> mostFreq(nums.size() + 1);

        for (int n : nums)
            frequencies[n]++;

        for (auto pair : frequencies)
            mostFreq[pair.second].push_back(pair.first);

        vector<int> answer;

        for (int i = mostFreq.size() - 1; answer.size() < k; i--)
            for (int n : mostFreq[i])
                answer.push_back(n);

        return answer;
    }
};
