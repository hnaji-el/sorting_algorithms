
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct	s_data
{
	int		*count_arr;
	int		*dup_arr;
	int		max;
}				t_data;

int	getmax(int	*arr, int n)
{
	int		max;
	int		i;

	i = 0;
	max = arr[0];
	while (++i <= n - 1)
	{
		if (max < arr[i])
			max = arr[i];
	}
	return (max);
}

t_data	*create_and_initialize_data(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data->count_arr = (void *)0;
	data->dup_arr = (void *)0;
	data->max = 10;
	return (data);
}

int	free_data(t_data *data)
{
	if (data->count_arr != NULL)
		free(data->count_arr);
	if (data->dup_arr != NULL)
		free(data->dup_arr);
	free(data);
	return (-1);
}

void	sort_original_array(int *arr, int i, t_data *data, int place)
{
	int		i_count;

	while (--i >= 0)
	{
		i_count = (data->dup_arr[i] / place) % 10;
		arr[data->count_arr[i_count] - 1] = data->dup_arr[i];
		data->count_arr[i_count] -= 1;
	}
}

void	fill_count_array(int *arr, int n, t_data *data, int place)
{
	int		i;

	i = -1;
	while (++i <= n - 1)
		data->count_arr[(arr[i] / place) % 10] += 1;
	i = 0;
	while (++i < data->max)
		data->count_arr[i] += data->count_arr[i - 1];
}

int	counting_sort(int *arr, int n, int place)
{
	t_data	*data;

	if (arr == NULL)
		return (-1);
	data = create_and_initialize_data();
	if (data == NULL)
		return (-1);
	data->dup_arr = (int *)malloc(sizeof(int) * n);
	if (data->dup_arr == NULL)
		return (free_data(data));
	memcpy(data->dup_arr, arr, sizeof(int) * n);
	data->count_arr = (int *)calloc(data->max, sizeof(int));
	if (data->count_arr == NULL)
		return (free_data(data));
	fill_count_array(arr, n, data, place);
	sort_original_array(arr, n, data, place);
	free_data(data);
	return (0);
}

int	radix_sort(int *arr, int n)
{
	int		place;
	int		max;

	max = getmax(arr, n);
	place = 1;
	while ((max / place) > 0)
	{
		if (counting_sort(arr, n, place) == -1)
			return (-1);
		place *= 10;
	}
	return (0);
}

int	main(void)
{
	int		i;
	int		arr[] = {2147483647, 90, 30, 55, 77};
	int		size = 5;

	printf("--------ORIGINAL LIST--------\n");
	i = -1;
	while (++i < size)
	{
		printf("%d\n", arr[i]);
	}
	radix_sort(arr, size);
	printf("--------SORTED LIST--------\n");
	i = -1;
	while (++i < size)
	{
		printf("%d\n", arr[i]);
	}
	return (0);
}
