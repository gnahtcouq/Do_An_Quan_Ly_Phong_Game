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