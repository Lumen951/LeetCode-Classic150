class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size(); // 如果数组长度小于等于2，直接返回长度

        int k = 2; // 计数，初始为2，因为最多保留两个相同的元素
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[k - 2]) { // 如果当前元素与前两个不同
                nums[k] = nums[i]; // 将当前元素放到新位置
                k++; // 增加计数
            }
        }
        return k; // 返回新长度
    }
};