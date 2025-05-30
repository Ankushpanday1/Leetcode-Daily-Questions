class Solution {
public:
    void sortColors(vector<int>& nums) {
       int n = nums.size();
    int low = 0;    // Pointer for the next position of 0
    int mid = 0;    // Pointer for the current element
    int high = n - 1; // Pointer for the next position of 2

    while (mid <= high) {
        if (nums[mid] == 0) {
            std::swap(nums[low], nums[mid]);
            ++low;
            ++mid;
        } else if (nums[mid] == 1) {
            ++mid;
        } else {
            std::swap(nums[mid], nums[high]);
            --high;
        }
    }
}
};