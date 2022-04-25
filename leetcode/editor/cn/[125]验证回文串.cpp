//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。 
//
// 说明：本题中，我们将空字符串定义为有效的回文串。 
//
// 
//
// 示例 1: 
//
// 
//输入: "A man, a plan, a canal: Panama"
//输出: true
//解释："amanaplanacanalpanama" 是回文串
// 
//
// 示例 2: 
//
// 
//输入: "race a car"
//输出: false
//解释："raceacar" 不是回文串
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 2 * 105 
// 字符串 s 由 ASCII 字符组成 
// 
// Related Topics 双指针 字符串 
// 👍 519 👎 0

#include<bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(char ch : s){
            // 只考虑字母和数字字符
            if(isalnum(ch)){
                // 将字符转换为小写
                str += tolower(ch);
            }
        }
        /**
         * c.rbegin() 返回一个逆序迭代器，它指向容器c的最后一个元素
         * c.rend() 返回一个逆序迭代器，它指向容器c的第一个元素前面的位置
         */
        string str2(str.rbegin(), str.rend());
        // 判断是否为回文串
        return str == str2;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
int main() {
    Solution s;
    cout << (s.isPalindrome("A man, a plan, a canal: Panama") ?"true":"false")<< endl;
    return 0;
}
