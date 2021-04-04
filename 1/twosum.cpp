class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>res;
        unordered_map<int,int>pos_map;
        for (int i = 0; i < nums.size();i++)
        {
            if (pos_map.count(target-nums[i]))
            {
                res.push_back(i);
                res.push_back(pos_map[target-nums[i]]);
                return res;
            }

            pos_map[nums[i]] = i;
        }

        return res;
    }
};
