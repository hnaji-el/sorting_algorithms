
#include <stdio.h>

/*
 * selection sort is the simplest sorting algorithm
 * 1/ time complexity of selection sort is Big Oh of n^2
 * selection sort is a slow sorting algorithm
 * 2/ In-place sorting algorithm
 * 3/ stable
 * 4/ 5/ internal and non recursive sort
 */

void	selection_sort(int	*arr, int n)
{
	int		temp;
	int		i_min;
	int		i;
	int		j;

	i = 0;
	while (i <= n - 2)
	{
		i_min = i;
		j = i + 1;
		while (j <= n - 1)
		{
			if (arr[j] < arr[i_min])
				i_min = j;
			j++;
		}
		temp = arr[i_min];
		arr[i_min] = arr[i];
		arr[i] = temp;
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
	selection_sort(arr, 5);
	printf("--------SORTED LIST--------\n");
	i = -1;
	while (++i < 5)
	{
		printf("%d\n", arr[i]);
	}
	return (0);
}
