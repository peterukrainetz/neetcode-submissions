class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> expression;
        
        int sum = 0;

        for (string s : tokens)
        {
            int result;

            if (s == "+")
            {
                result = stoi(expression.top());
                expression.pop();
                result += stoi(expression.top());
                expression.pop();
                expression.push(to_string(result));
            }
            else if (s == "-")
            {
                int num1 = stoi(expression.top());
                expression.pop();
                result = stoi(expression.top()) - num1;
                expression.pop();
                expression.push(to_string(result));
            }
            else if (s == "*")
            {
                result = stoi(expression.top());
                expression.pop();
                result *= stoi(expression.top());
                expression.pop();
                expression.push(to_string(result));
            }
            else if (s == "/")
            {
                int num1 = stoi(expression.top());
                expression.pop();
                result = stoi(expression.top()) / num1;
                expression.pop();
                expression.push(to_string(result));
            }
            else
                expression.push(s);
        }

        return stoi(expression.top());
    }
};
