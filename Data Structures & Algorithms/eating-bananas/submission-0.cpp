class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());

        int l = 1;
        int r = piles.back();
        
        int minK = r;

        while (l <= r)
        {
            int k = l + (r - l) / 2;

            int hours = 0;
            for (int i = 0; i < piles.size() && hours <= h; i++)
                hours += (piles[i] + k - 1) / k;

            if (hours > h)
                l = k + 1;
            else
            {
                minK = min(minK, k);
                r = k - 1;
            }
        }

        return minK;
    }
};
