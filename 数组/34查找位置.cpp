//二分查找 + 线性展开，性能为O（N)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while(left < right){
            int middle = left + ((right - left) >> 1);
            if(nums[middle]>target){
                right = middle;
            }
            else if (nums[middle]<target){
                left = right + 1;
            }
            else{
                int middle1 = middle;
                while(nums[middle]==nums[middle - 1]){
                    middle -= 1;
                }
                while(nums[middle1]==nums[middle1 + 1]){
                    middle1 += 1;
                }
                cout << "[" << middle << "," << middle1 << "]";
                return;
            }
        }
        cout << "[" << -1 << "," << -1 << "]";
        return;
    }
};
