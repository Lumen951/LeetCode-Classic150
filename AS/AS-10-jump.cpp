class Solution {
public:
    int jump(vector<int>& nums) {
        // 记录当前跳跃次数
        int jumps = 0;
        
        // 记录当前跳跃能够到达的最远位置
        int currentMax = 0;
        
        // 记录下一次跳跃能够到达的最远位置
        int nextMax = 0;
        
        // 遍历数组，注意这里只需要遍历到倒数第二个元素
        // 因为如果已经到达最后一个元素，就不需要再跳了
        for (int i = 0; i < nums.size() - 1; i++) {
            // 更新下一次能够到达的最远位置
            // nums[i] + i 表示从当前位置能跳到的最远距离
            nextMax = max(nextMax, nums[i] + i);
            
            // 如果已经到达当前跳跃能到达的最远位置
            // 说明需要进行下一次跳跃
            if (i == currentMax) {
                // 更新当前能够到达的最远位置
                currentMax = nextMax;
                // 跳跃次数加1
                jumps++;
            }
        }
        
        // 返回最小跳跃次数
        return jumps;
    }
};