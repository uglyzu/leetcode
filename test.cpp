
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
        while(it_i!=nums.begin()&&*(it_i-1)>=*it_i){
            it_i--;
        }
        cout<<*it_i<<endl;
        auto it_j = it_i+1;
        while(it_j !=nums.end()&&*it_j >*it_i){
            it_j ++;
        }
        it_j--;
        cout<<*it_j<<endl;
        
        int temp = *it_j;
        *it_j = *it_i;
        *it_i = temp;

        reverse(it_i+1,nums.end());
    }
};

int main(){
    vector<int> a = {1,3,2};
    Solution s;
    s.nextPermutation(a);
    system("pause");
    return 0;
}