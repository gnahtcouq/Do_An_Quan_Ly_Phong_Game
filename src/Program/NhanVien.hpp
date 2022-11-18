#pragma once
#include <random>

#include "NhieuMay.hpp"

struct NhanVien {
    int ma;
    string ten;
    string ho;
    string taiKhoan;
    string matKhau;
    string soDienThoai;
};

struct NodeT {
    NhanVien nv;
    NodeT *left;
    NodeT *right;
};
typedef struct NodeT *DanhSachNhanVien;

DanhSachNhanVien taoNodeNhanVien(NhanVien nv);
void khoiTaoDanhSachNhanVien(DanhSachNhanVien &dsnv);
void timNutNhoNhatBenPhai(DanhSachNhanVien &p, DanhSachNhanVien &dsnv);
int taoMaNhanVien(DanhSachNhanVien dsnv);
void nhapMotNhanVien(DanhSachNhanVien &dsnv);
void themNhanVien(DanhSachNhanVien &dsnv, DanhSachNhanVien nv);
void xoaMotNhanVien(DanhSachNhanVien &dsnv);
void xoaNhanVien(DanhSachNhanVien &dsnv, int ma);
void xoaDanhSachNhanVien(DanhSachNhanVien &dsnv);
bool kiemTraMaNhanVienTrung(DanhSachNhanVien dsnv, int ma);

DanhSachNhanVien taoNodeNhanVien(NhanVien nv) {
    DanhSachNhanVien nNV = new NodeT;
    nNV->nv = nv;
    nNV->left = NULL;
    nNV->right = NULL;
    return nNV;
}

void khoiTaoDanhSachNhanVien(DanhSachNhanVien &dsnv) {
    dsnv = NULL;
}

void timNutNhoNhatBenPhai(DanhSachNhanVien &p, DanhSachNhanVien &dsnv) {
    if (dsnv->left)
        timNutNhoNhatBenPhai(p, dsnv->left);
    else {
        p->nv = dsnv->nv;
        p = dsnv;
        dsnv = dsnv->right;
    }
}

int taoMaNhanVien(DanhSachNhanVien dsnv) {
    int ma;
    do {
        random_device rd;
        mt19937 rng(rd());
        uniform_int_distribution<int> uni(1, 100);
        ma = (100 + rand() % 890) + uni(rng);
    } while (kiemTraMaNhanVienTrung(dsnv, ma) == true);
    return ma;
}

void nhapMotNhanVien(DanhSachNhanVien &dsnv) {
    NhanVien nv;
    cin.ignore();
    do {
        cout << "\n(?) Nhap tai khoan :\t\t";
        getline(cin, nv.taiKhoan);
        if (nv.taiKhoan == "admin")
            cout << "\n\t(!) Tai khoan khong duoc trung voi admin";
    } while (nv.taiKhoan == "admin");
    cout << "\n(?) Nhap mat khau  :\t\t";
    getline(cin, nv.matKhau);
    do {
        cout << "\n(?) Nhap so dien thoai (10 so):\t";
        getline(cin, nv.soDienThoai);
        if (nv.soDienThoai.length() <= 0 || nv.soDienThoai.length() > 10 || nv.soDienThoai.length() != 10)
            cout << "\n\t(!) So dien thoai khong hop le. Hay nhap lai\n";
    } while (nv.soDienThoai.length() <= 0 || nv.soDienThoai.length() > 10 || nv.soDienThoai.length() != 10);
    nv.ma = taoMaNhanVien(dsnv);

    cout << "\n(?) Nhap ten :\t\t\t";
    cin >> nv.ten;
    cin.ignore();

    cout << "\n(?) Nhap ho  :\t\t\t";
    cin >> nv.ho;
    cin.ignore();

    themNhanVien(dsnv, taoNodeNhanVien(nv));
    system("cls");
    cout << "\n\t(!) Tao tai khoan thanh cong. Ma tai khoan " << nv.ma << "\n";
}

void themNhanVien(DanhSachNhanVien &dsnv, DanhSachNhanVien nv) {
    if (dsnv) {
        if (dsnv->nv.ma == nv->nv.ma)  // Trùng
            return;
        if (nv->nv.ma < dsnv->nv.ma)
            themNhanVien(dsnv->left, nv);
        else
            themNhanVien(dsnv->right, nv);
    } else
        dsnv = nv;
}

void xoaMotNhanVien(DanhSachNhanVien &dsnv) {
    int ma;
    cout << "\n(?) Nhap ma nhan vien can xoa: ";
    cin >> ma;
    xoaNhanVien(dsnv, ma);
}

void xoaNhanVien(DanhSachNhanVien &dsnv, int ma) {
    if (dsnv) {
        if (ma > dsnv->nv.ma)
            xoaNhanVien(dsnv->right, ma);
        else if (ma < dsnv->nv.ma)
            xoaNhanVien(dsnv->left, ma);
        else {
            DanhSachNhanVien p = dsnv;
            if (!dsnv->left)
                dsnv = dsnv->right;
            else if (!dsnv->right)
                dsnv = dsnv->left;
            else
                timNutNhoNhatBenPhai(p, dsnv->right);
            delete p;
            cout << "\n\t(!) Xoa thanh cong\n";
        }
    } else
        cout << "\n\t(!) Khong tim thay nhan vien can xoa\n";
}

void xoaDanhSachNhanVien(DanhSachNhanVien &dsnv) {
    if (dsnv) {
        xoaDanhSachNhanVien(dsnv->left);
        xoaDanhSachNhanVien(dsnv->right);
        delete dsnv;
    }
}

bool kiemTraMaNhanVienTrung(DanhSachNhanVien dsnv, int ma) {
    if (dsnv) {
        if (dsnv->nv.ma == ma)
            return true;
        if (ma < dsnv->nv.ma)
            kiemTraMaNhanVienTrung(dsnv->left, ma);
        else
            kiemTraMaNhanVienTrung(dsnv->right, ma);
    }
    return false;
}