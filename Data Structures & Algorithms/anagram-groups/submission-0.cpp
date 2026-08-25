class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> table;

        for (string &s : strs)
        {
            vector<int> frequency(26, 0);

            for (char &c : s)
                frequency[c - 'a']++;

            string key = "";

            for (int i : frequency)
                key += to_string(i) + "#";

            table[key].push_back(s);
        }

        vector<vector<string>> result;

        for (auto& [key, group] : table)
            result.push_back(group);

        return result;
    }
};
