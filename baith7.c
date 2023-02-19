#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct  Nguoi
{
	char hoTen[30];
	int namSinh;
};
struct CGP
{
	struct Nguoi duLieu;
	struct CGP *trai,*phai;
}
struct CGP* taoNut(struct Nguoi ng, struct CGP *tr, struct CGP *ph){
	struct CGP *p;
	p = (struct CGP*) malloc(sizeof(struct CGP));
	p->duLieu=ng;
	p->trai=tr;
	p->phai=ph;
	return p;		
};
struct CGP* taoCay(){
	struct Nguoi ng1,ng2,ng3,ng4,ng5,ng6,ng7,ng8;
	struct CGPNP *n1,*n2,*n3,*n4,*n5,*n6,*n7,*n8;
	

	strcpy(ng1.hoTen,"Nguyen H");
	ng1.namSinh=1970;
	n1=taoNut(ng1, NULL, NULL);

	strcpy(ng2.hoTen,"Nguyen G");
	ng2.namSinh=1965;
	n2=taoNut(ng2, n1, NULL);
	
	strcpy(ng3.hoTen,"Nguyen C");
	ng3.namSinh=1935;
	n3=taoNut(ng3, NULL, n2);
	
	strcpy(ng4.hoTen,"Nguyen F");
	ng4.namSinh=1965;
	n4=taoNut(ng4, NULL, NULL);
	
	strcpy(ng5.hoTen,"Nguyen E");
	ng5.namSinh=1960;
	n5=taoNut(ng5, n4, NULL);
	
	strcpy(ng6.hoTen,"Nguyen D");
	ng6.namSinh=1955;
	n6=taoNut(ng6, n5,NULL);
	
	strcpy(ng7.hoTen,"Nguyen B");
	ng6.namSinh=1930;
	n6=taoNut(ng7, n3,n6);
	
	strcpy(ng8.hoTen,"Nguyen D");
	ng8.namSinh=1955;
	n6=taoNut(ng8, NULL,n7);
};
