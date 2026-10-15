class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            unordered_map<int, int> mpp;
            int count=0;
            for(int j=i; j<nums.size(); j++){    
                if(mpp.find(nums[j])==mpp.end()){
                    count++;
                    mpp[nums[j]]++;
                }
                sum+=(count*count);
            }
        }
        return sum;
    }
};