class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int chintu = 0, pintu = 0; // Ye dono pointer bhai sahab nums1 aur nums2 pe najar rakh rahe hain
        vector<vector<int>> dhamaka; // Ye final result ka dabba hai
        
        while(chintu < nums1.size() && pintu < nums2.size()){
            // Bsdk check karne aya hai? Haan
            if(nums1[chintu][0] == nums2[pintu][0]){ 
                // Jab dono ke IDs same ho toh value jod de
                dhamaka.push_back({nums1[chintu][0], nums1[chintu][1] + nums2[pintu][1]});
                chintu++;
                pintu++;
            } 
            else if(nums1[chintu][0] < nums2[pintu][0]){
                // Agar nums1 ki ID chhoti ho toh usko result mai daal de
                dhamaka.push_back(nums1[chintu]);
                chintu++;
            } 
            else {
                // Agar nums2 ki ID chhoti ho toh usko result mai daal de
                dhamaka.push_back(nums2[pintu]);
                pintu++;
            }
        }
        
        // Jo bacha-kucha data hai usko bhi add karna hai bsdk
        while(chintu < nums1.size()){
            dhamaka.push_back(nums1[chintu]);
            chintu++;
        }
        
        while(pintu < nums2.size()){
            dhamaka.push_back(nums2[pintu]);
            pintu++;
        }
        
        return dhamaka; //sorted and merged array le lo
    }
};
