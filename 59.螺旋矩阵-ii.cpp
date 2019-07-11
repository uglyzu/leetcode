/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 *
 * https://leetcode-cn.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (73.31%)
 * Likes:    109
 * Dislikes: 0
 * Total Accepted:    11.6K
 * Total Submissions: 15.8K
 * Testcase Example:  '3'
 *
 * 给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 * 
 */
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n==0)return {{}};
        vector<vector<int>> result(n,vector<int>(n,0));
        int l=0,r = n-1;
        int t = 0,b = n-1;
        int item=1;
        while(l<=r && t<=b){
            for(int i=l;i<=r;i++) result[t][i] = item++;
            for(int i=t+1;i<=b;i++) result[i][r] = item++;
            if(l<=r){
                for(int i=r-1;i>=l;i--) result[b][i]= item++;
            }
            if(t<=b){
                for(int i=b-1;i>=t+1;i--) result[i][l]= item++;
            }
            l++;
            r--;
            b--;
            t++;
        } 

        return result;
    }
};

