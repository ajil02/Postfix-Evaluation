#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define n 5

int top=-1;
int stack[n];

int pop()
{	
	int t; 
	t=stack[top];
	stack[top]=-1;
	top--;
	return t;
}

void push(int res)
{
	top++;
	stack[top]=res;
}

int cal(char oper,int a,int b)
{
	switch(oper)
	{
		case '/':
		{
			return a/b;
		}
		
		case '*':
		{
			return a*b;
		}
		
		case '+':
		{
			return a+b;
		}
		
		case '-':
		{
			return a-b;
		}
		
		default:
		{
			return 0;
		}
	}
}


void main()
{
	char c[100];
	char *p;
	int i,x,y,z;
	printf("\nEnter the expression: ");
	scanf("%s",c);
	p=c;
	while(*p!='\0')
    	{
        	if(isdigit(*p))
        	{
        	    i=*p-48;
        	    push(i);
        	}
        	else
        	{
        	    x=pop();
        	    y=pop();
        	    z=cal(*p,y,x);
        	    push(z);
        	}
        	p++;
        }
        printf("The result is %d",pop());
}
