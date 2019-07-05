/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 *
 * https://leetcode-cn.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (30.95%)
 * Likes:    202
 * Dislikes: 0
 * Total Accepted:    14.9K
 * Total Submissions: 48.2K
 * Testcase Example:  '[1,2,3]'
 *
 * 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
 * 
 * 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
 * 
 * 必须原地修改，只允许使用额外常数空间。
 * 
 * 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if(len<2)return;
        auto it_i = nums.end()-1;
        while(it_i!=nums.begin()&&*(it_i-1)>=*(it_i)){
            it_i--;
        }
        if(it_i==nums.begin()){
            reverse(it_i,nums.end());
            return;
        }
        
        auto it_j = it_i;
        it_i--;
        while(it_j !=nums.end()-1&&*(it_j+1) >*it_i){
            it_j ++;
        }
        int temp = *it_j;
        *it_j = *it_i;
        *it_i = temp;
        reverse(it_i+1,nums.end());
        
    }
};

