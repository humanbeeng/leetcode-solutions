class Solution {
public:
    string frequencySort(string s) {
        string result = "";
        
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> mp;
        
        for(char c: s) {
            mp[c]++;
        }
        
        for(pair<char, int> it: mp) {
            pq.push(make_pair(it.second, it.first));
        }
        
        while(not pq.empty()) {
            int freq = pq.top().first;
            char c = pq.top().second;
            while(freq--) {
                result += c;
            }
            pq.pop();
        }
        
        return result;
        
    }
};