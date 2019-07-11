/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 *
 * https://leetcode-cn.com/problems/insert-interval/description/
 *
 * algorithms
 * Hard (34.39%)
 * Likes:    50
 * Dislikes: 0
 * Total Accepted:    6.2K
 * Total Submissions: 17.9K
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * 给出一个无重叠的 ，按照区间起始端点排序的区间列表。
 * 
 * 在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
 * 
 * 示例 1:
 * 
 * 输入: intervals = [[1,3],[6,9]], newInterval = [2,5]
 * 输出: [[1,5],[6,9]]
 * 
 * 
 * 示例 2:
 * 
 * 输入: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * 输出: [[1,2],[3,10],[12,16]]
 * 解释: 这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
 * 
 * 
 */
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int len = intervals.size();
        vector<vector<int>> result;
        vector<int> temp = newInterval;
        int i=0;
        for(;i<len;i++){
            vector<int> last = intervals[i];
            if(last[1]<temp[0]){
                result.push_back(last);
            }
            else if(last[0]<=temp[1]){
                temp[0] = min(temp[0], last[0]);
                temp[1] = max(temp[1], last[1]);
            }
            else{
                break;
            }
        }
        result.push_back(temp);
        for(;i<len;i++){
            result.push_back(intervals[i]);
        }

        return result;
    }
};

