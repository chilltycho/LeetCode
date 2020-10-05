/*给定列表accounts,accounts[i][0]是name,其余为该用户邮箱,现想合并账户,若有共同邮件
地址,则两个账户必定属于同一人*/
#include <vector>
#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;
static const int N = 1010;
int p[N];
unordered_map<string, int> email2id;
vector<vector<string>> res;
int find(int a)
{
    if (p[a] != a)
        p[a] = find(p[a]);
    return p[a];
}
vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
{
    int n = accounts.size();
    for (int i = 0; i < n; i++) //n个账户
        p[i] = i;
    for (int i = 0; i < n; i++)
        for (int j = 1; j < accounts[i].size(); j++) //遍历邮箱
        {
            string email = accounts[i][j];
            if (email2id.count(email))
                p[find(email2id[email])] = p[i];//若两账户邮箱相同,则建立UF连接 
            else
                email2id[email] = i;//每个邮箱对应一个id
        }
    unordered_map<int, set<string>> id2email;
    for (int i = 0; i < n; i++)
    {
        int t = find(i);
        for (int j = 1; j < accounts[i].size(); j++)
            id2email[t].insert(accounts[i][j]); //同一id下邮箱,set保证邮箱唯一性
    }
    for (auto &p : id2email)
    {
        vector<string> ans;
        ans.push_back(accounts[p.first][0]);//压入姓名
        for (string email : p.second)
            ans.push_back(email);//压入邮箱
        res.push_back(ans);
    }
    return res;
}
int main()
{
    vector<vector<string>> accounts{{"John", "johnsmith@mail.com", "john00@mail.com"},
                                    {"John", "johnnybravo@mail.com"},
                                    {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
                                    {"Mary", "mary@mail.com"}};
    vector<vector<string>> res{{"John", "jonnybravo@mail.com"},
                               {"John", "john00@mail.com", "john_newyork@mail.com", "johnsmith@mail.com"},
                               {"Mary", "mary@mail.com"}};
    auto res1 = accountsMerge(accounts);
    for (auto c : res1)
    {
        for (auto cc : c)
            cout << cc << ' ';
        cout << endl;
    }
}