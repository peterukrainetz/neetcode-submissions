class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int firstPointer = 0, secondPointer = 0;

        while (firstPointer < nums1.size() || secondPointer < nums2.size())
        {
            if (firstPointer < nums1.size() && (secondPointer >= nums2.size() || nums1[firstPointer] <= nums2[secondPointer]))
            {
                merged.push_back(nums1[firstPointer]);
                firstPointer++;
            }
            else
            {
                merged.push_back(nums2[secondPointer]);
                secondPointer++;
            }
        }

        int totalSize = nums1.size() + nums2.size();
        double median;

        if (totalSize % 2 == 0)
            median = (merged[totalSize / 2 - 1] + merged[totalSize / 2]) / 2.0;
        else
            median = merged[totalSize / 2];

        return median;
    }
};
