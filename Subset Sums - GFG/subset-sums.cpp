//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    
    void helper(vector<int> &arr, vector<int> &result, int n, int sum, int i) {
        
        if(i == n) {
            result.push_back(sum);
            return;
        }
        
        helper(arr, result, n, sum + arr[i], i + 1);
        helper(arr, result, n, sum, i + 1);
    }

    vector<int> subsetSums(vector<int> arr, int N){
        // Write Your Code here
        
        vector<int> result;
        
        helper(arr, result, N, 0, 0);
        
        return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends