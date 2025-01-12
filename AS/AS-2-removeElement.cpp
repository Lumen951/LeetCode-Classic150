class Solution{

public:
    int removeElement(vector<int>& nums, int val){
        int k = 0; // 计数不等于 val 的元素
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) { // 如果当前元素不等于 val
                nums[k] = nums[i]; // 将当前元素放到前面
                k++; // 增加计数
            }
        }
        return k; // 返回不等于 val 的元素数量
    }
}