#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//1
struct SinhVien {
	char ten[30];
	float dtb;
};
typedef struct SinhVien SinhVien;
typedef struct nut Nut;
struct nut {
	SinhVien DuLieu;
	Nut* LienKet;
};
struct list {
	Nut* pDau;
	Nut* pCuoi;
};
typedef struct list DSSV;
Nut* KhoiTaoNut(SinhVien x)
{
	Nut* p = (Nut*)malloc(sizeof(struct nut));
	p->DuLieu = x;
	p->LienKet = NULL;
	return p;
}
//1
int demSSV(DSSV l){
	Nut* k;
	int dem = 0;
	for (k = l.pDau; k != NULL; k = k->LienKet)
	{
		dem++;
	}
	return dem;
}
//2
DSSV themCuoi(DSSV l, Nut* p){
	if (l.pDau == NULL)
	{
		l.pDau = l.pCuoi = p;
	}
	else
	{
		l.pCuoi->LienKet = p;
		l.pCuoi = p;
	}
	return l;
}

void xuatDSSV(DSSV l) {
	int dem=1;
	Nut* k;
	printf("\t\tThong tin danh sach sinh vien\n");
	for (k = l.pDau; k != NULL; k = k->LienKet) {
		printf("\tSinh Vien thu %d\n",dem++);
		printf("Ten: %s\n",k->DuLieu.ten);
		printf("Diem trung binh: %f\n",k->DuLieu.dtb);
	}
}
//3
void taoDSSVGioi(DSSV l){
	int dem=1;
	Nut* k;
	printf("\t\tThong tin danh sach sinh vien xep loai gioi\n");
	for (k = l.pDau; k != NULL; k = k->LienKet) {
		if(k->DuLieu.dtb>=8.0){
			printf("\tSinh vien co dtb >= 8/0 thu %d\n",dem++);
			printf("Ten: %s\n",k->DuLieu.ten);
			printf("Dtb: %f\n",k->DuLieu.dtb);
		}
	}
}
//4
void xoaSV(DSSV l, int vt){
	Nut* k;
	int dem = 0;
	if (l.pDau == NULL || vt<0)
	{
		return 0;
	}
	
	
}


//5

int main(){
	DSSV l;
	l.pDau = NULL;
	l.pCuoi = NULL;
	//Tao 5 thong tin
	SinhVien sv;
	strcpy(sv.ten,"An");
    sv.dtb=8.0;
    Nut *p=KhoiTaoNut(sv);
    l = themCuoi(l, p);
	strcpy(sv.ten,"Vinh");
    sv.dtb=9.0;
    p=KhoiTaoNut(sv);
    l = themCuoi(l, p);
    strcpy(sv.ten,"Ly");
    sv.dtb=7.0;
    p=KhoiTaoNut(sv);
    l = themCuoi(l, p);
    strcpy(sv.ten,"Vi");
	sv.dtb=8.5;
    p=KhoiTaoNut(sv);
    l = themCuoi(l, p);
    strcpy(sv.ten,"Nhi");
    sv.dtb=10;
    p=KhoiTaoNut(sv);
    l = themCuoi(l, p);
    //In cac sinh vien trong danh sach
    xuatDSSV(l);
    
    int dem = demSSV(l);
		printf("\nSo sinh vien la: %d\n",dem);
		
	taoDSSVGioi(l);
	
}	    
	

