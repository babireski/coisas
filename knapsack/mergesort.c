void mergesort(void* array, int n, int t, int (*compare)(const void*, const void*))
{
	split(array, 0, n - 1, t, compare);
}

void split(void* array, int leftmost, int rightmost, int t, int (*compare)(const void*, const void*))
{
	if(leftmost < rightmost)
	{
		int halfway = (leftmost + rightmost) / 2;
		split(array, leftmost, halfway, t, compare);
		split(array, halfway + 1, rightmost, t, compare);
		merge(array, leftmost, halfway, rightmost, t, compare);
	}
}

void merge(void* array, int leftmost, int halfway, int rightmost, int t, int (*compare)(const void*, const void*))
{
	int n = halfway - leftmost + 1;
	int m = rightmost - halfway;
	void* leftside = calloc(n, t);
	void* rightside = calloc(m, t);

	for(int i = 0; i < n; i++)
		leftside[i] = array[leftmost + i];
	
	for(int i = 0; i < m; i++)
		rightside[i] = array[halfway + i + 1];

	int i = 0;
	int j = 0;
	int k = leftmost;

	while(i < n && j < m)
	{
		if(leftside[i] <= rightside[j])
		{
			array[k] = leftside[i];
			i++;
		}

		else
		{
			array[k] = rightside[j];
			j++;
		}

		k++;
	}

	while(i < n)
	{
		array[k] = leftside[i];
		i++;
		k++;
	}
	

	while(j < m)
	{
		array[k] = rightside[j];
		j++;
		k++;
	}
}