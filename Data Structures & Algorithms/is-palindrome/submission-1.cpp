class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;

        while (l < r)
        {
            while (!isalnum(static_cast<unsigned char>(s[l])))
            {
                l++;

                if (l > r)
                    return true;
            }

            while (!isalnum(static_cast<unsigned char>(s[r])))
            {
                r--;

                if (r < l)
                    return true;
            }

            if (tolower(static_cast<unsigned char>(s[l])) != tolower(static_cast<unsigned char>(s[r])))
                return false;

            l++;
            r--;
        }

        return true;
    }
};
