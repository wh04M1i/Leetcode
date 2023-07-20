//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    char nonrepeatingCharacter(string S) {
        // Create a hash map to store character counts.
        unordered_map<char, int> charCount;
        
        // Traverse the string to populate the hash map.
        for (char ch : S) {
            charCount[ch]++;
        }
        
        // Traverse the string again to find the first non-repeating character.
        for (char ch : S) {
            if (charCount[ch] == 1) {
                return ch; // Found the first non-repeating character.
            }
        }
        
        return '$'; // No non-repeating character found, return '$'.
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends