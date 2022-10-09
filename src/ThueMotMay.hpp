#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "NhieuMayTinh.hpp"

struct ThueMotMay {
    char taiKhoan[30];
    char matKhau[30];
    char soDienThoai[15];
    MayTinh *maytinh = NULL;
};

bool kiemTraSoMay(MayTinh nhieuMay[], int n, int soMay);
void chonMay(ThueMotMay &thueMotMay, MayTinh nhieuMay[], int n);
void nhapMotNguoiThue(ThueMotMay &thueMotMay, MayTinh nhieuMay[], int n);
void xuatMotNguoiThueTheoChieuDoc(ThueMotMay thueMotMay);
void xuatMotNguoiThueTheoChieuNgang(ThueMotMay thueMotMay);

void docMotNguoiThue(FILE *fileIn, ThueMotMay &thueMotMay, MayTinh nhieuMay[], int n);
void ghiMotNguoiThue(FILE *fileOut, ThueMotMay thueMotMay);
void thayDoiThongTinTaiKhoanMatKhau(ThueMotMay &thueMotMay, MayTinh nhieuMay[], int n);

bool kiemTraSoMay(MayTinh nhieuMay[], int n, int soMay) {
    for (int i = 0; i < n; i++)
        if (nhieuMay[i].soMay == soMay && nhieuMay[i].tinhTrang == 0)
            return 1;
    return 0;
}

void chonMay(ThueMotMay &thueMotMay, MayTinh nhieuMay[], int n) {
    int soMay;
    do {
        xuatDanhSachCacMayTrong(nhieuMay, n);
        cout << "\n(?) Nhap so may: ";
        cin >> soMay;
        if (!kiemTraSoMay(nhieuMay, n, soMay)) {
            cout << "\n\t(!) So may khong hop le - Nhap lai (!)\n";
            system("pause");
        } else
            thueMotMay.maytinh = layViTriCuaMay(nhieuMay, n, soMay);
    } while (!kiemTraSoMay(nhieuMay, n, soMay));
}

void nhapMotNguoiThue(ThueMotMay &thueMotMay, MayTinh nhieuMay[], int n) {
    cin.ignore();
    cout << "\n(?) Nhap tai khoan: ";
    cin.getline(thueMotMay.taiKhoan, 30);
    cout << "\n(*) Nhap mat khau: ";
    cin.getline(thueMotMay.matKhau, 30);
    do {
        cout << "\n(?) Nhap so dien thoai (10 so): ";
        cin.getline(thueMotMay.soDienThoai, 15);
        if (strlen(thueMotMay.soDienThoai) <= 0 || strlen(thueMotMay.soDienThoai) > 10 || strlen(thueMotMay.soDienThoai) != 10)
            cout << "\n\t(!) So dien thoai khong hop le - Nhap lai (!)\n";
    } while (strlen(thueMotMay.soDienThoai) <= 0 || strlen(thueMotMay.soDienThoai) > 10 || strlen(thueMotMay.soDienThoai) != 10);
    chonMay(thueMotMay, nhieuMay, n);
    thueMotMay.maytinh->tinhTrang = 1;
}

void xuatMotNguoiThueTheoChieuDoc(ThueMotMay thueMotMay) {
    cout << "\nTai khoan: " << thueMotMay.taiKhoan;
    cout << "\nMat khau: " << thueMotMay.matKhau;
    cout << "\nSo dien thoai: " << thueMotMay.soDienThoai;
    cout << "\nSo may: " << thueMotMay.maytinh->soMay;
}

void xuatMotNguoiThueTheoChieuNgang(ThueMotMay thueMotMay) {
    cout << setw(30) << left << thueMotMay.taiKhoan << "\t";
    cout << setw(30) << left << thueMotMay.matKhau << "\t";
    cout << setw(20) << left << thueMotMay.soDienThoai << "\t";
    cout << setw(10) << left << thueMotMay.maytinh->soMay << "\t" << endl;
}

void docMotNguoiThue(FILE *fileIn, ThueMotMay &thueMotMay, MayTinh nhieuMay[], int n) {
    int soMay = 0;
    fscanf(fileIn, "%s", &thueMotMay.taiKhoan);
    fscanf(fileIn, "%s", &thueMotMay.matKhau);
    removeEnterChar(thueMotMay.taiKhoan);
    fscanf(fileIn, "%s", &thueMotMay.soDienThoai);
    fscanf(fileIn, "%d", &soMay);
    fgetc(fileIn);
    thueMotMay.maytinh = layViTriCuaMay(nhieuMay, n, soMay);
}

void ghiMotNguoiThue(FILE *fileOut, ThueMotMay thueMotMay) {
    fprintf(fileOut, "\n%s", thueMotMay.taiKhoan);
    fprintf(fileOut, "\n%s", thueMotMay.matKhau);
    fprintf(fileOut, "\n%s", thueMotMay.soDienThoai);
    fprintf(fileOut, "\n%d", thueMotMay.maytinh->soMay);
}

void thayDoiThongTinTaiKhoanMatKhau(ThueMotMay &thueMotMay, MayTinh nhieuMay[], int n) {
    cout << "\n(?) Nhap tai khoan moi: ";
    cin.getline(thueMotMay.taiKhoan, 30);
    cout << "\n(?) Nhap mat khau moi: ";
    cin.getline(thueMotMay.matKhau, 30);
    cout << "\n(*) Thay doi thong tin thanh cong (*)";
}