class Solution {
public:
    // 方法1: 使用清理后的字符串判断回文
    bool isPalindrome(string s) {
        string cleaned;
        // 转换为小写并只保留字母数字字符
        // 这样可以忽略大小写和非字母数字字符的影响
        for (char c : s) {
            if (isalnum(c)) {
                cleaned += tolower(c);
            }
        }
        
        // 使用双指针判断是否为回文
        // 左指针从开头开始，右指针从结尾开始，逐步向中间移动
        int left = 0, right = cleaned.length() - 1;
        while (left < right) {
            // 如果左右指针指向的字符不相等，则不是回文
            if (cleaned[left] != cleaned[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true; // 如果所有字符都匹配，则是回文
    }
    
    // 方法2: 使用反转字符串判断回文
    bool isPalindrome(string s) {
        string sgood;
        // 清理字符串，保留字母数字并转换为小写
        for (char ch: s) {
            if (isalnum(ch)) {
                sgood += tolower(ch);
            }
        }
        // 创建清理后字符串的反转版本
        string sgood_rev(sgood.rbegin(), sgood.rend());
        // 比较清理后的字符串和其反转版本是否相等
        return sgood == sgood_rev; // 如果相等，则是回文
    }

    // 方法3: 使用双指针直接在原字符串上判断回文
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        // 使用双指针，左指针从开头，右指针从结尾
        while (left < right) {
            // 跳过非字母数字字符
            while (left < right && !isalnum(s[left])) {
                ++left; // 左指针向右移动
            }
            while (left < right && !isalnum(s[right])) {
                --right; // 右指针向左移动
            }
            // 如果左右指针指向的字符不相等，则不是回文
            if (left < right) {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                ++left; // 左指针向右移动
                --right; // 右指针向左移动
            }
        }
        return true; // 如果所有字符都匹配，则是回文
    }
};
