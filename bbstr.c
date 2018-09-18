#include <stdlib.h>
#include <stdio.h>

int main()
{
	char ola[100], *op;

	fgets(ola,100,stdin);
	
	switch(op[1])
	{
		case '+':
			
			break;
		case '-':

			break;
		case '*':

			break;
		case '/':

			break;
	}

	strtok( ola,"c")
	return 0;
}

void desvendando_str(char *str, int n[2])
{
	int i, j, k=0, ch[10];

	for(i=0, j=0; i<strlen(str); i++)
	{
		if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			op= str[i];

			ch[j]= '\0';
			if( strlen(ch[j]) != 0 )
			{
				n[k]= atoi(ch);
				k++;
			}
			ch[0]= '\0';
			j=0;
		}
		else if(str[i] == ' ')
		{
			ch[j]= '\0';
			if( strlen(ch[j]) != 0 )
			{
				n[k]= atoi(ch);
				k++;
			}

			ch[0]= '\0';
			j=0;
		}
		else
		{
			ch[j]= str[i];
			j++;
		}
	}
	return;
}
