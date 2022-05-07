#include <iostream>
#include <vector>
using namespace std;
inline int right(int i)
{
	return 2*i + 2;
}
inline int left(int i)
{
	return 2*i + 1;
}
void MAX_HEAPITY(vector<int>& v, int i)
{
	int l = left(i);
	int r = right(i);
	int largest = i;
	if (l < v.size() && v[l] >= v[i])
		largest = l;
	if (r < v.size() && v[r] >= v[largest])
		largest = r;
	if (largest != i)
	{
		iter_swap(v.begin() + i, v.begin() + largest);
		MAX_HEAPITY(v, largest);		
	}
}
void BUILD_MAX_HEAP(vector<int>& v)
{
	int heapsize = v.size()-1;
	for (int i = heapsize / 2; i >= 0; i--)
	{
		MAX_HEAPITY(v, i);
	}
}
