class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int mini=0,maxi=0;
        for(auto it:nums){
            if(it>0)maxi++;
            else if(it<0)mini++;
        }
        return max(mini,maxi);        
    }
};