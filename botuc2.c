#include <stdio.h>
#include <string.h>

struct SV
{
	char ho_ten[40];
	int nam_sinh;
	float diem_trung_binh;
};
void nhap_SV(struct SV* sv)
{
	fflush(stdin);
	printf("Nhap ho ten: ");
	gets(sv->ho_ten);
	printf("Nhap nam sinh: ");
	scanf("%d", &sv->nam_sinh);
	printf("Nhap diem trung binh: ");
	scanf("%f", &sv->diem_trung_binh);
}

void in_SV(struct SV sv)
{
	printf("%s %d %f", sv.ho_ten, sv.nam_sinh, sv.diem_trung_binh);
}

void nhap_DSSV(struct SV sv[], int n)
{
	for(int i = 0; i < n; i++)
	{
		nhap_SV(&sv[i]);
	}
}

void in_DSSV(struct SV sv[], int n)
{
	for (int i = 0; i < n; i++)
	{
		in_SV(sv[i]);
		printf("\n");
	}
}

int tim_SV(struct SV sv[], int n, char ho_ten[])
{
	for (int i = 0; i < n; i++)
	{
		if (strcmp(ho_ten, sv[i].ho_ten) == 0)
		{
			return i;
		}
	}

	return -1;
}

void inSVGioi(struct Sinh_Vien sv[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (sv[i].diem_trung_binh >= 8)
		{
			in_SV(sv[i]);
			printf("\n");
		}
	}
}

void them_SV(struct Sinh_Vien sv[], int* n, struct Sinh_Vien sv_x)
{
	strcpy(sv[*n].ho_ten, sv_x.ho_ten);
	sv[*n].nam_sinh = sv_x.nam_sinh;
	sv[*n].diem_trung_binh = sv_x.diem_trung_binh;
	*n = *n + 1;
}

int demSVNguyen(struct SV sv[], int n)
{
	int dem = 0;
	char ho[] = "Nguyen";
	int do_dai_ho = strlen(ho);
	int so_sanh_ho;

	for (int i = 0; i < n; i++)
	{
		so_sanh_ho = strncmp(ho, sv[i].ho_ten, do_dai_ho);
		if (so_sanh_ho == 0 && sv[i].ho_ten[do_dai_ho] == ' ')
		{
			dem++;
		}
	}

	return dem;
}

void chuyendoihoten(char hoten[], char tenho[])
{
	int i; 
	int j; 
	int dodai = strlen(hoten);

	for (i = dodai - 1; i > -1 && hoten[i] != ' '; i--);
	i++; 
	for (j = 0; i < dodaihoten; j++)
	{
		tenho[j] = hoten[i++];
	}
	tenho[j++] = ' '; 
	i = 0;
	while (j < dodai
	{
		tenho[j] = hoten[i];
		i++;
		j++;
	}
	tenho[j] = '\0';
}
int main(){
	
	struct SV dssv[100];
	struct SV x;
	char ho_ten_tim[40];
	int i;
	int sln = 0;
	int n;

	printf("Nhap so luong sinh vien: ");
	scanf("%d", &n);
	nhap_DSSV(dssv, n);
	printf("\n");
	in_DSSV(dssv, n);

	printf("\nNhap ho ten sinh vien can tim: ");
	fflush(stdin);
	gets(ho_ten_tim);
	vi_tri = tim_SV(dssv, n, ho_ten_tim);
	if (i == -1)
	{
		printf("Khong tim thay sinh vien %s", ho_ten_tim);
	}
	else
	{
		printf("Sinh vien %s co so thu tu la %d", ho_ten_tim, i);
	}

	printf("\n\nDanh sach sinh vien gioi:\n");
	in_DSSV_gioi(dssv, n);

	printf("\nNhap thong tin sinh vien can them:\n");
	nhap_SV(&n);
	them_SV(dssv, &n, x);

	sln = demSVNguyen(dssv, n);
	printf("\nSo luong sinh vien co ho Nguyen: %d\n", sln);
}
