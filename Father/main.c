#include <stdio.h>
#include <string.h>
int num_of_generation = 0;
int forest_dim = 0;
char** forest = NULL;

void parse_file(FILE* input_f)
{	
	int temp = 0;
	fscanf(input_f, "%d", &num_of_generation);
	fseek(input_f,1,1 );
	fscanf(input_f, "%d", &forest_dim);
	fseek(input_f, 1, 1);
	printf("%d, %d", num_of_generation, forest_dim);
}

void init_forest(FILE* input_f)
{
	int i = 0, j = 0;
	char c ='a';
	char** forest = (char**)malloc(forest_dim * sizeof(char*));
	while (i < forest_dim)
	{
		putc(c, input_f);
		if ((c == '\n') || (c == ','))
			putc(c, input_f);
		forest[i][j] = c;
		j++;
		if (j == forest_dim)
		{
			j = 0;
			i++;
		}
	}
	printf("forest current condition: %s", forest);
}
int main(int argc, char* argv[]) {
	FILE* program = fopen(argv[1], "r"), *output = fopen("output.txt", "w");
	if (NULL == program || NULL == output)
		{
		printf("Failed to open one of the files, the program will execute with status 1"); //Failed to open one of the files.
		return 1;
	}
	parse_file(program);
	init_forest(program);
	//execute(program, output); //read from the input file and write to the output file
	return 0;
}