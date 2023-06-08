class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int s1=str1.length();
        int s2=str2.length();
        int g;
    
        g=gcd(s2,s1);
        string gd;
        
        if (str1+str2==str2+str1)
        {
            for(int i=0;i<g;i++)
            {
                gd+=str1[i];
            }
        }
        else gd="";
        return gd;
        
    }
};
