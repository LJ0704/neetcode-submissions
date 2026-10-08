class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sz_1 = nums1.size();
        int sz_2 = nums2.size();


        vector<int> nums(sz_1 + sz_2);
        int i = 0;
        int j = 0;
        int k = 0;
        while(j < sz_1 && k < sz_2)
        { 
            if(nums1[j] <= nums2[k])
            {
                nums[i] = nums1[j];
                j++;
            }
            else
            {
                nums[i] = nums2[k];
                k++;
            }
            i++;
        }

        while(j < sz_1)
        {
            nums[i] = nums1[j];
            j++;
            i++;
        }

        while(k < sz_2)
        {
            nums[i] = nums2[k];
            k++;
            i++;
        }

        double mid = 0;
        int total = nums.size();

        if((sz_1 + sz_2) % 2 == 0)
        {
            mid = (nums[(total / 2) - 1] + nums[total /2]) / 2.0;
        }
        else
        {
            mid = nums[(total / 2)];
        }

        return mid;
    }
};
