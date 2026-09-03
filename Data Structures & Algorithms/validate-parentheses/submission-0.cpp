class Solution {
public:
    bool isValid(string s) {
        stack<char> deck;

        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
                deck.push(c);
            else
            {
                if (!deck.empty())
                {
                    if (deck.top() == '(' && c != ')') return false;
                    else if (deck.top() == '{' && c != '}') return false;
                    else if (deck.top() == '[' && c != ']') return false;
                    else deck.pop();
                }
                else
                    return false;
            }
        }

        if (deck.empty())
            return true;

        return false;
    }
};
