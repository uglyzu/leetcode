/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> result={0,0};
        for(int i=0;i<nums.size();i++){
            int a = target-nums[i];
            if(mp.count(a)){
                result[0]=mp[a];
                result[1]=i;
                return result;
            }
            mp[nums[i]] = i;
        }
        return result;
    }
};

