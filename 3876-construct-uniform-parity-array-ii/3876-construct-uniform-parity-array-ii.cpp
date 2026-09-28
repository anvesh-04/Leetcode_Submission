class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int miniOdd = INT_MAX;
        int miniEven = INT_MAX;
        
        // Find the minimum odd and minimum even numbers in a single pass
        for (int x : nums1) {
            if (x & 1) {
                miniOdd = min(miniOdd, x);
            } else {
                miniEven = min(miniEven, x);
            }
        }
        
        // If the array has ONLY odd numbers, or ONLY even numbers
        if (miniOdd == INT_MAX || miniEven == INT_MAX) {
            return true;
        }
        
        // If it has both, the smallest odd must be smaller than the smallest even
        return miniOdd < miniEven;
    }
};