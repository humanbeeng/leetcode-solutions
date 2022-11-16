//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        // code here
        vector<int> denominations = {1,2,5,10,20,50,100,200,500,2000};
        
        vector<int> coins_required;
        
        int max_denomination_usable_idx = 1;
        
        for(int i = 0; i < 10; i++) {
            int curr_denomination = denominations[i];
            
            if(curr_denomination <= N) max_denomination_usable_idx = i;
            
            else break;
        }
        
        for(int i = max_denomination_usable_idx; i >= 0; i--) {
            int denomination = denominations[i];
            
            int coins_used = N / denomination;
            
            for(int j = 0; j < coins_used; j++) {
                coins_required.push_back(denomination);
            }
            
            N -= denomination * coins_used;
        }
        
        return coins_required;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends