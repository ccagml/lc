/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 *
 * https://leetcode.cn/problems/redundant-connection/description/
 *
 * algorithms
 * Medium (67.39%)
 * Likes:    504
 * Dislikes: 0
 * Total Accepted:    83.3K
 * Total Submissions: 123.6K
 * Testcase Example:  '[[1,2],[1,3],[2,3]]'
 *
 * 树可以看成是一个连通且 无环 的 无向 图。
 *
 * 给定往一棵 n 个节点 (节点值 1～n) 的树中添加一条边后的图。添加的边的两个顶点包含在 1 到 n
 * 中间，且这条附加的边不属于树中已存在的边。图的信息记录于长度为 n 的二维数组 edges ，edges[i] = [ai, bi] 表示图中在 ai
 * 和 bi 之间存在一条边。
 *
 * 请找出一条可以删去的边，删除后可使得剩余部分是一个有着 n 个节点的树。如果有多个答案，则返回数组 edges 中最后出现的边。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入: edges = [[1,2], [1,3], [2,3]]
 * 输出: [2,3]
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入: edges = [[1,2], [2,3], [3,4], [1,4], [1,5]]
 * 输出: [1,4]
 *
 *
 *
 *
 * 提示:
 *
 *
 * n == edges.length
 * 3
 * edges[i].length == 2
 * 1
 * ai != bi
 * edges 中无重复元素
 * 给定的图是连通的 
 *
 *
 */

// @lc code=start

class uf
{
public:
    vector<int> vf;
    uf(int n)
    {
        for (int i = 0; i < n + 1; i++)
        {
            vf.push_back(i);
        }
    }
    int get_f(int i)
    {
        if (i == vf[i])
        {
            return i;
        }
        vf[i] = get_f(vf[i]);
        return vf[i];
    }
    void set_f(int i, int j)
    {
        int fi = get_f(i);
        int fj = get_f(j);
        if (fi > fj)
        {
            vf[fi] = fj;
        }
        else if (fi < fj)
        {
            vf[fj] = fi;
        }
    }
};

class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        uf *my_uf = new uf(n);
        for (int i = 0; i < n; i++)
        {
            vector<int> &temp = edges[i];
            int a = temp[0];
            int b = temp[1];
            int fa = my_uf->get_f(a);
            int fb = my_uf->get_f(b);
            if (fa == fb)
            {
                return temp;
            }
            my_uf->set_f(a, b);
        }
        vector<int> temp;
        return temp;
    }
};
// @lc code=end
