#include<stdio.h>
#include <string.h>
int main()
{
  char str[80], substr[10];
  int count1 = 0, count2 = 0, i, j, flag;


  printf("Enter a string: ");
  scanf("%s", str);

  printf("Enter a substring to search: ");
  scanf("%s", substr);

  count1=strlen(str);
  count2=strlen(substr);
  int k;
  int opc=0;
  for (i = 0; i <count1 - count2+1; i++)
  {k=i;
flag=0;
    for (j = 0; j < count2; j++)
    {
      opc++;
      if (str[k] != substr[j])
      {
        flag = 1;
        break;
      }k++;
    }

  if (flag == 0)
    {printf("Substring found at index %d\n ",i);
    break;
  }}
  if(flag!=0)
    printf("Substring not found \n ");
    printf("Operation count :%d \n",opc);
  return 0;
}