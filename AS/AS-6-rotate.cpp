// 时间复杂度：O(n)
// 空间复杂度：O(n)
// 思路：将数组复制一份，然后根据k计算出新的位置
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n);
        for(int i = 0; i < n; i++){
            temp[(i + k) % n] = nums[i];
        }
        nums = temp;
    }
};

// 时间复杂度：O(n)
// 空间复杂度：O(1)
// 思路：翻转数组
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        // 处理 k 大于数组长度的情况
        k = k % n;
        
        // 翻转整个数组
        reverse(nums.begin(), nums.end());
        // 翻转前 k 个元素
        reverse(nums.begin(), nums.begin() + k);
        // 翻转剩余元素
        reverse(nums.begin() + k, nums.end());
    }
};
