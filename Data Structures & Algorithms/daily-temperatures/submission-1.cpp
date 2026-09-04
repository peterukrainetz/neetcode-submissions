class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> temps;
        vector<int> answer(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++)
        {
            while (!temps.empty() && temperatures[i] > temperatures[temps.top()])
            {
                answer[temps.top()] = i - temps.top();
                temps.pop();
            }

            temps.push(i);
        }

        return answer;
    }
};
