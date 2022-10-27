class Solution {
public:
    void constructNGEAndProcessResult(vector<int> &nums2, unordered_map<int, int> &m, vector<int> &result) {
        
        stack<int> s;
        vector<int> ngr;
        
        int n_elements = nums2.size();
        bool found = false;
        
        for(int i = n_elements - 1; i >= 0; i--) {
            int curr_element = nums2[i];
            
            if(s.empty()) {
                s.push(curr_element);
                ngr.push_back(-1);
            } 
            else {
                if(curr_element < s.top()) {
                    ngr.push_back(s.top());
                    s.push(curr_element);
                    found = true;
                } 
                else {
                    while(not s.empty() and s.top() <= curr_element) {
                        s.pop();
                    }
                    
                    if(s.empty()) {
                        s.push(curr_element);
                        ngr.push_back(-1);
                    } else {
                        ngr.push_back(s.top());
                        s.push(curr_element);
                        found = true;
                    }
                }
            }
            
            if(m.find(curr_element) != m.end()) {
                if(found)
                    result[m[curr_element]] = ngr.back();
                else result[m[curr_element]] = -1;
            } 
        }
        
    }
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result(nums1.size(), -1);
        
        unordered_map<int, int> m;
        
        for(int i = 0; i < nums1.size(); i++) {
            m.insert({nums1[i], i});
        }
        
        constructNGEAndProcessResult(nums2, m, result);
        
        return result;
    }
};