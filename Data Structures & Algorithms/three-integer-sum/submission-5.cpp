/*
Method 1: Iteration + Hash Maps - failed because there are duplicates
Method 2: Two Pointer
*/

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         unordered_map<int, int> nums_arr;

//         // Store value -> index
//         for (int i = 0; i < nums.size(); i++) {
//             nums_arr[nums[i]] = i;
//         }

//         vector<vector<int>> three_sum;

//         for (int i = 0; i < nums.size(); i++) {
//             for (int j = i + 1; j < nums.size(); j++) {

//                 int target = -(nums[i] + nums[j]);

//                 if (nums_arr.find(target) != nums_arr.end()) {

//                     int k = nums_arr[target];

//                     if (k > j) {
//                         three_sum.push_back({nums[i], nums[j], nums[k]});
//                     }
//                 }
//             }
//         }

//         return three_sum;
//     }
// };

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> three_sum;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {

            // Skip duplicate nums[i]
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {

                    three_sum.push_back(
                        {nums[i], nums[left], nums[right]}
                    );

                    left++;
                    right--;

                    // Skip duplicate left values
                    while (left < right &&
                           nums[left] == nums[left - 1]) {
                        left++;
                    }

                    // Skip duplicate right values
                    while (left < right &&
                           nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
                else if (sum < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }

        return three_sum;
    }
};