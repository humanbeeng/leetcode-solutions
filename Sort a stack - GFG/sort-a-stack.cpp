//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

void pushToProperPosition(stack<int> &s, int val) {
    if(s.empty() or s.top() <= val) {
        s.push(val);
        return;
    }
    
    if(s.top() <= val) {
        s.push(val);
        return;
    }
    
    int curr_top = s.top();
    s.pop();
    pushToProperPosition(s,val);
    pushToProperPosition(s,curr_top);
    return;
    
}

void SortedStack :: sort(){
   if(s.size() == 1) {
       return;
   }
   
   int curr_top = s.top();
   s.pop();
   sort();
   
   pushToProperPosition(s,curr_top);
   
   return;
}