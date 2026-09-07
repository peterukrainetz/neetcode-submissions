class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size() - 1;

        int targetRow = -1;

        while (targetRow == -1 && l <= r)
        {
            int mid = l + (r - l) / 2;

            if (matrix[mid].front() > target)
                r = mid - 1;
            else if (matrix[mid].back() < target)
                l = mid + 1;
            else
                targetRow = mid;
        }

        if (targetRow == -1)
            return false;

        l = 0;
        r = matrix[targetRow].size() - 1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (matrix[targetRow][mid] > target)
                r = mid - 1;
            else if (matrix[targetRow][mid] < target)
                l = mid + 1;
            else
                return true;
        }

        return false;
    }
};
