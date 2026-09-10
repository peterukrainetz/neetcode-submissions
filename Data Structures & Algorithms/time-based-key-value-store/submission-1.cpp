class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back(pair{timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!store.contains(key))
            return "";

        int l = 0, r = store[key].size() - 1;

        string result = "";

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (store[key][mid].first > timestamp)
                r = mid - 1;
            else if (store[key][mid].first < timestamp)
            {
                result = store[key][mid].second;
                l = mid + 1;
            }
            else
            {
                if (!store[key][mid].second.empty())
                    return store[key][mid].second;
                else
                    return "";
            }
        }

        return result;
    }

private:
    unordered_map<string, vector<pair<int, string>>> store;
};
