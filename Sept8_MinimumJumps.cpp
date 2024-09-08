//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        int idx = 0;
        int cnt = 0;
        while(idx < n){
            int val = arr[idx];
            if(idx + val >= n - 1){
                cnt++;
                return cnt;
            }
            cnt++;
            int ans = INT_MIN;
            int newCurr = idx;
            for(int j = idx + 1; j <= idx + val; j++){
                if(ans <= arr[j] + j){
                    ans = arr[j] + j;
                    newCurr = j;
                }
            }
            if(ans != INT_MIN){
                idx = newCurr;
            }
            if(val == 0){
                return -1;
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends