/*需选修numCourses门课程，记为0到numCourses-1。选修某些课程前需先修一些课程。
[0,1]表示1为0先修课程。判断能否完成所有课程学习*/

/*
拓扑排序作用：
1. 得到拓扑序，不唯一
2. 检测有向图是否有环，无向图使用并查集。
*/
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

bool canFinish(int numCourse, vector<vector<int>> &prerequisites) {
  vector<int> inDegree(numCourse);
  unordered_map<int, vector<int>> map;
  // 统计入度，建立邻接表
  for (int i = 0; i < prerequisites.size(); ++i) {
    ++inDegree[prerequisites[i][0]];
    map[prerequisites[i][1]].push_back(prerequisites[i][0]);
  }

  queue<int> mq;
  // 从入度为0的节点开始
  for (int i = 0; i < numCourse; ++i) {
    if (inDegree[i] == 0)
      mq.push(i);
  }
  int count = 0;
  // BFS
  while (mq.size()) {
    int selected = mq.front(); // 选一个入度为0的
    mq.pop();                  // 弹出队列
    ++count;
    auto toEnque = map[selected]; // 后续课程，遍历并将入度减一
    if (toEnque.size()) {
      for (int i = 0; i < toEnque.size(); ++i) {
        --inDegree[toEnque[i]];
        if (inDegree[toEnque[i]] == 0)
          mq.push(toEnque[i]);
      }
    }
  }
  return count == numCourse;
}
