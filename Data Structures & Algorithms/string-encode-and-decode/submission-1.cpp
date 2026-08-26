class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string = "";

        for (const string &s : strs)
            encoded_string += to_string(s.length()) + "#" + s;

        cout << encoded_string;
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_strs;

        string currString = "";
        string currLength = "";
        int lengthRemaining = 0;

        for (char c : s)
        {
            if (lengthRemaining == 0 && c == '#')
            {
                lengthRemaining = stoi(currLength);
                currLength = "";

                if (lengthRemaining == 0)
                    decoded_strs.push_back(currString);
            }
            else if (lengthRemaining > 0)
            {
                currString += c;
                lengthRemaining--;

                if (lengthRemaining == 0)
                {
                    decoded_strs.push_back(currString);
                    currString = "";
                }
            }
            else
                currLength += c;
        }

        return decoded_strs;
    }
};
