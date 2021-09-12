#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 100

typedef struct NgaySinh
{
	unsigned ngay;
	unsigned thang;
	unsigned nam;
}NS;

typedef struct SinhVien
{
	char mssv[11];
	char hoten[30];
    char lop[10];
	struct NgaySinh ns;
	char gt;
    float toan;
    float ly;
    float hoa;
	float dtb;
}SV;

struct LIST
{
	int num;
	SV a[MAX];
};

void numList(LIST &L)
{
	L.num = 0;
}

int ListSize(LIST L)
{
	return L.num;
}

int IsEmpty(LIST L)
{
	return (L.num == 0);
}

int IsFull(LIST L)
{
	return (L.num == MAX);
}

void NhapSo(int &a)
{
	do
	{
		scanf("%d", &a);
		if(a<0 || a>100)
			printf("Nhap sai Nhap lai: ");
	} while (a<0 || a>100);
	
}

void Input_One_Old_Student(SV &x)
{
    fflush(stdin);
    printf("\nMSSV: ");
    gets(x.mssv);

    fflush(stdin);
    printf("Ho va ten: ");
    gets(x.hoten);

    do
	{
		printf("\nGioi tinh (X-nu) | (Y-nam): ");
		x.gt = getche();
		if(x.gt != 'x' || x.gt != 'y')
			x.gt = x.gt - 32;
		
		if(x.gt != 'X' && x.gt != 'Y')
		{
			printf("\nNhap sai. Nhap lai");
		}
	} while(x.gt != 'X' && x.gt != 'Y');

    fflush(stdin);
    printf("\nLop: ");
    gets(x.lop);

    // printf("\nNgay thang nam sinh\n");
	// NhapNgaySinh(x.ns);
	// printf("\n Nam sinh: %02u / %02u / %4d", x.ns.day, x.ns.month, x.ns.year);

    printf("Diem mon Toan: ");
    scanf("%f", &x.toan);
    
    printf("\nDiem mon Ly: ");
    scanf("%f", &x.ly);
    
    printf("\nDiem mon Hoa: ");
    scanf("%f", &x.hoa);

	x.dtb = (x.toan + x.ly + x.hoa) / 3;
}

void Output_One_Old_Student(SV x)
{
    printf("\n Ma so sinh vien: %s", x.mssv);
    printf("\n Ho va ten: %s", x.hoten);
    if(x.gt == 'X')
	{
		printf("\n Gioi tinh: Nu");
	}
	else if(x.gt == 'Y')
	{
		printf("\n Gioi tinh: Nam");
	}
    printf("\n Lop: %s", x.lop);
    printf("\n Diem Toan: %.1f", x.toan);
    printf("\n Diem Ly: %.1f", x.ly);
    printf("\n Diem Hoa: %.1f", x.hoa);
    printf("\n Diem trung binh: %.1f", x.dtb);
}

void Input_List_Old_Student(LIST &L)
{
    for(int i=0; i<L.num; i++)
	{
		printf("\n-------Nhap sinh vien thu %d-------", i+1);
		Input_One_Old_Student(L.a[i]);
	}
}

void Output_List_Old_Student(LIST L)
{
  	for(int i=0 ; i<L.num ; i++)
	{
		printf("\n\n-----Sinh vien thu %d-----", i+1);
		Output_One_Old_Student(L.a[i]);
	}
}

void Bubble_Sort_Student(LIST L)
{
	SV temp;
	for(int i=0 ; i<L.num-1 ; i++)
	{
		for(int j=L.num-i-1 ; j>i ; j--)
		{
			if(strcmp(L.a[i].hoten, L.a[j].hoten) < 0)
			{
				temp = L.a[i];
				L.a[i] = L.a[j];
				L.a[j] = L.a[i];
			}
		}
	}
}
/*
int Binary_Search_Name(LIST L, char name[])
{
	int l,r,mid;
	while(l <= r)
	{
		mid = (l + (r-1)) / 2;
		if(strcmp(L.a[i],name))
			return mid;
		if(SV a[mid] > name)
			l = mid + 1;
		else
			r = mid -1;
	}
	return -1;
}
*/
int main()
{
    LIST L;
	printf("Nhap so luong sinh vien: ");
	NhapSo(L.num);
	Input_List_Old_Student(L);
	Output_List_Old_Student(L);
	printf("\n------------------\n");
    char name[10];


}
