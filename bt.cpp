#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define MAX 100
//Linh
typedef struct NgaySinh
{
	unsigned ngay;
	unsigned thang;
	unsigned nam;
}NS;
//Nguyen
void InputDate(NgaySinh &z)
{
	printf("Hay nhap ngay sinh:\n");
	printf("- Ngay: ");
	scanf("%d",&z.ngay);
	printf("- Thang: ");
	scanf("%d",&z.thang);
	printf("- Nam: ");
	scanf("%d",&z.nam);

	int ngay,ngaymax;
	if((z.ngay <=0 || z.ngay >31)||(z.thang <=0 || z.thang >12)||z.nam < 0)
	{
		printf("\nNgay sinh khong hop le!!!");
	}
	else{
		switch(z.thang)
			{
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				ngaymax = 31;
				break;
			case 2:
				if((z.nam%4 == 0 && z.nam%100 !=0) || z.nam%400==0)
					ngaymax = 29;
				else
					ngaymax = 28;
			case 4: case 6: case 9: case 11:
					ngaymax = 30;
					break;			
			}
		}
	if(ngay <= ngaymax)
	{
		printf("Hop le ngay!!!");
	}else{
		printf("Ngay khong hop le!!!");
	}
}
//Nguyen
void OutputDate(NgaySinh z)
{
	printf("Ngay sinh: %d/%d/%d",z.ngay,z.thang,z.nam);
}
//Linh
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
//Huy
struct LIST
{
	int num;
	SV a[MAX];
};
//Huy
void numList(LIST &L)
{
	L.num = 0;
}
//Huy
int ListSize(LIST L)
{
	return L.num;
}
//Huy
bool IsEmpty(LIST L)
{
	return (L.num == 0);
}
//Huy
bool IsFull(LIST L)
{
	return (L.num == MAX);
}
//Huy
void NhapSo(int &a)
{
	do
	{
		scanf("%d", &a);
		if(a<0 || a>100)
			printf("Nhap sai Nhap lai: ");
	} while (a<0 || a>100);
	
}
//Huy
bool Check_Name(char name[])
{
	for(int i = 0 ; i < strlen(name) - 1 ; i++)
	{
		if(name[i] >= '0' && name[i] <= '9')
			return false;
	}
	return true;
}
//Huy
void Standardized_Name(char name[])
{
    char str[30];
    int count = 0;
	
    int first = 0, last = strlen(name) - 1;

    while (first < last && name[first] == ' ')
        first ++;
    while (last > first && name[last] == ' ')
        last --;
    
    if(name[first] >= 'a' && name[first] <= 'z')
        name[first] -= 32;

    for(int i = first + 1 ; i <= last ; i++)
    {
        if(name[i] >= 'A' && name[i] <= 'Z')
            name[i]+=32;
    }

    for(int i = first  ; i <= last ; i++)
    {
        if(i+1<=last)
        {
            if(name[i] == name[i+1] && name[i] == ' ')
                continue;
            if(name[i] == ' ' && name[i+1] >= 'a' && name[i+1] <= 'z')
                name[i+1] -= 32;
        }
        str[count] = name[i];
        count++;
    }
	name = str;
}
//Huy
bool Check_ID(char id[])
{
	int length = strlen(id);
	if(length != 10)
	{
		return false;
	}
	for(int i=0 ; i<length-1 ; i++)
	{
		if(id[i] <'0' || id[i] >'9')
		{
			return false;
		}
	}
	return true;
}
//Huy
bool Check_Class(char lop[])		//vi du: 20DATA1 or 20data1
{
	for(int i=0 ; i<strlen(lop)-1 ; i++)
	{
		if(lop[i] >= 'a' && lop[i] <= 'z')
			lop[i] -= 32;
	}

	if(strlen(lop) != 7)
		return false;
	if(lop[0] < '0' || lop[0] > '9')
		return false;
	if(lop[1] < '0' || lop[1] > '9')
		return false;
	if(lop[6] < '0' || lop[6] > '9')
		return false;
	if(lop[2] < 'A' || lop[2] > 'Z')
		return false;
	if(lop[3] < 'A' || lop[3] > 'Z')
		return false;
	if(lop[4] < 'A' || lop[4] > 'Z')
		return false;
	if(lop[5] < 'A' || lop[5] > 'Z')
		return false;
	return true;
}
//Huy
bool Check_Mark(float mark)
{
	if(mark<0 || mark >10)
	{
		return false;
	}
	return true;
}
//Linh
void Input_One_Old_Student(SV &x)
{
    printf("\nMSSV: ");
	do
	{
		fflush(stdin);
    	gets(x.mssv);
		if(!Check_ID(x.mssv))
			printf("MSSV vua nhap khong hop le. Vui long nhap lai: ");
	} while (!Check_ID(x.mssv));

    printf("Ho va ten: ");
	do
	{
		fflush(stdin);
    	gets(x.hoten);
		if(!Check_Name(x.hoten))
			printf("Ho ten vua nhap khong hop le. Vui long nhap lai: ");
	} while (!Check_Name(x.hoten));
	Standardized_Name(x.hoten);

	printf("Gioi tinh (X-nu) | (Y-nam): ");
    do
	{
        fflush(stdin);
		x.gt = getc(stdin);
		if(x.gt != 'x' || x.gt != 'y')
			x.gt = x.gt - 32;
		
		if(x.gt != 'X' && x.gt != 'Y')
		{
			printf("Gioi tinh vua nhap khong hop le. Vui long nhap lai: ");
		}
	} while(x.gt != 'X' && x.gt != 'Y');
    
	InputDate(x.ns);
	
    printf("\nLop: ");
	do
	{
		fflush(stdin);
		gets(x.lop);
		if(!Check_Class(x.lop))
			printf("Lop vua nhap khong hop le. Vui long nhap lai: ");
	} while (!Check_Class(x.lop));

    printf("Diem mon Toan: ");
	do
	{
		scanf("%f", &x.toan);
		if(!Check_Mark(x.toan))
			printf("Diem vua nhap khong hop le. Vui long nhap lai: ");
	} while (!Check_Mark(x.toan));    
    
    printf("Diem mon Ly: ");
	do
	{
		scanf("%f", &x.ly);
		if(!Check_Mark(x.ly))
			printf("Diem vua nhap khong hop le. Vui long nhap lai: ");
	} while (!Check_Mark(x.ly));    
    
    printf("Diem mon Hoa: ");
	do
	{
		scanf("%f", &x.hoa);
		if(!Check_Mark(x.hoa))
			printf("Diem vua nhap khong hop le. Vui long nhap lai: ");
	} while (!Check_Mark(x.hoa));    

	x.dtb = (x.toan + x.ly + x.hoa) / 3;
}
//Huy
void Output_One_Old_Student(SV x)
{
    printf("%10s %30s     %c %10s    %.1f   %.1f  %.1f   %.1f\n",x.mssv,x.hoten,x.gt,x.lop,x.toan,x.ly,x.hoa,x.dtb);
}
//Linh
void Input_List_Old_Student(LIST &L)
{
    for(int i=0; i<L.num; i++)
	{
		printf("\n-------Nhap sinh vien thu %d-------", i+1);
		Input_One_Old_Student(L.a[i]);
	}
}
//Huy
void Title1()
{
    printf("\nSTT |   MSSV   |\t   Ho va Ten   \t\t| GT |   Lop    | Toan | Ly | Hoa | TB\n");
}
//Huy
void Title2()
{
    printf("\n   MSSV   |\t   Ho va Ten   \t\t| GT |   Lop    | Toan | Ly | Hoa | TB\n");
}
//Linh
void Output_List_Old_Student(LIST L)
{
    Title1();
  	for(int i=0 ; i<L.num ; i++)
	{
        printf("%3d  ",i+1);
		Output_One_Old_Student(L.a[i]);
	}
}
//Nguyen
void Bubble_Sort_Student(LIST L)
{
	SV temp;
	for(int i=0 ; i<L.num-1 ; i++)
	{
		for(int j=L.num-i-1 ; j>i ; j--)
		{
			if(strcmp(L.a[j-1].hoten , L.a[j].hoten) > 0)
			{
				temp = L.a[j];
				L.a[j] = L.a[j-1];
				L.a[j-1] = temp;
			}
		}
	}
}
//Nguyen
void DeleteStudent(LIST &L)
{
	char mssv[11];
	printf("Nhap ma so sinh vien can xoa: ");
	fflush(stdin);
	gets(mssv);

	for(int i=0 ; i<L.num ; i++)
	{
		if(L.a[i].mssv == mssv)
		{
			L.a[i] = L.a[i + 1];
		}
		L.num --;
	}
}
//Nguyen
void AddStudent(LIST &L)
{
    int k;
    printf("Nhap vi tri can chen: ");
    do
    {
        scanf("%d",&k);
        if(k<0 || k>L.num)
            printf("Vi tri khong hop le. Nhap lai: ");
    } while (k<0 || k>L.num);

    L.num++;
    for(int i = L.num ; i>=k ; i--)
    {
        L.a[i] = L.a[i - 1];
    }
    printf("\nNhap thong tin sinh vien:\n");
    Input_One_Old_Student(L.a[k]);
}
//Nguyen
int Binary_Search_Name(LIST L, char name[])
{
	int l = 0, r = L.num - 1, mid, pos = -1;
	bool tim = false;
	while(!tim && l <= r)
	{
		mid = (l + r) / 2;
		if(L.a[mid].hoten == name)
		{
			tim = true;
			pos = mid;
		}
		else if(L.a[mid].hoten > name)
			l = mid + 1;
		else
			r = mid -1;
	}
	return pos;
}
//Nguyen
void Output_List_Student_Mark(LIST L)
{
	Bubble_Sort_Student(L);
	float mark;
	printf("Nhap danh sach sinh vien theo diem trung binh: ");
	scanf("%f",&mark);
	int count = 0;
	for(int i = 0 ; i < L.num ; i++)
	{
		if(L.a[i].dtb == mark)
		{
			count++;
			Output_One_Old_Student(L.a[i]);
		}
	}
	if(count == 0)
	{
		printf("Tim thay %d thong tin sinh vien\n");
	}
}
//Nguyen
void Output_List_Student_Technology(LIST L)
{
	char str[4] = "DTH";
    Title2();
	for(int i = 0 ; i<L.num ; i++)
	{
		if(strstr(L.a[i].lop,str) == 0)
		{
			Output_One_Old_Student(L.a[i]);
		}
	}
}
//Nguyen & Huy
void Menu(LIST &L)
{
    while (true)
    {
        system("cls");
		printf("\t\t--------------------MENU--------------------\n");
		printf("\t\t\t1. Tao Danh Sach Sinh Vien\n");
		printf("\t\t\t2. Xuat Danh Sach Sinh Vien\n");
		printf("\t\t\t3. Them Sinh Vien Vao Danh Sach\n");
        printf("\t\t\t4. Xoa Sinh Vien Theo MSSV\n");
		printf("\t\t\t5. Tim Sinh Vien Theo Ten\n");
		printf("\t\t\t6. Xuat Sinh Vien Theo Diem\n");
		printf("\t\t\t7. Xuat Sinh Vien Theo Nganh CNTT\n");
		printf("\t\t\t0. Thoat.\n");
		printf("\t\t--------------------------------------------\n");

        int chon;
		printf("Nhap lua chon: ");	
		scanf("%d",&chon);

        switch (chon)
        {
        case 1:         //Tao danh sach sinh vien
            {
                printf("Nhap so luong sinh vien: ");
				NhapSo(L.num);
                Input_List_Old_Student(L);
                system("pause");
            }
            break;
        case 2:         //Xuat danh sach sinh vien
            {
                if(IsEmpty(L))
                {
                    printf("Danh sach sinh vien hien dang rong!!!\n");
					printf("Nhap so luong sinh vien: ");
					NhapSo(L.num);
					Input_List_Old_Student(L);
                    system("pause");
                }
                else
                {
                    Output_List_Old_Student(L);
                    system("pause");
                } 
            }
            break;
        case 3:         //Them sinh vien vao danh sach
            {
                if(IsFull(L))
                {
                    printf("\nDanh sach da day");
                    system("pause");
                }
                if(IsEmpty(L))
                {
                    printf("Danh sach sinh vien hien dang rong !!!\n");
					printf("Nhap so luong sinh vien: ");
					NhapSo(L.num);
					Input_List_Old_Student(L);
                    system("pause");
                }
                else
                {
					AddStudent(L);
                    system("pause");
                }
            }
            break;
        case 4:         //Xoa sinh vien theo MSSV
            {
                if(IsEmpty(L))
                {
                    printf("\nDanh sach trong !!!");
                    system("pause");
                }
                else
                {
                    DeleteStudent(L);
                    system("pause");
                }
            }
            break;
        case 5:         //Tim sinh vien theo ten
            {
                if(IsEmpty(L))
                {
                    printf("\nDanh sach sinh vien hien dang rong !!!");
                    printf("Nhap so luong sinh vien: ");
					NhapSo(L.num);
					Input_List_Old_Student(L);
                    system("pause");
                }
                else
                {
					char name[30];
   					printf("Nhap ten can tim: ");
   					fflush(stdin);
					gets(name);

					Bubble_Sort_Student(L);
					int found = Binary_Search_Name(L,name);

					if(found == -1)
					{
						printf("Khong the tim thay sinh vien!!!");
                        system("pause");
					}
                    else
                    {
						Output_One_Old_Student(L.a[found]);
                        system("pause");
					}
                }
            }
            break;
        case 6:         //Xuat sinh vien theo diem
            {
                if(IsEmpty(L))
				{
					printf("Danh sach sinh vien hien dang rong!!!\n");
					printf("Nhap so luong sinh vien: ");
					NhapSo(L.num);
					Input_List_Old_Student(L);
                    system("pause");
				}
                else
                {
					DeleteStudent(L);
                    system("pause");
				}
            }
            break;
        case 7:         //Xuat sinh vien theo nganh CNTT
            {
                if(IsEmpty(L) == NULL)
				{
					printf("Danh sach sinh vien hien dang rong!!!\n");
					printf("Nhap so luong sinh vien: ");
					NhapSo(L.num);
					Input_List_Old_Student(L);
                    system("pause");
				}
                else
                {
					Output_List_Student_Technology(L);
                    system("pause");
				}
            }
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("\n\nLua chon khong hop le !!!");
            break;
        }
    }
}

int main()
{
    LIST L;
    numList(L);
    Menu(L);
    return 0;
}
