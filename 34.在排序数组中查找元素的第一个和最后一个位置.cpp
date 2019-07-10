/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (36.82%)
 * Likes:    146
 * Dislikes: 0
 * Total Accepted:    22.3K
 * Total Submissions: 60.5K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 * 
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 
 * 如果数组中不存在目标值，返回 [-1, -1]。
 * 
 * 示例 1:
 * 
 * 输入: nums = [5,7,7,8,8,10], target = 8
 * 输出: [3,4]
 * 
 * 示例 2:
 * 
 * 输入: nums = [5,7,7,8,8,10], target = 6
 * 输出: [-1,-1]
 * 
 */

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;
class Solution {
public:
    
    int searchExtremeIndex(vector<int>& nums, int target, bool left){
        int l = 0,r = nums.size();
        while(l<r){
            int mid = (l+r)/2;
            if(nums[mid]>target||left&&nums[mid]==target){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }

        return l;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result{-1,-1};

        int leftIndex = searchExtremeIndex(nums,target, true);
        if(leftIndex==nums.size()||nums[leftIndex]!=target){
            return result;
        }
        result[0] = leftIndex;
        result[1] = searchExtremeIndex(nums,target, false)-1;

        return result;
    }
};

