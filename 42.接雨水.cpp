/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (44.45%)
 * Likes:    459
 * Dislikes: 0
 * Total Accepted:    17.8K
 * Total Submissions: 39.9K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢
 * Marcos 贡献此图。
 * 
 * 示例:
 * 
 * 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出: 6
 * 
 */
#include <vector>
#include<iostream>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int max_left = 0,max_right = 0;
        int result=0;
        while(left<right){
            if(height[left]<height[right]){
                height[left]>max_left?max_left = height[left]:result+=max_left-height[left];
                left++;
            }
            else{
                height[right]>max_right?max_right = height[right]:result+=max_right-height[right];
                right--;
            }
        }

        return result;
    }
};

