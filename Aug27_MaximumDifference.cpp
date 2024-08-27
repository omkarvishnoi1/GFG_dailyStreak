//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void leftSmallest(vector<int> arr, vector<int>&left){
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            if(st.empty()){
                left.push_back(0);
            }
            else if(!st.empty() && st.top() >= arr[i]){
                while(!st.empty() && st.top() >= arr[i]) {
                    st.pop();
                }
                if(st.empty()) left.push_back(0);
                else left.push_back(st.top());
            }
            else if(!st.empty() && st.top() < arr[i]) left.push_back(st.top());
            
            st.push(arr[i]);
        }
    }
    
    void rightSmallest(vector<int> arr, vector<int>&right){
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            if(st.empty()){
                right.push_back(0);
            }
            else if(!st.empty() && st.top() >= arr[i]){
                while(!st.empty() && st.top() >= arr[i]){
                    st.pop();
                }
                if(st.empty()) right.push_back(0);
                else right.push_back(st.top());
            }
            else if(!st.empty() && st.top() < arr[i]) right.push_back(st.top());
            st.push(arr[i]);
        }
       
    }
    
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        vector<int> left;
        vector<int> right;
        leftSmallest(arr,left);
        rightSmallest(arr,right);
        reverse(right.begin(),right.end());
        
        int maxi = INT_MIN;
        for(int i=0;i<arr.size();i++){
            maxi = max(maxi,abs(left[i]-right[i]));
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends