class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> carInfo;
        stack<double> arrivalTimes;

        for (int i = 0; i < position.size(); i++)
            carInfo.push_back({position[i], speed[i]});

        sort(carInfo.begin(), carInfo.end());

        for (int j = carInfo.size() - 1; j >= 0; j--)
        {
            double hours = (target - carInfo[j].first) / (double)carInfo[j].second;

            if (arrivalTimes.empty() || hours > arrivalTimes.top())
                arrivalTimes.push(hours);
        }

        return arrivalTimes.size();
    }
};
