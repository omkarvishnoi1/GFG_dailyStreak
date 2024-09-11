//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        long long ans = 0;
    priority_queue<long long, vector<long long>, greater<long long>> q;

    // Push all elements into the priority queue
    for(int i = 0; i < arr.size(); i++) {
        q.push(arr[i]);
    }

    // Continue combining the smallest elements until one element is left
    while(q.size() > 1) {
        // Extract the two smallest elements
        long long first = q.top();
        q.pop();
        long long second = q.top();
        q.pop();

        // Combine them and add the result to the total cost
        long long sum = first + second;
        ans += sum;

        // Push the sum back into the priority queue
        q.push(sum);
    }

    return ans;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}

// } Driver Code Ends