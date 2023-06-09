class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
      char output=letters[0];
        int i=0;
        while(i<letters.size())
        {
            if(target<letters[i])
            {
                 output=letters[i];
                  break;
            }
            
            else
            { i++;}
        }
       
        return output;
    }
};
