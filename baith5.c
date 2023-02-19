#include<stdio.h>
#include<string.h>
#include <stdlib.h>

struct Tu
{
	char tiengAnh[20];
	char tiengViet[50];
};
struct TDAV
{
	struct Tu duLieu;
	struct TDAV *trai, *phai;
};

void them(struct TDAV **goc, struct Tu x)
{
	
	struct TDAV *q;

	if (*goc == NULL)
	{
		q = (struct TDAV*) malloc(sizeof(struct TDAV));
		q->duLieu = x;
		q->trai = NULL;
		q->phai = NULL;
		*goc = q;
	}
	else
	{
		if(strcmp((*goc)->duLieu.tiengAnh, x.tiengAnh)>0)
			them(&(*goc)->trai,x);
		else if(strcmp((*goc)->duLieu.tiengAnh, x.tiengAnh)<0)
			them((&(*goc)->phai),x);
	}
}

struct TDAV *docTep(char *tenTep){
	struct TDAV *r =NULL;
	FILE *f;
	char w[40];
	f= fopen(tenTep,"r");
	while (fgets(w, 20, f) != NULL)
	{
		struct Tu x;
		int k = strlen(w);
		if(w[k-1]=='\n') w[k-1]='\0';
		k=strstr(w,":")-w;
		strncpy(x.tiengAnh,w,k);
		x.tiengAnh[k]='\0';
		strcpy(x.tiengViet,w+k+1);
		them(&r,x);
	}
		fclose(f);
		return r;
}

char* traTu(struct TDAV *goc, char *ta)
{
	if(goc==NULL) return ;
	else 
		if(strcmp(goc->duLieu.tiengAnh, ta)==0)
			return goc->duLieu.tiengViet;
		else
			if(strcmp(goc->duLieu.tiengAnh,ta)>0)
				return traTu(goc->trai,ta);
			else return traTu(goc->phai,ta);
		
}

void inTD(struct TDAV *goc)
{
	if(goc !=NULL)
	{
		inTD(goc->trai);
		printf("%s: %s\n",goc->duLieu.tiengAnh, goc->duLieu.tiengViet);
		inTD(goc->phai);
	}
}

void xoaTu(struct TDAV **goc, char *ta)
{
	if(*goc==NULL) return;
	else 
		if(strcmp((*goc)->duLieu.tiengAnh,ta)<0)
			xoaTu(&(*goc)->phai,ta);
		if(strcmp((*goc)->duLieu.tiengAnh,ta)>0)
			xoaTu(&(*goc)->trai,ta);
		if((*goc)->trai==NULL && (*goc)->phai==NULL)
			(*goc)=NULL;	
	 	else if((*goc)->trai ==NULL){
	 		(*goc)=(*goc)->phai;
	 		free((*goc));
		}
		else if((*goc)->phai==NULL){
	 		(*goc)=(*goc)->trai;
	 		free((*goc));
		}
}

int main()
{
	char ta[20];
	char s;
	struct TDAV *td=docTep("tudien.txt");
	
	inTD(td);
	
	printf("\nNhap tu tieng Anh can tra: ");
	gets(ta);
	if (traTu(td, ta) == NULL)
		printf("Khong tim thay!\n", ta);
	else
		printf("Nghia tieng Viet cua %s la: %s\n", ta, traTu(td, ta));
	
	printf("\nNhap tu tieng Anh can xoa: ");
	gets(ta);
	xoaTu(&td, ta);
	inTD(td);
	
}

