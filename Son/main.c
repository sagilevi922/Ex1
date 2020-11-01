#include <stdio.h>


int count_burned_trees(char* forest)
{
	int count_burned = 0;
	char* tree = forest;
	while (*tree != '\0')
	{
		if (*tree == 'F')
			count_burned++;
		tree++;
	}
	return count_burned;
}

int main(int argc, char* argv[])
{
	char* forest = argv[1];
	int num_of_burned = 0;
	if (NULL == forest)
	{
		printf("Invalid input: Empty Forest");
	}
	num_of_burned = count_burned_trees(forest);
	printf("num of burned: %d", num_of_burned);
	return 0;
}