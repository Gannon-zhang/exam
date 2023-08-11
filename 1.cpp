#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int timeToMinutes(const string& time) {
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    return h * 60 + m;
}

int minOperations(string s, string t) {
    int sMinutes = timeToMinutes(s);
    int tMinutes = timeToMinutes(t);
    vector<int> dp(1440, 0);  // dp[i] represents the minimum operations to reach time i

    for (int i = sMinutes; i <= tMinutes; ++i) {
        dp[i] = i - sMinutes;  // Initialize with the difference in minutes
        if (i >= 1) dp[i] = min(dp[i], dp[i - 1] + 1);   // Add 1 minute
        if (i >= 5) dp[i] = min(dp[i], dp[i - 5] + 1);   // Add 5 minutes
        if (i >= 15) dp[i] = min(dp[i], dp[i - 15] + 1); // Add 15 minutes
        if (i >= 60) dp[i] = min(dp[i], dp[i - 60] + 1); // Add 60 minutes
    }

    return dp[tMinutes];
}

int main() {
    string s = "12:30";
    string t = "15:45";
    int result = minOperations(s, t);
    cout << "Minimum operations: " << result << endl;
    return 0;
}

// 下面是一个使用动态规划（Dynamic Programming）的C++实现，来计算将时间字符串 s 转换为时间字符串 t 的最少操作次数。我们可以首先将时间字符串转换为分钟数，然后使用动态规划计算从一个时间到另一个时间的最少操作次数。
// 在上面的代码中，timeToMinutes 函数将时间字符串转换为分钟数，然后使用动态规划数组 dp 计算从起始时间到目标时间的最少操作次数。最后，返回 dp[tMinutes] 即为最少操作次数。
// 请注意，上述代码假定输入的时间字符串合法且格式正确，未作错误处理。在实际应用中，可能需要添加适当的输入验证和错误处理。
