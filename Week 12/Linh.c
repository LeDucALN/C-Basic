#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct SinhVien;
void hienThiDSSV(struct SinhVien*, int slsv);
void hienThiTenCot();
typedef struct DiemMH {
	float toan;
	float van;
	float anh;
	float tbc;
}DiemMH;

typedef struct SinhVien {
  int ma;
  char ten[30];
  char gioiTinh[10];
  DiemMH diem;
}SinhVien;

void nhapDiem(DiemMH* diem) {
	printf("Toan: ");
	scanf("%f", &diem->toan);
	printf("Van: ");
	scanf("%f", &diem->van);
	printf("Anh: ");
	scanf("%f", &diem->anh);
	diem->tbc = (diem->toan + diem->van + diem->anh) / 3;
}
SinhVien nhapSV() {
        SinhVien sv;
	printf("Nhap ma: ");
	scanf("%d", &sv.ma);
	while(getchar()!='\n');
	printf(" Nhap ten: ");
	gets(sv.ten);
	printf("Gioi tinh: ");
	scanf("%s", sv.gioiTinh);
	nhapDiem(&sv.diem);
	return sv;
}

void hienThiTTSV( SinhVien sv) {
	printf("%-10d %-30s%-10s %-10.2f %-10.2f %-10.2f %-10.2f\n",
	       sv.ma, sv.ten, sv.gioiTinh,sv.diem.toan, sv.diem.van, sv.diem.anh, sv.diem.tbc);
}

void sapXepTheoTen( SinhVien* ds, int slsv) {
	int i, j;
	for(i = 0; i < slsv - 1; i++) {
		for(j = slsv - 1; j > i; j --) {
			if(strcmp(ds[j].ten, ds[j-1].ten) < 0) {
				struct SinhVien sv = ds[j];
				ds[j] = ds[j - 1];
				ds[j - 1] = sv;
			}
		}
	}
}

void sapXepTheoDiem( SinhVien* ds, int slsv) {
	int i, j;
	for(i = 0; i < slsv - 1; i++) {
		for(j = slsv - 1; j > i; j --) {
			if(ds[j].diem.tbc > ds[j - 1].diem.tbc) {
				struct SinhVien sv = ds[j];
				ds[j] = ds[j - 1];
				ds[j - 1] = sv;
			}
		}
	}
}

void timTheoTen(SinhVien* ds, int slsv) {
	char ten[20];
	printf("Nhap ten: ");
	scanf("%s", ten);
	hienThiTenCot();
	int i, timSV = 0;
	for(i = 0; i < slsv; i++) {
		if(strcmp(ten, ds[i].ten) == 0) {
			hienThiTTSV(ds[i]);
			timSV = 1;
		}
	}
	if(timSV == 0) {
		printf("Khong co sinh vien %s trong danh sach!\n", ten);
	}
}

void ghiFile( SinhVien* ds, int slsv) {
	getchar();
	char fName[26];
	printf("Nhap ten file: ");
	gets(fName);
	FILE* fOut = fopen(fName, "a");
	int i;
	for(i = 0; i < slsv; i++) {
		struct SinhVien sv = ds[i];
		fprintf(fOut, "%-10d %-30s%-10s %-10.2f %-10.2f %-10.2f %-10.2f\n",
		sv.ma, sv.ten, sv.gioiTinh,sv.diem.toan, sv.diem.van, sv.diem.anh, sv.diem.tbc);
	}
	fclose(fOut);
}

void docFile( SinhVien ds[], int slsv) {
	FILE* fOut = fopen("SV.txt", "r");
	int i = 0;
	if(fOut) {
		for(;;) {
		         SinhVien sv;
			fscanf(fOut, "%10d %30s %10s %10f %10f %10f %10f\n",
			&sv.ma, sv.ten, sv.gioiTinh,&sv.diem.toan, &sv.diem.van, &sv.diem.anh, &sv.diem.tbc);
			strcpy(ds[i].ten,sv.ten);
			strcpy(ds[i].gioiTinh,sv.gioiTinh);
			ds[i].ma=sv.ma;
			ds[i].diem.toan=sv.diem.toan;
			ds[i].diem.van=sv.diem.van;
			ds[i].diem.anh=sv.diem.anh;
			ds[i].diem.tbc=sv.diem.tbc;
			i++;
			if(feof(fOut)) { // thoat chuong trinh
				break;
			}
		}
	}
	
	fclose(fOut);
	slsv = i;
}

void hienThiTenCot() {
	printf("---------------------------------------------"
	"-----------------------------------------------\n");
	printf("%-10s %-28s %-10s %-10s %-10s %-10s %-10s\n", 
	       "Ma SV", "Ten", "Gioi Tinh","Diem Toan", "Diem Van", "Diem Anh", "Diem TBC");
}

void hienThiDSSV(SinhVien* ds, int slsv) {
	hienThiTenCot();
	int i;
	for(i = 0; i < slsv; i++) {
		hienThiTTSV(ds[i]);
	}
	printf("------------------------------------------"
	"--------------------------------------------------\n");
}
typedef struct Node {
    SinhVien key; 
    struct Node *Left, *Right;
}Node;

typedef Node* TreeType;
 
int compare(SinhVien x, SinhVien y) { 
    return strcmp(x.ten,y.ten);
}
void Free(Node* root ) // xoa cay
{
    if ( root == NULL )
        return;
 
    Free( root->Left );
    Free( root->Right );
    free( root );
}
void insertNode(TreeType *T, SinhVien x) {
  if (*T == NULL) {
    (*T) = (Node*)malloc( sizeof(Node ) );
    (*T)->Left=NULL;
    (*T)->Right=NULL;
    (*T)->key=x;
    }
  if (compare((*T)->key, x) > 0)
    insertNode(&((*T)->Left), x);
  else if (compare((*T)->key, x) < 0)
    insertNode(&((*T)->Right), x); 
}

 
Node* searchScores(Node* T, float diem)     // tim nut co diem < diem
        {
    if (T != NULL) {
        if (T->key.diem.tbc < diem) {
            struct Node *P = T;
            return P;
        }
        if (T->key.diem.tbc >= diem) {
            Node *node = searchScores(T->Left,diem );
            if (node != NULL)
                return node;
            else {
                return searchScores(T->Right, diem);
            }
        }
    }
    return NULL;
}
 void DuyetTruoc(Node* root){
    if(root != NULL)
    {
      hienThiTTSV(root->key);
      DuyetTruoc(root->Left);
      DuyetTruoc(root->Right);
    }
}
 
void DuyetGiua(Node* root){
    if(root != NULL)
    {
        DuyetGiua(root->Left);
        hienThiTTSV( root->key);
        DuyetGiua(root->Right);
    }
}
 
void DuyetSau(Node* root){
    if(root != NULL)
    {
        DuyetSau(root->Left);
        DuyetSau(root->Right);
        hienThiTTSV( root->key);
    }
}
SinhVien LeftMostValue( Node* root )
{
    while ( root->Left != NULL )
        root = root->Left;
    return root->key;
}

Node* delKey(Node *T, SinhVien x)     // xoa nut co key x
        {
    if (T == NULL)
        return T;
    else if (compare(T->key, x) > 0)
        return delKey(T->Left, x);
    else if (compare(T->key, x) < 0)
        return delKey(T->Right, x);
    else // T->key == x
    {
       
      if (T->Left == NULL){
	 Node* newRoot = T->Right;
	 free(T);
	 return newRoot;
      }
      else if (T->Right == NULL)
	{
	  Node* newRoot = T->Left;
	  free(T);
	  return newRoot;
	}
      T->key = LeftMostValue( T->Right );
      T->Right= delKey( T->Right, T->key );
      return T;
    }
	}
 
int main() {
    Node* T = NULL; //Tao cay rong
    SinhVien dssv[100];
    int slsv = 0;
    int luaChon;
    int i,n;
    SinhVien sv;
    FILE* fOut = fopen("SV.txt", "r");
    i=0;
    while(!feof(fOut)){	 
	  fscanf(fOut, "%10d %30s %10s %10f %10f %10f %10f\n",&sv.ma, sv.ten, sv.gioiTinh,&sv.diem.toan, &sv.diem.van, &sv.diem.anh, &sv.diem.tbc);
	  strcpy(dssv[i].ten,sv.ten);
	  strcpy(dssv[i].gioiTinh,sv.gioiTinh);
	  dssv[i].ma=sv.ma;
	  dssv[i].diem.toan=sv.diem.toan;
	  dssv[i].diem.van=sv.diem.van;
	  dssv[i].diem.anh=sv.diem.anh;
	  dssv[i].diem.tbc=sv.diem.tbc;
	  i++;
	  //	  dssv[i]=sv;
	}
	 slsv=i;		
	printf(" slsv: %d\n",slsv);
	printf("               DANH SACH SINH VIEN HIEN THOI:\n\n");
	hienThiDSSV(dssv, slsv);
	printf("\n");
	 for(i=0;i<slsv;i++){
		    insertNode(&T,dssv[i]);
		  }
		 


    do {
		printf("\n********************************************\n");
		printf("**                 MENU                   **\n");
		printf("**    1. Them Sinh vien vao danh sach.    **\n");
		printf("**    2. Xoa sinh vien co diem be hon 4.  **\n");
		printf("**    3. In danh sach sinh vien.          **\n");
		printf("**    4. Thoat.                           **\n");
		printf("********************************************\n");
		do{
		  printf("\nBan chon ? ");
		  scanf("%d", &luaChon);
		}while(luaChon<0||luaChon>4);
	
		switch(luaChon){
		case 1:
		  printf(" Nhap so luong sinh vien can them vao danh sach: ");
		  scanf("%d",&n);
		  
		  for(i=slsv;i<slsv+n;i++)
		    {
		      printf(" sinh vien thu %d :\n ",i+1);
		      dssv[i]=nhapSV();
		      insertNode(&T, dssv[i]);
		    }
		  printf("               DANH SACH SINH VIEN HIEN THOI:\n\n");
		  hienThiDSSV(dssv, slsv+n);
		  printf("\n");
		  break;

		case 3:
		    printf("*Duyet truoc :\n ");
		    DuyetTruoc(T);
		    printf("\n*Duyet giua  :\n ");
		    DuyetGiua(T);
		    printf("\n*Duyet sau:\n");
		    DuyetSau(T);
		    break;

		case 2:
		   
		    
		   if (searchScores(T, 4) != NULL) {
		     delKey(T, searchScores(T, 4)->key);
		       }
		   break;

		case 4:
		    printf("Exit!!\n");
		  break;
	    
		
		}
    }while(luaChon!=4);
	
	return 0;
}
