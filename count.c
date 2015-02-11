/*************************************************************************
    > File Name: count.c
    > Author: xiegd
    > Mail: xiegd@ipanel.com 
    > Created Time: Wed 28 Jan 2015 03:49:58 PM PST
 ************************************************************************/

#include<stdio.h>
#include<errno.h>

#define LOGD(str,...) fprintf( stdout , str , ##__VA_ARGS__) 
#define LOGE( str )  perror(str) 


int main( int argc , char** argv ){
	int a[10] = { 8 , 9 , 4 , 1 , 3 , 2 , 7 , 6 , 5 , 0};
	int c[10] = {0} , d[10] = {0};// c:count d:done
	int i=0;

	for( i = 0 ; i < 10 ; i ++ )
	{
		c[a[i]]++;	
	}
	for( i = 1 ; i < 10 ; i ++ )
	{
		c[i]+=c[i-1];
	}
	for( i = 0 ; i < 10 ; i ++ )
	{
		d[c[a[i]]-1]=a[i];
		c[a[i]]--;
	}
	LOGD(" result : ");
	for( i = 0 ; i < 10 ; i ++ )
	{
		LOGD("%d ",d[i]);
	}
	LOGD("\n");
	return 0;
}
