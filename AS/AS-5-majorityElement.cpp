
// 摩尔投票法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int candidate = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(count == 0){
                candidate = nums[i];
                count = 1;
            }
            else if(nums[i] == candidate){
                count++;
            }
            else{
                count--;
            }
        }
        return candidate;
    }
};

// 哈希表
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        int majority = 0, cnt = 0;
        for (int num: nums) {
            ++counts[num];
            if (counts[num] > cnt) {
                majority = num;
                cnt = counts[num];
            }
        }
        return majority;
    }
};

// 排序
// 时间复杂度：O(nlogn)
// 空间复杂度：O(1)
// 思路：排序后，众数一定在中间位置，因为一定要超过一半
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

// 分治
// 时间复杂度：O(nlogn)
// 空间复杂度：O(logn)
// 思路：将数组分成两部分，分别求出两部分的众数，然后合并
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return majorityElementRec(nums, 0, nums.size() - 1);
    }
};









