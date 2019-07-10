/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 *
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (36.58%)
 * Likes:    275
 * Dislikes: 0
 * Total Accepted:    28.6K
 * Total Submissions: 78.1K
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * 
 * ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
 * 
 * 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
 * 
 * 你可以假设数组中不存在重复的元素。
 * 
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 
 * 示例 1:
 * 
 * 输入: nums = [4,5,6,7,0,1,2], target = 0
 * 输出: 4
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [4,5,6,7,0,1,2], target = 3
 * 输出: -1
 * 
 */

#include <vector>
#include<iostream>

using namespace std;
class Solution {
public:

    int search_rotate_index(vector<int>& nums){
        int len = nums.size();
        int l=0,r = len-1;
        while(l<r){
            int mid = (l+r)/2;
            if(nums[mid]>nums[r]){
                l = mid+1;
            }
            else if(nums[mid]<nums[r]){
                r = mid;
            }
            else{

            }
        }
        return l;
    }

    int search(vector<int>& nums, int min,int max,int target){
        while(min<max){
            int mid = (min+max)/2;
            if(target<nums[mid]){
                max = mid;
            }
            else if(target>nums[mid]){
                min = mid+1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if(len==0) return-1;
        int rIndex = search_rotate_index(nums);
        cout<<rIndex<<endl;
        int result = search(nums, 0, rIndex,target);
        if(result==-1){
            return search(nums, rIndex, len,target);
        }
        else{
            return result;
        }
    }
};