#include <stdio.h>
#include <stdlib.h>

int mdc(int val1, int val2);

int main(void)
{
	printf("%d\n", mdc(45,18));
	return 0;
}

int mdc(int val1, int val2)
{
	int i, s=1, lim;
	lim= val1 > val2 ? val2 : val1;
	for(i=2; lim/(s*i)>1 ; i++)
	{
		while(1)
		{
			if(val1 % (s*i) == 0 && val2 % (s*i)== 0)
				s*=i;
			else
				break;
		}
	}
	return s;
}
