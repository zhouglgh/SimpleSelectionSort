#include "SimSelSort.h"
#define MAX_INT 0x7fffffff
static void findTheSmallest(int *array,int size,int start);

int SSsort::sort(int *array,int size)
{
	func(array,size);
}
void SSsort::func(int *array, int size)
{
	findTheSmallest(array,size,0);
}
static void findTheSmallest(int *array,int size,int start)
{
	if(start < size-1)
	{
		int i=start,smaller=MAX_INT,ident=-1;
		while(i<size)
		{
			if(array[i] < smaller)
			{
				smaller = array[i];
				ident= i;
			}
			i++;
		}
		if(array[start] != array[ident])
			array[start] ^= array[ident] ^= array[start] ^= array[ident];
		findTheSmallest(array,size,start+1);
	}
	else
		return;
}
