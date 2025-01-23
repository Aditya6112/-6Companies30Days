// Link: https://leetcode.com/problems/find-in-mountain-array/description/
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        // Find the peak index
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        int peak = left;
        //left
        int start = 0;
        int end = peak;
        while (start <= end) { // Corrected condition
            int mid = start + (end - start) / 2;
            if (mountainArr.get(mid) == target) {
                return mid;
            } else if (mountainArr.get(mid) > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        //right
        start = peak;
        end = mountainArr.length() - 1;
        while (start <= end) { // Corrected condition
            int mid = start + (end - start) / 2;
            if (mountainArr.get(mid) == target) {
                return mid;
            } else if (mountainArr.get(mid) > target) {
                start = mid + 1; // Corrected direction
            } else {
                end = mid - 1; // Corrected direction
            }
        }
        return -1;
    }
};