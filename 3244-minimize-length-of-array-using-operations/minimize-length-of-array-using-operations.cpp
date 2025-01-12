
class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        
        if (nums.empty())
            return 0;
        int minElement = nums[0];

        int minFrequency = 1;

       // Find frequency of minimum element
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] < minElement) {
                minElement = nums[i];
                minFrequency = 1;
            }
            else if (nums[i] == minElement) {
                minFrequency++;
            }
        }
        // condtition: if remainder of an element with minElement is !=0  then answer is 1
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=minElement){
                if(nums[i]%minElement!=0) return 1;
            }
        }

        // else return the ansser below
        return ceil(static_cast<double>(minFrequency) / 2);
    }
};