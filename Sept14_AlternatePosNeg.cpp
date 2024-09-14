//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        vector<int> pos;
        vector<int> neg;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=0) pos.push_back(arr[i]);
            else neg.push_back(arr[i]);
        }
        if(neg.size()==arr.size()) return;
        int iPos=0;
        int iNeg=0;
        int i=0;
        while(iPos<pos.size() && iNeg<neg.size()){
            arr[i++]=pos[iPos++];
            arr[i++]=neg[iNeg++];
        }
        while(iPos<pos.size()) arr[i++]=pos[iPos++];
        while(iNeg<neg.size()) arr[i++]=neg[iNeg++];
        return;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends