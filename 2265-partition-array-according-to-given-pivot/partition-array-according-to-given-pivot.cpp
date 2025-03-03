class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        // Ye vector un numbers ko rakhenge jo pivot se kam hai - low priority features
        vector<int> lowPriorityFeatures;
        // Ye vector un numbers ko rakhenge jo pivot ke barabar hain - core features (must have)
        vector<int> coreFeatures;
        // Ye vector un numbers ko rakhenge jo pivot se zyada hain - high priority features
        vector<int> highPriorityFeatures;
        
        // Ek baar iterate karte hain, aur product roadmap ke hisaab se allocate karte hain
        for (int feature : nums) {
            if (feature < pivot) {
                lowPriorityFeatures.push_back(feature); // below target feature add karo
            } else if (feature == pivot) {
                coreFeatures.push_back(feature); // core feature, bilkul must-have
            } else {
                highPriorityFeatures.push_back(feature); // premium features, high priority
            }
        }
        
        // Ab teeno segments ko ek final roadmap mein merge karte hain
        vector<int> finalRoadmap;
        finalRoadmap.reserve(nums.size());
        
        // Pehle low priority features, phir core features, aur last mein high priority features
        finalRoadmap.insert(finalRoadmap.end(), lowPriorityFeatures.begin(), lowPriorityFeatures.end());
        finalRoadmap.insert(finalRoadmap.end(), coreFeatures.begin(), coreFeatures.end());
        finalRoadmap.insert(finalRoadmap.end(), highPriorityFeatures.begin(), highPriorityFeatures.end());
        
        return finalRoadmap; // Lo bhai, ab final sorted array ready hai!
    }
};
