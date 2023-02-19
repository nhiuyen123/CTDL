#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct DaThuc
{
	int mu;
	float heSo;
	struct DaThuc *lienKet;
};

struct DaThuc* taoDT(float *mang, int sopt)
{
	int i;
	struct DaThuc;
}
struct DaThuc* taoDaThuc(float a[], int n)
{
	int i;
	struct DaThuc *p=NULL, *q;
	for(i=n-1; i>=0; i--){
		if(a[i]!=0)
		{
			q=(struct DaThuc*)malloc(sizeof(struct DaThuc));
			q->mu=i; q->heSo=a[i]; q->lienKet=p; p=q;
		}
	} 
	return p;
}
void inDaThuc(struct DaThuc *p)
{
	struct DaThuc *q;
	q=p;
	while(q!=NULL)
	{
		printf("%fx^%d", q->heSo, q->mu);
		q=q->lienKet;
		if(q!=NULL)
			printf(" + ");
	}	
}
float tinhGT(struct DaThuc *q, float x){
	float gt=0;
	int i=0;
	struct DaThuc *p = q;
	while(p != NULL)
	{
		double luy_thua = 1;
		for ( i = 0; i < p->mu; i++)
		{
			luy_thua *= x;
		}
		gt += p->heSo * luy_thua;
		p = p->lienKet;
	}
}
int main()
{
	float a[]={-10,0,7,5};
	float x=3;
	struct DaThuc *p;
	p=taoDaThuc(a,4);
	inDaThuc(p);
	float gt=tinhGT(p,x);
	printf("\nGia thi bieu thuc cua bieu thuc tai x=%f la: %f",x,gt);
}

