#include <stdio.h>
#include <string.h>

void resever(char* arr)
{
	char* left = arr;
	char* right = arr + strlen(arr) - 1;
	while (left < right)
	{
		char temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}
}

int main()
{
	char arr[10] = { 0 };
	scanf("%s", &arr);

	resever(arr);
	printf("%s", arr);

	return 0;
}
