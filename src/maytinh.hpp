#pragma once
#include "cautrucdulieu.hpp"

void themMayTinh(DanhSachMayTinh &dsmt);
string taoMaMayTinh(DanhSachMayTinh dsmt);
int kiemTraTrungMaMayTinh(DanhSachMayTinh dsmt, string str);
void inMotMayTheoChieuNgang(DanhSachMayTinh dsmt);
void docDanhSachMayTinh(DanhSachMayTinh &dsmt);
void xoaMayTinh(DanhSachMayTinh &dsmt);
void chinhSuaMayTinh(DanhSachMayTinh &dsmt);
void xuatDanhSachCacMayTrong(DanhSachMayTinh dsmt);
bool hetMay(DanhSachMayTinh dsmt);

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

void docDanhSachMayTinh(DanhSachMayTinh &dsmt) {
    ifstream fileIn;
    fileIn.open("../File/danhsachmaytinh.txt", ios_base::in);
    while (fileIn.eof() != true) {  // đọc đến cuối file thì dừng
        dsmt.ds[dsmt.soLuong] = new MayTinh;
        getline(fileIn, dsmt.ds[dsmt.soLuong]->maMay, ' ');
        fileIn >> dsmt.ds[dsmt.soLuong]->soMay;
        fileIn >> dsmt.ds[dsmt.soLuong]->kieuMay;
        fileIn >> dsmt.ds[dsmt.soLuong]->tinhTrang;
        fileIn.ignore();
        dsmt.soLuong++;
        Sleep(50);  // delay 0.05s
        cout << "\n(*) Doc ban ghi thu " << dsmt.soLuong << " (*)";
    }
    fileIn.close();
}

void xoaMayTinh(DanhSachMayTinh &dsmt) {
    string str;
    cout << "\n(?) Nhap ma may tinh can xoa: ";
    cin >> str;
    int vitri = kiemTraTrungMaMayTinh(dsmt, str);

    // Dời
    if (vitri < 0) {
        cout << "\nMay tinh khong ton tai\n";
        system("pause");
    } else {
        for (int i = vitri; i < dsmt.soLuong - 1; i++) {
            dsmt.ds[i]->maMay = dsmt.ds[i + 1]->maMay;
            dsmt.ds[i]->soMay = dsmt.ds[i + 1]->soMay;
            dsmt.ds[i]->kieuMay = dsmt.ds[i + 1]->kieuMay;
            dsmt.ds[i]->tinhTrang = dsmt.ds[i + 1]->tinhTrang;
        }
        // Giảm số lượng
        MayTinh *tam = dsmt.ds[dsmt.soLuong - 1];
        dsmt.soLuong--;
        cout << "\nDa xoa thanh cong\n";
        system("pause");
    }
}

void chinhSuaMayTinh(DanhSachMayTinh &dsmt) {
    string str;
    cout << "\n(?) Nhap ma may tinh can chinh sua: ";
    cin >> str;
    int vitri = kiemTraTrungMaMayTinh(dsmt, str);
    if (vitri < 0) {
        cout << "\n(!) Ma khong ton tai\n";
        system("pause");
    } else {
        cout << "\n(?) Nhap so may moi: ";
        cin >> dsmt.ds[vitri]->soMay;
        cout << "\n(?) Nhap kieu may moi (0: thuong - 1: cao cap): ";
        cin >> dsmt.ds[vitri]->kieuMay;
        cout << "\n(!) Da thay doi thong tin may tinh thanh cong\n";
        system("pause");
    }
}

void xuatDanhSachCacMayTrong(DanhSachMayTinh dsmt) {
    if (hetMay(dsmt))
        cout << "\n\t(!) Het may\n";
    else {
        cout << "\n";
        cout << setw(10) << left << "So may"
             << "\t";
        cout << setw(20) << left << "Kieu may"
             << "\t";
        cout << setw(20) << left << "Tinh trang"
             << "\t" << endl;
        for (int i = 0; i < dsmt.soLuong; i++)
            if (dsmt.ds[i]->tinhTrang == 0)
                inMotMayTheoChieuNgang(dsmt);
    }
}

bool hetMay(DanhSachMayTinh dsmt) {
    for (int i = 0; i < dsmt.soLuong; i++)
        if (dsmt.ds[i]->tinhTrang == 0)  // còn máy trống -> thì trả về false
            return false;
    return true;
}