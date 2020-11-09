#include"../ch8.h"

void dynamic_lib_fun_call(void)
{
	printf("Dynamic Lib Fun Called!\n");
}

void mysort(int *a,int len)
{
    printf("---------before sort----------\n");
    for(int k=0;k<len;k++){
        printf("a[%d] = %d\n",k,a[k]);
    }
    int temp=0;
    for(int i=0;i<len-1;i++){
        for(int j=i;j<len;j++)
        {
            if(a[j]<a[i]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("--------- After sort----------\n");
    for(int k=0;k<len;k++){
        printf("a[%d] = %d\n",k,a[k]);
    }
}
