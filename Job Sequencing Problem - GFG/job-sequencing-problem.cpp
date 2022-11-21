//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    
    const int NOT_OCCUPIED = -1;
    
    static bool JobComparator(const Job& a, const Job& b) {
        return a.profit > b.profit;
    }
    
    int getMaxDeadline(Job arr[], int n) {
        int max_deadline = 0;
        
        for(int i = 0; i < n; i++) {
            Job curr_job = arr[i];
            max_deadline = max(max_deadline, curr_job.dead);
        }
        
        return max_deadline;
    }
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        
        
        int max_profit = 0, jobs_scheduled = 0;
        
        sort(arr, arr+n, JobComparator);
        
        int max_deadline = getMaxDeadline(arr, n);
        
        vector<int> days(max_deadline + 1, -1);
        
        
        
        for(int i = 0; i < n; i++) {
            Job curr_job = arr[i];
            
            for(int j = curr_job.dead; j > 0; j--) {
                if(days[j] == NOT_OCCUPIED) {
                    days[j] = i;
                    max_profit += curr_job.profit;
                    jobs_scheduled++;
                    break;
                }
            }
        }
        
        vector<int> result = {jobs_scheduled, max_profit};
        
        return result;
        
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends