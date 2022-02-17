class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while(left < right){
            int middle = left + ((right - left)/2);
            if (nums[middle]>target){
                right = middle;
            }
            else if(nums[middle] < target){
                left = middle + 1;
            }
            else return middle;
            }
            if(left==nums.size())return left;
            else if(left==0&&nums[left]>target){
                return 0;
            }
            else if(nums[left]>target)return left;
            else return  left+ 1;
        }
};