class Solution {
public:
    // 本方法用于计算一个新数组，
    // 其中每个位置的值为原数组中除该位置外所有元素的乘积
    vector<int> productExceptSelf(vector<int>& nums) {
        // 获取输入数组的长度
        int N = nums.size();
        // 初始化答案数组 answer，每个元素初始为1
        // 使用1作为乘法的单位元，方便后续累乘操作
        std::vector<int> answer(N, 1);
        
        // 下面的循环计算从左向右的前缀乘积：
        // 对于每个位置 i，计算其左侧（不含当前位置）的所有数字乘积
        // 注意：对于 i==0，由于左侧没有元素，所以前缀乘积应为1
        for (int i = 1; i < N; i++){
            // answer[i-1] 保存了 nums[0] 到 nums[i-2] 的乘积，
            // 乘上 nums[i-1] 就得到了所有左侧数字的乘积
            // (但当 i==0 时，由于没有左侧元素，通常应直接保持为1；
            // 这里的实现可能会越界，一般建议从 i=1 开始循环)
            answer[i] = answer[i-1] * nums[i-1];
        }

        // 初始化后缀乘积 suffix 为1，
        // 用于记录从右到当前位置右侧所有数字的乘积
        int suffix = 1;
        
        // 从右向左遍历数组，计算后缀乘积并与之前计算的前缀乘积相乘
        for (int i = N-1; i >= 0; i--){
            // 此时 answer[i] 存储了左侧所有数字的乘积，
            // 乘以 suffix（即右侧所有数字的乘积）后，就得到了除 nums[i] 本身外全部数字的乘积
            answer[i] = answer[i] * suffix;
            // 更新后缀乘积，乘上当前位置的数字，为下一个位置准备
            suffix *= nums[i];
        }
        
        // 返回最终构造好的答案数组
        return answer;
    }
};