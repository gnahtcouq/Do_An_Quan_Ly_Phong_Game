#include "MotMayTinh.hpp"

void docDanhSachCacMay(MayTinh nhieuMay[], int &n);
void ghiDanhSachCacMay(MayTinh nhieuMay[], int &n);
void xuatDanhSachCacMay(MayTinh nhieuMay[], int n);
void xuatDanhSachCacMayDay(MayTinh nhieuMay[], int n);
void xuatDanhSachCacMayTrong(MayTinh nhieuMay[], int n);
bool hetMay(MayTinh nhieuMay[], int n);

void docDanhSachCacMay(MayTinh nhieuMay[], int &n) {
    FILE *fileIn = fopen("../File/maytinh/maytinh.in", "r");
    if (fileIn == NULL)
        cout << "\n(!) Loi khi mo file (!)\n";
    else {
        n = 0;
        while (!feof(fileIn)) {
            MayTinh c;
            docMotMay(fileIn, c);
            nhieuMay[n++] = c;
            cout << "(*) Doc ban ghi thu " << n << " (*)\n";
        }
    }
    fclose(fileIn);
}

void ghiDanhSachCacMay(MayTinh nhieuMay[], int &n) {
    int count = 1;
    FILE *fileOut = fopen("../File/maytinh/maytinh.in", "w");
    if (fileOut == NULL)
        cout << "(!) Loi khi mo file (!)\n";
    else {
        for (int i = 0; i < n; i++) {
            fflush(stdin);
            ghiMotMay(fileOut, nhieuMay[i]);
            cout << "(*) Ban ghi thu " << count++ << " (*)\n";
        }
    }
    fclose(fileOut);
}

void xuatDanhSachCacMay(MayTinh nhieuMay[], int n) {
    int count = 1;
    cout << "\n";
    cout << setw(10) << left << "STT" << "\t";
    cout << setw(10) << left << "So may" << "\t";
    cout << setw(20) << left << "Kieu may" << "\t";
    cout << setw(20) << left << "Tinh trang" << "\t" << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(10) << count++ << "\t";
        inMotMayTheoChieuNgang(nhieuMay[i]);
    }
}

void xuatDanhSachCacMayDay(MayTinh nhieuMay[], int n) {
    int count = 1;
    cout << "\n";
    cout << setw(10) << left << "STT" << "\t";
    cout << setw(10) << left << "So may" << "\t";
    cout << setw(20) << left << "Kieu may" << "\t";
    cout << setw(20) << left << "Tinh trang" << "\t" << endl;
    for (int i = 0; i < n; i++) {
        if (nhieuMay[i].tinhTrang) {
            cout << setw(10) << count++ << "\t";
            inMotMayTheoChieuNgang(nhieuMay[i]);
        }
    }
}

void xuatDanhSachCacMayTrong(MayTinh nhieuMay[], int n) {
    if (hetMay(nhieuMay, n))
        cout << "\n\t(!) Het may (!)\n";
    else {
        int count = 1;
        cout << "\n";
        cout << setw(10) << left << "STT" << "\t";
        cout << setw(10) << left << "So may" << "\t";
        cout << setw(20) << left << "Kieu may" << "\t";
        cout << setw(20) << left << "Tinh trang" << "\t" << endl;
        for (int i = 0; i < n; i++) {
            if (nhieuMay[i].tinhTrang == 0) {
                cout << setw(10) << count++ << "\t";
                inMotMayTheoChieuNgang(nhieuMay[i]);
            }
        }
    }
}

bool hetMay(MayTinh nhieuMay[], int n) {
    for (int i = 0; i < n; i++) {
        if (nhieuMay[i].tinhTrang == 0)
            return false;
    }
    return true;
}