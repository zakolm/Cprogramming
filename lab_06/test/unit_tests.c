#include <stdio.h>
#include "../resultex.h"

void test_sum_el( void )
{ 
    int ok_count = 0; 
    int a[] = {-5, 2, -3, -4, -1};
    int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int c[] = {11};
	int e[] = {0, 0, 0, 0};
    long int sum = 0;
    int result_a = -5;
    int result_b = 409113;
    int result_c = 11;
	int result_e = 0;
    
    result(a, a + 5, &sum);
    if (result_a == sum)
	{
        ok_count++;
	}

    result(b, b + 9, &sum);
    if (result_b == sum)
	{
        ok_count++;
	}
    
    result(c, c + 1, &sum);
    if (result_c == sum)
	{
        ok_count++;  
	}
	
	result(e, e + 4, &sum);
	if (result_e == sum)
	{
		ok_count++;
	}
    printf("%s: %s\n", __func__, !ok_count ? "FAILED" : "OK");    
}
