#include <stdio.h>
#include <math.h>

int main(void) 
{     
	float a, b, c, d;  
    printf("Enter a, b, c: ");

    setbuf(stdout,NULL);
	if (scanf("%f%f%f", &a, &b, &c) == 3)
	{
         if (a != 0.0)
         {
			d = b * b - 4 * a * c;  
            if (d < 0.0)             
			{
				printf("There are no real roots\n");
			}
			else if (d > 0)
			{
			printf("x1 = %f, x2 = %f\n", (-b - sqrt(d)) / (2 * a),
										(-b + sqrt(d)) / (2 * a));
			}
			else
			{
				printf("x1 = x2 = %f\n", -b / (2 * a));
			}
		}
		else
		{
			printf("Equation is not square\n");
		}
	}
	else
	{
		printf("I/O error\n");
	}  
	return 0;
} 
