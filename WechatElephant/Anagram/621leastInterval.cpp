/*任务调度器：给定一个用字符数组表示的CPU需要执行的任务列表。包含A-Z任务，任务可任意顺序执行，每个任务单位
时间内完成，CPU任何一个单位时间内可执行一个任务，或在待命状态。
两个相同种类任务间必须有长度为n的冷却时间。求最短时间
输入：tasks=[A,A,A,B,B,B] n=2 
输出：8  AB0AB0AB  0表示待命*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
/*
所有任务安排完成后，若仍有剩余槽，则答案为任务数（填入槽）+剩余空闲时间
若槽不够，则答案一定为任务总数，这时将该任务直接往后加，一定满足冷却要求
*/
int leastInterval(vector<char> &tasks, int n)
{
    vector<int> mmap(26, 0);
    for (char c : tasks)
        mmap[c - 'A']++;
    sort(mmap.begin(), mmap.end());//按个数排序
    int max_val = mmap[25] - 1, idle_slots = max_val * n;//空闲槽为最大任务数-1 * n
    for (int i = 24; i >= 0 && mmap[i] > 0; i--)//剩余24个任务
        idle_slots -= min(mmap[i], max_val);//填充槽，优先排个数多的，最多消耗max_val个槽
    return idle_slots > 0 ? idle_slots + tasks.size() : tasks.size();
}

int main()
{
    vector<char> tasks{'A', 'A', 'A', 'B', 'B', 'B'};
    cout << leastInterval(tasks, 2) << endl;

    vector<char> tasks1{'A', 'A', 'B', 'B', 'C', 'C', 'D', 'D', 'E', 'E'};
    cout << leastInterval(tasks1, 4) << endl;
}