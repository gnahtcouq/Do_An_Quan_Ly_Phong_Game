#pragma once
#include "MotMayTinh.hpp"
#include "ThueMotMay.hpp"

struct Node {
    ThueMotMay data;
    Node *pNext;
};

struct ThueNhieuMay {
    Node *pHead;
    Node *pTail;
};

void createList(ThueNhieuMay &thueNhieuMay);
Node *createNode(ThueMotMay value);
void addNodeInTail(ThueNhieuMay &thueNhieuMay, ThueMotMay thueMotMay);
void removeNodeInHead(ThueNhieuMay &thueNhieuMay);
void removeNodeInTail(ThueNhieuMay &thueNhieuMay);
void giaiPhongVungNhoDanhSachNguoiThue(ThueNhieuMay &thueNhieuMay);

bool kiemTraTaiKhoanDaTonTai(ThueNhieuMay thueNhieuMay, char *taiKhoan);
void themMotNguoiThueVaoDanhSach(ThueNhieuMay &thueNhieuMay, MayTinh nhieuMay[], int n);
void xuatDanhSachNguoiThue(ThueNhieuMay thueNhieuMay);

void chinhSuaDanhSachNguoiThue(ThueNhieuMay &thueNhieuMay, MayTinh nhieuMay[], int n, char *taiKhoan);
void xoaMotNguoiThue(ThueNhieuMay &thueNhieuMay, char *taiKhoan);
void docDanhSachNguoiThue(ThueNhieuMay &thueNhieuMay, MayTinh nhieuMay[], int n);
void ghiDanhSachNguoiThue(ThueNhieuMay thueNhieuMay);
bool kiemTraTaiKhoanDaTonTai(ThueNhieuMay thueNhieuMay, char *taiKhoan);
bool kiemTraSoDienThoaiDaTonTai(ThueNhieuMay thueNhieuMay, char *soDienThoai);

void ghiDanhSachNguoiThue(ThueNhieuMay thueNhieuMay);
void xuatFileDanhSachNguoiThue(ThueNhieuMay thueNhieuMay);

void createList(ThueNhieuMay &thueNhieuMay) {
    thueNhieuMay.pHead = NULL;
    thueNhieuMay.pTail = NULL;
}

Node *createNode(ThueMotMay value) {
    Node *p = (Node *)calloc(1, sizeof(Node));
    if (p == NULL) {
        cout << "\n\t(!) Khong du bo nho (!)";
        return NULL;
    } else {
        p->data = value;
        p->pNext = NULL;
    }
    return p;
}

void addNodeInTail(ThueNhieuMay &thueNhieuMay, ThueMotMay thueMotMay) {
    Node *p = createNode(thueMotMay);
    if (thueNhieuMay.pHead == NULL)
        thueNhieuMay.pHead = thueNhieuMay.pTail = p;
    else {
        thueNhieuMay.pTail->pNext = p;
        thueNhieuMay.pTail = p;
    }
}

void removeNodeInHead(ThueNhieuMay &thueNhieuMay) {
    if (thueNhieuMay.pHead == NULL)
        return;
    else {
        Node *p = thueNhieuMay.pHead;
        thueNhieuMay.pHead = p->pNext;
        free(p);
    }
}

void removeNodeInTail(ThueNhieuMay &thueNhieuMay) {
    if (thueNhieuMay.pHead == NULL)
        return;
    else if (thueNhieuMay.pHead == thueNhieuMay.pTail)
        removeNodeInHead(thueNhieuMay);
    else {
        for (Node *t = thueNhieuMay.pHead; t != NULL; t = t->pNext) {
            if (t->pNext == thueNhieuMay.pTail) {
                free(thueNhieuMay.pTail);
                t->pNext = NULL;
                thueNhieuMay.pTail = t;
                return;
            }
        }
    }
}

void giaiPhongVungNhoDanhSachNguoiThue(ThueNhieuMay &thueNhieuMay) {
    Node *t = NULL;
    while (thueNhieuMay.pHead != NULL) {
        t = thueNhieuMay.pHead;
        thueNhieuMay.pHead = thueNhieuMay.pHead->pNext;
        free(t);
    }
}

bool kiemTraTaiKhoanDaTonTai(ThueNhieuMay thueNhieuMay, char *taiKhoan) {
    for (Node *t = thueNhieuMay.pHead; t != NULL; t = t->pNext)
        if (strcmp(t->data.taiKhoan, taiKhoan) == 0)
            return 1;
    return 0;
}

void themMotNguoiThueVaoDanhSach(ThueNhieuMay &thueNhieuMay, MayTinh nhieuMay[], int n) {
    ThueMotMay r;
    nhapMotNguoiThue(r, nhieuMay, n);
    do {
        if (kiemTraTaiKhoanDaTonTai(thueNhieuMay, r.taiKhoan)) {
            cout << "\n\t(!) Da ton tai nguoi thue voi tai khoan nay (!)\n";
            cout << "\n(?) Nhap lai tai khoan khac: ";
            cin >> r.soDienThoai;
        }
    } while (kiemTraTaiKhoanDaTonTai(thueNhieuMay, r.taiKhoan));
    r.maytinh->tinhTrang = 1;
    cout << "\n\tTHONG TIN NGUOI THUE VUA NHAP\n";
    xuatMotNguoiThueTheoChieuDoc(r);
    addNodeInTail(thueNhieuMay, r);
}

void xuatDanhSachNguoiThue(ThueNhieuMay thueNhieuMay) {
    int count = 1;
    cout << "\n";
    cout << setw(10) << left << "STT"
         << "\t";
    cout << setw(30) << left << "Tai khoan"
         << "\t";
    cout << setw(30) << left << "Mat khau"
         << "\t";
    cout << setw(20) << left << "So dien thoai"
         << "\t";
    cout << setw(10) << left << "So may"
         << "\t" << endl;

    for (Node *t = thueNhieuMay.pHead; t != NULL; t = t->pNext) {
        cout << setw(10) << count++ << "\t";
        xuatMotNguoiThueTheoChieuNgang(t->data);
    }
}

void chinhSuaDanhSachNguoiThue(ThueNhieuMay &thueNhieuMay, MayTinh nhieuMay[], int n, char *soDienThoai) {
    if (!kiemTraSoDienThoaiDaTonTai(thueNhieuMay, soDienThoai))
        cout << "\n\t(!) Khong ton tai nguoi thue nay (!)\n\a";
    else {
        for (Node *t = thueNhieuMay.pHead; t != NULL; t = t->pNext) {
            if (strcmp(t->data.soDienThoai, soDienThoai) == 0) {
                thayDoiThongTinTaiKhoanMatKhau(t->data, nhieuMay, n);
                cout << "\n\t(*) Chinh sua thanh cong (*)\n";
                xuatMotNguoiThueTheoChieuDoc(t->data);
                break;
            }
        }
    }
}

void xoaMotNguoiThue(ThueNhieuMay &thueNhieuMay, char *taiKhoan) {
    if (strcmp(thueNhieuMay.pHead->data.taiKhoan, taiKhoan) == 0) {
        thueNhieuMay.pHead->data.maytinh->tinhTrang = 0;
        removeNodeInHead(thueNhieuMay);
        cout << "\n\t(*) Thanh toan thanh cong (*)\n";
    } else if (strcmp(thueNhieuMay.pTail->data.taiKhoan, taiKhoan) == 0) {
        thueNhieuMay.pTail->data.maytinh->tinhTrang = 0;
        removeNodeInTail(thueNhieuMay);
        cout << "\n\t(*) Thanh toan thanh cong (*)\n";
    } else {
        if (!kiemTraTaiKhoanDaTonTai(thueNhieuMay, taiKhoan))
            cout << "\n\t(!) Khong ton tai nguoi thue nay (!)\n";
        else {
            Node *g = NULL;
            for (Node *t = thueNhieuMay.pHead; t != NULL; t = t->pNext) {
                if (strcmp(t->data.taiKhoan, taiKhoan) == 0) {
                    t->data.maytinh->tinhTrang = 0;
                    g->pNext = t->pNext;
                    free(t);
                    cout << "\n\t(*) Thanh toan thanh cong (*)\n";
                    return;
                }
                g = t;
            }
        }
    }
}

void docDanhSachNguoiThue(ThueNhieuMay &thueNhieuMay, MayTinh nhieuMay[], int n) {
    int count = 1;
    FILE *fileIn = fopen("../File/thueMotMay/thueMotMay.in", "r");
    if (fileIn == NULL)
        cout << "\n(!) Loi khi mo file (!)\n";
    else {
        fgetc(fileIn);
        while (!feof(fileIn)) {
            ThueMotMay r;
            docMotNguoiThue(fileIn, r, nhieuMay, n);
            addNodeInTail(thueNhieuMay, r);
            cout << "\n(*) Doc ban ghi thu " << count++ << "(*)\n";
        }
    }
    fclose(fileIn);
}

void ghiDanhSachNguoiThue(ThueNhieuMay thueNhieuMay) {
    int count = 1;
    FILE *fileOut = fopen("../File/thueMotMay/thueMotMay.in", "w");
    if (fileOut == NULL)
        cout << "\n(!) Loi khi mo file (!)\n";
    else {
        for (Node *t = thueNhieuMay.pHead; t != NULL; t = t->pNext) {
            ghiMotNguoiThue(fileOut, t->data);
            cout << "\n(*) Ban ghi thu " << count++ << "(*)\n";
        }
    }
    fclose(fileOut);
}

bool kiemTraTaiKhoanDaTonTai(ThueNhieuMay thueNhieuMay, char *taiKhoan) {
    for (Node *t = thueNhieuMay.pHead; t != NULL; t = t->pNext)
        if (strcmp(t->data.taiKhoan, taiKhoan) == 0)
            return 1;
    return 0;
}

bool kiemTraSoDienThoaiDaTonTai(ThueNhieuMay thueNhieuMay, char *soDienThoai) {
    for (Node *t = thueNhieuMay.pHead; t != NULL; t = t->pNext)
        if (strcmp(t->data.soDienThoai, soDienThoai) == 0)
            return 1;
    return 0;
}

void ghiDanhSachNguoiThue(ThueNhieuMay thueNhieuMay) {
    int count = 1;
    FILE *fileOut = fopen("../File/thueMotMay/thueMotMay.in", "w");
    if (fileOut == NULL)
        cout << "\n(!) Loi khi mo file (!)\n\a";
    else {
        for (Node *t = thueNhieuMay.pHead; t != NULL; t = t->pNext) {
            ghiMotNguoiThue(fileOut, t->data);
            cout << "\n(*) Ban ghi thu " << count++ << "(*)\n";
        }
    }
    fclose(fileOut);
}

void xuatFileDanhSachNguoiThue(ThueNhieuMay thueNhieuMay) {
    FILE *fileOut = fopen("../File/thueMotMay/thueNhieuMay.txt", "w");
    if (fileOut == NULL) {
        cout << "\n\t(*) In file khong thanh cong (*)\n";
    } else {
        int count = 1;
        for (Node *t = thueNhieuMay.pHead; t != NULL; t = t->pNext) {
            fprintf(fileOut, "%s\n", t->data.taiKhoan);
            fprintf(fileOut, "%s\n", t->data.matKhau);
            fprintf(fileOut, "%s\n", t->data.soDienThoai);
            fprintf(fileOut, "%d\n", t->data.maytinh->soMay);
        }
        cout << "\n\t(*) In file thanh cong (*)\n";
    }
    fclose(fileOut);
}
