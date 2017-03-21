#include "SimSelSort.h"
#define MAX_INT 0x7fffffff
#define MIN_INT (-1)
/*简单选择排序*/
static void findTheSmallest(int *array,int size,int start);
/*双元选择排序*/
static void findTheSandB(int *array,int start,int end);

int SSsort::sort(int *array,int size)
{
	func(array,size);
}
void SSsort::func(int *array, int size)
{
	//findTheSmallest(array,size,0);
	findTheSandB(array,0,size-1);
}
/*
 * 找到最小的值放在最前
 * */
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
/*
 * 找到最小和最大分别放在最前和最后。
 * */
static void findTheSandB(int *array,int start,int end)
{
	if(start < end)
	{
		int i=start,smaller=MAX_INT,id_small=-1,largest=MIN_INT,id_large=-1;
		while(i<=end)
		{
			if(array[i] < smaller)
			{
				smaller = array[i];
				id_small = i;
			}
			if(array[i] > largest)
			{
				largest = array[i];
				id_large = i;
			}
			i++;
		}
		if(array[start] != array[id_small])
			array[start] ^= array[id_small] ^= array[start] ^= array[id_small];
		if(array[end] != array[id_large])
			array[end] ^= array[id_large] ^= array[end] ^= array[id_large];
		findTheSandB(array,start+1,end-1);
	}
	else
		return;
	
}
