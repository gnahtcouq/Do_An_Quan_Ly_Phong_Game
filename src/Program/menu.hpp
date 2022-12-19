#pragma once
#include "NhanVien.hpp"
#include "QuanLy.hpp"
#include "ThueNhieuMay.hpp"

void menu();                                                                    // hiển thị menu
void loading(MayTinh &, MayTinh[], int &, DanhSachNhanVien &, ThueNhieuMay &);  // nhập dữ liệu tổng
void nhapDuLieuGiaTien(MayTinh &);                                              // nhập dữ liệu giá tiền
void nhapDuLieuDanhSachMayTinh(MayTinh[], int &);                               // nhập dữ liệu máy tính
void nhapDuLieuDanhSachNhanVien(DanhSachNhanVien &);                            // nhập dữ liệu nhân viên
void nhapDuLieuDanhSachNguoiThueTrucTiep(ThueNhieuMay &, MayTinh[], int &);     // nhập dữ liệu thuê trực tiếp
void thongTinGioiThieu();                                                       // thông tin giới thiệu

void menu() {
    int n;
    MayTinh mt;
    ThueNhieuMay thueNhieuMay;
    MayTinh *nhieuMay = new MayTinh[MAX];
    //
    khoiTaoSoLuongDauVaoCuaFile();
    //
    DanhSachNhanVien dsnv;
    khoiTaoDanhSachNhanVien(dsnv);
    //
    loading(mt, nhieuMay, n, dsnv, thueNhieuMay);
    //
DANGNHAP:
    int phanQuyen;
    string ten;
    dangNhap(dsnv, phanQuyen, ten);
    //
    // Nếu đăng nhập với phân quyền là Admin
    if (phanQuyen == 1) {
    MENU_ADMIN:
        bool kiemTra = true;
        int c, y = 0;
        system("cls");
        cout << "\n\t\t\tXin chào, " << ten << "\n\n";
        cout << "\t\t\t*---------------------------------------------------*\n";
        cout << "\t\t\t|" << on_blue << "                                                   " << reset << "|\n";
        cout << "\t\t\t|" << on_blue << "              ~  QUẢN LÝ STU CYBER  ~              " << reset << "|\n";
        cout << "\t\t\t|" << on_blue << "                                                   " << reset << "|\n";
        cout << "\t\t\t*---------------------------------------------------*\n";
        cout << "\t\t\t|" << on_magenta << "     ->1.   Quản lý máy tính                       " << reset << "|\n";
        cout << "\t\t\t|      2.   Quản lý nhân viên                       |\n";
        cout << "\t\t\t|      3.   Xem tình trạng máy                      |\n";
        cout << "\t\t\t|      4.   Lịch sử thanh toán                      |\n";
        cout << "\t\t\t|      5.   Lịch sử đăng nhập                       |\n";
        cout << "\t\t\t|      6.   Kiểm tra doanh thu                      |\n";
        cout << "\t\t\t|      7.   Mở máy trực tiếp                        |\n";
        cout << "\t\t\t|      8.   Thanh toán                              |\n";
        cout << "\t\t\t|      9.   Thiết lập giá tiền                      |\n";
        cout << "\t\t\t|      10.  Thông tin giới thiệu                    |\n";
        cout << "\t\t\t|      0.   Đăng xuất                               |\n";
        cout << "\t\t\t*---------------------------------------------------*\n";
        cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
        while (kiemTra) {
            int c = _getch();
            if (c == '\r') {
                kiemTra = false;
            }
            if (c == 224) {
                int key = _getch();
                switch ((key)) {
                    case KEY_UP:
                        if (y > 0)
                            y--;
                        else
                            y = 10;
                        break;
                    case KEY_DOWN:
                        if (y < 11)
                            y++;
                        break;
                    default:
                        break;
                }
            }
            system("cls");

            if (y == 0) {
                cout << "\n\t\t\tXin chào, " << ten << "\n\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\t\t\t|" << on_blue << "                                                   " << reset << "|\n";
                cout << "\t\t\t|" << on_blue << "              ~  QUẢN LÝ STU CYBER  ~              " << reset << "|\n";
                cout << "\t\t\t|" << on_blue << "                                                   " << reset << "|\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\t\t\t|" << on_magenta << "     ->1.   Quản lý máy tính                       " << reset << "|\n";
                cout << "\t\t\t|      2.   Quản lý nhân viên                       |\n";
                cout << "\t\t\t|      3.   Xem tình trạng máy                      |\n";
                cout << "\t\t\t|      4.   Lịch sử thanh toán                      |\n";
                cout << "\t\t\t|      5.   Lịch sử đăng nhập                       |\n";
                cout << "\t\t\t|      6.   Kiểm tra doanh thu                      |\n";
                cout << "\t\t\t|      7.   Mở máy trực tiếp                        |\n";
                cout << "\t\t\t|      8.   Thanh toán                              |\n";
                cout << "\t\t\t|      9.   Thiết lập giá tiền                      |\n";
                cout << "\t\t\t|      10.  Thông tin giới thiệu                    |\n";
                cout << "\t\t\t|      0.   Đăng xuất                               |\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
            } else if (y == 1) {
                cout << "\n\t\t\tXin chào, " << ten << "\n\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\t\t\t|" << on_blue << "                                                   " << reset << "|\n";
                cout << "\t\t\t|" << on_blue << "              ~  QUẢN LÝ STU CYBER  ~              " << reset << "|\n";
                cout << "\t\t\t|" << on_blue << "                                                   " << reset << "|\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\t\t\t|      1.   Quản lý máy tính                        |\n";
                cout << "\t\t\t|" << on_magenta << "     ->2.   Quản lý nhân viên                      " << reset << "|\n";
                cout << "\t\t\t|      3.   Xem tình trạng máy                      |\n";
                cout << "\t\t\t|      4.   Lịch sử thanh toán                      |\n";
                cout << "\t\t\t|      5.   Lịch sử đăng nhập                       |\n";
                cout << "\t\t\t|      6.   Kiểm tra doanh thu                      |\n";
                cout << "\t\t\t|      7.   Mở máy trực tiếp                        |\n";
                cout << "\t\t\t|      8.   Thanh toán                              |\n";
                cout << "\t\t\t|      9.   Thiết lập giá tiền                      |\n";
                cout << "\t\t\t|      10.  Thông tin giới thiệu                    |\n";
                cout << "\t\t\t|      0.   Đăng xuất                               |\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
            } else if (y == 2) {
                cout << "\n\t\t\tXin chào, " << ten << "\n\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\t\t\t|" << on_blue << "                                                   " << reset << "|\n";
                cout << "\t\t\t|" << on_blue << "              ~  QUẢN LÝ STU CYBER  ~              " << reset << "|\n";
                cout << "\t\t\t|" << on_blue << "                                                   " << reset << "|\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\t\t\t|      1.   Quản lý máy tính                        |\n";
                cout << "\t\t\t|      2.   Quản lý nhân viên                       |\n";
                cout << "\t\t\t|" << on_magenta << "     ->3.   Xem tình trạng máy                     " << reset << "|\n";
                cout << "\t\t\t|      4.   Lịch sử thanh toán                      |\n";
                cout << "\t\t\t|      5.   Lịch sử đăng nhập                       |\n";
                cout << "\t\t\t|      6.   Kiểm tra doanh thu                      |\n";
                cout << "\t\t\t|      7.   Mở máy trực tiếp                        |\n";
                cout << "\t\t\t|      8.   Thanh toán                              |\n";
                cout << "\t\t\t|      9.   Thiết lập giá tiền                      |\n";
                cout << "\t\t\t|      10.  Thông tin giới thiệu                    |\n";
                cout << "\t\t\t|      0.   Đăng xuất                               |\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
            } else if (y == 3) {
                cout << "\n\t\t\tXin chào, " << ten << "\n\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\t\t\t|" << on_blue << "                                                   " << reset << "|\n";
                cout << "\t\t\t|" << on_blue << "              ~  QUẢN LÝ STU CYBER  ~              " << reset << "|\n";
                cout << "\t\t\t|" << on_blue << "                                                   " << reset << "|\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\t\t\t|      1.   Quản lý máy tính                        |\n";
                cout << "\t\t\t|      2.   Quản lý nhân viên                       |\n";
                cout << "\t\t\t|      3.   Xem tình trạng máy                      |\n";
                cout << "\t\t\t|" << on_magenta << "     ->4.   Lịch sử thanh toán                     " << reset << "|\n";
                cout << "\t\t\t|      5.   Lịch sử đăng nhập                       |\n";
                cout << "\t\t\t|      6.   Kiểm tra doanh thu                      |\n";
                cout << "\t\t\t|      7.   Mở máy trực tiếp                        |\n";
                cout << "\t\t\t|      8.   Thanh toán                              |\n";
                cout << "\t\t\t|      9.   Thiết lập giá tiền                      |\n";
                cout << "\t\t\t|      10.  Thông tin giới thiệu                    |\n";
                cout << "\t\t\t|      0.   Đăng xuất                               |\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
            } else if (y == 4) {
                cout << "\n\t\t\tXin chào, " << ten << "\n\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\t\t\t|" << on_blue << "                                                   " << reset << "|\n";
                cout << "\t\t\t|" << on_blue << "              ~  QUẢN LÝ STU CYBER  ~              " << reset << "|\n";
                cout << "\t\t\t|" << on_blue << "                                                   " << reset << "|\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\t\t\t|      1.   Quản lý máy tính                        |\n";
                cout << "\t\t\t|      2.   Quản lý nhân viên                       |\n";
                cout << "\t\t\t|      3.   Xem tình trạng máy                      |\n";
                cout << "\t\t\t|      4.   Lịch sử thanh toán                      |\n";
                cout << "\t\t\t|" << on_magenta << "     ->5.   Lịch sử đăng nhập                      " << reset << "|\n";
                cout << "\t\t\t|      6.   Kiểm tra doanh thu                      |\n";
                cout << "\t\t\t|      7.   Mở máy trực tiếp                        |\n";
                cout << "\t\t\t|      8.   Thanh toán                              |\n";
                cout << "\t\t\t|      9.   Thiết lập giá tiền                      |\n";
                cout << "\t\t\t|      10.  Thông tin giới thiệu                    |\n";
                cout << "\t\t\t|      0.   Đăng xuất                               |\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
            } else if (y == 5) {
                cout << "\n\t\t\tXin chào, " << ten << "\n\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\t\t\t|" << on_blue << "                                                   " << reset << "|\n";
                cout << "\t\t\t|" << on_blue << "              ~  QUẢN LÝ STU CYBER  ~              " << reset << "|\n";
                cout << "\t\t\t|" << on_blue << "                                                   " << reset << "|\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\t\t\t|      1.   Quản lý máy tính                        |\n";
                cout << "\t\t\t|      2.   Quản lý nhân viên                       |\n";
                cout << "\t\t\t|      3.   Xem tình trạng máy                      |\n";
                cout << "\t\t\t|      4.   Lịch sử thanh toán                      |\n";
                cout << "\t\t\t|      5.   Lịch sử đăng nhập                       |\n";
                cout << "\t\t\t|" << on_magenta << "     ->6.   Kiểm tra doanh thu                     " << reset << "|\n";
                cout << "\t\t\t|      7.   Mở máy trực tiếp                        |\n";
                cout << "\t\t\t|      8.   Thanh toán                              |\n";
                cout << "\t\t\t|      9.   Thiết lập giá tiền                      |\n";
                cout << "\t\t\t|      10.  Thông tin giới thiệu                    |\n";
                cout << "\t\t\t|      0.   Đăng xuất                               |\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
            } else if (y == 6) {
                cout << "\n\t\t\tXin chào, " << ten << "\n\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\t\t\t|" << on_blue << "                                                   " << reset << "|\n";
                cout << "\t\t\t|" << on_blue << "              ~  QUẢN LÝ STU CYBER  ~              " << reset << "|\n";
                cout << "\t\t\t|" << on_blue << "                                                   " << reset << "|\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\t\t\t|      1.   Quản lý máy tính                        |\n";
                cout << "\t\t\t|      2.   Quản lý nhân viên                       |\n";
                cout << "\t\t\t|      3.   Xem tình trạng máy                      |\n";
                cout << "\t\t\t|      4.   Lịch sử thanh toán                      |\n";
                cout << "\t\t\t|      5.   Lịch sử đăng nhập                       |\n";
                cout << "\t\t\t|      6.   Kiểm tra doanh thu                      |\n";
                cout << "\t\t\t|" << on_magenta << "     ->7.   Mở máy trực tiếp                       " << reset << "|\n";
                cout << "\t\t\t|      8.   Thanh toán                              |\n";
                cout << "\t\t\t|      9.   Thiết lập giá tiền                      |\n";
                cout << "\t\t\t|      10.  Thông tin giới thiệu                    |\n";
                cout << "\t\t\t|      0.   Đăng xuất                               |\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
            } else if (y == 7) {
                cout << "\n\t\t\tXin chào, " << ten << "\n\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\t\t\t|" << on_blue << "                                                   " << reset << "|\n";
                cout << "\t\t\t|" << on_blue << "              ~  QUẢN LÝ STU CYBER  ~              " << reset << "|\n";
                cout << "\t\t\t|" << on_blue << "                                                   " << reset << "|\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\t\t\t|      1.   Quản lý máy tính                        |\n";
                cout << "\t\t\t|      2.   Quản lý nhân viên                       |\n";
                cout << "\t\t\t|      3.   Xem tình trạng máy                      |\n";
                cout << "\t\t\t|      4.   Lịch sử thanh toán                      |\n";
                cout << "\t\t\t|      5.   Lịch sử đăng nhập                       |\n";
                cout << "\t\t\t|      6.   Kiểm tra doanh thu                      |\n";
                cout << "\t\t\t|      7.   Mở máy trực tiếp                        |\n";
                cout << "\t\t\t|" << on_magenta << "     ->8.   Thanh toán                             " << reset << "|\n";
                cout << "\t\t\t|      9.   Thiết lập giá tiền                      |\n";
                cout << "\t\t\t|      10.  Thông tin giới thiệu                    |\n";
                cout << "\t\t\t|      0.   Đăng xuất                               |\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
            } else if (y == 8) {
                cout << "\n\t\t\tXin chào, " << ten << "\n\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\t\t\t|" << on_blue << "                                                   " << reset << "|\n";
                cout << "\t\t\t|" << on_blue << "              ~  QUẢN LÝ STU CYBER  ~              " << reset << "|\n";
                cout << "\t\t\t|" << on_blue << "                                                   " << reset << "|\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\t\t\t|      1.   Quản lý máy tính                        |\n";
                cout << "\t\t\t|      2.   Quản lý nhân viên                       |\n";
                cout << "\t\t\t|      3.   Xem tình trạng máy                      |\n";
                cout << "\t\t\t|      4.   Lịch sử thanh toán                      |\n";
                cout << "\t\t\t|      5.   Lịch sử đăng nhập                       |\n";
                cout << "\t\t\t|      6.   Kiểm tra doanh thu                      |\n";
                cout << "\t\t\t|      7.   Mở máy trực tiếp                        |\n";
                cout << "\t\t\t|      8.   Thanh toán                              |\n";
                cout << "\t\t\t|" << on_magenta << "     ->9.   Thiết lập giá tiền                     " << reset << "|\n";
                cout << "\t\t\t|      10.  Thông tin giới thiệu                    |\n";
                cout << "\t\t\t|      0.   Đăng xuất                               |\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
            } else if (y == 9) {
                cout << "\n\t\t\tXin chào, " << ten << "\n\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\t\t\t|" << on_blue << "                                                   " << reset << "|\n";
                cout << "\t\t\t|" << on_blue << "              ~  QUẢN LÝ STU CYBER  ~              " << reset << "|\n";
                cout << "\t\t\t|" << on_blue << "                                                   " << reset << "|\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\t\t\t|      1.   Quản lý máy tính                        |\n";
                cout << "\t\t\t|      2.   Quản lý nhân viên                       |\n";
                cout << "\t\t\t|      3.   Xem tình trạng máy                      |\n";
                cout << "\t\t\t|      4.   Lịch sử thanh toán                      |\n";
                cout << "\t\t\t|      5.   Lịch sử đăng nhập                       |\n";
                cout << "\t\t\t|      6.   Kiểm tra doanh thu                      |\n";
                cout << "\t\t\t|      7.   Mở máy trực tiếp                        |\n";
                cout << "\t\t\t|      8.   Thanh toán                              |\n";
                cout << "\t\t\t|      9.   Thiết lập giá tiền                      |\n";
                cout << "\t\t\t|" << on_magenta << "     ->10.   Thông tin giới thiệu                  " << reset << "|\n";
                cout << "\t\t\t|      0.   Đăng xuất                               |\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
            } else if (y == 10) {
                cout << "\n\t\t\tXin chào, " << ten << "\n\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\t\t\t|" << on_blue << "                                                   " << reset << "|\n";
                cout << "\t\t\t|" << on_blue << "              ~  QUẢN LÝ STU CYBER  ~              " << reset << "|\n";
                cout << "\t\t\t|" << on_blue << "                                                   " << reset << "|\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\t\t\t|      1.   Quản lý máy tính                        |\n";
                cout << "\t\t\t|      2.   Quản lý nhân viên                       |\n";
                cout << "\t\t\t|      3.   Xem tình trạng máy                      |\n";
                cout << "\t\t\t|      4.   Lịch sử thanh toán                      |\n";
                cout << "\t\t\t|      5.   Lịch sử đăng nhập                       |\n";
                cout << "\t\t\t|      6.   Kiểm tra doanh thu                      |\n";
                cout << "\t\t\t|      7.   Mở máy trực tiếp                        |\n";
                cout << "\t\t\t|      8.   Thanh toán                              |\n";
                cout << "\t\t\t|      9.   Thiết lập giá tiền                      |\n";
                cout << "\t\t\t|      10.  Thông tin giới thiệu                    |\n";
                cout << "\t\t\t|" << on_magenta << "     ->0.   Đăng xuất                              " << reset << "|\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
            } else
                goto MENU_ADMIN;
        }

        if (y == 0) {
        MENU_ADMIN_QUANLYMAYTINH:
            bool kiemTra = true;
            int c, y = 0;
            system("cls");
            cout << bright_yellow << "\n\t\t\tMENU/QUẢN LÝ MÁY TÍNH" << reset << "\n";
            cout << "\t\t\t*----------------------------------------*\n";
            cout << "\t\t\t|" << on_magenta << "     ->1. Thêm máy tính                 " << reset << "|\n";
            cout << "\t\t\t|      2. Xóa máy tính                   |\n";
            cout << "\t\t\t|      0. Trở về                         |\n";
            cout << "\t\t\t*----------------------------------------*\n";
            cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
            while (kiemTra) {
                int c = _getch();
                if (c == '\r') {
                    kiemTra = false;
                }
                if (c == 224) {
                    int key = _getch();
                    switch ((key)) {
                        case KEY_UP:
                            if (y > 0)
                                y--;
                            else
                                y = 2;
                            break;
                        case KEY_DOWN:
                            if (y < 3)
                                y++;
                            break;
                        default:
                            break;
                    }
                }
                system("cls");
                if (y == 0) {
                    cout << bright_yellow << "\n\t\t\tMENU/QUẢN LÝ MÁY TÍNH" << reset << "\n";
                    cout << "\t\t\t*----------------------------------------*\n";
                    cout << "\t\t\t|" << on_magenta << "     ->1. Thêm máy tính                 " << reset << "|\n";
                    cout << "\t\t\t|      2. Xóa máy tính                   |\n";
                    cout << "\t\t\t|      0. Trở về                         |\n";
                    cout << "\t\t\t*----------------------------------------*\n";
                    cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
                } else if (y == 1) {
                    cout << bright_yellow << "\n\t\t\tMENU/QUẢN LÝ MÁY TÍNH" << reset << "\n";
                    cout << "\t\t\t*----------------------------------------*\n";
                    cout << "\t\t\t|      1. Thêm máy tính                  |\n";
                    cout << "\t\t\t|" << on_magenta << "     ->2. Xóa máy tính                  " << reset << "|\n";
                    cout << "\t\t\t|      0. Trở về                         |\n";
                    cout << "\t\t\t*----------------------------------------*\n";
                    cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
                } else if (y == 2) {
                    cout << bright_yellow << "\n\t\t\tMENU/QUẢN LÝ MÁY TÍNH" << reset << "\n";
                    cout << "\t\t\t*----------------------------------------*\n";
                    cout << "\t\t\t|      1. Thêm máy tính                  |\n";
                    cout << "\t\t\t|      2. Xóa máy tính                   |\n";
                    cout << "\t\t\t|" << on_magenta << "     ->0. Trở về                        " << reset << "|\n";
                    cout << "\t\t\t*----------------------------------------*\n";
                    cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
                } else
                    goto MENU_ADMIN_QUANLYMAYTINH;
            }
            if (y == 0) {
                system("cls");
                int soMay;
                cout << bright_yellow << "\nMENU/QUẢN LÝ MÁY TÍNH/THÊM MÁY TÍNH" << reset << "\n";
                if (n != 0)
                    xuatDanhSachCacMay(nhieuMay, n);
                mt.themMayTinh(nhieuMay, n, soMay);
                // sapXepDanhSachMayTinh(nhieuMay, n);
                mergeSort(nhieuMay, 0, n - 1);
                ThueMotMay r;
                r.maytinh = layViTriCuaMay(nhieuMay, n, soMay);
                r.maytinh->soMay = soMay;
                r.maytinh->gioBD = 0;
                r.maytinh->phutBD = 0;
                r.maytinh->giayBD = 0;
                r.maytinh->ngayBD = 0;
                r.maytinh->thangBD = 0;
                r.maytinh->namBD = 0;
                thueNhieuMay.themNodeVaoCuoi(r);
                sapXepDanhSachNguoiThueTheoSoMay(thueNhieuMay);
                ghiDanhSachCacMay(nhieuMay, n);
                ghiDanhSachNguoiThueTrucTiep(thueNhieuMay, n);
            } else if (y == 1) {
                system("cls");
                cout << bright_yellow << "\nMENU/QUẢN LÝ MÁY TÍNH/XÓA MÁY TÍNH" << reset << "\n";
                if (n != 0) {
                    int kiemTra;
                    xuatDanhSachCacMay(nhieuMay, n);
                    mt.xoaMayTinh(nhieuMay, n, kiemTra);
                    if (kiemTra == 1) {
                        thueNhieuMay.xoaNodeCuoiCung();
                        // sapXepDanhSachMayTinh(nhieuMay, n);
                        mergeSort(nhieuMay, 0, n - 1);
                    }
                    ghiDanhSachCacMay(nhieuMay, n);
                    ghiDanhSachNguoiThueTrucTiep(thueNhieuMay, n);
                } else {
                    cout << "\n\t(!) Danh sách máy tính trống\n";
                    cout << "\n[Nhấn ENTER để tiếp tục...]";
                    while (true) {
                        int key = _getch();
                        if (key == KEY_ENTER)
                            break;
                    }
                }
            } else if (y == 2) {
                system("cls");
                goto MENU_ADMIN;
            } else
                goto MENU_ADMIN_QUANLYMAYTINH;
            goto MENU_ADMIN_QUANLYMAYTINH;
        } else if (y == 1) {
        MENU_ADMIN_QUANLYNHANVIEN:
            bool kiemTra = true;
            int c, y = 0;
            system("cls");
            cout << bright_yellow << "\n\t\t\tMENU/QUẢN LÝ NHÂN VIÊN" << reset << "\n";
            cout << "\t\t\t*----------------------------------------*\n";
            cout << "\t\t\t|" << on_magenta << "     ->1. Thêm nhân viên                " << reset << "|\n";
            cout << "\t\t\t|      2. Xóa nhân viên                  |\n";
            cout << "\t\t\t|      3. Xem danh sách                  |\n";
            cout << "\t\t\t|      0. Trở về                         |\n";
            cout << "\t\t\t*----------------------------------------*\n";
            cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
            while (kiemTra) {
                int c = _getch();
                if (c == '\r') {
                    kiemTra = false;
                }
                if (c == 224) {
                    int key = _getch();
                    switch ((key)) {
                        case KEY_UP:
                            if (y > 0)
                                y--;
                            else
                                y = 3;
                            break;
                        case KEY_DOWN:
                            if (y < 4)
                                y++;
                            break;
                        default:
                            break;
                    }
                }
                system("cls");
                if (y == 0) {
                    cout << bright_yellow << "\n\t\t\tMENU/QUẢN LÝ NHÂN VIÊN" << reset << "\n";
                    cout << "\t\t\t*----------------------------------------*\n";
                    cout << "\t\t\t|" << on_magenta << "     ->1. Thêm nhân viên                " << reset << "|\n";
                    cout << "\t\t\t|      2. Xóa nhân viên                  |\n";
                    cout << "\t\t\t|      3. Xem danh sách                  |\n";
                    cout << "\t\t\t|      0. Trở về                         |\n";
                    cout << "\t\t\t*----------------------------------------*\n";
                    cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
                } else if (y == 1) {
                    cout << bright_yellow << "\n\t\t\tMENU/QUẢN LÝ NHÂN VIÊN" << reset << "\n";
                    cout << "\t\t\t*----------------------------------------*\n";
                    cout << "\t\t\t|      1. Thêm nhân viên                 |\n";
                    cout << "\t\t\t|" << on_magenta << "     ->2. Xóa nhân viên                 " << reset << "|\n";
                    cout << "\t\t\t|      3. Xem danh sách                  |\n";
                    cout << "\t\t\t|      0. Trở về                         |\n";
                    cout << "\t\t\t*----------------------------------------*\n";
                    cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
                } else if (y == 2) {
                    cout << bright_yellow << "\n\t\t\tMENU/QUẢN LÝ NHÂN VIÊN" << reset << "\n";
                    cout << "\t\t\t*----------------------------------------*\n";
                    cout << "\t\t\t|      1. Thêm nhân viên                 |\n";
                    cout << "\t\t\t|      2. Xóa nhân viên                  |\n";
                    cout << "\t\t\t|" << on_magenta << "     ->3. Xem danh sách                 " << reset << "|\n";
                    cout << "\t\t\t|      0. Trở về                         |\n";
                    cout << "\t\t\t*----------------------------------------*\n";
                    cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
                } else if (y == 3) {
                    cout << bright_yellow << "\n\t\t\tMENU/QUẢN LÝ NHÂN VIÊN" << reset << "\n";
                    cout << "\t\t\t*----------------------------------------*\n";
                    cout << "\t\t\t|      1. Thêm nhân viên                 |\n";
                    cout << "\t\t\t|      2. Xóa nhân viên                  |\n";
                    cout << "\t\t\t|      3. Xem danh sách                  |\n";
                    cout << "\t\t\t|" << on_magenta << "     ->0. Trở về                        " << reset << "|\n";
                    cout << "\t\t\t*----------------------------------------*\n";
                    cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
                } else
                    goto MENU_ADMIN_QUANLYNHANVIEN;
            }
            if (y == 0) {
                system("cls");
                cout << bright_yellow << "\nMENU/QUẢN LÝ NHÂN VIÊN/THÊM NHÂN VIÊN" << reset << "\n";
                if (dsnv)
                    inDanhSachNhanVien(dsnv);
                nhapMotNhanVien(dsnv);
                ghiDanhSachNhanVien(dsnv);
                cout << "\n[Nhấn ENTER để tiếp tục...]";
                while (true) {
                    int key = _getch();
                    if (key == KEY_ENTER)
                        break;
                }
            } else if (y == 1) {
                system("cls");
                cout << bright_yellow << "\nMENU/QUẢN LÝ NHÂN VIÊN/XÓA NHÂN VIÊN" << reset << "\n";
                if (dsnv) {
                    inDanhSachNhanVien(dsnv);
                    xoaMotNhanVien(dsnv);
                    ghiDanhSachNhanVien(dsnv);
                } else
                    cout << bright_red << "\n\t(!) Danh sách nhân viên trống" << reset << "\n";
                cout << "\n[Nhấn ENTER để tiếp tục...]";
                while (true) {
                    int key = _getch();
                    if (key == KEY_ENTER)
                        break;
                }
            } else if (y == 2) {
                system("cls");
                cout << bright_yellow << "\nMENU/QUẢN LÝ NHÂN VIÊN/XEM DANH SÁCH" << reset << "\n";
                if (dsnv)
                    inDanhSachNhanVien(dsnv);
                else
                    cout << bright_red << "\n\t(!) Danh sách nhân viên trống" << reset << "\n";
                cout << "\n[Nhấn ENTER để tiếp tục...]";
                while (true) {
                    int key = _getch();
                    if (key == KEY_ENTER)
                        break;
                }
            } else if (y == 3) {
                system("cls");
                goto MENU_ADMIN;
            } else
                goto MENU_ADMIN_QUANLYNHANVIEN;
            goto MENU_ADMIN_QUANLYNHANVIEN;
        } else if (y == 2) {
        MENU_ADMIN_TINHTRANGMAY:
            bool kiemTra = true;
            int c, y = 0;
            system("cls");
            cout << bright_yellow << "\n\t\t\tMENU/TÌNH TRẠNG MÁY" << reset << "\n";
            cout << "\t\t\t*-----------------------------------------*\n";
            cout << "\t\t\t|" << on_magenta << "     ->1. Máy trống                      " << reset << "|\n";
            cout << "\t\t\t|      2. Máy đầy                         |\n";
            cout << "\t\t\t|      3. Tất cả                          |\n";
            cout << "\t\t\t|      0. Trở về                          |\n";
            cout << "\t\t\t*-----------------------------------------*\n";
            cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
            while (kiemTra) {
                int c = _getch();
                if (c == '\r') {
                    kiemTra = false;
                }
                if (c == 224) {
                    int key = _getch();
                    switch ((key)) {
                        case KEY_UP:
                            if (y > 0)
                                y--;
                            else
                                y = 3;
                            break;
                        case KEY_DOWN:
                            if (y < 4)
                                y++;
                            break;
                        default:
                            break;
                    }
                }
                system("cls");
                if (y == 0) {
                    cout << bright_yellow << "\n\t\t\tMENU/TÌNH TRẠNG MÁY" << reset << "\n";
                    cout << "\t\t\t*-----------------------------------------*\n";
                    cout << "\t\t\t|" << on_magenta << "     ->1. Máy trống                      " << reset << "|\n";
                    cout << "\t\t\t|      2. Máy đầy                         |\n";
                    cout << "\t\t\t|      3. Tất cả                          |\n";
                    cout << "\t\t\t|      0. Trở về                          |\n";
                    cout << "\t\t\t*-----------------------------------------*\n";
                    cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
                } else if (y == 1) {
                    cout << bright_yellow << "\n\t\t\tMENU/TÌNH TRẠNG MÁY" << reset << "\n";
                    cout << "\t\t\t*-----------------------------------------*\n";
                    cout << "\t\t\t|      1. Máy trống                       |\n";
                    cout << "\t\t\t|" << on_magenta << "     ->2. Máy đầy                        " << reset << "|\n";
                    cout << "\t\t\t|      3. Tất cả                          |\n";
                    cout << "\t\t\t|      0. Trở về                          |\n";
                    cout << "\t\t\t*-----------------------------------------*\n";
                    cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
                } else if (y == 2) {
                    cout << bright_yellow << "\n\t\t\tMENU/TÌNH TRẠNG MÁY" << reset << "\n";
                    cout << "\t\t\t*-----------------------------------------*\n";
                    cout << "\t\t\t|      1. Máy trống                       |\n";
                    cout << "\t\t\t|      2. Máy đầy                         |\n";
                    cout << "\t\t\t|" << on_magenta << "     ->3. Tất cả                         " << reset << "|\n";
                    cout << "\t\t\t|      0. Trở về                          |\n";
                    cout << "\t\t\t*-----------------------------------------*\n";
                    cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
                } else if (y == 3) {
                    cout << bright_yellow << "\n\t\t\tMENU/TÌNH TRẠNG MÁY" << reset << "\n";
                    cout << "\t\t\t*-----------------------------------------*\n";
                    cout << "\t\t\t|      1. Máy trống                       |\n";
                    cout << "\t\t\t|      2. Máy đầy                         |\n";
                    cout << "\t\t\t|      3. Tất cả                          |\n";
                    cout << "\t\t\t|" << on_magenta << "     ->0. Trở về                         " << reset << "|\n";
                    cout << "\t\t\t*-----------------------------------------*\n";
                    cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
                } else
                    goto MENU_ADMIN_TINHTRANGMAY;
            }
            if (y == 0) {
                system("cls");
                cout << bright_yellow << "\nMENU/TÌNH TRẠNG MÁY/MÁY TRỐNG" << reset << "\n";
                xuatDanhSachCacMayTrong(nhieuMay, n);
                cout << "\n[Nhấn ENTER để tiếp tục...]";
                while (true) {
                    int key = _getch();
                    if (key == KEY_ENTER)
                        break;
                }
            } else if (y == 1) {
                system("cls");
                cout << bright_yellow << "\nMENU/TÌNH TRẠNG MÁY/MÁY ĐẦY" << reset << "\n";
                xuatDanhSachCacMayDay(nhieuMay, n);
                cout << "\n[Nhấn ENTER để tiếp tục...]";
                while (true) {
                    int key = _getch();
                    if (key == KEY_ENTER)
                        break;
                }
            } else if (y == 2) {
                system("cls");
                cout << bright_yellow << "\nMENU/TÌNH TRẠNG MÁY/TẤT CẢ" << reset << "\n";
                xuatDanhSachCacMay(nhieuMay, n);
                cout << "\n[Nhấn ENTER để tiếp tục...]";
                while (true) {
                    int key = _getch();
                    if (key == KEY_ENTER)
                        break;
                }
            } else if (y == 3) {
                system("cls");
                goto MENU_ADMIN;
            } else
                goto MENU_ADMIN_TINHTRANGMAY;
            goto MENU_ADMIN_TINHTRANGMAY;
        } else if (y == 3) {
            system("cls");
            cout << bright_yellow << "\nMENU/LỊCH SỬ THANH TOÁN" << reset << "\n";
            string fileName = "../File/lichsu/lichsuthanhtoan.txt";
            if (kiemTraFileTrong(fileName) != -1) {
                cout << on_bright_blue << "*------------------------*-------------------------*----------*----------*--------------------*" << reset << "\n";
                cout << on_bright_blue << setw(32) << left << "| Thời gian bắt đầu"
                     << "|" << reset;
                cout << on_bright_blue << setw(30) << left << " Thời gian kết thúc"
                     << "|" << reset;
                cout << on_bright_blue << setw(13) << left << " Số máy"
                     << "|" << reset;
                cout << on_bright_blue << setw(13) << left << " Kiểu máy"
                     << "|" << reset;
                cout << on_bright_blue << setw(24) << right << "Số tiền "
                     << "|" << reset << "\n";
                cout << on_bright_blue << "*------------------------*-------------------------*----------*----------*--------------------*" << reset << "\n";
                docLichSu(fileName);
                cout << on_bright_blue << "*------------------------*-------------------------*----------*----------*--------------------*" << reset << "\n";
            } else
                cout << "\n\t(!) Lịch sử thanh toán trống\n";
            cout << "\n[Nhấn ENTER để tiếp tục...]";
            while (true) {
                int key = _getch();
                if (key == KEY_ENTER)
                    break;
            }
        } else if (y == 4) {
            system("cls");
            cout << bright_yellow << "\nMENU/LỊCH SỬ ĐĂNG NHẬP" << reset << "\n";
            string fileName = "../File/lichsu/lichsudangnhap.txt";
            if (kiemTraFileTrong(fileName) != -1) {
                cout << on_bright_blue << "*------------------------*------------------------------*------------*" << reset << "\n";
                cout << on_bright_blue << setw(27) << left << "| Thời gian"
                     << "|" << reset;
                cout << on_bright_blue << setw(33) << left << " Tài khoản"
                     << "|" << reset;
                cout << on_bright_blue << setw(15) << left << " Trạng thái"
                     << "|" << reset << "\n";
                cout << on_bright_blue << "*------------------------*------------------------------*------------*" << reset << "\n";
                docLichSu(fileName);
                cout << on_bright_blue << "*------------------------*------------------------------*------------*" << reset << "\n";
            } else
                cout << "\n\t(!) Lịch sử đăng nhập trống\n";
            cout << "\n[Nhấn ENTER để tiếp tục...]";
            while (true) {
                int key = _getch();
                if (key == KEY_ENTER)
                    break;
            }
        } else if (y == 5) {
        MENU_ADMIN_KIEMTRADOANHTHU:
            bool kiemTra = true;
            int c, y = 0;
            system("cls");
            cout << bright_yellow << "\n\t\t\tMENU/KIỂM TRA DOANH THU" << reset << "\n";
            cout << "\t\t\t*----------------------------------------*\n";
            cout << "\t\t\t|" << on_magenta << "     ->1. Doanh thu 7 ngày gần nhất     " << reset << "|\n";
            cout << "\t\t\t|      2. Doanh thu ngày tùy chỉnh       |\n";
            cout << "\t\t\t|      0. Trở về                         |\n";
            cout << "\t\t\t*----------------------------------------*\n";
            cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
            while (kiemTra) {
                int c = _getch();
                if (c == '\r') {
                    kiemTra = false;
                }
                if (c == 224) {
                    int key = _getch();
                    switch ((key)) {
                        case KEY_UP:
                            if (y > 0)
                                y--;
                            else
                                y = 2;
                            break;
                        case KEY_DOWN:
                            if (y < 3)
                                y++;
                            break;
                        default:
                            break;
                    }
                }
                system("cls");
                if (y == 0) {
                    cout << bright_yellow << "\n\t\t\tMENU/KIỂM TRA DOANH THU" << reset << "\n";
                    cout << "\t\t\t*----------------------------------------*\n";
                    cout << "\t\t\t|" << on_magenta << "     ->1. Doanh thu 7 ngày gần nhất     " << reset << "|\n";
                    cout << "\t\t\t|      2. Doanh thu ngày tùy chỉnh       |\n";
                    cout << "\t\t\t|      0. Trở về                         |\n";
                    cout << "\t\t\t*----------------------------------------*\n";
                    cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
                } else if (y == 1) {
                    cout << bright_yellow << "\n\t\t\tMENU/KIỂM TRA DOANH THU" << reset << "\n";
                    cout << "\t\t\t*----------------------------------------*\n";
                    cout << "\t\t\t|      1. Doanh thu 7 ngày gần nhất      |\n";
                    cout << "\t\t\t|" << on_magenta << "     ->2. Doanh thu ngày tùy chỉnh      " << reset << "|\n";
                    cout << "\t\t\t|      0. Trở về                         |\n";
                    cout << "\t\t\t*----------------------------------------*\n";
                    cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
                } else if (y == 2) {
                    cout << bright_yellow << "\n\t\t\tMENU/KIỂM TRA DOANH THU" << reset << "\n";
                    cout << "\t\t\t*----------------------------------------*\n";
                    cout << "\t\t\t|      1. Doanh thu 7 ngày gần nhất      |\n";
                    cout << "\t\t\t|      2. Doanh thu ngày tùy chỉnh       |\n";
                    cout << "\t\t\t|" << on_magenta << "     ->0. Trở về                        " << reset << "|\n";
                    cout << "\t\t\t*----------------------------------------*\n";
                    cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
                } else
                    goto MENU_ADMIN_KIEMTRADOANHTHU;
            }
            if (y == 0) {
                system("cls");
                kiemTraDoanhThu7NgayGanNhat();
                cout << "\n[Nhấn ENTER để tiếp tục...]";
                while (true) {
                    int key = _getch();
                    if (key == KEY_ENTER)
                        break;
                }
            } else if (y == 1) {
                system("cls");
                kiemTraDoanhThuNgayTuyChinh();
                cout << "\n[Nhấn ENTER để tiếp tục...]";
                while (true) {
                    int key = _getch();
                    if (key == KEY_ENTER)
                        break;
                }
            } else if (y == 2) {
                system("cls");
                goto MENU_ADMIN;
            } else
                goto MENU_ADMIN_KIEMTRADOANHTHU;
            goto MENU_ADMIN_KIEMTRADOANHTHU;
        } else if (y == 6) {
            system("cls");
            cout << bright_yellow << "\nMENU/MỞ MÁY TRỰC TIẾP" << reset << "\n";
            thueNhieuMay.moMayTrucTiep(nhieuMay, n);
            ghiDanhSachCacMay(nhieuMay, n);
            ghiDanhSachNguoiThueTrucTiep(thueNhieuMay, n);
        } else if (y == 7) {
            system("cls");
            cout << bright_yellow << "\nMENU/THANH TOÁN" << reset << "\n";
            thueNhieuMay.thanhToan(nhieuMay, n);
            ghiDanhSachCacMay(nhieuMay, n);
            ghiDanhSachNguoiThueTrucTiep(thueNhieuMay, n);
        } else if (y == 8) {
            system("cls");
            cout << bright_yellow << "\nMENU/THIẾT LẬP GIÁ TIỀN" << reset << "\n";
            mt.thietLapGiaTien();
            cout << "\n\t[Nhấn ENTER để tiếp tục...]";
            while (true) {
                int key = _getch();
                if (key == KEY_ENTER)
                    break;
            }
        } else if (y == 9) {
            system("cls");
            thongTinGioiThieu();
            cout << "\n[Nhấn ENTER để tiếp tục...]";
            while (true) {
                int key = _getch();
                if (key == KEY_ENTER)
                    break;
            }
        } else if (y == 10) {
            system("cls");
            cout << bright_green << "\n\t(!) Đăng xuất thành công" << reset << "\n";
            cout << "\n\t[Nhấn ENTER để tiếp tục...]";
            while (true) {
                int key = _getch();
                if (key == KEY_ENTER)
                    break;
            }

            // Ghi lịch sử đăng xuất
            int gio, phut, giay, ngay, thang, nam;
            layThoiGianHeThong(gio, phut, giay, ngay, thang, nam);

            string GIO = to_string(gio);
            string PHUT = to_string(phut);
            string GIAY = to_string(giay);
            string NGAY = to_string(ngay);
            string THANG = to_string(thang);
            string NAM = to_string(nam);

            if (GIO.length() == 1) GIO = "0" + GIO;
            if (PHUT.length() == 1) PHUT = "0" + PHUT;
            if (GIAY.length() == 1) GIAY = "0" + GIAY;
            if (NGAY.length() == 1) NGAY = "0" + NGAY;
            if (THANG.length() == 1) THANG = "0" + THANG;
            if (NAM.length() == 1) NAM = "0" + NAM;

            string thoiGianDangXuat = GIO + ":" + PHUT + ":" + GIAY + " - " + NGAY + "/" + THANG + "/" + NAM;
            string fileName = "../File/lichsu/lichsudangnhap.txt";
            ofstream fileOut(fileName, ios::app);
            if (fileOut.fail()) {
                cout << "\n\t(!) Không tìm thấy tập tin\n";
                cout << "\n[Nhấn ENTER để tiếp tục...]";
                while (true) {
                    int key = _getch();
                    if (key == KEY_ENTER)
                        break;
                }
            } else {
                fileOut << setw(25) << left << "| " + thoiGianDangXuat << "|";
                fileOut << setw(30) << left << " " + ten << "|";
                fileOut << setw(16) << left << " Đăng xuất"
                        << "|\n";
            }
            fileOut.close();
            goto DANGNHAP;
        }
        goto MENU_ADMIN;
    }
    //
    //
    //
    // Nếu đăng nhập với phân quyền là nhân viên
    else {
    MENU_NHANVIEN:
        bool kiemTra = true;
        int c, y = 0;
        system("cls");
        cout << "\n\t\t\tXin chào, " << ten << "\n\n";
        cout << "\t\t\t*---------------------------------------------------*\n";
        cout << "\t\t\t|" << on_blue << "                                                   " << reset << "|\n";
        cout << "\t\t\t|" << on_blue << "              ~  QUẢN LÝ STU CYBER  ~              " << reset << "|\n";
        cout << "\t\t\t|" << on_blue << "                                                   " << reset << "|\n";
        cout << "\t\t\t*---------------------------------------------------*\n";
        cout << "\t\t\t|" << on_magenta << "     ->1.   Xem tình trạng máy                     " << reset << "|\n";
        cout << "\t\t\t|      2.   Mở máy trực tiếp                        |\n";
        cout << "\t\t\t|      3.   Thanh toán                              |\n";
        cout << "\t\t\t|      4.   Thông tin giới thiệu                    |\n";
        cout << "\t\t\t|      0.   Đăng xuất                               |\n";
        cout << "\t\t\t*---------------------------------------------------*\n";
        cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
        while (kiemTra) {
            int c = _getch();
            if (c == '\r') {
                kiemTra = false;
            }
            if (c == 224) {
                int key = _getch();
                switch ((key)) {
                    case KEY_UP:
                        if (y > 0)
                            y--;
                        else
                            y = 4;
                        break;
                    case KEY_DOWN:
                        if (y < 5)
                            y++;
                        break;
                    default:
                        break;
                }
            }
            system("cls");

            if (y == 0) {
                cout << "\n\t\t\tXin chào, " << ten << "\n\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\t\t\t|" << on_blue << "                                                   " << reset << "|\n";
                cout << "\t\t\t|" << on_blue << "              ~  QUẢN LÝ STU CYBER  ~              " << reset << "|\n";
                cout << "\t\t\t|" << on_blue << "                                                   " << reset << "|\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\t\t\t|" << on_magenta << "     ->1.   Xem tình trạng máy                     " << reset << "|\n";
                cout << "\t\t\t|      2.   Mở máy trực tiếp                        |\n";
                cout << "\t\t\t|      3.   Thanh toán                              |\n";
                cout << "\t\t\t|      4.   Thông tin giới thiệu                    |\n";
                cout << "\t\t\t|      0.   Đăng xuất                               |\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
            } else if (y == 1) {
                cout << "\n\t\t\tXin chào, " << ten << "\n\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\t\t\t|" << on_blue << "                                                   " << reset << "|\n";
                cout << "\t\t\t|" << on_blue << "              ~  QUẢN LÝ STU CYBER  ~              " << reset << "|\n";
                cout << "\t\t\t|" << on_blue << "                                                   " << reset << "|\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\t\t\t|      1.   Xem tình trạng máy                      |\n";
                cout << "\t\t\t|" << on_magenta << "     ->2.   Mở máy trực tiếp                       " << reset << "|\n";
                cout << "\t\t\t|      3.   Thanh toán                              |\n";
                cout << "\t\t\t|      4.   Thông tin giới thiệu                    |\n";
                cout << "\t\t\t|      0.   Đăng xuất                               |\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
            } else if (y == 2) {
                cout << "\n\t\t\tXin chào, " << ten << "\n\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\t\t\t|" << on_blue << "                                                   " << reset << "|\n";
                cout << "\t\t\t|" << on_blue << "              ~  QUẢN LÝ STU CYBER  ~              " << reset << "|\n";
                cout << "\t\t\t|" << on_blue << "                                                   " << reset << "|\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\t\t\t|      1.   Xem tình trạng máy                      |\n";
                cout << "\t\t\t|      2.   Mở máy trực tiếp                        |\n";
                cout << "\t\t\t|" << on_magenta << "     ->3.   Thanh toán                             " << reset << "|\n";
                cout << "\t\t\t|      4.   Thông tin giới thiệu                    |\n";
                cout << "\t\t\t|      0.   Đăng xuất                               |\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
            } else if (y == 3) {
                cout << "\n\t\t\tXin chào, " << ten << "\n\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\t\t\t|" << on_blue << "                                                   " << reset << "|\n";
                cout << "\t\t\t|" << on_blue << "              ~  QUẢN LÝ STU CYBER  ~              " << reset << "|\n";
                cout << "\t\t\t|" << on_blue << "                                                   " << reset << "|\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\t\t\t|      1.   Xem tình trạng máy                      |\n";
                cout << "\t\t\t|      2.   Mở máy trực tiếp                        |\n";
                cout << "\t\t\t|      3.   Thanh toán                              |\n";
                cout << "\t\t\t|" << on_magenta << "     ->4.   Thông tin giới thiệu                   " << reset << "|\n";
                cout << "\t\t\t|      0.   Đăng xuất                               |\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
            } else if (y == 4) {
                cout << "\n\t\t\tXin chào, " << ten << "\n\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\t\t\t|" << on_blue << "                                                   " << reset << "|\n";
                cout << "\t\t\t|" << on_blue << "              ~  QUẢN LÝ STU CYBER  ~              " << reset << "|\n";
                cout << "\t\t\t|" << on_blue << "                                                   " << reset << "|\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\t\t\t|      1.   Xem tình trạng máy                      |\n";
                cout << "\t\t\t|      2.   Mở máy trực tiếp                        |\n";
                cout << "\t\t\t|      3.   Thanh toán                              |\n";
                cout << "\t\t\t|      4.   Thông tin giới thiệu                    |\n";
                cout << "\t\t\t|" << on_magenta << "     ->0.   Đăng xuất                              " << reset << "|\n";
                cout << "\t\t\t*---------------------------------------------------*\n";
                cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
            } else
                goto MENU_NHANVIEN;
        }
        if (y == 0) {
        MENU_NHANVIEN_TINHTRANGMAY:
            bool kiemTra = true;
            int c, y = 0;
            system("cls");
            cout << bright_yellow << "\n\t\t\tMENU/TÌNH TRẠNG MÁY" << reset << "\n";
            cout << "\t\t\t*-----------------------------------------*\n";
            cout << "\t\t\t|" << on_magenta << "     ->1. Máy trống                      " << reset << "|\n";
            cout << "\t\t\t|      2. Máy đầy                         |\n";
            cout << "\t\t\t|      3. Tất cả                          |\n";
            cout << "\t\t\t|      0. Trở về                          |\n";
            cout << "\t\t\t*-----------------------------------------*\n";
            cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
            while (kiemTra) {
                int c = _getch();
                if (c == '\r') {
                    kiemTra = false;
                }
                if (c == 224) {
                    int key = _getch();
                    switch ((key)) {
                        case KEY_UP:
                            if (y > 0)
                                y--;
                            else
                                y = 3;
                            break;
                        case KEY_DOWN:
                            if (y < 4)
                                y++;
                            break;
                        default:
                            break;
                    }
                }
                system("cls");
                if (y == 0) {
                    cout << bright_yellow << "\n\t\t\tMENU/TÌNH TRẠNG MÁY" << reset << "\n";
                    cout << "\t\t\t*-----------------------------------------*\n";
                    cout << "\t\t\t|" << on_magenta << "     ->1. Máy trống                      " << reset << "|\n";
                    cout << "\t\t\t|      2. Máy đầy                         |\n";
                    cout << "\t\t\t|      3. Tất cả                          |\n";
                    cout << "\t\t\t|      0. Trở về                          |\n";
                    cout << "\t\t\t*-----------------------------------------*\n";
                    cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
                } else if (y == 1) {
                    cout << bright_yellow << "\n\t\t\tMENU/TÌNH TRẠNG MÁY" << reset << "\n";
                    cout << "\t\t\t*-----------------------------------------*\n";
                    cout << "\t\t\t|      1. Máy trống                       |\n";
                    cout << "\t\t\t|" << on_magenta << "     ->2. Máy đầy                        " << reset << "|\n";
                    cout << "\t\t\t|      3. Tất cả                          |\n";
                    cout << "\t\t\t|      0. Trở về                          |\n";
                    cout << "\t\t\t*-----------------------------------------*\n";
                    cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
                } else if (y == 2) {
                    cout << bright_yellow << "\n\t\t\tMENU/TÌNH TRẠNG MÁY" << reset << "\n";
                    cout << "\t\t\t*-----------------------------------------*\n";
                    cout << "\t\t\t|      1. Máy trống                       |\n";
                    cout << "\t\t\t|      2. Máy đầy                         |\n";
                    cout << "\t\t\t|" << on_magenta << "     ->3. Tất cả                         " << reset << "|\n";
                    cout << "\t\t\t|      0. Trở về                          |\n";
                    cout << "\t\t\t*-----------------------------------------*\n";
                    cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
                } else if (y == 3) {
                    cout << bright_yellow << "\n\t\t\tMENU/TÌNH TRẠNG MÁY" << reset << "\n";
                    cout << "\t\t\t*-----------------------------------------*\n";
                    cout << "\t\t\t|      1. Máy trống                       |\n";
                    cout << "\t\t\t|      2. Máy đầy                         |\n";
                    cout << "\t\t\t|      3. Tất cả                          |\n";
                    cout << "\t\t\t|" << on_magenta << "     ->0. Trở về                         " << reset << "|\n";
                    cout << "\t\t\t*-----------------------------------------*\n";
                    cout << "\n\t\t\t(Sử dụng các phím ↑ ↓ để di chuyển và ENTER để chọn)";
                } else
                    goto MENU_NHANVIEN_TINHTRANGMAY;
            }
            if (y == 0) {
                system("cls");
                cout << bright_yellow << "\nMENU/TÌNH TRẠNG MÁY/MÁY TRỐNG" << reset << "\n";
                xuatDanhSachCacMayTrong(nhieuMay, n);
                cout << "\n[Nhấn ENTER để tiếp tục...]";
                while (true) {
                    int key = _getch();
                    if (key == KEY_ENTER)
                        break;
                }
            } else if (y == 1) {
                system("cls");
                cout << bright_yellow << "\nMENU/TÌNH TRẠNG MÁY/MÁY ĐẦY" << reset << "\n";
                xuatDanhSachCacMayDay(nhieuMay, n);
                cout << "\n[Nhấn ENTER để tiếp tục...]";
                while (true) {
                    int key = _getch();
                    if (key == KEY_ENTER)
                        break;
                }
            } else if (y == 2) {
                system("cls");
                cout << bright_yellow << "\nMENU/TÌNH TRẠNG MÁY/TẤT CẢ" << reset << "\n";
                xuatDanhSachCacMay(nhieuMay, n);
                cout << "\n[Nhấn ENTER để tiếp tục...]";
                while (true) {
                    int key = _getch();
                    if (key == KEY_ENTER)
                        break;
                }
            } else if (y == 3) {
                system("cls");
                goto MENU_NHANVIEN;
            } else
                goto MENU_NHANVIEN_TINHTRANGMAY;
            goto MENU_NHANVIEN_TINHTRANGMAY;
        } else if (y == 1) {
            system("cls");
            cout << bright_yellow << "\nMENU/MỞ MÁY TRỰC TIẾP" << reset << "\n";
            thueNhieuMay.moMayTrucTiep(nhieuMay, n);
            ghiDanhSachCacMay(nhieuMay, n);
            ghiDanhSachNguoiThueTrucTiep(thueNhieuMay, n);
        } else if (y == 2) {
            system("cls");
            cout << bright_yellow << "\nMENU/THANH TOÁN" << reset << "\n";
            thueNhieuMay.thanhToan(nhieuMay, n);
            ghiDanhSachCacMay(nhieuMay, n);
            ghiDanhSachNguoiThueTrucTiep(thueNhieuMay, n);
        } else if (y == 3) {
            system("cls");
            thongTinGioiThieu();
            cout << "\n[Nhấn ENTER để tiếp tục...]";
            while (true) {
                int key = _getch();
                if (key == KEY_ENTER)
                    break;
            }
        } else if (y == 4) {
            system("cls");
            cout << bright_green << "\n\t(!) Đăng xuất thành công" << reset << "\n";
            cout << "\n\t[Nhấn ENTER để tiếp tục...]";
            while (true) {
                int key = _getch();
                if (key == KEY_ENTER)
                    break;
            }

            // Ghi lịch sử đăng xuất
            int gio, phut, giay, ngay, thang, nam;
            layThoiGianHeThong(gio, phut, giay, ngay, thang, nam);

            string GIO = to_string(gio);
            string PHUT = to_string(phut);
            string GIAY = to_string(giay);
            string NGAY = to_string(ngay);
            string THANG = to_string(thang);
            string NAM = to_string(nam);

            if (GIO.length() == 1) GIO = "0" + GIO;
            if (PHUT.length() == 1) PHUT = "0" + PHUT;
            if (GIAY.length() == 1) GIAY = "0" + GIAY;
            if (NGAY.length() == 1) NGAY = "0" + NGAY;
            if (THANG.length() == 1) THANG = "0" + THANG;
            if (NAM.length() == 1) NAM = "0" + NAM;

            string thoiGianDangXuat = GIO + ":" + PHUT + ":" + GIAY + " - " + NGAY + "/" + THANG + "/" + NAM;
            string fileName = "../File/lichsu/lichsudangnhap.txt";
            ofstream fileOut(fileName, ios::app);
            if (fileOut.fail()) {
                cout << "\n\t(!) Không tìm thấy tập tin\n";
                cout << "\n[Nhấn ENTER để tiếp tục...]";
                while (true) {
                    int key = _getch();
                    if (key == KEY_ENTER)
                        break;
                }
            } else {
                fileOut << setw(25) << left << "| " + thoiGianDangXuat << "|";
                fileOut << setw(30) << left << " " + ten << "|";
                fileOut << setw(16) << left << " Đăng xuất"
                        << "|\n";
            }
            fileOut.close();
            goto DANGNHAP;
        }
        goto MENU_NHANVIEN;
    }
    delete[] nhieuMay;                                  // giải phóng bộ nhớ của ds máy tính
    giaiPhongDanhSachNhanVien(dsnv);                    // giải phóng bộ nhớ của ds khách hàng
    thueNhieuMay.giaiPhongDanhSachNguoiThueTrucTiep();  // giải phóng bộ nhớ của ds người thuê trực tiếp
}

void loading(MayTinh &mt, MayTinh nhieuMay[], int &n, DanhSachNhanVien &dsnv, ThueNhieuMay &thueNhieuMay) {
    system("cls");
    float tienTrinh = 0.0;
    while (tienTrinh <= 1) {
        int doDaiThanh = 100;

        cout << "[";
        int viTri = doDaiThanh * tienTrinh;
        for (int i = 0; i < doDaiThanh; ++i) {
            if (i < viTri)
                cout << on_bright_green << " " << reset;
            else if (i == viTri)
                cout << on_bright_green << " " << reset;
            else
                cout << " ";
        }
        cout << "] " << int(tienTrinh * 100.0) << " %\r";
        cout.flush();
        if (tienTrinh == float(0.2))
            nhapDuLieuGiaTien(mt);
        else if (tienTrinh == float(0.4))
            nhapDuLieuDanhSachMayTinh(nhieuMay, n);
        else if (tienTrinh == float(0.6))
            nhapDuLieuDanhSachNhanVien(dsnv);
        else if (tienTrinh == float(0.8))
            nhapDuLieuDanhSachNguoiThueTrucTiep(thueNhieuMay, nhieuMay, n);
        else if (tienTrinh == float(1))
            cout << bright_red << "\n\t(*) Nhập dữ liệu thành công (*)" << reset << "\n";
        tienTrinh += 0.2;
        Sleep(350);
        system("cls");
    }
    cout << endl;
}

void nhapDuLieuGiaTien(MayTinh &mt) {
    mt.docGiaTien();
    if (mt.giaTienThuong == 0 || mt.giaTienCaoCap == 0) {
        cout << bright_red << "\n\t(!) Hệ thống đang chưa được thiết lập giá tiền. Hãy thiết lập ngay bây giờ" << reset << "\n";
        cout << "\n\t[Nhấn ENTER để tiếp tục...]";
        while (true) {
            int key = _getch();
            if (key == KEY_ENTER)
                break;
        }
        mt.thietLapGiaTien();
    } else
        cout << bright_red << "\n\t(*) Đang nhập dữ liệu giá tiền (*)" << reset << "\n";
}

void nhapDuLieuDanhSachMayTinh(MayTinh nhieuMay[], int &n) {
    string fileName = "../File/maytinh/danhsachmaytinh.txt";
    int x = kiemTraFileTrong(fileName);
    if (x == -1)
        n = 0;
    else {
        cout << bright_red << "\n\t(*) Đang nhập dữ liệu danh sách máy tính (*)" << reset << "\n";
        docDanhSachCacMay(nhieuMay, n);
    }
}

void nhapDuLieuDanhSachNhanVien(DanhSachNhanVien &dsnv) {
    cout << bright_red << "\n\t(*) Đang nhập dữ liệu danh sách nhân viên (*)" << reset << "\n";
    docDanhSachNhanVien(dsnv);
}

void nhapDuLieuDanhSachNguoiThueTrucTiep(ThueNhieuMay &thueNhieuMay, MayTinh nhieuMay[], int &n) {
    thueNhieuMay.taoListThueMotMay();
    cout << bright_red << "\n\t(*) Đang nhập dữ liệu danh sách người thuê trực tiếp (*)" << reset << "\n";
    docDanhSachNguoiThueTrucTiep(thueNhieuMay, nhieuMay, n);
}

void thongTinGioiThieu() {
    cout << bright_yellow << "\nMENU/THÔNG TIN GIỚI THIỆU" << reset << "\n";
    cout << on_bright_blue << "\n*-------------------- ĐẠI HỌC CÔNG NGHỆ SÀI GÒN --------------------*" << reset;
    cout << on_bright_blue << "\n| * Đồ án:      Quản Lý Phòng Game                                  |" << reset;
    cout << on_bright_blue << "\n|                                                                   |" << reset;
    cout << on_bright_blue << "\n| * Giảng viên: Hoàng Khuê                                          |" << reset;
    cout << on_bright_blue << "\n|                                                                   |" << reset;
    cout << on_bright_blue << "\n| * Sinh viên:  1. Trần Văn Quốc Thắng - DH52007101 - D20_TH11      |" << reset;
    cout << on_bright_blue << "\n|               2. Võ Xuân Lam - DH52006929 - D20_TH11              |" << reset;
    cout << on_bright_blue << "\n|               3. Đặng Xuân Sang - DH52006904 - D20_TH11           |" << reset;
    cout << on_bright_blue << "\n|               4. Trần Nguyễn Thanh Sang - DH52007102 - D20_TH11   |" << reset;
    cout << on_bright_blue << "\n|               5. Đỗ Trần Hải Sơn - DH52007024 - D20_TH11          |" << reset;
    cout << on_bright_blue << "\n*------------------------------- 2022 ------------------------------*" << reset << "\n";
}