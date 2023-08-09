/*给定一个只包含数字的字符串，复原它并返回所有可能的IP地址格式
输入：25525511135
输出：["255.255.11.135","255.255.111.35"]*/
#include <iostream>
#include <vector>
using namespace std;

vector<string> path;
vector<string> res;

    void dfs(const string& s, int start){
        if(path.size()==4&&start==s.size()){
            string tmp{};
            for(auto & t_s: path){
                tmp+=t_s+".";
            }
            tmp.pop_back();
            res.push_back(tmp);
            return;
        }
        if(start>s.size()){
            return;
        }
        for(int i=1;i<4;i++) {
            string ip0 = s.substr(start,i);
            if(i>1&&ip0[0]=='0'){
                return;
            }
            if(!ip0.empty()&&stoi(ip0)>255){
                return;
            }
            path.push_back(ip0);
            dfs(s,start+i);
            path.pop_back();
        }

    }

vector<string> restoreIpAddresses(string s) {
  if (s.size() < 4 || s.size() > 12)
    return res;
  dfs(s, 0);
  return res;
}

int main() {
  string s = "25525511135";
  auto res = restoreIpAddresses(s);
  for (auto c : res)
    cout << c << ' ';
}