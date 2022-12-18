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
        cout << "\nXin chao, " << ten << "\n\n";
        cout << "*---------------------------------------------------*\n";
        cout << "|" << on_blue << "                                                   " << reset << "|\n";
        cout << "|" << on_blue << "              ~  QUAN LY STU CYBER  ~              " << reset << "|\n";
        cout << "|" << on_blue << "                                                   " << reset << "|\n";
        cout << "*---------------------------------------------------*\n";
        cout << "|" << on_magenta << "     ->1.   Quan ly may tinh                       " << reset << "|\n";
        cout << "|      2.   Quan ly nhan vien                       |\n";
        cout << "|      3.   Xem tinh trang may                      |\n";
        cout << "|      4.   Lich su thanh toan                      |\n";
        cout << "|      5.   Lich su dang nhap                       |\n";
        cout << "|      6.   Kiem tra doanh thu                      |\n";
        cout << "|      7.   Mo may truc tiep                        |\n";
        cout << "|      8.   Thanh toan                              |\n";
        cout << "|      9.   Thiet lap gia tien                      |\n";
        cout << "|      10.  Thong tin gioi thieu                    |\n";
        cout << "|      0.   Dang xuat                               |\n";
        cout << "*---------------------------------------------------*\n";
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
                cout << "\nXin chao, " << ten << "\n\n";
                cout << "*---------------------------------------------------*\n";
                cout << "|" << on_blue << "                                                   " << reset << "|\n";
                cout << "|" << on_blue << "              ~  QUAN LY STU CYBER  ~              " << reset << "|\n";
                cout << "|" << on_blue << "                                                   " << reset << "|\n";
                cout << "*---------------------------------------------------*\n";
                cout << "|" << on_magenta << "     ->1.   Quan ly may tinh                       " << reset << "|\n";
                cout << "|      2.   Quan ly nhan vien                       |\n";
                cout << "|      3.   Xem tinh trang may                      |\n";
                cout << "|      4.   Lich su thanh toan                      |\n";
                cout << "|      5.   Lich su dang nhap                       |\n";
                cout << "|      6.   Kiem tra doanh thu                      |\n";
                cout << "|      7.   Mo may truc tiep                        |\n";
                cout << "|      8.   Thanh toan                              |\n";
                cout << "|      9.   Thiet lap gia tien                      |\n";
                cout << "|      10.  Thong tin gioi thieu                    |\n";
                cout << "|      0.   Dang xuat                               |\n";
                cout << "*---------------------------------------------------*\n";
            } else if (y == 1) {
                cout << "\nXin chao, " << ten << "\n\n";
                cout << "*---------------------------------------------------*\n";
                cout << "|" << on_blue << "                                                   " << reset << "|\n";
                cout << "|" << on_blue << "              ~  QUAN LY STU CYBER  ~              " << reset << "|\n";
                cout << "|" << on_blue << "                                                   " << reset << "|\n";
                cout << "*---------------------------------------------------*\n";
                cout << "|      1.   Quan ly may tinh                        |\n";
                cout << "|" << on_magenta << "     ->2.   Quan ly nhan vien                      " << reset << "|\n";
                cout << "|      3.   Xem tinh trang may                      |\n";
                cout << "|      4.   Lich su thanh toan                      |\n";
                cout << "|      5.   Lich su dang nhap                       |\n";
                cout << "|      6.   Kiem tra doanh thu                      |\n";
                cout << "|      7.   Mo may truc tiep                        |\n";
                cout << "|      8.   Thanh toan                              |\n";
                cout << "|      9.   Thiet lap gia tien                      |\n";
                cout << "|      10.  Thong tin gioi thieu                    |\n";
                cout << "|      0.   Dang xuat                               |\n";
                cout << "*---------------------------------------------------*\n";
            } else if (y == 2) {
                cout << "\nXin chao, " << ten << "\n\n";
                cout << "*---------------------------------------------------*\n";
                cout << "|" << on_blue << "                                                   " << reset << "|\n";
                cout << "|" << on_blue << "              ~  QUAN LY STU CYBER  ~              " << reset << "|\n";
                cout << "|" << on_blue << "                                                   " << reset << "|\n";
                cout << "*---------------------------------------------------*\n";
                cout << "|      1.   Quan ly may tinh                        |\n";
                cout << "|      2.   Quan ly nhan vien                       |\n";
                cout << "|" << on_magenta << "     ->3.   Xem tinh trang may                     " << reset << "|\n";
                cout << "|      4.   Lich su thanh toan                      |\n";
                cout << "|      5.   Lich su dang nhap                       |\n";
                cout << "|      6.   Kiem tra doanh thu                      |\n";
                cout << "|      7.   Mo may truc tiep                        |\n";
                cout << "|      8.   Thanh toan                              |\n";
                cout << "|      9.   Thiet lap gia tien                      |\n";
                cout << "|      10.  Thong tin gioi thieu                    |\n";
                cout << "|      0.   Dang xuat                               |\n";
                cout << "*---------------------------------------------------*\n";
            } else if (y == 3) {
                cout << "\nXin chao, " << ten << "\n\n";
                cout << "*---------------------------------------------------*\n";
                cout << "|" << on_blue << "                                                   " << reset << "|\n";
                cout << "|" << on_blue << "              ~  QUAN LY STU CYBER  ~              " << reset << "|\n";
                cout << "|" << on_blue << "                                                   " << reset << "|\n";
                cout << "*---------------------------------------------------*\n";
                cout << "|      1.   Quan ly may tinh                        |\n";
                cout << "|      2.   Quan ly nhan vien                       |\n";
                cout << "|      3.   Xem tinh trang may                      |\n";
                cout << "|" << on_magenta << "     ->4.   Lich su thanh toan                     " << reset << "|\n";
                cout << "|      5.   Lich su dang nhap                       |\n";
                cout << "|      6.   Kiem tra doanh thu                      |\n";
                cout << "|      7.   Mo may truc tiep                        |\n";
                cout << "|      8.   Thanh toan                              |\n";
                cout << "|      9.   Thiet lap gia tien                      |\n";
                cout << "|      10.  Thong tin gioi thieu                    |\n";
                cout << "|      0.   Dang xuat                               |\n";
                cout << "*---------------------------------------------------*\n";
            } else if (y == 4) {
                cout << "\nXin chao, " << ten << "\n\n";
                cout << "*---------------------------------------------------*\n";
                cout << "|" << on_blue << "                                                   " << reset << "|\n";
                cout << "|" << on_blue << "              ~  QUAN LY STU CYBER  ~              " << reset << "|\n";
                cout << "|" << on_blue << "                                                   " << reset << "|\n";
                cout << "*---------------------------------------------------*\n";
                cout << "|      1.   Quan ly may tinh                        |\n";
                cout << "|      2.   Quan ly nhan vien                       |\n";
                cout << "|      3.   Xem tinh trang may                      |\n";
                cout << "|      4.   Lich su thanh toan                      |\n";
                cout << "|" << on_magenta << "     ->5.   Lich su dang nhap                      " << reset << "|\n";
                cout << "|      6.   Kiem tra doanh thu                      |\n";
                cout << "|      7.   Mo may truc tiep                        |\n";
                cout << "|      8.   Thanh toan                              |\n";
                cout << "|      9.   Thiet lap gia tien                      |\n";
                cout << "|      10.  Thong tin gioi thieu                    |\n";
                cout << "|      0.   Dang xuat                               |\n";
                cout << "*---------------------------------------------------*\n";
            } else if (y == 5) {
                cout << "\nXin chao, " << ten << "\n\n";
                cout << "*---------------------------------------------------*\n";
                cout << "|" << on_blue << "                                                   " << reset << "|\n";
                cout << "|" << on_blue << "              ~  QUAN LY STU CYBER  ~              " << reset << "|\n";
                cout << "|" << on_blue << "                                                   " << reset << "|\n";
                cout << "*---------------------------------------------------*\n";
                cout << "|      1.   Quan ly may tinh                        |\n";
                cout << "|      2.   Quan ly nhan vien                       |\n";
                cout << "|      3.   Xem tinh trang may                      |\n";
                cout << "|      4.   Lich su thanh toan                      |\n";
                cout << "|      5.   Lich su dang nhap                       |\n";
                cout << "|" << on_magenta << "     ->6.   Kiem tra doanh thu                     " << reset << "|\n";
                cout << "|      7.   Mo may truc tiep                        |\n";
                cout << "|      8.   Thanh toan                              |\n";
                cout << "|      9.   Thiet lap gia tien                      |\n";
                cout << "|      10.  Thong tin gioi thieu                    |\n";
                cout << "|      0.   Dang xuat                               |\n";
                cout << "*---------------------------------------------------*\n";
            } else if (y == 6) {
                cout << "\nXin chao, " << ten << "\n\n";
                cout << "*---------------------------------------------------*\n";
                cout << "|" << on_blue << "                                                   " << reset << "|\n";
                cout << "|" << on_blue << "              ~  QUAN LY STU CYBER  ~              " << reset << "|\n";
                cout << "|" << on_blue << "                                                   " << reset << "|\n";
                cout << "*---------------------------------------------------*\n";
                cout << "|      1.   Quan ly may tinh                        |\n";
                cout << "|      2.   Quan ly nhan vien                       |\n";
                cout << "|      3.   Xem tinh trang may                      |\n";
                cout << "|      4.   Lich su thanh toan                      |\n";
                cout << "|      5.   Lich su dang nhap                       |\n";
                cout << "|      6.   Kiem tra doanh thu                      |\n";
                cout << "|" << on_magenta << "     ->7.   Mo may truc tiep                       " << reset << "|\n";
                cout << "|      8.   Thanh toan                              |\n";
                cout << "|      9.   Thiet lap gia tien                      |\n";
                cout << "|      10.  Thong tin gioi thieu                    |\n";
                cout << "|      0.   Dang xuat                               |\n";
                cout << "*---------------------------------------------------*\n";
            } else if (y == 7) {
                cout << "\nXin chao, " << ten << "\n\n";
                cout << "*---------------------------------------------------*\n";
                cout << "|" << on_blue << "                                                   " << reset << "|\n";
                cout << "|" << on_blue << "              ~  QUAN LY STU CYBER  ~              " << reset << "|\n";
                cout << "|" << on_blue << "                                                   " << reset << "|\n";
                cout << "*---------------------------------------------------*\n";
                cout << "|      1.   Quan ly may tinh                        |\n";
                cout << "|      2.   Quan ly nhan vien                       |\n";
                cout << "|      3.   Xem tinh trang may                      |\n";
                cout << "|      4.   Lich su thanh toan                      |\n";
                cout << "|      5.   Lich su dang nhap                       |\n";
                cout << "|      6.   Kiem tra doanh thu                      |\n";
                cout << "|      7.   Mo may truc tiep                        |\n";
                cout << "|" << on_magenta << "     ->8.   Thanh toan                             " << reset << "|\n";
                cout << "|      9.   Thiet lap gia tien                      |\n";
                cout << "|      10.  Thong tin gioi thieu                    |\n";
                cout << "|      0.   Dang xuat                               |\n";
                cout << "*---------------------------------------------------*\n";
            } else if (y == 8) {
                cout << "\nXin chao, " << ten << "\n\n";
                cout << "*---------------------------------------------------*\n";
                cout << "|" << on_blue << "                                                   " << reset << "|\n";
                cout << "|" << on_blue << "              ~  QUAN LY STU CYBER  ~              " << reset << "|\n";
                cout << "|" << on_blue << "                                                   " << reset << "|\n";
                cout << "*---------------------------------------------------*\n";
                cout << "|      1.   Quan ly may tinh                        |\n";
                cout << "|      2.   Quan ly nhan vien                       |\n";
                cout << "|      3.   Xem tinh trang may                      |\n";
                cout << "|      4.   Lich su thanh toan                      |\n";
                cout << "|      5.   Lich su dang nhap                       |\n";
                cout << "|      6.   Kiem tra doanh thu                      |\n";
                cout << "|      7.   Mo may truc tiep                        |\n";
                cout << "|      8.   Thanh toan                              |\n";
                cout << "|" << on_magenta << "     ->9.   Thiet lap gia tien                     " << reset << "|\n";
                cout << "|      10.  Thong tin gioi thieu                    |\n";
                cout << "|      0.   Dang xuat                               |\n";
                cout << "*---------------------------------------------------*\n";
            } else if (y == 9) {
                cout << "\nXin chao, " << ten << "\n\n";
                cout << "*---------------------------------------------------*\n";
                cout << "|" << on_blue << "                                                   " << reset << "|\n";
                cout << "|" << on_blue << "              ~  QUAN LY STU CYBER  ~              " << reset << "|\n";
                cout << "|" << on_blue << "                                                   " << reset << "|\n";
                cout << "*---------------------------------------------------*\n";
                cout << "|      1.   Quan ly may tinh                        |\n";
                cout << "|      2.   Quan ly nhan vien                       |\n";
                cout << "|      3.   Xem tinh trang may                      |\n";
                cout << "|      4.   Lich su thanh toan                      |\n";
                cout << "|      5.   Lich su dang nhap                       |\n";
                cout << "|      6.   Kiem tra doanh thu                      |\n";
                cout << "|      7.   Mo may truc tiep                        |\n";
                cout << "|      8.   Thanh toan                              |\n";
                cout << "|      9.   Thiet lap gia tien                      |\n";
                cout << "|" << on_magenta << "     ->10.   Thong tin gioi thieu                  " << reset << "|\n";
                cout << "|      0.   Dang xuat                               |\n";
                cout << "*---------------------------------------------------*\n";
            } else if (y == 10) {
                cout << "\nXin chao, " << ten << "\n\n";
                cout << "*---------------------------------------------------*\n";
                cout << "|" << on_blue << "                                                   " << reset << "|\n";
                cout << "|" << on_blue << "              ~  QUAN LY STU CYBER  ~              " << reset << "|\n";
                cout << "|" << on_blue << "                                                   " << reset << "|\n";
                cout << "*---------------------------------------------------*\n";
                cout << "|      1.   Quan ly may tinh                        |\n";
                cout << "|      2.   Quan ly nhan vien                       |\n";
                cout << "|      3.   Xem tinh trang may                      |\n";
                cout << "|      4.   Lich su thanh toan                      |\n";
                cout << "|      5.   Lich su dang nhap                       |\n";
                cout << "|      6.   Kiem tra doanh thu                      |\n";
                cout << "|      7.   Mo may truc tiep                        |\n";
                cout << "|      8.   Thanh toan                              |\n";
                cout << "|      9.   Thiet lap gia tien                      |\n";
                cout << "|      10.  Thong tin gioi thieu                    |\n";
                cout << "|" << on_magenta << "     ->0.   Dang xuat                              " << reset << "|\n";
                cout << "*---------------------------------------------------*\n";
            } else
                goto MENU_ADMIN;
        }

        if (y == 0) {
        MENU_ADMIN_QUANLYMAYTINH:
            bool kiemTra = true;
            int c, y = 0;
            system("cls");
            cout << bright_yellow << "\nMENU/QUAN LY MAY TINH" << reset << "\n";
            cout << "*----------------------------------------*\n";
            cout << "|" << on_magenta << "     ->1. Them may tinh                 " << reset << "|\n";
            cout << "|      2. Xoa may tinh                   |\n";
            cout << "|      0. Tro ve                         |\n";
            cout << "*----------------------------------------*\n";
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
                    cout << bright_yellow << "\nMENU/QUAN LY MAY TINH" << reset << "\n";
                    cout << "*----------------------------------------*\n";
                    cout << "|" << on_magenta << "     ->1. Them may tinh                 " << reset << "|\n";
                    cout << "|      2. Xoa may tinh                   |\n";
                    cout << "|      0. Tro ve                         |\n";
                    cout << "*----------------------------------------*\n";
                } else if (y == 1) {
                    cout << bright_yellow << "\nMENU/QUAN LY MAY TINH" << reset << "\n";
                    cout << "*----------------------------------------*\n";
                    cout << "|      1. Them may tinh                  |\n";
                    cout << "|" << on_magenta << "     ->2. Xoa may tinh                  " << reset << "|\n";
                    cout << "|      0. Tro ve                         |\n";
                    cout << "*----------------------------------------*\n";
                } else if (y == 2) {
                    cout << bright_yellow << "\nMENU/QUAN LY MAY TINH" << reset << "\n";
                    cout << "*----------------------------------------*\n";
                    cout << "|      1. Them may tinh                  |\n";
                    cout << "|      2. Xoa may tinh                   |\n";
                    cout << "|" << on_magenta << "     ->0. Tro ve                        " << reset << "|\n";
                    cout << "*----------------------------------------*\n";
                } else
                    goto MENU_ADMIN_QUANLYMAYTINH;
            }
            if (y == 0) {
                system("cls");
                int soMay;
                cout << bright_yellow << "\nMENU/QUAN LY MAY TINH/THEM MAY TINH" << reset << "\n";
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
                cout << bright_yellow << "\nMENU/QUAN LY MAY TINH/XOA MAY TINH" << reset << "\n";
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
                    cout << "\n\t(!) Danh sach may tinh trong\n";
                    system("pause");
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
            cout << bright_yellow << "\nMENU/QUAN LY NHAN VIEN" << reset << "\n";
            cout << "*----------------------------------------*\n";
            cout << "|" << on_magenta << "     ->1. Them nhan vien                " << reset << "|\n";
            cout << "|      2. Xoa nhan vien                  |\n";
            cout << "|      3. Xem danh sach                  |\n";
            cout << "|      0. Tro ve                         |\n";
            cout << "*----------------------------------------*\n";
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
                    cout << bright_yellow << "\nMENU/QUAN LY NHAN VIEN" << reset << "\n";
                    cout << "*----------------------------------------*\n";
                    cout << "|" << on_magenta << "     ->1. Them nhan vien                " << reset << "|\n";
                    cout << "|      2. Xoa nhan vien                  |\n";
                    cout << "|      3. Xem danh sach                  |\n";
                    cout << "|      0. Tro ve                         |\n";
                    cout << "*----------------------------------------*\n";
                } else if (y == 1) {
                    cout << bright_yellow << "\nMENU/QUAN LY NHAN VIEN" << reset << "\n";
                    cout << "*----------------------------------------*\n";
                    cout << "|      1. Them nhan vien                 |\n";
                    cout << "|" << on_magenta << "     ->2. Xoa nhan vien                 " << reset << "|\n";
                    cout << "|      3. Xem danh sach                  |\n";
                    cout << "|      0. Tro ve                         |\n";
                    cout << "*----------------------------------------*\n";
                } else if (y == 2) {
                    cout << bright_yellow << "\nMENU/QUAN LY NHAN VIEN" << reset << "\n";
                    cout << "*----------------------------------------*\n";
                    cout << "|      1. Them nhan vien                 |\n";
                    cout << "|      2. Xoa nhan vien                  |\n";
                    cout << "|" << on_magenta << "     ->3. Xem danh sach                 " << reset << "|\n";
                    cout << "|      0. Tro ve                         |\n";
                    cout << "*----------------------------------------*\n";
                } else if (y == 3) {
                    cout << bright_yellow << "\nMENU/QUAN LY NHAN VIEN" << reset << "\n";
                    cout << "*----------------------------------------*\n";
                    cout << "|      1. Them nhan vien                 |\n";
                    cout << "|      2. Xoa nhan vien                  |\n";
                    cout << "|      3. Xem danh sach                  |\n";
                    cout << "|" << on_magenta << "     ->0. Tro ve                        " << reset << "|\n";
                    cout << "*----------------------------------------*\n";
                } else
                    goto MENU_ADMIN_QUANLYNHANVIEN;
            }
            if (y == 0) {
                system("cls");
                cout << bright_yellow << "\nMENU/QUAN LY NHAN VIEN/XOA NHAN VIEN" << reset << "\n";
                nhapMotNhanVien(dsnv);
                ghiDanhSachNhanVien(dsnv);
                system("pause");
            } else if (y == 1) {
                system("cls");
                cout << bright_yellow << "\nMENU/QUAN LY NHAN VIEN/XOA NHAN VIEN" << reset << "\n";
                if (dsnv) {
                    inDanhSachNhanVien(dsnv);
                    xoaMotNhanVien(dsnv);
                    ghiDanhSachNhanVien(dsnv);
                } else
                    cout << bright_red << "\n\t(!) Danh sach nhan vien trong" << reset << "\n";
                system("pause");
            } else if (y == 2) {
                system("cls");
                cout << bright_yellow << "\nMENU/QUAN LY NHAN VIEN/XEM DANH SACH" << reset << "\n";
                if (dsnv)
                    inDanhSachNhanVien(dsnv);
                else
                    cout << bright_red << "\n\t(!) Danh sach nhan vien trong" << reset << "\n";
                system("pause");
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
            cout << bright_yellow << "\nMENU/TINH TRANG MAY" << reset << "\n";
            cout << "*-----------------------------------------*\n";
            cout << "|" << on_magenta << "     ->1. May trong                      " << reset << "|\n";
            cout << "|      2. May day                         |\n";
            cout << "|      3. Tat ca                          |\n";
            cout << "|      0. Tro ve                          |\n";
            cout << "*-----------------------------------------*\n";
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
                    cout << bright_yellow << "\nMENU/TINH TRANG MAY" << reset << "\n";
                    cout << "*-----------------------------------------*\n";
                    cout << "|" << on_magenta << "     ->1. May trong                      " << reset << "|\n";
                    cout << "|      2. May day                         |\n";
                    cout << "|      3. Tat ca                          |\n";
                    cout << "|      0. Tro ve                          |\n";
                    cout << "*-----------------------------------------*\n";
                } else if (y == 1) {
                    cout << bright_yellow << "\nMENU/TINH TRANG MAY" << reset << "\n";
                    cout << "*-----------------------------------------*\n";
                    cout << "|      1. May trong                       |\n";
                    cout << "|" << on_magenta << "     ->2. May day                        " << reset << "|\n";
                    cout << "|      3. Tat ca                          |\n";
                    cout << "|      0. Tro ve                          |\n";
                    cout << "*-----------------------------------------*\n";
                } else if (y == 2) {
                    cout << bright_yellow << "\nMENU/TINH TRANG MAY" << reset << "\n";
                    cout << "*-----------------------------------------*\n";
                    cout << "|      1. May trong                       |\n";
                    cout << "|      2. May day                         |\n";
                    cout << "|" << on_magenta << "     ->3. Tat ca                         " << reset << "|\n";
                    cout << "|      0. Tro ve                          |\n";
                    cout << "*-----------------------------------------*\n";
                } else if (y == 3) {
                    cout << bright_yellow << "\nMENU/TINH TRANG MAY" << reset << "\n";
                    cout << "*-----------------------------------------*\n";
                    cout << "|      1. May trong                       |\n";
                    cout << "|      2. May day                         |\n";
                    cout << "|      3. Tat ca                          |\n";
                    cout << "|" << on_magenta << "     ->0. Tro ve                         " << reset << "|\n";
                    cout << "*-----------------------------------------*\n";
                } else
                    goto MENU_ADMIN_TINHTRANGMAY;
            }
            if (y == 0) {
                system("cls");
                cout << bright_yellow << "\nMENU/TINH TRANG MAY/MAY TRONG" << reset << "\n";
                xuatDanhSachCacMayTrong(nhieuMay, n);
                system("pause");
            } else if (y == 1) {
                system("cls");
                cout << bright_yellow << "\nMENU/TINH TRANG MAY/MAY DAY" << reset << "\n";
                xuatDanhSachCacMayDay(nhieuMay, n);
                system("pause");
            } else if (y == 2) {
                system("cls");
                cout << bright_yellow << "\nMENU/TINH TRANG MAY/TAT CA" << reset << "\n";
                xuatDanhSachCacMay(nhieuMay, n);
                system("pause");
            } else if (y == 3) {
                system("cls");
                goto MENU_ADMIN;
            } else
                goto MENU_ADMIN_TINHTRANGMAY;
            goto MENU_ADMIN_TINHTRANGMAY;
        } else if (y == 3) {
            system("cls");
            cout << bright_yellow << "\nMENU/LICH SU THANH TOAN" << reset << "\n";
            string fileName = "../File/lichsu/lichsuthanhtoan.txt";
            if (kiemTraFileTrong(fileName) != -1) {
                cout << on_bright_blue << "*------------------------*-------------------------*----------*----------*--------------------*" << reset << "\n";
                cout << on_bright_blue << setw(25) << left << "| Thoi gian bat dau"
                     << "|" << reset;
                cout << on_bright_blue << setw(25) << left << " Thoi gian ket thuc"
                     << "|" << reset;
                cout << on_bright_blue << setw(10) << left << " So may"
                     << "|" << reset;
                cout << on_bright_blue << setw(10) << left << " Kieu may"
                     << "|" << reset;
                cout << on_bright_blue << setw(20) << right << "So tien "
                     << "|" << reset << "\n";
                cout << on_bright_blue << "*------------------------*-------------------------*----------*----------*--------------------*" << reset << "\n";
                docLichSu(fileName);
                cout << on_bright_blue << "*------------------------*-------------------------*----------*----------*--------------------*" << reset << "\n";
            } else
                cout << "\n\t(!) Lich su thanh toan trong\n";
            system("pause");
        } else if (y == 4) {
            system("cls");
            cout << bright_yellow << "\nMENU/LICH SU DANG NHAP" << reset << "\n";
            string fileName = "../File/lichsu/lichsudangnhap.txt";
            if (kiemTraFileTrong(fileName) != -1) {
                cout << on_bright_blue << "*------------------------*------------------------------*------------*" << reset << "\n";
                cout << on_bright_blue << setw(25) << left << "| Thoi gian"
                     << "|" << reset;
                cout << on_bright_blue << setw(30) << left << " Tai khoan"
                     << "|" << reset;
                cout << on_bright_blue << setw(12) << left << " Trang thai"
                     << "|" << reset << "\n";
                cout << on_bright_blue << "*------------------------*------------------------------*------------*" << reset << "\n";
                docLichSu(fileName);
                cout << on_bright_blue << "*------------------------*------------------------------*------------*" << reset << "\n";
            } else
                cout << "\n\t(!) Lich su dang nhap trong\n";
            system("pause");
        } else if (y == 5) {
        MENU_ADMIN_KIEMTRADOANHTHU:
            bool kiemTra = true;
            int c, y = 0;
            system("cls");
            cout << bright_yellow << "\nMENU/KIEM TRA DOANH THU" << reset << "\n";
            cout << "*----------------------------------------*\n";
            cout << "|" << on_magenta << "     ->1. Doanh thu 7 ngay gan nhat     " << reset << "|\n";
            cout << "|      2. Doanh thu ngay tuy chinh       |\n";
            cout << "|      0. Tro ve                         |\n";
            cout << "*----------------------------------------*\n";
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
                    cout << bright_yellow << "\nMENU/KIEM TRA DOANH THU" << reset << "\n";
                    cout << "*----------------------------------------*\n";
                    cout << "|" << on_magenta << "     ->1. Doanh thu 7 ngay gan nhat     " << reset << "|\n";
                    cout << "|      2. Doanh thu ngay tuy chinh       |\n";
                    cout << "|      0. Tro ve                         |\n";
                    cout << "*----------------------------------------*\n";
                } else if (y == 1) {
                    cout << bright_yellow << "\nMENU/KIEM TRA DOANH THU" << reset << "\n";
                    cout << "*----------------------------------------*\n";
                    cout << "|      1. Doanh thu 7 ngay gan nhat      |\n";
                    cout << "|" << on_magenta << "     ->2. Doanh thu ngay tuy chinh      " << reset << "|\n";
                    cout << "|      0. Tro ve                         |\n";
                    cout << "*----------------------------------------*\n";
                } else if (y == 2) {
                    cout << bright_yellow << "\nMENU/KIEM TRA DOANH THU" << reset << "\n";
                    cout << "*----------------------------------------*\n";
                    cout << "|      1. Doanh thu 7 ngay gan nhat      |\n";
                    cout << "|      2. Doanh thu ngay tuy chinh       |\n";
                    cout << "|" << on_magenta << "     ->0. Tro ve                        " << reset << "|\n";
                    cout << "*----------------------------------------*\n";
                } else
                    goto MENU_ADMIN_KIEMTRADOANHTHU;
            }
            if (y == 0) {
                system("cls");
                kiemTraDoanhThu7NgayGanNhat();
                system("pause");
            } else if (y == 1) {
                system("cls");
                kiemTraDoanhThuNgayTuyChinh();
                system("pause");
            } else if (y == 2) {
                system("cls");
                goto MENU_ADMIN;
            } else
                goto MENU_ADMIN_KIEMTRADOANHTHU;
            goto MENU_ADMIN_KIEMTRADOANHTHU;
        } else if (y == 6) {
            system("cls");
            cout << bright_yellow << "\nMENU/MO MAY TRUC TIEP" << reset << "\n";
            thueNhieuMay.moMayTrucTiep(nhieuMay, n);
            ghiDanhSachCacMay(nhieuMay, n);
            ghiDanhSachNguoiThueTrucTiep(thueNhieuMay, n);
        } else if (y == 7) {
            system("cls");
            cout << bright_yellow << "\nMENU/THANH TOAN" << reset << "\n";
            thueNhieuMay.thanhToan(nhieuMay, n);
            ghiDanhSachCacMay(nhieuMay, n);
            ghiDanhSachNguoiThueTrucTiep(thueNhieuMay, n);
        } else if (y == 8) {
            system("cls");
            cout << bright_yellow << "\nMENU/THIET LAP GIA TIEN" << reset << "\n";
            mt.thietLapGiaTien();
            system("pause");
        } else if (y == 9) {
            system("cls");
            thongTinGioiThieu();
            system("pause");
        } else if (y == 10) {
            system("cls");
            cout << bright_green << "\n\t(!) Dang xuat thanh cong" << reset << "\n";
            system("pause");

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
                cout << "\n\t(!) Tap tin khong ton tai\n";
                system("pause");
            } else {
                fileOut << setw(25) << left << "| " + thoiGianDangXuat << "|";
                fileOut << setw(30) << left << " " + ten << "|";
                fileOut << setw(12) << left << " Dang xuat"
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
        cout << "\nXin chao, " << ten << "\n\n";
        cout << "*---------------------------------------------------*\n";
        cout << "|" << on_blue << "                                                   " << reset << "|\n";
        cout << "|" << on_blue << "              ~  QUAN LY STU CYBER  ~              " << reset << "|\n";
        cout << "|" << on_blue << "                                                   " << reset << "|\n";
        cout << "*---------------------------------------------------*\n";
        cout << "|" << on_magenta << "     ->1.   Xem tinh trang may                     " << reset << "|\n";
        cout << "|      2.   Mo may truc tiep                        |\n";
        cout << "|      3.   Thanh toan                              |\n";
        cout << "|      4.   Thong tin gioi thieu                    |\n";
        cout << "|      0.   Dang xuat                               |\n";
        cout << "*---------------------------------------------------*\n";
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
                cout << "\nXin chao, " << ten << "\n\n";
                cout << "*---------------------------------------------------*\n";
                cout << "|" << on_blue << "                                                   " << reset << "|\n";
                cout << "|" << on_blue << "              ~  QUAN LY STU CYBER  ~              " << reset << "|\n";
                cout << "|" << on_blue << "                                                   " << reset << "|\n";
                cout << "*---------------------------------------------------*\n";
                cout << "|" << on_magenta << "     ->1.   Xem tinh trang may                     " << reset << "|\n";
                cout << "|      2.   Mo may truc tiep                        |\n";
                cout << "|      3.   Thanh toan                              |\n";
                cout << "|      4.   Thong tin gioi thieu                    |\n";
                cout << "|      0.   Dang xuat                               |\n";
                cout << "*---------------------------------------------------*\n";
            } else if (y == 1) {
                cout << "\nXin chao, " << ten << "\n\n";
                cout << "*---------------------------------------------------*\n";
                cout << "|" << on_blue << "                                                   " << reset << "|\n";
                cout << "|" << on_blue << "              ~  QUAN LY STU CYBER  ~              " << reset << "|\n";
                cout << "|" << on_blue << "                                                   " << reset << "|\n";
                cout << "*---------------------------------------------------*\n";
                cout << "|      1.   Xem tinh trang may                      |\n";
                cout << "|" << on_magenta << "     ->2.   Mo may truc tiep                       " << reset << "|\n";
                cout << "|      3.   Thanh toan                              |\n";
                cout << "|      4.   Thong tin gioi thieu                    |\n";
                cout << "|      0.   Dang xuat                               |\n";
                cout << "*---------------------------------------------------*\n";
            } else if (y == 2) {
                cout << "\nXin chao, " << ten << "\n\n";
                cout << "*---------------------------------------------------*\n";
                cout << "|" << on_blue << "                                                   " << reset << "|\n";
                cout << "|" << on_blue << "              ~  QUAN LY STU CYBER  ~              " << reset << "|\n";
                cout << "|" << on_blue << "                                                   " << reset << "|\n";
                cout << "*---------------------------------------------------*\n";
                cout << "|      1.   Xem tinh trang may                      |\n";
                cout << "|      2.   Mo may truc tiep                        |\n";
                cout << "|" << on_magenta << "     ->3.   Thanh toan                             " << reset << "|\n";
                cout << "|      4.   Thong tin gioi thieu                    |\n";
                cout << "|      0.   Dang xuat                               |\n";
                cout << "*---------------------------------------------------*\n";
            } else if (y == 3) {
                cout << "\nXin chao, " << ten << "\n\n";
                cout << "*---------------------------------------------------*\n";
                cout << "|" << on_blue << "                                                   " << reset << "|\n";
                cout << "|" << on_blue << "              ~  QUAN LY STU CYBER  ~              " << reset << "|\n";
                cout << "|" << on_blue << "                                                   " << reset << "|\n";
                cout << "*---------------------------------------------------*\n";
                cout << "|      1.   Xem tinh trang may                      |\n";
                cout << "|      2.   Mo may truc tiep                        |\n";
                cout << "|      3.   Thanh toan                              |\n";
                cout << "|" << on_magenta << "     ->4.   Thong tin gioi thieu                   " << reset << "|\n";
                cout << "|      0.   Dang xuat                               |\n";
                cout << "*---------------------------------------------------*\n";
            } else if (y == 4) {
                cout << "\nXin chao, " << ten << "\n\n";
                cout << "*---------------------------------------------------*\n";
                cout << "|" << on_blue << "                                                   " << reset << "|\n";
                cout << "|" << on_blue << "              ~  QUAN LY STU CYBER  ~              " << reset << "|\n";
                cout << "|" << on_blue << "                                                   " << reset << "|\n";
                cout << "*---------------------------------------------------*\n";
                cout << "|      1.   Xem tinh trang may                      |\n";
                cout << "|      2.   Mo may truc tiep                        |\n";
                cout << "|      3.   Thanh toan                              |\n";
                cout << "|      4.   Thong tin gioi thieu                    |\n";
                cout << "|" << on_magenta << "     ->0.   Dang xuat                              " << reset << "|\n";
                cout << "*---------------------------------------------------*\n";
            } else
                goto MENU_NHANVIEN;
        }
        if (y == 0) {
        MENU_NHANVIEN_TINHTRANGMAY:
            bool kiemTra = true;
            int c, y = 0;
            system("cls");
            cout << bright_yellow << "\nMENU/TINH TRANG MAY" << reset << "\n";
            cout << "*-----------------------------------------*\n";
            cout << "|" << on_magenta << "     ->1. May trong                      " << reset << "|\n";
            cout << "|      2. May day                         |\n";
            cout << "|      3. Tat ca                          |\n";
            cout << "|      0. Tro ve                          |\n";
            cout << "*-----------------------------------------*\n";
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
                    cout << bright_yellow << "\nMENU/TINH TRANG MAY" << reset << "\n";
                    cout << "*-----------------------------------------*\n";
                    cout << "|" << on_magenta << "     ->1. May trong                      " << reset << "|\n";
                    cout << "|      2. May day                         |\n";
                    cout << "|      3. Tat ca                          |\n";
                    cout << "|      0. Tro ve                          |\n";
                    cout << "*-----------------------------------------*\n";
                } else if (y == 1) {
                    cout << bright_yellow << "\nMENU/TINH TRANG MAY" << reset << "\n";
                    cout << "*-----------------------------------------*\n";
                    cout << "|      1. May trong                       |\n";
                    cout << "|" << on_magenta << "     ->2. May day                        " << reset << "|\n";
                    cout << "|      3. Tat ca                          |\n";
                    cout << "|      0. Tro ve                          |\n";
                    cout << "*-----------------------------------------*\n";
                } else if (y == 2) {
                    cout << bright_yellow << "\nMENU/TINH TRANG MAY" << reset << "\n";
                    cout << "*-----------------------------------------*\n";
                    cout << "|      1. May trong                       |\n";
                    cout << "|      2. May day                         |\n";
                    cout << "|" << on_magenta << "     ->3. Tat ca                         " << reset << "|\n";
                    cout << "|      0. Tro ve                          |\n";
                    cout << "*-----------------------------------------*\n";
                } else if (y == 3) {
                    cout << bright_yellow << "\nMENU/TINH TRANG MAY" << reset << "\n";
                    cout << "*-----------------------------------------*\n";
                    cout << "|      1. May trong                       |\n";
                    cout << "|      2. May day                         |\n";
                    cout << "|      3. Tat ca                          |\n";
                    cout << "|" << on_magenta << "     ->0. Tro ve                         " << reset << "|\n";
                    cout << "*-----------------------------------------*\n";
                } else
                    goto MENU_NHANVIEN_TINHTRANGMAY;
            }
            if (y == 0) {
                system("cls");
                cout << bright_yellow << "\nMENU/TINH TRANG MAY/MAY TRONG" << reset << "\n";
                xuatDanhSachCacMayTrong(nhieuMay, n);
                system("pause");
            } else if (y == 1) {
                system("cls");
                cout << bright_yellow << "\nMENU/TINH TRANG MAY/MAY DAY" << reset << "\n";
                xuatDanhSachCacMayDay(nhieuMay, n);
                system("pause");
            } else if (y == 2) {
                system("cls");
                cout << bright_yellow << "\nMENU/TINH TRANG MAY/TAT CA" << reset << "\n";
                xuatDanhSachCacMay(nhieuMay, n);
                system("pause");
            } else if (y == 3) {
                system("cls");
                goto MENU_NHANVIEN;
            } else
                goto MENU_NHANVIEN_TINHTRANGMAY;
            goto MENU_NHANVIEN_TINHTRANGMAY;
        } else if (y == 1) {
            system("cls");
            cout << bright_yellow << "\nMENU/MO MAY TRUC TIEP" << reset << "\n";
            thueNhieuMay.moMayTrucTiep(nhieuMay, n);
            ghiDanhSachCacMay(nhieuMay, n);
            ghiDanhSachNguoiThueTrucTiep(thueNhieuMay, n);
        } else if (y == 2) {
            system("cls");
            cout << bright_yellow << "\nMENU/THANH TOAN" << reset << "\n";
            thueNhieuMay.thanhToan(nhieuMay, n);
            ghiDanhSachCacMay(nhieuMay, n);
            ghiDanhSachNguoiThueTrucTiep(thueNhieuMay, n);
        } else if (y == 3) {
            system("cls");
            thongTinGioiThieu();
            system("pause");
        } else if (y == 4) {
            system("cls");
            cout << bright_green << "\n\t(!) Dang xuat thanh cong" << reset << "\n";
            system("pause");

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
                cout << "\n\t(!) Tap tin khong ton tai\n";
                system("pause");
            } else {
                fileOut << setw(25) << left << "| " + thoiGianDangXuat << "|";
                fileOut << setw(30) << left << " " + ten << "|";
                fileOut << setw(12) << left << " Dang xuat"
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
            cout << bright_red << "\n\t(*) Tai du lieu thanh cong (*)" << reset << "\n";
        tienTrinh += 0.2;
        Sleep(350);
        system("cls");
    }
    cout << endl;
}

void nhapDuLieuGiaTien(MayTinh &mt) {
    mt.docGiaTien();
    if (mt.giaTienThuong == 0 || mt.giaTienCaoCap == 0) {
        cout << bright_red << "\n\t(!) Chua thiet lap gia tien. Hay thiet lap gia tien bay gio" << reset << "\n";
        system("pause");
        mt.thietLapGiaTien();
    } else
        cout << bright_red << "\n\t(*) Dang nhap du lieu gia tien (*)" << reset << "\n";
}

void nhapDuLieuDanhSachMayTinh(MayTinh nhieuMay[], int &n) {
    string fileName = "../File/maytinh/danhsachmaytinh.txt";
    int x = kiemTraFileTrong(fileName);
    if (x == -1)
        n = 0;
    else {
        cout << bright_red << "\n\t(*) Dang nhap du lieu danh sach may tinh (*)" << reset << "\n";
        docDanhSachCacMay(nhieuMay, n);
    }
}

void nhapDuLieuDanhSachNhanVien(DanhSachNhanVien &dsnv) {
    cout << bright_red << "\n\t(*) Dang nhap du lieu danh sach nhan vien (*)" << reset << "\n";
    docDanhSachNhanVien(dsnv);
}

void nhapDuLieuDanhSachNguoiThueTrucTiep(ThueNhieuMay &thueNhieuMay, MayTinh nhieuMay[], int &n) {
    thueNhieuMay.taoListThueMotMay();
    cout << bright_red << "\n\t(*) Dang nhap du lieu danh sach nguoi thue truc tiep (*)" << reset << "\n";
    docDanhSachNguoiThueTrucTiep(thueNhieuMay, nhieuMay, n);
}

void thongTinGioiThieu() {
    cout << bright_yellow << "\nMENU/THONG TIN GIOI THIEU" << reset << "\n";
    cout << on_bright_blue << "\n*-------------------- DAI HOC CONG NGHE SAI GON --------------------*" << reset;
    cout << on_bright_blue << "\n| * Do an:      Quan Ly Phong Game                                  |" << reset;
    cout << on_bright_blue << "\n|                                                                   |" << reset;
    cout << on_bright_blue << "\n| * Giang vien: Hoang Khue                                          |" << reset;
    cout << on_bright_blue << "\n|                                                                   |" << reset;
    cout << on_bright_blue << "\n| * Sinh vien:  1. Tran Van Quoc Thang - DH52007101 - D20_TH11      |" << reset;
    cout << on_bright_blue << "\n|               2. Vo Xuan Lam - DH52006929 - D20_TH11              |" << reset;
    cout << on_bright_blue << "\n|               3. Dang Xuan Sang - DH52006904 - D20_TH11           |" << reset;
    cout << on_bright_blue << "\n|               4. Tran Nguyen Thanh Sang - DH52007102 - D20_TH11   |" << reset;
    cout << on_bright_blue << "\n|               5. Do Tran Hai Son - DH52007024 - D20_TH11          |" << reset;
    cout << on_bright_blue << "\n*------------------------------- 2022 ------------------------------*" << reset << "\n";
}