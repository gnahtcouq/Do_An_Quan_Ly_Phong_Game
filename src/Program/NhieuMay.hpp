#pragma once
#include <windows.h>

#include "MotMay.hpp"

void docDanhSachCacMay(MayTinh nhieuMay[], int &n);             // đọc danh sách các máy
void ghiDanhSachCacMay(MayTinh nhieuMay[], int &n);             // ghi danh sách các máy
void xuatDanhSachCacMay(MayTinh nhieuMay[], int n);             // xuất danh sách các máy (cả trống và đã được sử dụng)
MayTinh *layViTriCuaMay(MayTinh nhieuMay[], int n, int soMay);  // lấy vị trí của máy
void xuatDanhSachCacMayDay(MayTinh nhieuMay[], int n);          // xuất danh sách các máy đã được sử dụng
void xuatDanhSachCacMayTrong(MayTinh nhieuMay[], int n);        // xuất danh sách các máy trống
void sapXepDanhSachMayTinh(MayTinh nhieuMay[], int &n);         // sắp xếp danh sách máy tính tăng dần theo số máy
bool hetMay(MayTinh nhieuMay[], int n);                         // kiểm tra hết máy
bool kiemTraSoMay(MayTinh nhieuMay[], int n, int soMay);        // kiểm tra máy còn trống hay đã được sử dụng

void docDanhSachCacMay(MayTinh nhieuMay[], int &n) {
    ifstream fileIn("../File/maytinh/danhsachmaytinh.txt");
    if (fileIn.fail()) {
        cout << "\n(!) Loi khi doc file (!)\n";
        system("pause");
    } else {
        n = 0;
        while (!fileIn.eof()) {
            MayTinh mt;
            mt.docMotMay(fileIn);
            nhieuMay[n++] = mt;  // đưa máy vừa đọc vào mảng
            Sleep(50);           // delay 0.05s
            cout << "\n(*) Doc ban ghi thu " << n << " (*)";
        }
    }
    fileIn.close();
}

void ghiDanhSachCacMay(MayTinh nhieuMay[], int &n) {
    int count = 1;
    ofstream fileOut("../File/maytinh/danhsachmaytinh.txt");
    if (fileOut.fail()) {
        cout << "\n(!) Loi khi mo file (!)\n";
        system("pause");
    } else {
        for (int i = 0; i < n; i++) {
            fflush(stdin);
            nhieuMay[i].ghiMotMay(fileOut);
            Sleep(50);  // delay 0.05s
            cout << "\n(*) Ban ghi thu " << count++ << " (*)";
            if (i != n - 1)
                fileOut << endl;
        }
    }
    fileOut.close();
}

void xuatDanhSachCacMay(MayTinh nhieuMay[], int n) {
    MayTinh mt;
    cout << "\n";
    cout << setw(10) << left << "Ma may"
         << "\t";
    cout << setw(10) << left << "So may"
         << "\t";
    cout << setw(20) << left << "Kieu may"
         << "\t";
    cout << setw(20) << left << "Tinh trang"
         << "\t";
    cout << setw(20) << left << "Thoi gian bat dau"
         << "\t" << endl;
    for (int i = 0; i < n; i++)
        nhieuMay[i].inMotMayTheoChieuNgangCoThoiGian();
}

MayTinh *layViTriCuaMay(MayTinh nhieuMay[], int n, int soMay) {
    for (int i = 0; i < n; i++)
        if (nhieuMay[i].soMay == soMay)
            return &nhieuMay[i];
    return NULL;
}

void xuatDanhSachCacMayDay(MayTinh nhieuMay[], int n) {
    cout << "\n";
    cout << setw(10) << left << "Ma May"
         << "\t";
    cout << setw(10) << left << "So may"
         << "\t";
    cout << setw(20) << left << "Kieu may"
         << "\t";
    cout << setw(20) << left << "Tinh trang"
         << "\t";
    cout << setw(20) << left << "Thoi gian bat dau"
         << "\t" << endl;
    for (int i = 0; i < n; i++)
        if (nhieuMay[i].tinhTrang == 1)
            nhieuMay[i].inMotMayTheoChieuNgangCoThoiGian();
}

void xuatDanhSachCacMayTrong(MayTinh nhieuMay[], int n) {
    if (hetMay(nhieuMay, n))  // nếu hết máy
        cout << "\n\t(!) Het may (!)\n";
    else {
        cout << "\n";
        cout << setw(10) << left << "Ma May"
             << "\t";
        cout << setw(10) << left << "So may"
             << "\t";
        cout << setw(20) << left << "Kieu may"
             << "\t";
        cout << setw(20) << left << "Tinh trang"
             << "\t" << endl;
        for (int i = 0; i < n; i++)
            if (nhieuMay[i].tinhTrang == 0)
                nhieuMay[i].inMotMayTheoChieuNgang();
    }
}

void sapXepDanhSachMayTinh(MayTinh nhieuMay[], int &n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (nhieuMay[i].soMay > nhieuMay[j].soMay) {
                MayTinh tam = nhieuMay[i];
                nhieuMay[i] = nhieuMay[j];
                nhieuMay[j] = tam;
            }
}

bool hetMay(MayTinh nhieuMay[], int n) {
    for (int i = 0; i < n; i++)
        if (nhieuMay[i].tinhTrang == 0)  // còn máy trống -> thì trả về false
            return false;
    return true;
}

bool kiemTraSoMay(MayTinh nhieuMay[], int n, int soMay) {
    for (int i = 0; i < n; i++)
        if (nhieuMay[i].soMay == soMay && nhieuMay[i].tinhTrang == 0)
            return true;
    return false;
}