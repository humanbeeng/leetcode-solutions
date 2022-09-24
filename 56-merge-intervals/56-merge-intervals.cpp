class Solution {
public:
    
    static auto Comp(const vector<int> a, const vector<int> b) -> bool {
        return (a[0] < b[0]);
    }
    
//     auto merge(vector<vector<int>>& intervals) -> vector<vector<int>>{
//         vector<vector<int>> result;
//         int n_intervals = intervals.size();
        
        
//         sort(intervals.begin(), intervals.end());
        
//         for(auto interval: intervals) {
//             if(result.empty()) {
//                 result.push_back(interval);
//                 continue;
//             }
            
//             if(result.back()[1] >= interval[0]) {
//                 result.back()[0] = min(result.back()[0], interval[0]);
//                 result.back()[1] = max(result.back()[1], interval[1]);
//             } else {
//                 result.push_back(interval);
//             }
//         }
        
//         return result;
//     }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0){
            return intervals;
        }
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        vector<int> element = intervals[0];
        for(auto it: intervals){
            
            if(element[1] >= it[0] ){
                element[1] = max(element[1], it[1]);
            }
            else{
                res.push_back(element);
                element = it;
            } 
        }
        res.push_back(element);
        return res;
        
    }
};