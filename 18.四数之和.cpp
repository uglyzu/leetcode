/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 *
 * https://leetcode-cn.com/problems/4sum/description/
 *
 * algorithms
 * Medium (35.61%)
 * Likes:    239
 * Dislikes: 0
 * Total Accepted:    21.7K
 * Total Submissions: 60.9K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c
 * + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 * 
 * 注意：
 * 
 * 答案中不可以包含重复的四元组。
 * 
 * 示例：
 * 
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 * 
 * 满足要求的四元组集合为：
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int len = nums.size();
        vector<vector<int>> result;
        for(int i=0;i<len-3;i++){
            if(i>0&&nums[i]==nums[i-1])continue;
            for(int j=i+1;j<len-2;j++){
                if(j>i+1&&nums[j]==nums[j-1])continue;
                int l=j+1,r = len-1;
                while(l<r){
                    int sum = nums[i]+nums[j]+nums[l]+nums[r];
                    if(sum>target){
                        while(l<r&&nums[r]==nums[r-1])r--;
                        r--;
                    }
                    else if(sum<target){
                        while(l<r&&nums[l]==nums[l+1])l++;
                        l++;
                    }
                    else{
                        result.push_back({nums[i],nums[j],nums[l],nums[r]});
                        while(l<r&&nums[r]==nums[r-1])r--;
                        while(l<r&&nums[l]==nums[l+1])l++;
                        r--;
                        l++;
                    }
                }
            }
        }

        return result;
    }
};

