//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    void pushToBottom(stack<int> &st, int val) {
        if(st.size() == 0) {
            st.push(val);
            return;
        }
        
        int curr_top = st.top();
        st.pop();
        
        pushToBottom(st, val);
        
        st.push(curr_top);
        
        return;
    }
    
    stack<int> Reverse(stack<int> &st){
        if(st.size() == 1) {
            return st;
        }
        
        int curr_top = st.top();
        st.pop();
        
        Reverse(st);
        
        pushToBottom(st, curr_top);
        
        return st;
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        stack<int> ans=ob.Reverse(St);
        vector<int>res;
        while(ans.size())
        {
            res.push_back(ans.top());
            ans.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends