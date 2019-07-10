/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode-cn.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (36.25%)
 * Likes:    176
 * Dislikes: 0
 * Total Accepted:    17.1K
 * Total Submissions: 47K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
 * 
 * 示例 1:
 * 
 * 输入:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * 输出: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * 输出: [1,2,3,4,8,12,11,10,9,5,6,7]
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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int n = matrix.size();
        if(n==0) return result;
        int m = matrix[0].size();
        int l=0,r = m;
        int t = 0,b = n;
        while(true){
            for(int i=l;i<r;i++) result.push_back(matrix[t][i]);
            if(++t>=b) break;
            for(int i=t;i<b;i++) result.push_back(matrix[i][r-1]);
            if(--r<=l) break;
            for(int i=r-1;i>=l;i--) result.push_back(matrix[b-1][i]);
            if(--b<=t) break;
            for(int i=b-1;i>=t;i--) result.push_back(matrix[i][l]);
            if(++l>=r) break;
        }

        return result;
    }
};

