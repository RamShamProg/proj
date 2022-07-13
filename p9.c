#include<stdio.h>
#include<stdlib.h>
void fifo(char [],char [],int, int);
void lru(char [],char [],int, int);
int main()
{
    int ch,yn=1,i,l,f;
    char F[10],s[25];
    printf("\n\nEnter the no of empty frames: ");
    scanf("%d",&f);
    printf("\n\nEnter the length of the string: ");
    scanf("%d",&l);
    printf("\n\nEnter the string: ");
    scanf("%s",s);
    for(i=0;i<f;i++)
    F[i]=-1;
    do{
        printf("\n\n\t******Menu******");
        printf("\n\n\t1:FIFO\n\n\t2:LRU\n\n\t3:Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            for(i=0;i<f;i++)
            {
                F[i]=-1;
            }
            fifo(s, F,l,f);
            break;
            case 2:
            for(i=0;i<f;i++)
            {
                F[i]=-1;
            }
            lru(s,F,l,f);
            break;
            case 3:
            exit(0);
        }
        printf("\n\n\tDo you want to continue If Yess press 1\n\n\tIf No press 0: ");
        scanf("%d",&yn);
    }
    while(yn==1);
    return(0);
}


void fifo(char s[],char F[],int l,int f)
{
    int i,j=0,k,flag=0,cnt=0;
    printf("\n\tPage\tFrames\tFaults");
    for(i=0;i<l;i++)
    {
        for(k=0;k<f;k++)
        {
            if(F[k]==s[i])
            flag=1;
        }
        if(flag==0)
        {
            printf("\n\t%c\t",s[i]);
            F[j]=s[i];
            j++;
            for(k=0;k<f;k++)
            {
                printf(" %c",F[k]);
            }
            printf("\tPage-fault%d",cnt);
            cnt++;
        }
        else{
            flag=0;
            printf("\n\t%c\t",s[i]);
            for(k=0;k<f;k++)
            {
                printf(" %c",F[k]);
            }
            printf("\tNo Page-fault%d",cnt);
        }
        if(j==f)
            j=0;
    }
}
void lru(char s[],char F[],int l,int f)
{
    int i,j=0,k,m,flag=0,cnt=0,top=0;
    printf("\n\tPage\tFrames\tFaults");
    for(i=0;i<l;i++)
    {
        for(k=0;k<f;k++)
        {
            if(F[k]==s[i])
            {
            flag=1;
            break;
            }
        }
        printf("\n\t%c\t",s[i]);
        if(j!=f && flag!=1)
        {
            F[top]=s[i];
            j++;
            if(j!=f)
            top++;
        }
        else
        {
            if(flag!=1)
            {
                for(k=0;k<top;k++)
                {
                    F[k]=F[k+1];
                }
                F[top]=s[i];
            }
            if(flag==1)
            {
                for(m=k;m<top;m++)
                {
                    F[m]=F[m+1];
                }
                F[top]=s[i];
            }
        }
        for(k=0;k<f;k++)
        {
            printf(" %c",F[k]);
        }
        if(flag==0)
        {
            printf("\tPage-fault%d",cnt);
            cnt++;
        }
        else
        printf("\tNo page fault");
        flag=0;
    }    
}