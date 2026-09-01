class Solution {
public:
    int characterReplacement(string s, int k) {
        int longest = 1;

        unordered_map<char, int> table;

        int left = 0;
        int maxCount = 0;
        
        for (int right = 0; right < s.size(); right++)
        {
            table[s[right]]++;
            maxCount = max(maxCount, table[s[right]]);

            while ((right - left + 1) - maxCount > k)
            {
                table[s[left]]--;
                left++;
            }

            longest = max(longest, right - left + 1);
        }

        return longest;
    }
};
