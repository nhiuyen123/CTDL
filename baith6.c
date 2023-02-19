#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct CCB
{
	int so;
	int cao;
	struct CCB *trai,*phai;
}
struct CCB* them ( struct CCB *goc, int x){
	int cb;
	if(goc==NULL)
	{ 
		goc = (struct CCB*) malloc (sizeof(struct CCB));
		goc->x=x;
		goc->cao=1;
		goc->trai=oc->phai=NULL;
		
		return goc;
	}
}

