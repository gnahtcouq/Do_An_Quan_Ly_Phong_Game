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