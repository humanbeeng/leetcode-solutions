class Solution {
public:
    
    void calculateNSL(vector<int> &arr, int n_elements, vector<int> &nsl) {
        stack<int> s;
        
        for(int i = n_elements - 1; i >= 0; i--) {
            int curr_element = arr[i];
            
            while(not s.empty() and curr_element < arr[s.top()]) {
                nsl[s.top()] = i;
                s.pop();
            }
            
            s.push(i);
            
        }
    }
    
    void calculateNSR(vector<int> &arr, int n_elements, vector<int> &nsr) {
        stack<int> s;
        
        for(int i = 0; i < n_elements; i++) {
            int curr_element = arr[i];
            
            while(not s.empty() and curr_element <= arr[s.top()]) {
                nsr[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
    }
    

    
    int sumSubarrayMins(vector<int>& arr) {
        int n_elements = arr.size();
        int mod = 1e9 + 7, sum_subarray_mins = 0;
        
        vector<int> nsl(n_elements, -1);
        vector<int> nsr(n_elements, n_elements);
        
      
        calculateNSL(arr, n_elements, nsl);
        calculateNSR(arr, n_elements, nsr);
        
        
        for(int i = 0; i < n_elements; i++) {
            int curr_element = arr[i];
            
            int m = i - nsl[i];
            int n = nsr[i] - i;
            
            long long n_subsets = (m * n) % mod;
            long long contribution = (n_subsets * curr_element) % mod;
            
            sum_subarray_mins = (sum_subarray_mins + contribution) % mod;
        }
        
        return sum_subarray_mins;
    }
};