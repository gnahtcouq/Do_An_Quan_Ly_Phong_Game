#pragma once
#include <windows.h>

#include "MotMay.hpp"

void docDanhSachCacMay(MayTinh nhieuMay[], int &n);                   // đọc danh sách các máy
void ghiDanhSachCacMay(MayTinh nhieuMay[], int &n);                   // ghi danh sách các máy
MayTinh *layViTriCuaMay(MayTinh nhieuMay[], int n, int soMay);        // lấy vị trí của máy
void xuatDanhSachCacMay(MayTinh nhieuMay[], int n);                   // xuất danh sách các máy (cả trống và đã được sử dụng)
void xuatDanhSachCacMayDay(MayTinh nhieuMay[], int n);                // xuất danh sách các máy đã được sử dụng
void xuatDanhSachCacMayTrong(MayTinh nhieuMay[], int n);              // xuất danh sách các máy trống
void sapXepDanhSachMayTinh(MayTinh nhieuMay[], int &n);               // sắp xếp danh sách máy tính tăng dần theo số máy
bool kiemTraHetMay(MayTinh nhieuMay[], int n);                        // kiểm tra hết máy
bool kiemTraTrangThai(MayTinh nhieuMay[], int n);                     // kiểm tra trạng thái
bool kiemTraSoMay(MayTinh nhieuMay[], int n, int soMay);              // kiểm tra máy còn trống hay đã được sử dụng
bool kiemTraSoMayCanThanhToan(MayTinh nhieuMay[], int n, int soMay);  // kiểm tra số máy cần thanh toán

void docDanhSachCacMay(MayTinh nhieuMay[], int &n) {
    string fileName = "../File/maytinh/danhsachmaytinh.txt";
    ifstream fileIn(fileName);
    if (fileIn.fail()) {
        cout << "\n\t(!) Tap tin khong ton tai\n";
        system("pause");
    } else {
        n = 0;
        while (!fileIn.eof()) {
            MayTinh mt;
            mt.docMotMay(fileIn);
            nhieuMay[n++] = mt;  // đưa máy vừa đọc vào mảng
            // Sleep(50);           // delay 0.05s
            // cout << "\n(*) Doc ban ghi thu " << n << " (*)";
        }
    }
    fileIn.close();
}

void ghiDanhSachCacMay(MayTinh nhieuMay[], int &n) {
    string fileName = "../File/maytinh/danhsachmaytinh.txt";
    // int count = 1;
    ofstream fileOut(fileName);
    if (fileOut.fail()) {
        cout << "\n\t(!) Tap tin khong ton tai\n";
        system("pause");
    } else {
        for (int i = 0; i < n; i++) {
            fflush(stdin);
            nhieuMay[i].ghiMotMay(fileOut);
            // Sleep(50);  // delay 0.05s
            // cout << "\n(*) Ban ghi thu " << count++ << " (*)";
            if (i != n - 1)
                fileOut << endl;
        }
    }
    fileOut.close();
}

MayTinh *layViTriCuaMay(MayTinh nhieuMay[], int n, int soMay) {
    for (int i = 0; i < n; i++)
        if (nhieuMay[i].soMay == soMay)
            return &nhieuMay[i];
    return NULL;
}

void xuatDanhSachCacMay(MayTinh nhieuMay[], int n) {
    if (n != 0) {
        MayTinh mt;
        cout << "*---------*---------------*-------------------------*-----------------------*--------------------------*\n";
        cout << setw(10) << left << "| Ma may"
             << "|\t";
        cout << setw(10) << left << "So may"
             << "|\t";
        cout << setw(20) << left << "Kieu may"
             << "|\t";
        cout << setw(20) << left << "Tinh trang"
             << "|\t";
        cout << setw(23) << left << "Thoi gian bat dau"
             << "|\n";
        cout << "*---------*---------------*-------------------------*-----------------------*--------------------------*\n";
        for (int i = 0; i < n; i++)
            nhieuMay[i].inMotMayTheoChieuNgangCoThoiGian();
        cout << "*---------*---------------*-------------------------*-----------------------*--------------------------*\n";
    } else
        cout << "\n\t(!) Danh sach may tinh trong\n";
}

void xuatDanhSachCacMayDay(MayTinh nhieuMay[], int n) {
    if (n != 0) {
        cout << "*---------*---------------*-------------------------*-----------------------*--------------------------*\n";
        cout << setw(10) << left << "| Ma May"
             << "|\t";
        cout << setw(10) << left << "So may"
             << "|\t";
        cout << setw(20) << left << "Kieu may"
             << "|\t";
        cout << setw(20) << left << "Tinh trang"
             << "|\t";
        cout << setw(23) << left << "Thoi gian bat dau"
             << "|\n";
        cout << "*---------*---------------*-------------------------*-----------------------*--------------------------*\n";
        for (int i = 0; i < n; i++)
            if (nhieuMay[i].tinhTrang == 1)
                nhieuMay[i].inMotMayTheoChieuNgangCoThoiGian();
        cout << "*---------*---------------*-------------------------*-----------------------*--------------------------*\n";
    } else
        cout << "\n\t(!) Danh sach may tinh trong\n";
}

void xuatDanhSachCacMayTrong(MayTinh nhieuMay[], int n) {
    if (n != 0) {
        if (kiemTraHetMay(nhieuMay, n))  // nếu hết máy
            cout << "\n\t(!) Het may\n";
        else {
            cout << "*---------*---------------*-------------------------*-----------------------*\n";
            cout << setw(10) << left << "| Ma May"
                 << "|\t";
            cout << setw(10) << left << "So may"
                 << "|\t";
            cout << setw(20) << left << "Kieu may"
                 << "|\t";
            cout << setw(20) << left << "Tinh trang"
                 << "|\n";
            cout << "*---------*---------------*-------------------------*-----------------------*\n";
            for (int i = 0; i < n; i++)
                if (nhieuMay[i].tinhTrang == 0)
                    nhieuMay[i].inMotMayTheoChieuNgang();
            cout << "*---------*---------------*-------------------------*-----------------------*\n";
        }
    } else
        cout << "\n\t(!) Danh sach may tinh trong\n";
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

bool kiemTraHetMay(MayTinh nhieuMay[], int n) {
    for (int i = 0; i < n; i++)
        if (nhieuMay[i].tinhTrang == 0)  // còn máy trống -> thì trả về false
            return false;
    return true;
}

bool kiemTraTrangThai(MayTinh nhieuMay[], int n) {
    bool kiemTra = false;
    for (int i = 0; i < n; i++) {
        if (nhieuMay[i].tinhTrang == 1) {
            kiemTra = true;
            break;
        }
    }
    return kiemTra;
}

bool kiemTraSoMay(MayTinh nhieuMay[], int n, int soMay) {
    for (int i = 0; i < n; i++)
        if (nhieuMay[i].soMay == soMay && nhieuMay[i].tinhTrang == 0)
            return true;
    return false;
}

bool kiemTraSoMayCanThanhToan(MayTinh nhieuMay[], int n, int soMay) {
    for (int i = 0; i < n; i++)
        if (nhieuMay[i].soMay == soMay && nhieuMay[i].tinhTrang == 1)
            return true;
    return false;
}