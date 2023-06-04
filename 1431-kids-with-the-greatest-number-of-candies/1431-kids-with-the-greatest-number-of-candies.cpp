class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max =0;
        vector <bool> result;
        for(int i=0;i<candies.size();i++){
            if(candies[i]>max){
                max=candies[i];
            }
        }
        for(int i=0;i<candies.size();i++){
            candies[i]+=extraCandies;
            result.push_back(max<=candies[i]);
        }
        return result;

        
    }
};