/*
1. 二分查找前提：1有序2无重复
2. 循环不变原则→二分有闭区间和左闭右开两种写法
*/


//闭区间
class Solution {
public:
    int search(vector<int>& nums, int target) {
            int left = 0;
            int right = nums.size() - 1;
            while (left<=right){
                int middle = left + ((right-left)/2);
                if(nums[middle] > target){
                    right = middle - 1;
                }
                else if(nums[middle] < target){
                    left = middle + 1;
                }
                else{return middle;}
            }
            return -1;
    }
};

//左闭右开
class Solution {
    public:
        int search(vector<int>& nums, int target){
            int left = 0;
            int right = nums.size();
            while(left<right){
                int middle = left + ((right - left)>>1);
                if(nums[middle] > target){
                    right = middle;
                }
                else if(nums[middle] < target){
                    left = middle + 1;
                }
                else
                    return middle;
            }
            return -1;
        }
};