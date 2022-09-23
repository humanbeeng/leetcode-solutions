class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1 = 0;
        int c2 = 0;
        
        int f1 = 0, f2 = 0;
        
        int n_elements = nums.size();
        
        vector<int> result;
        
        if(n_elements == 1) {
            result.push_back(nums[0]);
            return result;
        } 
        
        for(int i = 0; i < n_elements; i++ ){
            int curr_element = nums[i];
            
            if(curr_element == c1) {
                f1++;
            } else if(curr_element == c2) {
                f2++;
            }
            
            else if(f1 == 0) {
                c1 = curr_element;
                f1++;
            }
            else if(f2 == 0) {
                c2 = curr_element;
                f2++;
            }
            
            else {
                f1--;
                f2--;
            }
            
            
        }
        
        f1 = 0; f2 = 0;
        
        for(int element: nums) {
            if(element == c1) {
                f1++;
            } else if(element == c2) {
                f2++;
            }
        }
        
        
        int majority_criteria = n_elements / 3;
        
        if(f1 > majority_criteria) {
            result.push_back(c1);
        }
        
        if(f2 > majority_criteria) {
            result.push_back(c2);
        }
        
        return result;
        
    }
};