/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 *
 * https://leetcode-cn.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (41.04%)
 * Likes:    204
 * Dislikes: 0
 * Total Accepted:    29.4K
 * Total Submissions: 71.7K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target
 * 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 * 
 * 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
 * 
 * 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
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
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int result = nums[0]+nums[1]+nums[2];
        for(int i=0;i<len-2;i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            int l = i+1;
            int r = len-1;
            while(l<r){
                int sum = nums[i]+nums[l]+nums[r];
                if(abs(target-sum)<abs(target-result)){
                    result = sum;
                }
                if(sum>target){
                    while(l<r&&nums[r]==nums[r-1]) r--;
                    r--;
                }
                else if(sum<target){
                    while(l<r&&nums[l]==nums[l+1]) l++;
                    l++;
                }
                else{
                    return sum;
                }
                
            }
        }
        return result;
    }
};

