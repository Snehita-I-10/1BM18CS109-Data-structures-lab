/*Week 0-Assignment
Problem:
Given an sorted array arr[] of N integers and a number K is given. The task is to check if the element K is present in the array or not.
Input:
First line of input contains number of testcases T. For each testcase, first line of input contains number of elements in the array and the number K separated by space. Next line contains N elements.
Output:
For each testcase, if the element is present in the array print "1" (without quotes), else print "-1" (without quotes).
‌
Example:
Input:
2
5 6
1 2 3 4 6
5 2
1 3 4 5 6
Output:
1
-1*/
#include<stdio.h>
int main()
{
  int n,k,flag=0,t,arr[100],arr1[100],j=0,m;
  scanf("%d",&t);
for(int i=0;i<t;i++)
{
   scanf("%d %d",&n,&k);
   for(int i=0;i<n;i++)
   {
	scanf("%d ",&arr[i]);
	
   }
  for(int i=0;i<n;i++)
  {
   if(arr[i]==k)
		{
		  
		  flag=1;
		  break;
		}
  }

if(flag==1)
{
arr1[j]=1;
j++;
}
else{
	arr1[j]=-1;
	j++;
}
flag=0;
}
for(int m=0;m<j;m++)
	printf("%d\n",arr1[m]);
	
return 0;

}
