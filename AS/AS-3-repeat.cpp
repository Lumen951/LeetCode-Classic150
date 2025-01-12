class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0; // 如果数组为空，返回0

        int k = 1; // 唯一元素的计数，初始为1
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[k - 1]) { // 如果当前元素与最后一个唯一元素不同
                nums[k] = nums[i]; // 将当前元素放到唯一元素的后面
                k++; // 增加唯一元素的计数
            }
        }
        return k; // 返回唯一元素的个数
    }
};


