//动态规划求解正则表达式匹配
/*要求：
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
    '.' 匹配任意单个字符
    '*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
*/
//算法思路
/*
从字符串p中取出一个【字符】或【字符+‘*’】在字符串s中进行匹配；
用 f[i][j] 表示 s 的前 i 个字符与 p 中的前 j 个字符是否能够匹配。
设计状态转移方程：
若p中第j个位置为字母或'.'，则f[i][j]=f[i-1][j-1](s[i]=p[j]);f[i][j]=false(s[i]≠p[j])
若p中第j个位置为'*'，则f[i][j]=f[i-1][j]或f[i][j-2](s[i]=p[j-1]);f[i][j]=f[i][j-2](s[i]≠p[j])
*/
bool isMatch(string s, string p)
{
    int n = s.length();
    int m = p.length();
    vector<vector<int>> f(n + 1, vector<int>(m + 1));
    auto matches = [&](int i, int j)
    {
        if (i == 0)
            return false;
        if (p[j - 1] == '.')
            return true;
        return s[i - 1] == p[j - 1];
    };
    f[0][0] = true;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (p[j - 1] == '*')
            {
                f[i][j] |= f[i][j - 2];
                if (matches(i, j - 1))
                {
                    f[i][j] |= f[i - 1][j];
                }
            }
            else
            {
                if (matches(i, j))
                    f[i][j] |= f[i - 1][j - 1];
            }
        }
    }
    return f[n][m];
}