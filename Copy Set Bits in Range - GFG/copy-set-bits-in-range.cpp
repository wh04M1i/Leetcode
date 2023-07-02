//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        // code here
          int i = 0;
    int sum = 0;

    while (x != 0 || y != 0) {
        int bit1 = x & 1;
        int bit2 = y & 1;

        if (bit1 == 1) {
            sum |= (1 << i);
        } else if (bit2 == 1 && (i + 1) >= l && (i + 1) <= r) {
            sum |= (1 << i);
        }

        i++;
        x >>= 1;
        y >>= 1;
    }

    return sum;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, l, r;
        cin>>x>>y>>l>>r;
        
        Solution ob;
        cout<<ob.setSetBit(x, y, l, r)<<"\n";
    }
    return 0;
}
// } Driver Code Ends