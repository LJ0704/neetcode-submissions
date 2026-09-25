/*
Can add one one number in hashmap and check if the diffreence already exists and return the value
*/

/*
Just re-read the problem the array of integers are sorted in non-decreasing order.
-----> So that means you can use binary search or better two pointer method.
If its unsorted then hashmap would have been good?

*/




class Solution {
public:

    vector<int> twoSum(vector<int>& numbers, int target) {
        /*Method - 1 (Hash Maps) Time Complexity is O(n) and Space complexity is O(n)*/
        /*
        unordered_map<int, int> map;
        for(int i = 0; i < numbers.size(); i++)
        {
            int num = numbers[i];            
            int diff = target - num;

            if(map.find(diff) != map.end())
            {
                return {map[diff] + 1, i + 1};
            }
            
            map[num] = i;
        }
        return {};*/
    

    /*Method 2 : Two Pointer Method since it is an sorted array it will be better efficent*/

    int start_index = 0;
    int end_index = numbers.size() - 1;
    //vector<int> index = {};

    while(start_index < end_index)
    {
        int num = numbers[start_index] + numbers[end_index];
        if(num == target)
        {
            return {start_index + 1, end_index + 1};
        }
        if(num < target)
        {
            start_index++;
        }
        else
        {
            end_index--;
        }      
        
    }
    return {};
    }

    
};


