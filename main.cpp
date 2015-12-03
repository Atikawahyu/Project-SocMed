#include "comment.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>

using namespace std;

infotype_comment x;
list_comment listcom,templ;
list_likecom listlikecom,temp2;
adrcomment p,id;
adrlikecom q;
int cekID,pil,idcom,pilih;
bool cektgl;

int main()
{
    do
    {
        system("cls");
        cout <<"===== MENU UTAMA ======"<<endl;
        cout <<"1. Add Comment"<<endl;
        cout <<"2. View Comment"<<endl;
        cout <<"3. Find Comment"<<endl;
        cout <<"4. Sort Comment"<<endl;
        cout <<"0. Keluar"<<endl;
        cout<<"Masukan pilihan : ";
        cin>>pilih;
        switch(pilih)
        {
        case 1 :
        {
            //tambah komen
            system("cls");
            cout << "======= INPUT COMMENT =======" << endl;
            cout << endl;
            cin.ignore();
            cout << "Masukkan isi comment : ";
            getline(cin,x.isi);
            do
            {
                cout << "Tanggal comment (YYYYMMDD) : ";
                cin >> x.tgl_com;
                cektgl = cekDate(x.tgl_com);
            }
            while (cektgl == FALSE);
            do
            {
                x.id_com = rand () % 999 + 1000;
                cekID = check_IDComment(listcom,x.id_com);
            }
            while (cekID != -1);
            addComment(listcom,listlikecom,x);
            break;
        }
        case 2 :
            {
                //tampilin komen
                do
                {
                    system("cls");
                    viewcomment (listcom,listlikecom);
                    cout << "=============================================="<< endl;
                    cout << endl;
                    cout<<"1. Pilih comment"<<endl
                        <<"0. Kembali"<<endl
                        <<"Pilih : ";
                    cin>>pil;
                    switch(pil)
                    {
                    case 1 :
                    {
                        if (listcom.first == NULL)
                        {
                            cout << "List Kosong" << endl;
                            getch();
                        }
                        else
                        {
                            do
                            {
                                cout<<"Input ID : ";
                                cin>>idcom;
                                id=findComment_ID(listcom,idcom);
                            }
                            while (id == NULL);
                            do
                            {
                                system("cls");
                                viewcom_ID(listcom,listlikecom,idcom);
                                cout<<endl;
                                cout << "=========================================" << endl;
                                cout<< endl;
                                cout<<"1. Add Like"<<endl
                                    <<"2. Delete Like"<<endl
                                    <<"3. Edit Comment"<<endl
                                    <<"4. Delete Comment"<<endl
                                    <<"5. View List Like"<<endl
                                    <<"0. Back"<<endl
                                    <<"Pilih : ";;
                                cin>>pil;
                                switch(pil)
                                {
                                case 1 :
                                {
                                    addLikeCom(listcom,listlikecom,id);
                                    break;
                                }
                                case 2 :
                                {
                                    cout << endl;
                                    deleteLikeCom(listlikecom,id);
                                    break;
                                }
                                case 3 :
                                    editComment(listcom,(id -> info).id_com);
                                    break;
                                case 4 :
                                    deleteComment(listcom,listlikecom,(id -> info).id_com);
                                    break;
                                case 5 :
                                    cout << endl;
                                    viewLike(listlikecom,id);
                                    getch();
                                    break;
                                }
                            }
                            while (pil!=0 && pil != 4);
                            pil=888;
                        }
                    }
                    case 0 :
                       break;
                    default :
                        break;
                    }
                }
                while(pil != 0);
            }
            break;
        case 3 :
        {
            //find comment
            system("cls");
            if (listcom.first == NULL) {
                cout << "List Masih Kosong!" << endl;
                getch();
            } else {
                    cout<<"1. Find Comment ID"<<endl
                        <<"2. Find Comment Date"<<endl
                        <<"Pilih : ";
                    cin>>pil;
                    switch (pil)
                    {
                    case 1 :
                    {
                        cout<<"Input ID : ";
                        cin>>idcom;
                        cout<<"----------------------------------"<<endl;
                        p = findComment_ID(listcom,idcom);
                        if (p == NULL)
                        {
                            cout << "Comment tidak ditemukan" << endl;
                        }
                        else
                        {
                            viewcom_ID(listcom,listlikecom,(p -> info).id_com);
                        }
                        getch();
                        break;
                    }
                    case 2 :
                        cout<<"Input Date (YYYYMMDD) : ";
                        int date;
                        cin>>date;
                        cout<<"----------------------------------"<<endl;
                        findCommentbyDate(listcom,date);
                        getch();
                        break;
                    }
            }
            break;
        }


        case 4:
            {
                system("cls");
                cout<<"1. Sort Comment ID"<<endl
                    <<"2. Sort Comment Date"<<endl
                    <<"Pilih : ";
                cin>>pil;
            switch (pil)
            {
            case 1 :
                {
                    if (listcom.first == NULL) {
                        cout << "List Kosong" << endl;
                    } else {
                        sortComment_ID(listcom,listlikecom);
                    }
                getch();
                break;
                }
            case 2 :
                {
                    if (listcom.first == NULL) {
                        cout << "List Kosong" << endl;
                    } else {
                        sortComment_date(listcom,listlikecom);
                    }
                getch();
                break;
            }
        }

    }
    }
    } while (pilih != 0);
}
