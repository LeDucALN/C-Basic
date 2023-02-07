#include <stdio.h>
#include <stdlib.h>


typedef int ElementType;
struct _PointerType{
  ElementType Inf;
  struct _PointerType *Next;
};
typedef struct _PointerType PointerType;

//1. Chen vao giua
PointerType *InsertMiddle(PointerType *Prev, ElementType X);

//2.Chen vao dau
PointerType *InsertToHead(PointerType *First, ElementType X);

//3.Chen vao cuoi
PointerType *InsertToLast(PointerType *First, ElementType X);

//4. Xoa dau
PointerType *DeleteHead(PointerType *First);

//5, Xoa giua
ElementType Delete(PointerType *Prev);

//6.Xoa cuoi
PointerType *DeleteLast(PointerType *First);

//7. Rong khong
int IsEmpty(PointerType *First);

//8. Tao
PointerType *MakeNull(PointerType *First);

//9. In
void Print(PointerType *First);

//10. Dia chi tuong ung trong danh sach
PointerType *DiaChiTuongUng(PointerType *ds,int n);

//11.Chen voi tham so tuong ung trong danh sach
PointerType *ChenVoiThamSo(PointerType *ds,int n, ElementType X);

//12. Xoa voi tham so tuong ung trong danh sach
ElementType XoaVoiThamSo(PointerType *ds,int n);
