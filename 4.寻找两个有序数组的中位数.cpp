/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (35.26%)
 * Likes:    1181
 * Dislikes: 0
 * Total Accepted:    62.9K
 * Total Submissions: 178.4K
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
 * 
 * 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 * 
 * 你可以假设 nums1 和 nums2 不会同时为空。
 * 
 * 示例 1:
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * 则中位数是 2.0
 * 
 * 
 * 示例 2:
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * 则中位数是 (2 + 3)/2 = 2.5
 * 
 * 
 */

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> A = nums1;
        vector<int> B = nums2;
        if(A.size()>B.size()){
            A = nums2;
            B = nums1;
        }
        int m = A.size();
        int n = B.size();

        int imin = 0, imax = m, half = (m+n+1)/2;
        while(imin<=imax){
            int i = (imin+imax)/2;
            int j = half-i;
            if(i<imax&&B[j-1]>A[i]){
                imin = i+1;
            }
            else if(i>imin&&A[i-1]>B[j]){
                imax = i-1;
            }
            else{
                int maxLeft=0;
                if(i==0){maxLeft = B[j-1];}
                else if(j==0){maxLeft = A[i-1];}
                else{maxLeft = max(A[i-1], B[j-1]);}
                
                if((m+n)%2==1){
                    return maxLeft;
                }

                int minRight = 0;
                if(i==m){minRight = B[j];}
                else if(j==n){minRight = A[i];}
                else{ minRight = min(A[i], B[j]);}

                return (maxLeft+minRight)/2.0;
            }
        }

        return 0.0;
    }
};

