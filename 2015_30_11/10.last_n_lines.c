#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

void lastklines(int lines)
{
    int count=0,n;
    char c;
    int fp=open("C:\\Users\\VAMSHI\\Desktop\\teja\\missionrnd\\filelastklines\\file.txt",O_RDONLY);
    lseek(fp,-1L,2);
    while((n=read(fp,&c,1))!=0)
    {
        if(count==lines)
        {
            break;
        }
        if(c=='\n')
        {
            count++;
            lseek(fp,-3L,1);
        }
        else
        {
            lseek(fp,-2L,1);
        }
    }
    n=read(fp,&c,1);
    printf("\nLast %d lines in the file are : \n\n");
    while((n=read(fp,&c,1))!=0)
    {
        printf("%c",c);
    }
    close(fp);
}

int main()
{
    int lines;
    printf("\nEnter number of lines: ");
    scanf("%d",&lines);
    lastklines(lines);
    return 0;
}
