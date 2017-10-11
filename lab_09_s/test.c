#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str.h"

int main(void)
{
	int err_code = 0;

	char* str1 = "word1, word2! word3. word4?";
	char strcmp_my1[][100] = {"word1", "word2", "word3", "word4"};
	int count_res_my1 = 4;
	
	int count_str1 = my_count_str(str1);
	printf("%d\n", count_str1);
	
	if ( count_str1 == count_res_my1 )
	{
		err_code++;
	}
	if ( count_str1 )
	{
		//char *result1[100]; 
		char **result1 = malloc(count_str1 * sizeof(char*));
		if ( 1 )
		{
			//my_strtok(str1, result1);
			for ( int i = 0; i < count_str1; ++i )
			{
				if ( strcmp(strcmp_my1[i], result1[i]) != 0 )
				{
					err_code++;
				}
			}
			free(result1);
		}
	}
	
	char* str2 = "";
	int count_str2 = my_count_str(str2);
	int count_res_my2  = 0;
	
	printf("%d\n", count_str2);
	if ( count_str2 == count_res_my2 )
	{
		err_code++;
	}
	if ( count_str2 )
	{
		//char *result1[100]; 
		char **result2 = malloc(count_str2 * sizeof(char*));
		if ( 1 )
		{
			//my_strtok(str1, result1);
			for ( int i = 0; i < count_str2; ++i )
			{
				if ( strcmp(strcmp_my1[i], result2[i]) != 0 )
				{
					err_code++;
				}
			}
			free(result2);
		}
	}
	
	
	//int result_count1 = 4;
	//if ( result_count1 == count_str1 )

	return 0;
}
