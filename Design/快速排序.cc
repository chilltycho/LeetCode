#include <vector>
#include <random>
#include <iostream>
using namespace std;
/*
时间复杂度为nlogn: 分治算法，每次选出哨兵，将待排序列分成两部分，一直分下去，直到只有一个元素，平均分开，相当于n个结点的二叉树，共有logn层，递归深度为logn。
空间复杂度O(logn)~O(n)：主要是递归造成的栈空间的使用，最好情况递归树深度为logn，最坏情况为n

快排的最差情况什么时候发生？
已排序，数值全部相等（1的特殊情况）

在上面的情况下选择的标定元素一直为第一个，则时间复杂度变为O(n^2)
rand()返回0到RAND_MAX间伪随机数。
*/

//双路快排
int partition2(vector<int> &data, int start, int end)
{
	int index = (rand() % (end - start + 1)) + start;
	swap(data[index], data[start]);
	int pivot = data[start];
	int i = start + 1, j = end;
	while (true)
	{
		while (i <= end && data[i] <= pivot)
			i++;
		while (j >= start + 1 && data[j] >= pivot)
			j--;
		if (i > j)
			break;
		swap(data[i], data[j]);
		i++;
		j--;
	}
	//最后j停止在<= v的最后一个位置， i停止在>=pivot的第一个位置，pivot与j进行交换
	swap(data[start], data[j]);
	return j;
}

void quickSortOffer(vector<int> &data, int start, int end)
{
	if (start >= end)
		return;
	int index = partition2(data, start, end);
	quickSortOffer(data, start, index - 1);
	quickSortOffer(data, index + 1, end);
}

int main()
{
	vector<int> res{2, 3, 5, 1, 1, 0};
	quickSortOffer(res, 0, res.size() - 1);
	for (auto c : res)
		cout << c << ' ';
}