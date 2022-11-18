#pragma once
#include "NhanVien.hpp"

class Admin {
   private:
    string taiKhoanAdmin = "admin",
           matKhauAdmin = "admin";

   public:
    bool laAdmin(string taiKhoan, string matKhau) {
        if (taiKhoan == taiKhoanAdmin && matKhau == matKhauAdmin)
            return true;
        return false;
    }
    string getTaiKhoanAdmin() { return taiKhoanAdmin; }
    string getMatKhauAdmin() { return matKhauAdmin; }
};

int kiemTraTaiKhoan(DanhSachNhanVien dsnv, string taiKhoan, string matKhau);
int xacThucDangNhap(DanhSachNhanVien dsnv, string taiKhoan, string matKhau);
void dangNhap(DanhSachNhanVien dsnv, int &phanQuyen, string &ten);

int kiemTraTaiKhoan(DanhSachNhanVien dsnv, string taiKhoan, string matKhau) {
    if (dsnv) {
        if (dsnv->nv.taiKhoan == taiKhoan && dsnv->nv.matKhau == matKhau)
            return 1;
        return kiemTraTaiKhoan(dsnv->left, taiKhoan, matKhau) + kiemTraTaiKhoan(dsnv->right, taiKhoan, matKhau);
    } else
        return 0;
}

int xacThucDangNhap(DanhSachNhanVien dsnv, string taiKhoan, string matKhau) {
    Admin dangNhap;
    if (dangNhap.laAdmin(taiKhoan, matKhau))
        return 1;
    else {
        if (kiemTraTaiKhoan(dsnv, taiKhoan, matKhau) == 1)
            return 2;
    }
    return 0;
}

void dangNhap(DanhSachNhanVien dsnv, int &phanQuyen, string &ten) {
    string taiKhoan, matKhau;
    do {
        system("cls");
        cout << "-----------------------------------\n";
        cout << "         QUAN LY STU CYBER         \n";
        cout << "             DANG NHAP             \n";
        cout << "-----------------------------------\n";
        cout << "\n(?) Nhap tai khoan :\t";
        cin >> taiKhoan;
        cin.ignore();
        cout << "\n(?) Nhap mat khau  :\t";
        cin >> matKhau;
        cin.ignore();
        ten = taiKhoan;
        phanQuyen = xacThucDangNhap(dsnv, taiKhoan, matKhau);
        if (phanQuyen == 0) {
            cout << "\n\t(!) Tai khoan/Mat khau khong chinh xac. Hay nhap lai\n";
            system("pause");
        }
    } while (phanQuyen == 0);
    cout << "\n\t(!) Dang nhap thanh cong\n";
    system("pause");
}