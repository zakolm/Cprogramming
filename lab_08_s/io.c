#include <stdio.h>
#define OK 0
#define ERRORINPUT 1
#define MAXN 5
#define MAXM 7
#define MAXCOUNT 35

void write_array(FILE* f, int* count_n, int* count_m, int (*pa)[MAXM] )
{
	int count_i = 1, count_j = 1, count_el = 1;
	while( fscanf(f, "%d", &(*(*pa+count_el))) == 1 ) {
		count_el++;
		if (count_j >= MAXM && count_i >= MAXN )
			break;
		if ( count_i >= MAXN ){
			count_j++;
			count_i = 0;
		} else {
			count_i++;
		}
	}
	*count_n = count_i;
	*count_m = count_j;
}

int max_in_array(const int count, const int *pa) {
	int max = *pa;
	for ( int i = 0; i < count; ++i) {
		if ( max < *(pa+i) )
			max = *(pa+i);
	}
	return max;
}

void swap(const int count, int* pa, int* sa) {

	for(int i = 0; i < count; i++){
	    int tmp_item = *(pa +i);
	    *(pa+i)=*(sa+i);
	    *(sa+i)=tmp_item;
	}
}
/*
void sort(const int count_n, const int count_m, int array) {
	for (int i = 0; i < count_m; ++i) {
		if (max_in_array(count_n, int () )
	}
}
*/
int main(int argc, char** argv) {
	FILE* f;
	int rc = OK;

	if ( argc != 2 ) {
		printf("ERROR INPUT");
		return ERRORINPUT;
	}

	f = fopen(argv[1], "r");
	int count_n, count_m;
	int array[MAXN][MAXM];
	write_array(f, &count_n, &count_m, array);
	return OK;
}