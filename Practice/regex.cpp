#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int i,j;
char p[10],s[20];
int countp()
{
	int h,temp=0,ch;
	h=i+2;
    printf("i=%d\n",i);
    printf("h=%c i=%c\n",p[h],p[i]);
	while(p[i]==p[h])
	{      
		h++;
		temp++;
	}  printf("ptemp=%d\n",temp);
	return temp;
}
int counts()
{
	int temp=0,h;
	h=j;
	while(s[j]==s[h])
	{
		h++;
		temp++;
	} printf("stemp=%d\n",temp);
	return temp;
}
void check(int a,int b)
{
    i=a;j=b;
    printf("i=%d j=%d\n",i,j);
	//Base case
	if(p[i]=='\0' && s[j]!='\0')
	{
		printf("Not present");
		exit(0);
	}
	else
	{
		if(p[i]=='\0' && s[j]=='\0')
		{
			printf("Is present");
			exit(0);
		}
		
	}
	//Base case ends
	if(p[i+1]!='*')
	{       printf("pre=%c sre=%c\n",p[i],s[j]);
		if(p[i]==s[j])
		{
			i++;j++;
			check(i,j);
		}
		else
		{ 
			printf("Not present");
			exit(0);
		}
	}
	else if(p[i]==s[j])
	{
		if(p[i+2]==p[i])
		{
			if(countp()<=counts()) //count after * in RE is greater than or equal to count in s
			{
				i=i+countp()+2;
				j=j+counts();
			}
            
			check(i,j);
		}
		else
		{
			i=i+2;
			j=j+counts();
			check(i,j);
		}
	}
    else
        {
        i=i+2;
        check(i,j);
    }
}
int main() {
	scanf("%s",p);
	scanf("%s",s);
	check(0,0);
	return(0);
}