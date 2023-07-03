//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        // code here
         stack<int> stk;
        for(int i=n-1; i>=0; i--){
            if(stk.empty()) stk.push(i);
            else if(arr[i]>arr[stk.top()]) stk.push(i);
        }
        
        int ans=0;
        for(int i=0; i<n; i++){
            while(!stk.empty() && arr[i] <= arr[stk.top()]){
                ans = max(ans, stk.top()-i);
                stk.pop();
            }
        }
        return ans;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends