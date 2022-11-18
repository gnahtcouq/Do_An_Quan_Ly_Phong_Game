#pragma once
#include "NhanVien.hpp"
#include "QuanLy.hpp"
#include "ThueNhieuMay.hpp"

#define MAX 200

void menu();
void loading(MayTinh &mt, MayTinh nhieuMay[], int &n, DanhSachNhanVien &dsnv, ThueNhieuMay &thueNhieuMay);
void khoiTaoSoLuongDauVaoCuaFile();
void nhapDuLieuGiaTien(MayTinh &mt);
void nhapDuLieuNhieuMay(MayTinh nhieuMay[], int &n);
void nhapDuLieuDanhSachNhanVien(DanhSachNhanVien &dsnv);
void nhapDuLieuDanhSachNguoiThueTrucTiep(ThueNhieuMay &thueNhieuMay, MayTinh nhieuMay[], int &n);
void luuFile(ThueNhieuMay thueNhieuMay, MayTinh nhieuMay[], int n);

void menu() {
    khoiTaoSoLuongDauVaoCuaFile();
    int luaChon;
    bool thoat = false;
    //
    int n;
    MayTinh mt;
    ThueNhieuMay thueNhieuMay;
    MayTinh *nhieuMay = new MayTinh[MAX];  // tạo mảng động với MAX phần tử
    //
    DanhSachNhanVien dsnv;
    khoiTaoDanhSachNhanVien(dsnv);
    //
    loading(mt, nhieuMay, n, dsnv, thueNhieuMay);
    //
    int phanQuyen;
    string ten;
    dangNhap(dsnv, phanQuyen, ten);
    //
    do {
        system("cls");
        cout << "\nXin chao, " << ten << "\n\n";
        cout << "*---------------------------------------------------*\n";
        cout << "|              ~  QUAN LY STU CYBER  ~              |\n";
        cout << "*---------------------------------------------------*\n";
        cout << "|      1.   Quan ly may tinh                        |\n";
        cout << "|      2.   Quan ly nhan vien                       |\n";
        cout << "|      3.   Xem tinh trang may                      |\n";
        cout << "|      4.   Lich su thanh toan                      |\n";
        cout << "|      10.  Mo may truc tiep                        |\n";
        cout << "|      11.  Thanh toan                              |\n";
        cout << "|      12.  Thiet lap gia tien                      |\n";
        cout << "|      0.   Dang xuat                               |\n";
        cout << "*---------------------------------------------------*\n";
        cout << "\tLua chon cua ban -> ";
        cin >> luaChon;
        fflush(stdin);
        switch (luaChon) {
            case 1: {
                int luaChon;
                bool thoat = false;
                do {
                    system("cls");
                    cout << "\nMENU/QUAN LY MAY TINH\n";
                    cout << "*----------------------------------------*\n";
                    cout << "|      1. Them may tinh                  |\n";
                    cout << "|      2. Xoa may tinh                   |\n";
                    cout << "|      0. Tro ve                         |\n";
                    cout << "*----------------------------------------*\n";
                    cout << "\tLua chon cua ban -> ";
                    cin >> luaChon;
                    switch (luaChon) {
                        case 1: {
                            system("cls");
                            cout << "\nMENU/QUAN LY MAY TINH/THEM MAY TINH\n";
                            if (n != 0)
                                xuatDanhSachCacMay(nhieuMay, n);
                            mt.themMayTinh(nhieuMay, n);
                            sapXepDanhSachMayTinh(nhieuMay, n);
                            ThueMotMay r;
                            int soMay = n;
                            r.maytinh = layViTriCuaMay(nhieuMay, n, soMay);
                            r.maytinh->soMay = soMay;
                            r.maytinh->gioBD = 0;
                            r.maytinh->phutBD = 0;
                            r.maytinh->giayBD = 0;
                            r.maytinh->ngayBD = 0;
                            r.maytinh->thangBD = 0;
                            r.maytinh->namBD = 0;
                            thueNhieuMay.addNodeInTail(r);
                            luuFile(thueNhieuMay, nhieuMay, n);
                            break;
                        }
                        case 2: {
                            system("cls");
                            cout << "\nMENU/QUAN LY MAY TINH/XOA MAY TINH\n";
                            if (n != 0) {
                                xuatDanhSachCacMay(nhieuMay, n);
                                mt.xoaMayTinh(nhieuMay, n);
                                sapXepDanhSachMayTinh(nhieuMay, n);
                                thueNhieuMay.removeNodeInTail();
                                luuFile(thueNhieuMay, nhieuMay, n);
                            } else {
                                cout << "\n\t(!) Danh sach may tinh trong\n";
                                system("pause");
                            }
                            break;
                        }
                        case 0:
                            thoat = true;
                            break;
                        default:
                            cout << "\n\t(!) Lua chon khong hop le\n";
                            system("pause");
                            break;
                    }
                } while (!thoat);
                break;
            }
            case 2: {
                int luaChon;
                bool thoat = false;
                do {
                    system("cls");
                    cout << "\nMENU/QUAN LY NHAN VIEN\n";
                    cout << "*----------------------------------------*\n";
                    cout << "|      1. Them nhan vien                 |\n";
                    cout << "|      2. Xoa nhan vien                  |\n";
                    cout << "|      3. Chinh sua thong tin            |\n";
                    cout << "|      4. Xem danh sach                  |\n";
                    cout << "|      0. Tro ve                         |\n";
                    cout << "*----------------------------------------*\n";
                    cout << "\tLua chon cua ban -> ";
                    cin >> luaChon;
                    switch (luaChon) {
                        case 1: {
                            system("cls");
                            cout << "\nMENU/QUAN LY NHAN VIEN/THEM NHAN VIEN\n";
                            nhapMotNhanVien(dsnv);
                            ghiDanhSachNhanVien(dsnv);
                            system("pause");
                            break;
                        }
                        case 2: {
                            system("cls");
                            cout << "\nMENU/QUAN LY NHAN VIEN/XOA NHAN VIEN\n";
                            if (dsnv) {
                                inDanhSachNhanVien(dsnv);
                                xoaMotNhanVien(dsnv);
                                ghiDanhSachNhanVien(dsnv);
                            } else
                                cout << "\n\t(!) Danh sach nhan vien trong\n";
                            system("pause");
                            break;
                        }
                        case 3: {
                            system("cls");
                            cout << "\nMENU/QUAN LY NHAN VIEN/CHINH SUA THONG TIN\n";
                            cout << "\n\t(!) Tinh nang dang duoc phat trien\n";
                            system("pause");
                            break;
                        }
                        case 4: {
                            system("cls");
                            cout << "\nMENU/QUAN LY NHAN VIEN/XEM DANH SACH\n";
                            if (dsnv)
                                inDanhSachNhanVien(dsnv);
                            else
                                cout << "\n\t(!) Danh sach nhan vien trong\n";
                            system("pause");
                        }
                        case 0:
                            thoat = true;
                            break;
                        default:
                            cout << "\n\t(!) Lua chon khong hop le\n";
                            system("pause");
                            break;
                    }
                } while (!thoat);
                break;
            }
            case 3: {
                int luaChon;
                bool thoat = false;
                do {
                    system("cls");
                    cout << "\nMENU/TINH TRANG MAY\n";
                    cout << "*-----------------------------------------*\n";
                    cout << "|      1. May trong                       |\n";
                    cout << "|      2. May day                         |\n";
                    cout << "|      3. Tat ca                          |\n";
                    cout << "|      0. Tro ve                          |\n";
                    cout << "*-----------------------------------------*\n";
                    cout << "\tLua chon cua ban -> ";
                    cin >> luaChon;
                    switch (luaChon) {
                        case 1: {
                            system("cls");
                            cout << "\nMENU/TINH TRANG MAY/MAY TRONG\n";
                            xuatDanhSachCacMayTrong(nhieuMay, n);
                            system("pause");
                            break;
                        }
                        case 2: {
                            system("cls");
                            cout << "\nMENU/TINH TRANG MAY/MAY DAY\n";
                            xuatDanhSachCacMayDay(nhieuMay, n);
                            system("pause");
                            break;
                        }
                        case 3: {
                            system("cls");
                            cout << "\nMENU/TINH TRANG MAY/TAT CA\n";
                            xuatDanhSachCacMay(nhieuMay, n);
                            system("pause");
                            break;
                        }
                        case 0:
                            thoat = true;
                            break;
                        default:
                            cout << "\n\t(!) Lua chon khong hop le\n";
                            system("pause");
                            break;
                    }
                } while (!thoat);
                break;
            }
            case 4: {
                system("cls");
                cout << "\nMENU/LICH SU THANH TOAN\n";
                string fileName = "../File/lichsu/lichsuthanhtoan.txt";
                if (kiemTraFileTrong(fileName) != -1) {
                    cout << "*------------------------*-------------------------------*----------------*---------------*--------------------------*\n";
                    cout << setw(25) << left << "| Thoi gian bat dau"
                         << "|\t";
                    cout << setw(25) << left << "Thoi gian ket thuc"
                         << "|\t";
                    cout << setw(10) << left << "So may"
                         << "|\t";
                    cout << setw(10) << left << "Kieu may"
                         << "|\t";
                    cout << setw(20) << right << "So tien"
                         << " |\n";
                    cout << "*------------------------*-------------------------------*----------------*---------------*--------------------------*\n";
                    docLichSuThanhToan(fileName);
                    cout << "*------------------------*-------------------------------*----------------*---------------*--------------------------*\n";
                } else
                    cout << "\n\t(!) Lich su thanh toan trong\n";
                system("pause");
                break;
            }
            case 5: {
                break;
            }
            case 6: {
                break;
            }
            case 7: {
                break;
            }
            case 8: {
                break;
            }
            case 9: {
                break;
            }
            case 10: {
                system("cls");
                cout << "\nMENU/MO MAY TRUC TIEP\n";
                thueNhieuMay.moMayTrucTiep(nhieuMay, n);
                luuFile(thueNhieuMay, nhieuMay, n);
                break;
            }
            case 11: {
                system("cls");
                cout << "\nMENU/THANH TOAN\n";
                thueNhieuMay.thanhToan(nhieuMay, n);
                luuFile(thueNhieuMay, nhieuMay, n);
                break;
            }
            case 12: {
                system("cls");
                cout << "\nMENU/THIET LAP GIA TIEN\n";
                mt.thietLapGiaTien();
                system("pause");
                break;
            }
            case 0: {
                system("cls");
                cout << "\n\t(!) Dang xuat thanh cong\n";
                system("pause");
                thoat = true;
                menu();
                break;
            }
            default:
                cout << "\n\t(!) Lua chon khong hop le\n";
                system("pause");
                break;
        }
    } while (!thoat);           // thoat == true
    delete[] nhieuMay;          // giải phóng bộ nhớ của ds máy tính
    xoaDanhSachNhanVien(dsnv);  // giải phóng bộ nhớ của ds khách hàng
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
                cout << "=";
            else if (i == viTri)
                cout << ">";
            else
                cout << " ";
        }
        cout << "] " << int(tienTrinh * 100.0) << " %\r";
        cout.flush();
        if (tienTrinh == float(0.2))
            nhapDuLieuGiaTien(mt);
        else if (tienTrinh == float(0.4))
            nhapDuLieuNhieuMay(nhieuMay, n);
        else if (tienTrinh == float(0.6))
            nhapDuLieuDanhSachNhanVien(dsnv);
        else if (tienTrinh == float(0.8))
            nhapDuLieuDanhSachNguoiThueTrucTiep(thueNhieuMay, nhieuMay, n);
        else if (tienTrinh == float(1))
            cout << "\n\t(*) Tai du lieu thanh cong (*)\n";
        tienTrinh += 0.2;
        Sleep(350);
        system("cls");
    }
    cout << endl;
}

void khoiTaoSoLuongDauVaoCuaFile() {
    string fileName = "../File/maytinh/momaytructiep.txt";
    int x = kiemTraFileTrong(fileName);
    if (x == -1) {
        ofstream fileOut(fileName);
        fileOut << '0';
        fileOut.close();
    }
}

void nhapDuLieuGiaTien(MayTinh &mt) {
    // system("cls");
    mt.docGiaTien();
    if (mt.giaTienThuong == 0 || mt.giaTienCaoCap == 0) {
        cout << "\n\t(!) Chua thiet lap gia tien. Hay thiet lap gia tien bay gio\n";
        system("pause");
        mt.thietLapGiaTien();
    } else
        cout << "\n\t(*) Dang nhap du lieu gia tien (*)\n";
}

void nhapDuLieuNhieuMay(MayTinh nhieuMay[], int &n) {
    // system("cls");
    string fileName = "../File/maytinh/danhsachmaytinh.txt";
    int x = kiemTraFileTrong(fileName);
    if (x == -1)
        n = 0;
    else {
        cout << "\n\t(*) Dang nhap du lieu danh sach may tinh (*)\n";
        // Sleep(1000);  // delay 2s
        docDanhSachCacMay(nhieuMay, n);
    }
}

void nhapDuLieuDanhSachNhanVien(DanhSachNhanVien &dsnv) {
    // system("cls");
    cout << "\n\t(*) Dang nhap du lieu danh sach nhan vien (*)\n";
    // Sleep(1000);  // delay 2s
    docDanhSachNhanVien(dsnv);
}

void nhapDuLieuDanhSachNguoiThueTrucTiep(ThueNhieuMay &thueNhieuMay, MayTinh nhieuMay[], int &n) {
    // system("cls");
    thueNhieuMay.createList();
    cout << "\n\t(*) Dang nhap du lieu danh sach nguoi thue truc tiep (*)\n";
    // Sleep(1000);  // delay 2s
    docDanhSachNguoiThueTrucTiep(thueNhieuMay, nhieuMay, n);
}

void luuFile(ThueNhieuMay thueNhieuMay, MayTinh nhieuMay[], int n) {
    // cout << "\n\t(*) Dang luu du lieu danh sach may tinh (*)\n";
    // Sleep(1000);  // delay 2s
    ghiDanhSachCacMay(nhieuMay, n);
    // cout << "\n\n\t(*) Dang luu du lieu danh sach nguoi thue (*)\n";
    // Sleep(1000);  // delay 2s
    ghiDanhSachNguoiThueTrucTiep(thueNhieuMay, n);
    system("cls");
    cout << "\n\t(*) Luu thanh cong (*)\n";
}
