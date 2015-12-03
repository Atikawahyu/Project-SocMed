#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "comment.h"

using namespace std;

//COMMENT
void createListComment(list_comment &l)
{
    l.first = NULL;
    l.last = NULL;
}

adrcomment alokasi_comment(infotype_comment x)
{
    adrcomment p = new elmComment;
    p -> info = x;
    p -> next = NULL;
    p -> prev = NULL;
    p -> akun = NULL;
    return p;
}

void addComment (list_comment &l, list_likecom l2, infotype_comment x)
{
    int pilih, cariID, hsl;
    adrcomment p = alokasi_comment(x);
    viewAll(l,l2);
    do
    {
        cout << "Masukkan comment ke urutan : " << endl;
        cout << "1. Pertama" << endl;
        cout << "2. Terakhir" << endl;
        cout << "3. Setelah ID ke-" << endl;
        cout << endl;
        cout << "Pilihan : ";
        cin >> pilih;
        if ((pilih == 3) && (l.first == NULL)) {
            cout << "Comment masih kosong" << endl;
            getch();
        }
        system("cls");
    }
    while ((pilih != 1) && (pilih != 2) && ((pilih != 3) || ((pilih == 3) && (l.first == NULL))));
    switch (pilih)
    {
    case 1 :
        addFirstComment(l,p);
        break;
    case 2 :
        addLastComment(l,p);
        break;
    case 3 :
        do
        {
            system("cls");
            viewAll(l,l2);
            cout << endl;
            cout << "Masukkan Comment setelah ID ke - ";
            cin >> cariID;
            hsl = check_IDComment(l,cariID);
            if (hsl == -1)
            {
                cout << "ID Tidak Ditemukan" << endl;
                getch();
            }
        }
        while (hsl == -1);
        addAfterComment(l,p,cariID);
        break;
    default :
        cout << "Pilihan Salah" << endl;
        getch();
        break;
    }
}

void addFirstComment (list_comment &l, adrcomment p)
{
    if (l.first == NULL)
    {
        l.first = p;
        l.last = p;
    }
    else
    {
        p -> next = l.first;
        (l.first) -> prev = p;
        l.first = p;
    }
}

void addLastComment (list_comment &l, adrcomment p)
{
    if (l.first == NULL)
    {
        l.first = p;
        l.last = p;
    }
    else
    {
        p -> prev = l.last;
        (l.last) -> next = p;
        l.last = p;
    }
}

void addAfterComment (list_comment &l, adrcomment p, int x)
{
    adrcomment q = l.first;
    while ((q -> info).id_com != x)
    {
        q = q -> next;
    }
    if (q == l.first) {
        addFirstComment(l,p);
    }
    else if (q == l.last) {
        addLastComment(l,p);
    } else {
        (q -> next) -> prev = p;
        p -> next = q -> next;
        q -> next = p;
        p -> prev = q;
    }
}

void deleteComment (list_comment &l1,list_likecom &l2, int x)
{
    adrcomment p;
    adrcomment q;
    q=findComment_ID(l1,x);
    if(q!=NULL)
    {
        clearAllRelation(l2,q);
    }
    p = l1.first;
    while (((p -> info).id_com != x) && (p -> next != NULL))
    {
        p = p -> next;
    }
    if ((p -> info).id_com == x) {
        if(p==l1.first)
        {
            deleteFirstComment(l1);
        }
        else if(p==l1.last)
        {
            deleteLastComment(l1);
        }
        else
        {
            deleteAfterComment(l1,p);
        }
    }
}

adrcomment deleteFirstComment (list_comment &l)
{
    adrcomment p = l.first;
    if (l.first == NULL)
    {
        return NULL;
    }
    else
    {
        if (p -> next == NULL)
        {
            l.first = NULL;
            l.last = NULL;
            return p;
        }
        else
        {
            l.first = p -> next;
            p -> next = NULL;
            return p;
        }
    }
}

adrcomment deleteLastComment (list_comment &l)
{
    adrcomment p =l.last;
    if (l.first== NULL)
    {
        return NULL;
    }
    else
    {
        if (p -> prev == NULL)
        {
            l.first = NULL;
            l.last = NULL;
            return p;
        }
        else
        {
            l.last = p -> prev;
            (l.last) -> next = NULL;
            p -> prev = NULL;
            return p;
        }
    }
    return NULL;
}

adrcomment deleteAfterComment(list_comment &l, adrcomment p)
{
    adrcomment r;
    adrcomment q = l.first;
    if (l.first == NULL)
    {
        return NULL;
    }
    else
    {
        while ((q != p) && (q != NULL)) {
            q = q -> next;
        }
        r = q -> prev;
        if (r != NULL) {
            r -> next = q -> next;
            (q -> next) -> prev = r;
            q -> prev = NULL;
            q -> next = NULL;
            return q;
        }
        return NULL;
    }
    return NULL;
}

void editComment (list_comment &l, int x)
{
    adrcomment p = l.first;
    while (p != NULL)
    {
        if ((p -> info).id_com == x)
        {
            break;
        }
        else
        {
            p = p -> next;
        }
    }
    if ((p -> info).id_com != x)
    {
        cout << "Comment Tidak Ditemukan" << endl;
        getch();
    }
    else
    {
        system("cls");
        cout << "ID : " << (p -> info).id_com << endl;
        cout << "Tanggal : " << (p -> info).tgl_com << endl;
        cout << "Isi : " << (p -> info).isi << endl;
        cout << endl;
        cin.ignore();
        cout << "Masukkan Isi Comment yg Baru : ";
        getline(cin,(p -> info).isi);
    }
}

adrcomment findComment_ID (list_comment l,int x)
{
    adrcomment p = l.first;
    while (p != NULL)
    {
        if ((p -> info).id_com == x)
        {
            return p;
        }
        p = p -> next;
    }
    return NULL;
}

void findCommentbyDate (list_comment l,int x)
{
    adrcomment p = l.first;
    while (p != NULL)
    {
        if ((p -> info).tgl_com == x)
        {
            cout << "ID : " << (p -> info).id_com << endl;
            cout << "Tanggal : " << (p -> info).tgl_com << endl;
            cout << "Isi Comment : " << (p -> info).isi << endl;
            cout << endl;
        }
        p = p -> next;
    }
}

void sortComment_ID (list_comment l,list_likecom l2)
{
    adrcomment p, q;
    p = l.first;
    while(p!=NULL)
    {
        q=p;
        while ((q->prev!=NULL) && (q!=NULL) && ((q->prev->info).id_com > (q->info).id_com))
        {
            swap(q->prev-> info,q -> info);
            swap(q->prev -> akun,q -> akun);
            q=q->prev;
        }
        p=p->next;
    }
    p=NULL;
    q=NULL;
    viewcomment(l,l2);
}

void sortComment_date (list_comment l1,list_likecom l2)
{
    adrcomment p = l1.first;
    adrcomment iMin;
    adrcomment q;
    while (p -> next != NULL)
    {
        iMin = p;
        if (p -> next != NULL) {
            q = p -> next;
        }
        while (q != NULL)
        {
            if ((q -> info).tgl_com < (iMin -> info).tgl_com)
            {
                iMin = q;
            }
            q = q -> next;
        }
        if ((iMin -> info).tgl_com < (p -> info).tgl_com)
        {
            swap(p -> info,iMin -> info);
            swap(p -> akun,iMin -> akun);
        }
        if (p -> next != NULL) {
            p = p -> next;
        }
    }
    viewcomment(l1,l2);
}

int check_IDComment (list_comment l, int x)
{
    if (l.first != NULL)
    {
        adrcomment p = l.first;
        while (p != NULL)
        {
            if ((p -> info).id_com == x)
            {
                return (p -> info).id_com;
            }
            p = p -> next;
        }
    }
    return -1;
}

//LIKE COMMENT
void createListLikeCom (list_likecom &l)
{
    l.first = NULL;
}

adrlikecom alokasi_likecom (infotype_likecom x)
{
    adrlikecom p = new elmLikeComment;
    p -> info = x;
    p -> next = NULL;
    p -> akun = NULL;
    p -> like = NULL;
    return p;
}

void addLikeCom (list_comment &l1, list_likecom &l2, adrcomment q)
{
    int likeID,pilih,cek,hsl;
    bool cektgl;
    infotype_likecom x;
    system ("cls");
    do
    {
        cout << "Tanggal Like (YYYYMMDD) : ";
        cin >> x.tgl_likecom;
        cektgl = cekDate(x.tgl_likecom);
        if (x.tgl_likecom < (q -> info).tgl_com) {
            cout << "Tanggal Like tidak boleh kurang dari tanggal comment" << endl;
            getch();
        }
    }
    while ((cektgl != TRUE) || (x.tgl_likecom < (q -> info).tgl_com));
    do
    {
        x.id_likecom = rand () % 999 + 2000;
        cek = check_IDLikeCom(l2,x.id_likecom);
    }
    while (cek != -1);
    cout << endl;
    do
    {
        viewLike(l2,q);
        cout << endl;
        cout << "Masukkan Like di urutan ke -" << endl;
        cout << "1. Pertama" << endl;
        cout << "2. Terakhir" << endl;
        cout << "3. Setelah Like dengan ID" << endl;
        cout << "0. Batal" << endl;
        cout << endl;
        cout << "Pilihan : ";
        cin >> pilih;
        if ((pilih == 3) && (l2.first == NULL)) {
            cout << "Like masih kosong" << endl;
            getch();
        }
        system("cls");
    }
    while ((pilih != 1) && (pilih != 2) && ((pilih != 3) || ((pilih == 3) && (l2.first == NULL))) && (pilih != 0));
    adrlikecom p = alokasi_likecom(x);
    setRelation(p,q);
    switch (pilih)
    {
    case 1 :
        addFirstLikeCom(l2,p);
        break;
    case 2 :
        addLastLikeCom(l2,p);
        break;
    case 3 :
        do
        {
            system("cls");
            viewLike(l2,q);
            cout << endl;
            cout << "Masukkan Comment setelah ID ke - ";
            cin >> likeID;
            hsl = check_IDLikeCom(l2,likeID);
            if (hsl == -1)
            {
                cout << "ID Tidak Ditemukan" << endl;
                getch();
            }
        }
        while (hsl == -1);
        addAfterLikeCom(l2,p,likeID);
        break;
    case 0 :
        break;
    default :
        cout << "Pilihan Salah" << endl;
        getch();
        break;
    }
}

void addFirstLikeCom (list_likecom &l, adrlikecom p)
{
    if (l.first == NULL)
    {
        l.first = p;
    }
    else
    {
        p -> next = l.first;
        l.first = p;
    }
}

void addLastLikeCom (list_likecom &l, adrlikecom p)
{
    adrlikecom q = l.first;
    if (l.first == NULL)
    {
        l.first = p;
    }
    else
    {
        while (q -> next != NULL)
        {
            q = q -> next;
        }
        q -> next = p;
    }
}

void addAfterLikeCom (list_likecom &l, adrlikecom p, int x)
{
    adrlikecom q = l.first;
    while ((q -> info).id_likecom != x)
    {
        q = q -> next;
    }
    if (q == l.first) {
        addFirstLikeCom(l,p);
    } else if (q -> next == NULL) {
        addLastLikeCom(l,p);
    } else {
        p -> next = q -> next;
        q -> next = p;
    }
}

void deleteLikeCom (list_likecom &l, adrcomment r)
{
    adrlikecom p,q;
    int x;
    viewLike(l,r);
    if (l.first == NULL) {
        cout << "Like masih kosong!" << endl;
        getch();
    } else {
        cout << "======================================" << endl;
        cout << "Masukkan ID Like yang ingin dihapus : ";
        cin >> x;
        p = l.first;
        while (((p -> info).id_likecom != x) && (p -> next != NULL))
        {
            p = p -> next;
        }
        if ((p -> info).id_likecom == x)
        {
            if ((p -> like) == r)
            {
                if (p == l.first)
                {
                    q = deleteFirstLikeCom(l);
                    delete q;
                }
                else if (p -> next == NULL)
                {
                    q = deleteLastLikeCom(l);
                    delete q;
                }
                else
                {
                    q = deleteAfterLikeCom(l,(p -> info).id_likecom);
                    delete q;
                }
            }
        }
    }
}

adrlikecom deleteFirstLikeCom (list_likecom &l)
{
    adrlikecom p = l.first;
    p = clearRelation(p);
    l.first = p -> next;
    p -> next = NULL;
    return p;
}

adrlikecom deleteLastLikeCom (list_likecom &l)
{
    adrlikecom r;
    adrlikecom p = l.first;
    while (p -> next != NULL)
    {
        r = p;
        p = p -> next;
    }
    p = clearRelation(p);
    r -> next = NULL;
    return p;
}

adrlikecom deleteAfterLikeCom (list_likecom &l,int x)
{
    adrlikecom prec;
    adrlikecom p = l.first;
    while (((p -> info).id_likecom != x) && (p -> next != NULL))
    {
        prec = p;
        p = p -> next;
    }
    if ((p -> info).id_likecom == x)
    {
        p = clearRelation(p);
        prec -> next = p -> next;
        p -> next = NULL;
        return p;
    }
    return NULL;
}

adrlikecom findLikeCom_ID (list_likecom l, int x)
{
    adrlikecom p = l.first;
    while (p != NULL)
    {
        if ((p -> info).id_likecom == x)
        {
            return p;
        }
        p = p -> next;
    }
    return NULL;
}

int countLike (list_likecom l, adrcomment q)
{
    int counter = 0;
    adrlikecom p = l.first;
    while (p != NULL)
    {
        if (p -> like == q)
        {
            counter++;
        }
        p = p -> next;
    }
    return counter;
}

int check_IDLikeCom (list_likecom l, int x)
{
    adrlikecom p = l.first;
    while (p != NULL)
    {
        if ((p -> info).id_likecom == x)
        {
            return (p -> info).id_likecom;
        }
        p = p -> next;
    }
    return -1;
}

void viewLike (list_likecom l, adrcomment q)
{
    int no = 0;
    adrlikecom p = l.first;
    while (p != NULL)
    {
        if (p -> like == q)
        {
            no++;
            cout << "Like " << no << " ID : " << (p -> info).id_likecom << endl;
        }
        p = p -> next;
    }
}

void setRelation (adrlikecom p, adrcomment q)
{
    p -> like = q;
}

void clearAllRelation (list_likecom &l,adrcomment q)
{
    adrlikecom p = l.first;
    while (p != NULL)
    {
        if (p -> like == q)
        {
            p = clearRelation(p);
        }
        p = p -> next;
    }
}

adrlikecom clearRelation (adrlikecom p)
{
    p -> like = NULL;
    return p;
}

bool cekDate (int x)
{
    int thn,bln,tgl;
    thn = x / 10000;
    x = x - (thn * 10000);
    bln = x / 100;
    tgl = x - (bln * 100);
    if (((thn < 1980) || (thn > 2099)) || ((bln > 12) || (bln < 1)) || ((tgl > 31) || (tgl < 1)))
    {
        return FALSE;
    }
    return TRUE;
}

void viewAll (list_comment l1,list_likecom l2)
{
    system("cls");
    adrcomment p = l1.first;
    if (p != NULL)
    {
        while (p != NULL)
        {
            cout << "ID Comment : " << (p -> info).id_com << endl;
            cout << "Isi Comment : " << (p -> info).isi << endl;
            int jml = countLike(l2,p);
            cout << "Jumlah Like : " << jml << endl;
            viewLike(l2,p);
            cout << endl;
            p = p -> next;
        }
    }
    else
    {
        cout << "Tidak Ada Comment" << endl;
        cout << endl;
    }
}
void viewlistlike(list_likecom l)
{
    adrlikecom p = l.first;
    if(p == NULL)
    {
        cout<<"list kosong";
    }
    else
    {
        while(p != NULL)
        {
            cout<<"ID like :"<<p->info.id_likecom<<endl
                <<"Date    :"<<p->info.tgl_likecom<<endl
                <<"----------------------------"<<endl;
            p = p -> next;
        }
    }
}

void viewcomment(list_comment l1, list_likecom l2) {
    system("cls");
    adrcomment p = l1.first;
    if (p != NULL)
    {
        while (p != NULL)
        {
            cout << "ID Comment : " << (p -> info).id_com << endl;
            cout << "Tgl Comment : " << (p -> info).tgl_com << endl;
            cout << "Isi Comment : " << (p -> info).isi << endl;
            int jml = countLike(l2,p);
            cout << "Jumlah Like : " << jml << endl;
            p = p -> next;
            cout << endl;
        }
    }
    else
    {
        cout << "Tidak Ada Comment" << endl;
        cout << endl;
    }
}

void viewcom_ID(list_comment l1,list_likecom l2,int x) {
    adrcomment p = l1.first;
    while (((p -> info).id_com != x) && (p -> next != NULL)) {
        p = p -> next;
    }
    if ((p -> info).id_com == x) {
        cout << "ID Comment : " << (p -> info).id_com << endl;
        cout << "Tgl Comment : " << (p -> info).tgl_com << endl;
        cout << "Isi Comment  : " << (p -> info).isi << endl;
        int jml = countLike(l2,p);
        cout << "Jumlah Like : " << jml << endl;
    } else {
        cout << "Comment tidak ditemukan" << endl;
    }
}
