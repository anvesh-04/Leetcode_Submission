#include <vector>

using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int bit_counts[32] = {0};
        
        // Step 1: Count the frequency of each set bit across all numbers
        for (int num : nums) {
            for (int i = 0; i < 32; i++) {
                if ((num >> i) & 1) {
                    bit_counts[i]++;
                }
            }
        }
        
        long long total_sum = 0;
        const int MOD = 1e9 + 7;
        
        // Step 2: Greedily construct the k largest numbers
        for (int i = 0; i < k; i++) {
            long long current_num = 0;
            for (int j = 0; j < 32; j++) {
                // If we have available set bits at position j, use one
                if (bit_counts[j] > 0) {
                    current_num |= (1LL << j);
                    bit_counts[j]--;
                }
            }
            
            // Add the square of the optimally constructed number to the total
            total_sum = (total_sum + (current_num * current_num) % MOD) % MOD;
        }
        
        return total_sum;
    }
};