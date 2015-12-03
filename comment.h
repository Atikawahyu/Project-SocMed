#ifndef COMMENT_H_INCLUDED
#define COMMENT_H_INCLUDED
#include <string>

using namespace std;

typedef struct like_comment infotype_likecom;
typedef struct comment infotype_comment;
typedef struct elmComment *adrcomment;
typedef struct elmLikeComment *adrlikecom;
typedef struct elmAddressAkun *adrakun;

struct comment {
    int id_com, tgl_com;
    string isi;
};

struct like_comment {
    int id_likecom, tgl_likecom;
};

struct elmComment {
    infotype_comment info;
    adrcomment next, prev;
    adrakun akun;
};

struct elmLikeComment {
    infotype_likecom info;
    adrlikecom next;
    adrakun akun;
    adrcomment like;
};

struct list_comment {
    adrcomment first, last;
};

struct list_likecom {
    adrlikecom first;
};

// Comment
void createListComment (list_comment &l);
adrcomment alokasi_comment (infotype_comment x);
void addComment (list_comment &l, list_likecom l2, infotype_comment x);
void addFirstComment (list_comment &l, adrcomment p);
void addLastComment (list_comment &l, adrcomment p);
void addAfterComment (list_comment &l, adrcomment p, int x);
void deleteComment (list_comment &l1,list_likecom &l2, int x);
adrcomment deleteFirstComment (list_comment &l);
adrcomment deleteLastComment (list_comment &l);
adrcomment deleteAfterComment(list_comment &l,adrcomment p);
void editComment (list_comment &l, int x);
adrcomment findComment_ID (list_comment l,int x);
void findCommentbyDate (list_comment l,int x);
void sortComment_ID (list_comment l,list_likecom l2);
void sortComment_date (list_comment l1,list_likecom l2);
int check_IDComment (list_comment l, int x);

// Like Comment
void createListLikeCom (list_likecom &l);
adrlikecom alokasi_likecom (infotype_likecom x);
void addLikeCom (list_comment &l1, list_likecom &l2, adrcomment q);
void addFirstLikeCom (list_likecom &l, adrlikecom p);
void addLastLikeCom (list_likecom &l, adrlikecom p);
void addAfterLikeCom (list_likecom &l, adrlikecom p, int x);
void deleteLikeCom (list_likecom &l, adrcomment r);
adrlikecom deleteFirstLikeCom (list_likecom &l);
adrlikecom deleteLastLikeCom (list_likecom &l);
adrlikecom deleteAfterLikeCom (list_likecom &l,int x);
adrlikecom findLikeCom_ID (list_likecom l, int x);
int countLike (list_likecom l, adrcomment q);
int check_IDLikeCom (list_likecom l, int x);
void viewLike (list_likecom l, adrcomment q);
void viewlistlike(list_likecom l);
void viewcomment (list_comment l1, list_likecom l2);
void viewcom_ID (list_comment l1, list_likecom l2, int x);

void setRelation (adrlikecom p, adrcomment q);
void clearAllRelation (list_likecom &l,adrcomment q);
adrlikecom clearRelation (adrlikecom p);
bool cekDate (int x);
void viewAll (list_comment l1,list_likecom l2);

#endif // COMMENT_H_INCLUDED
