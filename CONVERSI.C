/* The given program converts the user inputed infix
	expression to postfix expression and evaluates 
	the postfix expression
					*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

void push1(char a);
char pop1();
void push2(char c);
int pop2();
void postfix();
char stack[100];
int s[100];
int top1=-1;
int top2=-1;
void main()
{
 clrscr();

 postfix();
 getch();
}
void postfix()
{
 int a,k=0,j,l;
 char i[100],p[100],temp[100];
 printf("enter the infix expression:");
 scanf("%s",temp);
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

			if(top1==-1||stack[top1]=='(')
			    {
				push1('+');
			    }

			else
				{
					while(top1!=-1&&stack[top1]!='(')
					 {
						p[k]=pop1();
						k++;
					 }
					push1('+');
				}
		     break;

		     case '-':

			if(top1==-1||stack[top1]=='(')
			       {
				push1('-');
			       }

			else
				{
					while(top1!=-1&&stack[top1]!='(')
					 {
						p[k]=pop1();
						k++;
					 }
					push1('-');
				}
		     break;

		     case '(':
			push1('(');
		     break;

		     case')':

			while(top1!=-1&&stack[top1]!='(')
				{
					p[k]=pop1();
					k++;
				}
			 pop1();

		     break;

		     case'^':
			if(stack[top1]!='^')
			 {
			  push1('^');
			 }

			else
			 {
				while(stack[top1]=='^'&&(top1!=-1))
				 {
					p[k]=pop1();
					k++;
				 }
				push1('^');
			 }
		    break;

		    case '*':
			while((stack[top1]=='*'||stack[top1]=='/'||stack[top1]=='^')&&(top1!=-1))
			 {
			   p[k]=pop1();
			   k++;
			 }
			push1('*');
		    break;

		    case '/':
			while((stack[top1]=='*'||stack[top1]=='/'||stack[top1]=='^')&&(top1!=-1))
			{
			 p[k]=pop1();
			 k++;
			}
			push1('/');
		    break;

		    default:
		    printf("invalid symbol");

		   }

		  }
		}

     printf("the postfix expression is:\n");
     printf("%s\n",p);
for(l=0;l<strlen(p);l++)
{
  if(isdigit(p[l]))
   {
    push2(p[l]);
   }
  else
  {
  switch(p[l])
  {
	int a,b,c;
	case '+':a=pop2();
		 b=pop2();
		 c=b+a;
		 push2((char)(c+48));
		 break;

	case '-':a=pop2();
		 b=pop2();
		 c=b-a;
		 push2((char)(c+48));
		 break;
	case '*':a=pop2();
		 b=pop2();
		 c=b*a;
		 push2((char)(c+48));
		 break;
	case '/':a=pop2();
		 b=pop2();
		 c=b/a;
		 push2((char)(c+48));
		 break;

		 default:printf("invalid input\n");
     }
  }
}

a=pop2();
printf("result of the given expression is:%d\n",a);
}

void push1(char a)
{
 if(top1==-1)
 {
  top1=0;
  stack[top1]=a;
 }
 else
 {
  top1++;
  stack[top1]=a;
 }
}

char pop1()
{
  top1--;
  return stack[top1+1];
}

void push2(char c)
{
	 int n=(int)c - 48;
	 top2=top2++;
	 s[top2]=n;
}


int pop2()
{
	int b;
	 b=s[top2];
	 top2=top2--;
	return b;
}

/* OUTPUT
enter the infix expression:3*(3-2)/1+4
the postfix expression is:
332-*1/4+
result of the given expression is:7
                                                                                
                                                                                
	  */
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
