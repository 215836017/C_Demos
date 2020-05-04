#include <stdio.h>
#include <stdlib.h>
int main()
{
FILE *fp;
int x=123443432;
fp=fopen("testFile.txt","wb");
if(fp==NULL)
{
printf("create file failed\n");
return -1;
}
fprintf(fp,"%d",x);
fclose(fp);
return 0;
}