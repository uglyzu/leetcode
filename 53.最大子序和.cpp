/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 *
 * https://leetcode-cn.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (45.78%)
 * Likes:    1036
 * Dislikes: 0
 * Total Accepted:    68K
 * Total Submissions: 148.1K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 
 * 示例:
 * 
 * 输入: [-2,1,-3,4,-1,2,1,-5,4],
 * 输出: 6
 * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 * 
 * 
 * 进阶:
 * 
 * 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 * 
 */
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
   int divideSum(vector<int>& nums, int l, int r){
        if(l==r) return nums[l];
        if(l>r) return INT_MIN;
        int mid = (l+r)/2;
        int leftSum = divideSum(nums, l, mid-1);
        int rightSum = divideSum(nums, mid+1, r);
        int maxsum = nums[mid];
        int sum = nums[mid];
        for(int i=mid+1;i<=r;i++){
            sum+=nums[i];
            maxsum = max(maxsum,sum);
        }
        sum = maxsum;
        for (int i=mid-1;i>=l;i--){
            sum+=nums[i];
            maxsum = max(maxsum, sum);
        }

        return max(maxsum, max(leftSum,rightSum));
    }
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len==0)return 0;
        // int result = divideSum(nums,0,len-1);
        int result=INT_MIN;
        int sum=0;
        for(int i=0;i<len;i++){
            sum += nums[i];
            result = max(sum,result);
            if(sum<0){
                sum=0;
            }  
        }
        return result;
    }
};

