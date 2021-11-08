

#include <stdio.h>

/*
 * ./  insertion sort is the simplest sorting algorithm.
 * ../ insertion sort is not the best sorting algorithm in terms of performance,
 * but it's a little more effecient than selection sort and bubble sort in
 * in practical scenarios.
 * 1/ time complexity of insertion sort is Big Oh of n^2 in worst case <unsorted>
 * - Best case O(n) <sorted list>
 * - average case O(n^2) <mid-way>
 * .../ insertion sort is a slow sorting algorithm.
 * ..../ Even though insertion sort is also O(n^2) for worst and average case,
 * the number of comparisons and shifts in insertion sort in all practical
 * scenarios is a lot less than selection and bubble sort.
 * 2/ In-place sorting algorithm
 * 3/ stable
 * 4/ 5/ internal and non recursive sort
 */

void	insertion_sort(int	*arr, int n)
{
	int		i;
	int		hole;
	int		value;

	i = 1;
	while (i <= n - 1)
	{
		value = arr[i];
		hole = i;
		while (hole > 0 && arr[hole - 1] > value)
		{
			arr[hole] = arr[hole - 1];
			hole -= 1;
		}
		arr[hole] = value;
		i++;
	}
}
