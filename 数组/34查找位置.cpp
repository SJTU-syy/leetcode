//answer
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1,-1};//empty optimization
        
        int left = 0;
        int right = nums.size()-1;//right open -> close
        while(left < right){
            int middle = (right + left)/2;
            if(nums[middle] >= target)
                right = middle;
            else
                left = middle + 1;
        } 
        if( nums[right] != target) return {-1,-1}; 
        int L = right;
        left = 0;
        right = nums.size()-1;
        while(left < right){
            int m = (right + left + 1) / 2;
            if(nums[m]<=target)
                left = m;
            else
                right = m - 1;
        }
        return {L,right};
    }
};


//ck-非对称二分寻找<=/>=
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1,-1};
    
        int l = 0, r = nums.size() - 1; //二分范围
        while( l < r)			        //查找元素的开始位置
        {
            int mid = (l + r )/2;
            if(nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        if( nums[r] != target) return {-1,-1};  //查找失败
        int L = r;
        l = 0, r = nums.size() - 1;     //二分范围
        while( l < r)                   //查找元素的结束位置
        {
            int mid = (l + r + 1)/2;
            if(nums[mid] <= target ) l = mid;
            else r = mid - 1;
        }
        return {L,r};
    }
};



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
