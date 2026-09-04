class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> temps;
        vector<int> answer(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++)
        {
            if (temps.empty() || temperatures[i] <= temperatures[temps.top()])
                temps.push(i);
            else
            {
                while (!temps.empty() && temperatures[i] > temperatures[temps.top()])
                {
                    answer[temps.top()] = i - temps.top();
                    temps.pop();
                }

                temps.push(i);
            }
        }

        return answer;
    }
};
