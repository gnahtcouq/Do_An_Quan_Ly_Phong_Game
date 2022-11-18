#pragma once
#include "NhieuMay.hpp"
#include "ThueMotMay.hpp"

class ThueMotMay {
   public:
    MayTinh *maytinh = NULL;                                   // trỏ đến máy
    void chonMay(MayTinh[], int);                              // chọn máy
    void chonMayCanThanhToan(MayTinh[], int);                  // chọn máy cần thanh toán
    void docMotNguoiThueTrucTiep(ifstream &, MayTinh[], int);  // đọc một người thuê trực tiếp từ file
    void ghiMotNguoiThueTrucTiep(ofstream &);                  // ghi một người thuê trực tiếp ra file
};

void ThueMotMay::chonMay(MayTinh nhieuMay[], int n) {
    int soMay;
    do {
        system("cls");
        cout << "\nMENU/MO MAY TRUC TIEP";
        cout << "\n*-------------------*\n";
        xuatDanhSachCacMayTrong(nhieuMay, n);
        cout << "\n(?) Nhap so may: ";
        cin >> soMay;
        if (!kiemTraSoMay(nhieuMay, n, soMay)) {
            cout << "\n\t(!) So may khong hop le. Hay nhap lai\n";
            system("pause");
        } else
            maytinh = layViTriCuaMay(nhieuMay, n, soMay);  // hàm này trong file NhieuMay.hpp
    } while (!kiemTraSoMay(nhieuMay, n, soMay));
}

void ThueMotMay::chonMayCanThanhToan(MayTinh nhieuMay[], int n) {
    int soMay;
    do {
        system("cls");
        cout << "\nMENU/THANH TOAN";
        cout << "\n*-------------*\n";
        xuatDanhSachCacMayDay(nhieuMay, n);
        cout << "\n(?) Nhap so may: ";
        cin >> soMay;
        if (!kiemTraSoMayCanThanhToan(nhieuMay, n, soMay)) {
            cout << "\n\t(!) So may khong hop le. Hay nhap lai\n";
            system("pause");
        } else
            maytinh = layViTriCuaMay(nhieuMay, n, soMay);  // hàm này trong file NhieuMay.hpp
    } while (!kiemTraSoMayCanThanhToan(nhieuMay, n, soMay));
}

void ThueMotMay::docMotNguoiThueTrucTiep(ifstream &fileIn, MayTinh nhieuMay[], int n) {
    int soMay = 0;  // lưu tạm số máy lúc đọc từ file
    fileIn >> soMay;
    maytinh = layViTriCuaMay(nhieuMay, n, soMay);  // lấy số máy lưu tạm để trả về máy của số máy đó
    fileIn >> maytinh->gioBD;
    fileIn >> maytinh->phutBD;
    fileIn >> maytinh->giayBD;
    fileIn >> maytinh->ngayBD;
    fileIn >> maytinh->thangBD;
    fileIn >> maytinh->namBD;
    fileIn.ignore();
    if (maytinh->gioBD == 0 && maytinh->phutBD == 0 && maytinh->giayBD == 0 && maytinh->ngayBD == 0 && maytinh->thangBD == 0 && maytinh->namBD == 0)
        maytinh->tinhTrang = 0;
    else
        maytinh->tinhTrang = 1;  // cập nhật lại tình trạng máy -> 1 (máy đã có người sử dụng)
}

void ThueMotMay::ghiMotNguoiThueTrucTiep(ofstream &fileOut) {
    fileOut << maytinh->soMay << ' ';
    fileOut << maytinh->gioBD << ' ';
    fileOut << maytinh->phutBD << ' ';
    fileOut << maytinh->giayBD << ' ';
    fileOut << maytinh->ngayBD << ' ';
    fileOut << maytinh->thangBD << ' ';
    fileOut << maytinh->namBD;
}