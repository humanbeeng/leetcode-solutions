class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        vector<int> majority_elements;
        
        int n_elements = nums.size();
        
        if(n_elements == 1) {
            majority_elements.push_back(nums[0]);
            return majority_elements;
        }
        
        int candidate_1 = 0, candidate_2 = 0, freq_1 = 0, freq_2 = 0;
        
        for(int i = 0; i < n_elements; i++) {
            
            int curr_element = nums[i];
            
            if(curr_element == candidate_1) {
                freq_1++;
            } 
            
            else if(curr_element == candidate_2) {
                freq_2++;
            }
            
            else if(freq_1 == 0) {
                candidate_1 = curr_element;
                freq_1++;
            }
            
            else if(freq_2 == 0) {
                candidate_2 = curr_element;
                freq_2++;
            }
            
            else {
                freq_1--; freq_2--;
            }
            
        }
        
        freq_1 = 0; freq_2 = 0;
        
        for(int element: nums) {
            if(element == candidate_1) freq_1++;
            else if(element == candidate_2) freq_2++;
        }

        
        int majority_criteria = floor(n_elements / 3);
        
        if(freq_1 > majority_criteria) {
            majority_elements.push_back(candidate_1);
        }
        
        if(freq_2 > majority_criteria) {
            majority_elements.push_back(candidate_2);
        }
        
        return majority_elements;
        
        
        
    }
};