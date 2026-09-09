/*顺序表的归并操作*/
#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
#define Length 10
#define LISTINCREMENT 10
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR -1
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;
typedef struct lineorder {
    int* elem;
    int length;
    int listsize;
}SqList;

Status initlist_Sq(SqList& L) /*初始化顺序表*/
{
    L.elem = (ElemType*)malloc(sizeof(ElemType) * Length);
    if (!L.elem) exit(OVERFLOW);
    L.listsize = Length;
    L.length = 0;
    return OK;
}

void destroylist(SqList& c) /*销毁顺序表*/
{
    free(c.elem);
    c.elem = NULL;
    c.length = 0;
}

void clearlist_Sq(SqList& c) /*清空顺序表*/
{
    c.length = 0;
}

Status listempty_Sq(SqList c) /*测试顺序表是否为空*/
{
    if (c.length != 0) return(FALSE);
    return(TRUE);
}
Status ListInsert_Sq(SqList* L, int i, ElemType e) /*在第i个位置上插入一个元素*/
{
    int j, * newbase;
    if (i<1 || i>L->length + 1) return ERROR;
    if (L->length >= L->listsize) 
    {
        newbase = (ElemType*)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!newbase)  exit(OVERFLOW);
        L->elem = newbase;  
        L->listsize += LISTINCREMENT;
    }
    for (j = L->length; j >= i; --j)
        L->elem[j] = L->elem[j - 1];
    L->elem[j] = e;  ++L->length;
    return OK;
}

void Print_Sq(const char* ch, SqList L) /*输出顺序表*/
{
    int i;
    if (listempty_Sq(L))
        printf("\n%s Sequential List 's length is %d. It's empty!", ch, L.length);
    else
        printf("\n%s Sequential List's length is %d. These element are : ", ch, L.length);
    for (i = 0;i < L.length;i++)
        printf(" %d", L.elem[i]);
}

int LocateElem_Sq(SqList* L, ElemType e) /*返回元素e在顺序表中的位置*/
{
    int i = 1;
    ElemType* p;
    p = L->elem;
    while (i <= L->length && !(*p == e)) { i++; p++; }
    if (i <= L->length) return i;
    return FALSE;
}

int union_Sq(SqList* La, SqList Lb)
{
    int i, La_len = La->length, Lb_len = Lb.length, j;
    ElemType e;
    for (i = 1;i <= Lb_len;i++) {
        e = Lb.elem[i - 1];
        if (!LocateElem_Sq(La, e))
            ListInsert_Sq(La, ++La_len, e);
    }
    return OK;
}

int MergeList(SqList La, SqList Lb, SqList* Lc)
{
    int i = 1, j = 1, k = 0, La_len = La.length, Lb_len = Lb.length;
    ElemType ai, bj;
    while ((i <= La_len) && (j <= Lb_len))
    {
        ai = La.elem[i - 1]; bj = Lb.elem[j - 1];
        if (ai <= bj) { ListInsert_Sq(Lc, ++k, ai);i++; }
        else { ListInsert_Sq(Lc, ++k, bj);j++; }
    }
    while (i <= La_len) { ai = La.elem[-1 + i++];ListInsert_Sq(Lc, ++k, ai); }
    while (j <= Lb_len) { bj = Lb.elem[-1 + j++];ListInsert_Sq(Lc, ++k, bj); }
    return OK;
}
void main()
{
    ElemType e;
    SqList La, Lb, Lc;
    int n, i;
    system("cls");
    initlist_Sq(La);
    initlist_Sq(Lb);
    printf("\nInput a number of the element in the Sequential List La (n<=%d):", Length);
    cin >> n;
    printf("\nEnter these elements:");
    for (i = 1;i <= n;i++)
    {
        cin >> e;
        ListInsert_Sq(&La, i, e);
    }
    printf("\nInput a number of the element in the Sequential List Lb (n<=%d):", Length);
    cin>>n;
    printf("\nEnter these elements:");
    for (i = 1;i <= n;i++)
    {
        cin >> e;
        ListInsert_Sq(&Lb, i, e);
    }
    Print_Sq("La", La);
    printf("\n");
    Print_Sq("Lb", Lb);
    union_Sq(&La, Lb);
    printf("\n");
    Print_Sq("La after union (La&Lb)", La);
    initlist_Sq(Lc);
    MergeList(La, Lb, &Lc);
    printf("\n");
    Print_Sq("Lc (La or Lb)", Lc);
    printf("\n");
    clearlist_Sq(Lc);
    Print_Sq("Lc after clear", Lc);
    int n = getch();
}
