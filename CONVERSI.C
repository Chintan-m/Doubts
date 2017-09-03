#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

void push(char a);
char pop();
void postfix();

char stack[100];

int top=-1;

void main()
{
 clrscr();

 postfix();
 getch();
}

void postfix()
{
 int k=0,j;
 char i[100],p[100],temp[100];
 printf("enter the infix expression:");
 gets(temp);
 i[0]='(';
 strcat(i,temp);
 i[strlen(i)]=')';
	for(j=0;j<strlen(i);j++)
		{
		  if(isdigit(i[j])||isalpha(i[j]))
		   {
			p[k]=i[j];
			k++;
		   }

		  else
		  {
		   switch(i[j])
		    {
		     case '+' :

			if(top==-1||stack[top]=='(')
			    {
				push('+');
			    }

			else
				{
					while(top!=-1&&stack[top]!='(')
					 {
						p[k]=pop();
						k++;
					 }
					push('+');
				}
		     break;

		     case '-':

			if(top==-1||stack[top]=='(')
			       {
				push('-');
			       }

			else
				{
					while(top!=-1&&stack[top]!='(')
					 {
						p[k]=pop();
						k++;
					 }
					push('-');
				}
		     break;

		     case '(':
			push('(');
		     break;

		     case')':

			while(top!=-1&&stack[top]!='(')
				{
					p[k]=pop();
					k++;
				}
			 pop();

		     break;

		     case'^':
			if(stack[top]!='^')
			 {
			  push('^');
			 }

			else
			 {
				while(stack[top]=='^'&&(top!=-1))
				 {
					p[k]=pop();
					k++;
				 }
				push('^');
			 }
		    break;

		    case '*':
			while((stack[top]=='*'||stack[top]=='/'||stack[top]=='^')&&(top!=-1))
			 {
			   p[k]=pop();
			   k++;
			 }
			push('*');
		    break;

		    case '/':
			while((stack[top]=='*'||stack[top]=='/'||stack[top]=='^')&&(top!=-1))
			{
			 p[k]=pop();
			 k++;
			}
			push('/');
		    break;

		    default:
		    printf("invalid symbol");

		   }

		  }
		}

     printf("the postfix expression is:");
     printf("%s",p);
}

void push(char a)
{
 if(top==-1)
 {
  top=0;
  stack[top]=a;
 }
 else
 {
  top++;
  stack[top]=a;
 }
}

char pop()
{
  top--;
  return stack[top+1];
}