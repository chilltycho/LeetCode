//给定4个数组列表，计算有多少元组(i,j,k,l)使得A[i]+B[j]+C[k]+D[l]=0
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
{
    unordered_map<int, int> countAB;
    for (auto &u : A)
    {
        for (auto &v : B)
            countAB[u + v]++;
    }
    int res = 0;
    for (auto &c : C)
    {
        for (auto &d : D)
            if (countAB.count(-c - d))
                res += countAB[-c - d];
    }
    return res;
}