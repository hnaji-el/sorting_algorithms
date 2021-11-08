
#include <stdio.h>

/*
 * bubble sort is the simplest sorting algorithm
 * 1/ time complexity of bubble sort is Big Oh of n^2 in worst case
 * - Best case O(n)
 * - average case O(n^2)
 * bubble sort is a slow sorting algorithm
 * 2/ In-place sorting algorithm
 * 3/ stable
 * 4/ 5/ internal and non recursive sort
 */

void	bubble_sort(int	*arr, int n)
{
	int		temp;
	int		flag;
	int		i;
	int		j;

	i = 0;
	while (i <= n - 2)
	{
		j = 0;
		flag = 0;
		while (j <= n - 2 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = 1;
			}
			j++;
		}
		if (flag == 0)
			break ;
		i++;
	}
}

int	main(void)
{
	int		i;
	int		arr[] = {4, 3, 2, 1, 0};

	printf("--------ORIGINAL LIST--------\n");
	i = -1;
	while (++i < 5)
	{
		printf("%d\n", arr[i]);
	}
	bubble_sort(arr, 5);
	printf("--------SORTED LIST--------\n");
	i = -1;
	while (++i < 5)
	{
		printf("%d\n", arr[i]);
	}
	return (0);
}
