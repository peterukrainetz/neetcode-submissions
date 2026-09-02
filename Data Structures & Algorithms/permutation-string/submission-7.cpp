class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> counts(26, 0);

        for (char c : s1)
            counts[c - 'a']++;

        int left = 0;
        int diff = 0;

        for (int i = 0; i < counts.size(); i++)
            if (counts[i] != 0) diff++;

        for (int right = 0; right < s2.length(); right++)
        {
            counts[s2[right] - 'a']--;

            if (counts[s2[right] - 'a'] == 0) diff--;
            else if (counts[s2[right] - 'a'] == -1) diff++;

            if ((right - left + 1) > s1.length())
            {
                counts[s2[left] - 'a']++;

                if (counts[s2[left] - 'a'] == 0) diff--;
                else if (counts[s2[left] - 'a'] == 1) diff++;

                left++;
            }

            if (diff == 0) return true;
        }

        return false;
    }
};
