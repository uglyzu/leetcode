/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 *
 * https://leetcode-cn.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (31.45%)
 * Likes:    135
 * Dislikes: 0
 * Total Accepted:    14.6K
 * Total Submissions: 46.2K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 * 
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 * 
 * 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
 * 
 * 
 * 
 * 网格中的障碍物和空位置分别用 1 和 0 来表示。
 * 
 * 说明：m 和 n 的值均不超过 100。
 * 
 * 示例 1:
 * 
 * 输入:
 * [
 * [0,0,0],
 * [0,1,0],
 * [0,0,0]
 * ]
 * 输出: 2
 * 解释:
 * 3x3 网格的正中间有一个障碍物。
 * 从左上角到右下角一共有 2 条不同的路径：
 * 1. 向右 -> 向右 -> 向下 -> 向下
 * 2. 向下 -> 向下 -> 向右 -> 向右
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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m==0) return 0;
        int n = obstacleGrid[0].size();

        vector<vector<long long>> a;
        for(int i=0;i<m;i++){
            a.push_back({});
            for(int j=0;j<n;j++){
                a[i].push_back(obstacleGrid[i][j]);
            }
        }
        if (a[0][0] == 1) {
            return 0;
        }
        a[0][0] = 1;
        for(int i=1;i<n;i++){
            if(a[0][i]==0&&a[0][i-1]==1){
                a[0][i] = 1;
            }
            else{
                a[0][i] = 0;
            }
        }

        for(int i=1;i<m;i++){
            if(a[i][0]==0&&a[i-1][0]==1){
                a[i][0] = 1;
            }
            else{
                a[i][0] = 0;
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(a[i][j] == 1){
                    a[i][j] = 0;
                }
                else{
                    a[i][j] = a[i-1][j] + a[i][j-1];
                }
            }
        }

        return a[m-1][n-1];
    }
};

