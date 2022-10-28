class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n_elements = nums.size();
        vector<int> nge(n_elements, -1);
        
        for(int i = 0; i < (2 * n_elements); i++) {
            int idx = i % n_elements;
            int curr_element = nums[idx];
            
            // curr element is tested as nge for all the elements in stack. 
            // ie, prev elements
            while(not s.empty() and curr_element > nums[s.top()]) {
                // if so, then we update their nge as curr_element in result arr;
                nge[s.top()] = curr_element;
                
                // Since we have found nge of this top element, it is processed, 
                // hence popped out.
                s.pop(); 
            }
            // Push the curr_element to be be processed, ie, to find nge for it. 
            s.push(idx);
        }
        
        
        return nge;
    }
};