class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int curr_sum = 0;
        unordered_map<int, int> umap;
        int n_subarrays = 0;
        
        umap[0] = 1;
        
        for(int element: nums) {
            
            curr_sum += element;
            
            int target = curr_sum - k;
            
            if(umap[target] > 0) {
                n_subarrays += umap[target];
            }
            umap[curr_sum]++;
        
        }
        
        
        return n_subarrays;
    }
};