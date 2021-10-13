#include <iostream>
using namespace std;
//ex Генериране на n-торки
//boolean vector
// 2 -> [0,0]
//      [0,1]
//      [1,0]
//      [1,1]
void print(int* arr, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return;
}
void solve(int* arr, int currentPos, int lastPos)
{
	if (currentPos == lastPos)
	{
		print(arr, lastPos);
		return;
	}
	arr[currentPos] = 1;
	solve(arr, currentPos + 1, lastPos);
	arr[currentPos] = 0;
	solve(arr, currentPos + 1, lastPos);
	return;
}
