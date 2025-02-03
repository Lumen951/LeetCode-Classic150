class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 如果所有油量总和小于总消耗量，则不可能绕环行驶一周
        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) {
            return -1;
        }
        else{
            int N = gas.size();
            vector<int> diff(N, 0);
            int sum = 0;
            for(int i = 0; i < N; i++){
                diff[i] = gas[i] - cost[i];
            }
            for(int j = 0; j < N; j++){
                sum = 0;
                for(int k = 0; k < N ; k++){
                    int idx = (j + k) % N;
                    sum += diff[idx];
                    if(sum < 0){
                        break;
                    }
                }
                if(sum >= 0){
                    return j;
                }
            }
        }
        return -1;
    }
};

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int N = gas.size();
        int total = 0; // 记录所有位置的剩余油量总和
        int tank = 0;  // 当前油箱剩余油量
        int start = 0; // 出发起始位置
        for (int i = 0; i < N; i++) {
            int diff = gas[i] - cost[i];
            total += diff;
            tank += diff;
            // 如果当前油箱油量不足以到达下一个加油站，则重新设置起点
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }
        // 若总剩余油量不足，则不可能绕行一周
        return total < 0 ? -1 : start;
    }
};