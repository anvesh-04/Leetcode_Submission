class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> vec(1e5+1);
        long long ans=0;
        int k = k1+k2;
        for(int i=0; i<nums1.size(); i++){
            vec[abs(nums1[i]-nums2[i])]++;
        }
        for(int i=1e5; i>0; i--){
            if(vec[i]<=k){
                vec[i-1]+=vec[i];
                k-=vec[i];
                vec[i]=0;
            }
            else{
                vec[i-1]+=k;
                vec[i]-=k;
                k=0;
                break;
            }
        }
        for(int i=1; i<1e5+1; i++){
            ans+=1LL*vec[i]*(1LL*i*i);
        }
        return ans;
    }
};