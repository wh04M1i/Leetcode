class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int n = needle.size();
        int m = haystack.size();
        if(haystack==needle)
            return 0;
        
        for(int i = 0 ; i< m-n+1 ; i++)
        {
            string temp = haystack.substr(i,n);
            if(temp==needle)
            {
                return i;
            }
        }
        
        return -1;
    }
};