//给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i]
// 是指在第 i 天之后，才会有更高的温度
//。如果气温在这之后都不会升高，请在该位置用 0 来代替。 
//
// 
//
// 示例 1: 
//
// 
//输入: temperatures = [73,74,75,71,69,72,76,73]
//输出: [1,1,4,2,1,1,0,0]
// 
//
// 示例 2: 
//
// 
//输入: temperatures = [30,40,50,60]
//输出: [1,1,1,0]
// 
//
// 示例 3: 
//
// 
//输入: temperatures = [30,60,90]
//输出: [1,1,0] 
//
// 
//
// 提示： 
//
// 
// 1 <= temperatures.length <= 105 
// 30 <= temperatures[i] <= 100 
// 
// Related Topics 栈 数组 单调栈 
// 👍 1119 👎 0

#include<bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int ans[temperatures.size()];
        //初始化ans
        for(int i=0;i<temperatures.size();i++){
            ans[i]=0;
        }
        //初始化单调栈
        stack<int> st;
        //遍历temperatures
        for (int i = 0; i < temperatures.size(); ++i) {
            //如果单调栈为空，或者当前温度比栈顶元素大，则入栈
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                //计算ans
                ans[st.top()] = i - st.top();
                //出栈
                st.pop();
            }
            //入栈
            st.push(i);
        }
        //返回ans
        return vector<int>(ans, ans + temperatures.size());
    }
};
//leetcode submit region end(Prohibit modification and deletion)
int main(){
    Solution solution;
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    vector<int> ans = solution.dailyTemperatures(temperatures);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
