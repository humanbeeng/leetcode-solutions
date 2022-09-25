class Solution {
public:
    bool check(vector<int>& nums) {
        
        int n_elements = nums.size();
        
        bool first_section = true;
        
        bool dip_found = false;
        
        for(int i = 0; i + 1 < n_elements; i++) {
            
           if(nums[i] > nums[i + 1]) {
                    
                if(not dip_found) {
                    dip_found = true;
                } 
                else if(dip_found) {
                    return false;
                }
            }
                
        }
        
        if(not dip_found) {
            return true;
        }
        
        if(nums[n_elements - 1] > nums[0]) {
            return false;
        }
        
        return true;
        
        
    }
};