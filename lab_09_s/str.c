#include <string.h>
#include "str.h"
#define DEL "!,.:; "

int my_count_str(char* str)
{
	int count = 0;
	int len = strlen(str);
	for ( int i = 0; i < len; ++i )
	{
		if ( !strchr(DEL, str[i]) )
		{
			if ( i == 0 || strchr(DEL, str[i-1]) )
			{
				count++;
			}
		}
	}
	return count;
}

void my_strtok(char* str, char** words)
{
	int n = 0;
	int len = strlen(str);
	for ( int i = 0; i < len-1; ++i )
	{
		if ( !strchr(DEL, str[i]) )
		{
			if ( i == 0 || str[i-1] == 0 )
			{
				words[n] = &str[i];
				n++;
			}
		} else
		{
			str[i] = 0;
		}
	}
}

void my_sort(char** words; int count_str)
{
	for ( int i = 0; i < count_str; ++i )
	{
		for( int j = 0 ; j < count_str - i - 1 ; j++ ) { 
			if( strcmp(words[j], words[j+1]) > 0 )
			{
				char tmp[100];
				strcpy(tmp, words[j]);
				strcpy(words[j], words[j+1]);
				strcpy(words[j], tmp);
			}
		}
	}
}
