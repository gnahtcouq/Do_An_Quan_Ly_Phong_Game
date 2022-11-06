#pragma once
#include "ThueMotMay.hpp"

class Node : public ThueMotMay {
   public:
    ThueMotMay data;
    Node *pNext;
};

class ThueNhieuMay : public Node {
   public:
    Node *pHead;
    Node *pTail;
    void createList();
    void addNodeInTail(ThueMotMay);
    void removeNodeInHead();
    void removeNodeInTail();
    void moMayTrucTiep(MayTinh[], int);
};

Node *createNode(ThueMotMay value);
void docDanhSachNguoiThueTrucTiep(ThueNhieuMay &thueNhieuMay, MayTinh nhieuMay[], int n);
void ghiDanhSachNguoiThueTrucTiep(ThueNhieuMay thueNhieuMay);

void ThueNhieuMay::createList() {
    pHead = NULL;
    pTail = NULL;
}

Node *createNode(ThueMotMay value) {
    Node *p = new Node;
    if (p == NULL) {
        cout << "\n\t(!) Khong du bo nho (!)";
        return NULL;
    } else {
        p->data = value;
        p->pNext = NULL;
    }
    return p;
}

void ThueNhieuMay::addNodeInTail(ThueMotMay thueMotMay) {
    Node *p = createNode(thueMotMay);
    if (pHead == NULL)
        pHead = pTail = p;
    else {
        pTail->pNext = p;
        pTail = p;
    }
}

void ThueNhieuMay::removeNodeInHead() {
    if (pHead == NULL)  // không có phần tử nào
        return;
    else {
        Node *p = pHead;
        pHead = p->pNext;
        delete p;
    }
}

void ThueNhieuMay::removeNodeInTail() {
    if (pHead == NULL)
        return;
    // nếu phần tử nằm đầu cũng là phần tử nằm cuối
    else if (pHead == pTail)
        removeNodeInHead();
    else {
        for (Node *t = pHead; t != NULL; t = t->pNext) {
            if (t->pNext == pTail) {
                free(pTail);
                t->pNext = NULL;
                pTail = t;
                return;
            }
        }
    }
}

void ThueNhieuMay::moMayTrucTiep(MayTinh nhieuMay[], int n) {
    int gioBD = 0, phutBD = 0, giayBD = 0;
    ThueMotMay r;
    r.chonMay(nhieuMay, n);
    r.maytinh->tinhTrang = 1;  // cập nhật lại tình trạng máy -> 1 (máy đã có người sử dụng)
    layThoiGianHeThong(gioBD, phutBD, giayBD);
    r.maytinh->gioBD = gioBD;
    r.maytinh->phutBD = phutBD;
    r.maytinh->giayBD = giayBD;
    system("cls");
    cout << "\n\t(!) Mo may thanh cong (!)\n";
    addNodeInTail(r);
}

void docDanhSachNguoiThueTrucTiep(ThueNhieuMay &thueNhieuMay, MayTinh nhieuMay[], int n) {
    int count = 1;
    ifstream fileIn("../File/khachhang/momaytructiep.txt");
    if (fileIn.fail()) {
        cout << "\n(!) Loi khi doc file (!)\n";
        system("pause");
    } else {
        while (!fileIn.eof()) {
            ThueMotMay r;
            r.docMotNguoiThueTrucTiep(fileIn, nhieuMay, n);
            thueNhieuMay.addNodeInTail(r);
            Sleep(50);  // delay 0.05s
            cout << "\n(*) Doc ban ghi thu " << count++ << "(*)";
        }
    }
    fileIn.close();
}

void ghiDanhSachNguoiThueTrucTiep(ThueNhieuMay thueNhieuMay) {
    int count = 1;
    ofstream fileOut("../File/khachhang/momaytructiep.txt");
    if (fileOut.fail()) {
        cout << "\n(!) Loi khi mo file (!)\n";
        system("pause");
    } else {
        for (Node *t = thueNhieuMay.pHead; t != NULL; t = t->pNext) {
            t->data.ghiMotNguoiThueTrucTiep(fileOut);
            Sleep(50);  // delay 0.05s
            cout << "\n(*) Ban ghi thu " << count++ << "(*)";
            if (t->pNext != NULL)
                fileOut << endl;
        }
    }
    fileOut.close();
}