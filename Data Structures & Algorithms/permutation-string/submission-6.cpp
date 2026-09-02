class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> freq;

        int left = 0;
        int matchingChars = 0;

        for (int i = 0; i < s1.length(); i++)
            freq[s1[i]]++;

        for (int right = 0; right < s2.length(); right++)
        {
            while ((right - left + 1) > s1.length())
            {
                if (freq.contains(s2[left]))
                {
                    if (freq[s2[left]] == -1)
                        matchingChars++;
                    else if (freq[s2[left]] == 0)
                        matchingChars--;

                    freq[s2[left]]++;
                }

                left++;
            }

            if (freq.contains(s2[right]))
            {
                if (freq[s2[right]] == 1)
                    matchingChars++;
                else if (freq[s2[right]] == 0)
                    matchingChars--;

                freq[s2[right]]--;

                if (matchingChars == freq.size())
                    return true;
            }
        }

        return false;
    }
};
