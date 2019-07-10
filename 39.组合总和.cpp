/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 *
 * https://leetcode-cn.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (65.64%)
 * Likes:    301
 * Dislikes: 0
 * Total Accepted:    23.2K
 * Total Submissions: 35.3K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的数字可以无限制重复被选取。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括 target）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: candidates = [2,3,6,7], target = 7,
 * 所求解集为:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入: candidates = [2,3,5], target = 8,
 * 所求解集为:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 */
#include <vector>
#include<iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> result;
        vector<int> temp;
        backtarce(candidates, target, result, 0, temp);
        return result;
    }

    void backtarce(vector<int>& candidates, int target, vector<vector<int>>& result, int i, vector<int>& temp){
        if(target<0) return;
        if(target==0){
            result.push_back(temp);
            return;\
        }
        for(int j=i;j<candidates.size();j++){
            if(target<candidates[j]) break;
            temp.push_back(candidates[j]);
            backtarce(candidates, target-candidates[j], result, j, temp);
            temp.pop_back();
        }
    }
};

