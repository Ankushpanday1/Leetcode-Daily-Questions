class Solution {
public:
int findNumberOfLIS(vector<int>& nums) {
	const int SIZE = nums.size();
	vector<int> longestSubsetAtIndex(SIZE, 1), longestSubsetCountsAtIndex(SIZE, 1);
	int longestSubset = 1, prevLongest, newLongest, longestSubsetCount = 0;
	for (int i = 1; i < SIZE; i++) {
		for (int j = 0; j < i; j++) {
			if (nums[i] > nums[j]) {
				prevLongest = longestSubsetAtIndex[i];
				newLongest = longestSubsetAtIndex[j] + 1;
				if (prevLongest == newLongest) {
					longestSubsetCountsAtIndex[i] += longestSubsetCountsAtIndex[j];                        
				} else if (newLongest > prevLongest) {
					if (prevLongest == longestSubset)
						longestSubset = newLongest;
					longestSubsetAtIndex[i] = newLongest;
					longestSubsetCountsAtIndex[i] = longestSubsetCountsAtIndex[j];
				}
			}
		}
	}
	for (int i = 0; i < SIZE; i++) {
		if (longestSubsetAtIndex[i] == longestSubset)
			longestSubsetCount += longestSubsetCountsAtIndex[i];
	}
	return longestSubsetCount;
}
};