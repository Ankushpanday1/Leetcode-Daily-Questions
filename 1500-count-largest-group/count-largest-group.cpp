class Solution {
public:
    int findDigitSum(int n){
        int sum=0;
        while(n){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int, int> mpp;
        int maxSize=0, count=0;
        for(int i=1;i<=n;i++){
            int digitSum= findDigitSum(i);
            mpp[digitSum]++;
            if(mpp[digitSum]==maxSize){
                count++;
            }
            else if(mpp[digitSum]>maxSize){
                maxSize=mpp[digitSum];
                count=1;
            }
        }
        return count;
    }
};