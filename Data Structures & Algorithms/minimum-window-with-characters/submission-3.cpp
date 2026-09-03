class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> counts;

        string shortestStr = "";

        for (char c : t)
            counts[c]++;

        int diff = counts.size();
        int left = 0;

        for (int right = 0; right < s.size(); right++)
        {            
            if (counts.contains(s[right]))
            {
                counts[s[right]]--;

                if (counts[s[right]] == 0)
                    diff--;
            }

            // Shrink window
            while ((!counts.contains(s[left]) || counts[s[left]] < 0) && left <= right)
            {
                if (counts.contains(s[left]))
                {
                    counts[s[left]]++;

                    if (counts[s[left]] > 0)
                        diff++;
                }

                left++;
            }

            // Updating shortest string
            if (diff == 0)
            {
                string window = "";

                for (int j = left; j < right + 1; j++)
                    window += s[j];

                if (window.length() < shortestStr.length() || shortestStr == "")
                {
                    shortestStr = window;
                    counts[s[left]]++;
                    left++;
                    diff++;
                }
            }
        }

        return shortestStr;
            
    }
};
