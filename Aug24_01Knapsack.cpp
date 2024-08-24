//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   int f(int index,int weight, vector<int>& wt, vector<int>& val,vector<vector<int>>&dp){
        if(index==0){
            if(wt[index]<=weight) return val[index];
            return 0;
        }
        if(dp[index][weight]!=-1) return dp[index][weight];
        int notTake=f(index-1,weight,wt,val,dp);
        int Take=INT_MIN;
        if(wt[index]<=weight) Take=val[index]+f(index-1,weight-wt[index],wt,val,dp);
        return dp[index][weight]=max(notTake,Take);
    }
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n = wt.size();
       vector<vector<int>> dp(n,vector<int>(W+1,-1));
       return f(n-1,W,wt,val,dp);
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends