/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 *
 * https://leetcode-cn.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (36.69%)
 * Likes:    139
 * Dislikes: 0
 * Total Accepted:    18.6K
 * Total Submissions: 50.5K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 给出一个区间的集合，请合并所有重叠的区间。
 * 
 * 示例 1:
 * 
 * 输入: [[1,3],[2,6],[8,10],[15,18]]
 * 输出: [[1,6],[8,10],[15,18]]
 * 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2:
 * 
 * 输入: [[1,4],[4,5]]
 * 输出: [[1,5]]
 * 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 */
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int len = intervals.size();
        vector<vector<int>> result;
        if(len==0) return result;
        sort(intervals.begin(),intervals.end(), comp);
        
        vector<int> temp = intervals[0];
        for(int i=1;i<len;i++){
            vector<int>& last = intervals[i];
            if(last[0]<=temp[1]){
                temp[1] = max(temp[1],last[1]);
            }
            else{
                result.push_back(temp);
                temp=last;
            }
        }
        result.push_back(temp);

        return result;
    }
};

