#pragma once
#include "cautrucdulieu.hpp"

void themMayTinh(DanhSachMayTinh &dsmt);
string taoMaMayTinh(DanhSachMayTinh dsmt);
int kiemTraTrungMaMayTinh(DanhSachMayTinh dsmt, string str);
void inMotMayTheoChieuNgang(DanhSachMayTinh dsmt);

void themMayTinh(DanhSachMayTinh &dsmt) {
    MayTinh *p = new MayTinh;
    p->maMay = taoMaMayTinh(dsmt);
    cout << "\n(?) Nhap so may: ";
    cin.ignore();
    cin >> p->soMay;
    cout << "\n(?) Nhap kieu may (0: Thuong - 1: Cao cap): ";
    cin >> p->kieuMay;
    dsmt.ds[dsmt.soLuong] = p;
    dsmt.soLuong++;
}

string taoMaMayTinh(DanhSachMayTinh dsmt) {
    string ma = "STU000";
    do {
        for (int i = 3; i < ma.length(); i++)
            ma[i] = rand() % (57 - 48 + 1) + 48;
    } while (kiemTraTrungMaMayTinh(dsmt, ma) >= 0);
    return ma;
}

int kiemTraTrungMaMayTinh(DanhSachMayTinh dsmt, string str) {
    for (int i = 0; i < dsmt.soLuong; i++)
        if (dsmt.ds[i]->maMay == str)
            return i;
    return -1;
}

void inMotMayTheoChieuNgang(DanhSachMayTinh dsmt) {
    for (int i = 0; i < dsmt.soLuong; i++) {
        char tinhTrangMay[20], kieuMay[20];
        if (dsmt.ds[i]->tinhTrang == 1)  // tinhTrang == 1 -> Máy đã có người sử dụng
            strcpy(tinhTrangMay, "Day");
        else  // tinhTrang == 0 -> Máy trống
            strcpy(tinhTrangMay, "Trong");
        if (dsmt.ds[i]->kieuMay == 1)  // kieuMay == 1 -> Máy cao cấp
            strcpy(kieuMay, "Cao cap");
        else  // kieuMay == 0 -> Máy thường
            strcpy(kieuMay, "Thuong");
        cout << setw(10) << left << dsmt.ds[i]->maMay << "\t";
        cout << setw(10) << left << dsmt.ds[i]->soMay << "\t";
        cout << setw(20) << left << kieuMay << "\t";
        cout << setw(20) << left << tinhTrangMay << "\t" << endl;
    }
}
