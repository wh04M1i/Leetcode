class Solution {
public:
    string convertToBase7(int num) {
        string r;
          if (num == 0)
            return "0";

         bool isNegative = num < 0;
        num = abs(num);
        while(num!=0)
        {
            r= to_string(num%7)+r;
            num/=7;
        }
         if (isNegative)
            r = "-" + r;
        return r;
    }
};