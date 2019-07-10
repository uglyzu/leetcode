/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 *
 * https://leetcode-cn.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (55.88%)
 * Likes:    113
 * Dislikes: 0
 * Total Accepted:    15.8K
 * Total Submissions: 28.2K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的每个数字在每个组合中只能使用一次。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括目标数）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 所求解集为:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 所求解集为:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 */

#include <vector>
#include<iostream>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    map<vector<int>, int> item;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> result;
        vector<int> temp;
        backtarce(candidates, target, 0, temp);
        for(auto i:item){
            result.push_back(i.first);
        }
        return result;
    }

    void backtarce(vector<int>& candidates, int target, int i, vector<int>& temp){
        if(target<0) return;
        if(target==0){
            item[temp] = 1;
            return;
        }
        for(int j=i;j<candidates.size();j++){
            if(target<candidates[j]) break;
            temp.push_back(candidates[j]);
            backtarce(candidates, target-candidates[j], j+1, temp);
            temp.pop_back();
        }
    }
};

