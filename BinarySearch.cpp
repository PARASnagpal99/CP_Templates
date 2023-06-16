// binary search function using template
// n: size of arr
// x: value to search
// the fucntion returns -1 if x is not found in arr
// otherwise it returns index of x
template<typename T>
int binary_search(T arr[],int n,T x)
{
	int start = 0;
	int end = n-1;
	while(start<=end)
	{
		int mid = (start+end)/2;
		if(arr[mid]==x)	
			return mid;
		else if(arr[mid]<x)	
			start = mid + 1;
		else	
			end = mid - 1;
	}
	return -1;
}
