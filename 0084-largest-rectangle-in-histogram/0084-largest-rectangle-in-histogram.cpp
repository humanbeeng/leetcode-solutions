class Solution {
public:
    
    vector<int> calculateNSR(vector<int> &heights) {
        stack<int> s;
        int n = heights.size();
        vector<int> nsr(n, n);
        
        for(int i = 0; i < n; i++) {
            int curr_height = heights[i];
            
            while(not s.empty() and curr_height < heights[s.top()]) {
                nsr[s.top()]  = i;
                s.pop();
            }
            
            s.push(i);
        }
        return nsr;
    }
    
    vector<int> calculateNSL(vector<int> &heights) {
        int n = heights.size();
        vector<int> nsl(n, -1);
        stack<int> s;
        
        for(int i = n - 1; i >= 0; i--) {
            int curr_height = heights[i];
            
            while(not s.empty() and curr_height < heights[s.top()]) {
                nsl[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        return nsl;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nsr = calculateNSR(heights);
        vector<int> nsl = calculateNSL(heights);
        int max_area = 0;
        
        for(int i = 0; i < heights.size(); i++) {
            int curr_height = heights[i];
            int width = nsr[i] - nsl[i] - 1;
            int area = curr_height * width;
            max_area = max(max_area, area);
        }
        
        return max_area;
    }
};