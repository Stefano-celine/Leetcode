//动态规划求解最长回文子串
//因为一个回文子串去掉两头后剩下的依然是回文串，得状态转移方程dp[i][j]=dp[i+1][j-1]∩s[i][j];
//当子串长度小于等于2时，得边界条件dp[i][i]=true或dp[i][i+1]=true(s[i]==s[i+1])
//时间复杂度O(n^2),空间复杂度O(n^2)
string longestPalindrome(string s)
{
    int n = s.length();
    if (n < 2)
        return s;
    vector<vector<int>> dp(n, vector<int>(n));//dp[i][j]表示s[i...j]是否为回文子串
    for (int i = 0; i < n; i++)// 初始化：所有长度为 1 的子串都是回文串
    {
        dp[i][i] = true;
    }
    int max = 1;
    int begin = 0;
    //枚举子串长度
    for (int L = 2; L <= n; L++)
    {
        //枚举左边界
        for (int i = 0; i < n; i++)
        {
            int j = L + i - 1;//j-i+1=L;L为子串长度
            if (j >= n)//右边界越界，退出循环
                break;
            if (s[i] != s[j])
                dp[i][j] = false;
            else
            {
                if (j - i < 3)//(j-1)-(i+1)<1化简得，还剩最后一个或零个必为回文子串
                    dp[i][j] = true;
                else
                    dp[i][j] = dp[i + 1][j - 1];
            }
            if (dp[i][j] && j - i + 1 > max)//是回文子串，且长度大于之前的回文串则记录该子串的起始位置和终止位置
            {
                max = j - i + 1;
                begin = i;
            }
        }
    }
    return s.substr(begin, max);
}
