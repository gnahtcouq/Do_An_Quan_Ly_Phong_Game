#pragma once
#include <conio.h>
#include <string.h>
#include <windows.h>

#include <cstdlib>  // rand , srand
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

struct MayTinh {
    string maMay;
    int soMay;           // số máy
    bool kieuMay;        // kiểu máy: - 0:thường   1:cao cấp
    bool tinhTrang = 0;  // tình trạng máy - 0:trống   1:đã được sử dụng
};

struct DanhSachMayTinh {
    MayTinh *ds[100];
    int soLuong = 0;
};

// // --------------------- Danh sách chi tiết hóa đơn ---------------------
// struct ChiTietHoaDon {
//     string soMay;
//     int donGia;
//     float VAT;  // % thuế
// };

// struct DanhSachChiTietHoaDon {
//     ChiTietHoaDon ds[20];
//     int soLuong = 0;
// };

// // --------------------- Danh sách hóa đơn ---------------------
// struct HoaDon {
//     // data
//     string soHoaDon;
//     string ngayLapHoaDon;
//     char loai;  // X: xuất - N: nhập
//     // dschitiet hd
//     DanhSachChiTietHoaDon danhsachchitiethd;
//     // pointer
//     HoaDon *pNext;
// };

// struct DanhSachHoaDon {
//     HoaDon *pHead = NULL;
//     int soLuong = 0;
// };

// --------------------- Danh sách khách hàng ---------------------
struct KhachHang {
    // data
    int maKH;
    string taiKhoan;
    string matKhau;
    string soDienThoai;
    //*dshd
    // DanhSachHoaDon danhsachhd;
    // pointer
    KhachHang *pleft;
    KhachHang *pright;
};
typedef struct KhachHang *tree;

struct DanhSachKhachHang {
    tree TREE = NULL;
    int soLuong = 0;
};
