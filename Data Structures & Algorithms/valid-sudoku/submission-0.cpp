class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> row;
        unordered_map<char, int> col;
        unordered_map<char, int> box;

        for (const vector<char>& r : board)
        {
            for (int i = 0; i < r.size(); i++)
            {
                if (r[i] != '.')
                {
                    row[r[i]]++;

                    if (row[r[i]] > 1)
                        return false;
                }
            }

            row.clear();
        }

        for (int j = 0; j < board.size(); j++)
        {
            for (const vector<char>& c : board)
            {
                if (c[j] != '.')
                {
                    col[c[j]]++;

                    if (col[c[j]] > 1)
                        return false;
                }
            }

            col.clear();
        }

        int k = 0;
        int rowCnt = 1;

        while (k < 9)
        {
            for (const vector<char>& b : board)
            {
                for (int l = k; l < k + 3; l++)
                {
                    if (b[l] != '.')
                    {
                        box[b[l]]++;

                        if (box[b[l]] > 1)
                            return false;
                    }
                }

                rowCnt++;

                if (rowCnt == 4)
                {
                    rowCnt = 1;
                    box.clear();
                }
            }

            k += 3;
        }

        return true;
    }
};
