#include <vector>
using namespace std;
int binarySearch(vector<int> &arr, int target)
{

	//在[l,r]中查找target
	//包含右边界
	int n = arr.size();
	int l = 0, r = n - 1;
	int res;
	while (l <= r)
	{
		//int mid = (l + r) / 2;
		//防止溢出
		int mid = l + (r - l) / 2;
		if (arr[mid] == target)
		{
			res = mid;
			break;
		}
		//在[l,mid-1]中查找target
		else if (arr[mid] > target)
			r = mid - 1;
		//在[mid+1,r]中查找target
		else
			l = mid + 1;
	}
	return res;
}

int first(vector<int> &data, int k)
{
	int l = 0, r = data.size();
	while (l < r)
	{
		int m = l + (r - l) / 2;
		if (data[m] < k)
			l = m + 1;
		else
			r = m;
	}
	return l; // k最左索引
}

int last(vector<int> &data, int k)
{
	int l = 0, r = data.size();
	while (l < r)
	{
		int m = l + (r - l) / 2;
		if (data[m] <= k)
			l = m + 1;
		else
			r = m;
	}
	return l; // 最后一个元素索引+1
}