class Solution {
public:
    bool isValid(string s) {
        stack<char> deck;

        for (char c : s)
        {
            if (c == '(') deck.push(')');
            else if (c == '{') deck.push('}');
            else if (c == '[') deck.push(']');
            else
            {
                if (deck.empty() || deck.top() != c) return false;
                deck.pop();
            }
        }

        if (deck.empty())
            return true;

        return false;
    }
};
