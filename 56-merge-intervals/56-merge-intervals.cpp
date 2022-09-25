class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n_intervals = intervals.size();
        
        if(n_intervals == 1) {
            return intervals;
        }
        
        vector<vector<int>> merged_intervals;
        
        sort(intervals.begin(), intervals.end());
        
        for(vector<int> interval: intervals) {
            if(merged_intervals.empty()) {
                merged_intervals.push_back(interval);
                continue;
            }
            
           if(merged_intervals.back()[1] >= interval[0]) {
               merged_intervals.back()[0] = min(merged_intervals.back()[0], interval[0]);
               merged_intervals.back()[1] = max(merged_intervals.back()[1], interval[1]);
           } else {
               merged_intervals.push_back(interval);
           }
        }
        
        return merged_intervals;
        
    }
};