#pragma once
#include "KhachHang.hpp"
#include "NhieuMay.hpp"
#include "ThueNhieuMay.hpp"

#define MAX 200

void menu();
void nhapDuLieuNhieuMay(MayTinh nhieuMay[], int &n);
void nhapDuLieuDanhSachKhachHang(DanhSachKhachHang &dskh);
void nhapDuLieuDanhSachNguoiThueTrucTiep(ThueNhieuMay &thueNhieuMay, MayTinh nhieuMay[], int n);
void luuFile(ThueNhieuMay thueNhieuMay, MayTinh nhieuMay[], int n);

void menu() {
    int choose, n, nds;
    bool exit = false, fileSaved = false;
    MayTinh mt;
    ThueNhieuMay thueNhieuMay;
    MayTinh *nhieuMay = new MayTinh[MAX];  // tạo mảng động với MAX phần tử
    KhachHang *ds[MAX];
    DanhSachKhachHang dskh;
    nhapDuLieuNhieuMay(nhieuMay, n);
    nhapDuLieuDanhSachKhachHang(dskh);
    nhapDuLieuDanhSachNguoiThueTrucTiep(thueNhieuMay, nhieuMay, n);
    cout << "\n";
    do {
        system("cls");
        cout << "*--------------------------------------------------*\n";
        cout << "|               QUAN LY PHONG GAME                 |\n";
        cout << "*--------------------------------------------------*\n";
        cout << "|    1. Them may tinh                              |\n";
        cout << "|    2. Xoa may tinh                               |\n";
        cout << "|    3. Xem tinh trang may                         |\n";
        cout << "|    4. Them khach hang                            |\n";
        cout << "|    5. Xoa khach hang                             |\n";
        cout << "|    6. Chinh sua thong tin khach hang             |\n";
        cout << "|    7. Xem danh sach khach hang                   |\n";
        cout << "|    8. In danh sach nguoi thue truc tiep          |\n";
        cout << "|    9. Luu thay doi                               |\n";
        cout << "|    10. Mo may truc tiep                          |\n";
        cout << "|    11. Thanh toan                                |\n";
        cout << "*--------------------------------------------------*\n";
        cout << "|            0. Thoat chuong trinh                 |\n";
        cout << "*--------------------------------------------------*\n";
        cout << "\tLua chon cua ban -> ";
        cin >> choose;
        fflush(stdin);
        switch (choose) {
            case 1: {
                system("cls");
                cout << "\n\t1. THEM MAY TINH\n";
                mt.themMayTinh(nhieuMay, n);
                sapXepDanhSachMayTinh(nhieuMay, n);
                break;
            }
            case 2: {
                system("cls");
                cout << "\n\t2. XOA MAY TINH\n";
                xuatDanhSachCacMay(nhieuMay, n);
                mt.xoaMayTinh(nhieuMay, n);
                sapXepDanhSachMayTinh(nhieuMay, n);
                break;
            }
            case 3: {
                int choose;
                bool exit = false;
                do {
                    system("cls");
                    cout << "*-----------------------------------------*\n";
                    cout << "|             TINH TRANG MAY              |\n";
                    cout << "|-----------------------------------------|\n";
                    cout << "|      1. May trong                       |\n";
                    cout << "|      2. May day                         |\n";
                    cout << "|      3. Tat ca                          |\n";
                    cout << "|-----------------------------------------|\n";
                    cout << "|              0. Tro ve                  |\n";
                    cout << "*-----------------------------------------*\n";
                    cout << "\tLua chon cua ban -> ";
                    cin >> choose;
                    switch (choose) {
                        case 1: {
                            system("cls");
                            cout << "\n\t1. MAY TRONG\n";
                            xuatDanhSachCacMayTrong(nhieuMay, n);
                            system("pause");
                            break;
                        }
                        case 2: {
                            system("cls");
                            cout << "\n\t2. MAY DAY\n";
                            xuatDanhSachCacMayDay(nhieuMay, n);
                            system("pause");
                            break;
                        }
                        case 3: {
                            system("cls");
                            cout << "\n\t3. TAT CA\n";
                            xuatDanhSachCacMay(nhieuMay, n);
                            system("pause");
                            break;
                        }
                        case 0:
                            exit = true;
                            break;
                        default:
                            cout << "\n\t(!) Lua chon khong hop le (!)\n";
                            system("pause");
                            break;
                    }
                } while (!exit);
                break;
            }
            case 4: {
                system("cls");
                cout << "\n\t4. THEM KHACH HANG\n";
                nhapMotKhachHang(dskh);
                break;
            }
            case 5: {
                system("cls");
                nds = 0;
                cout << "\n\t5. XOA KHACH HANG\n";
                chuyenCaySangMang(dskh.TREE, ds, nds);
                sapXepDanhSachKhachHang(ds, nds);
                inDanhSachKhachHangTheoChieuNgang(ds, nds);
                xoaKhachHang(dskh);
                giaiPhongDanhSachKhachHang(ds, nds);
                break;
            }
            case 6: {
                system("cls");
                cout << "\n\t6. CHINH SUA THONG TIN KHACH HANG\n";
                chinhSuaThongTinKhachHang(dskh);
                break;
            }
            case 7: {
                system("cls");
                nds = 0;
                cout << "\n\t5. XEM DANH SACH KHACH HANG\n";
                chuyenCaySangMang(dskh.TREE, ds, nds);
                sapXepDanhSachKhachHang(ds, nds);
                inDanhSachKhachHangTheoChieuNgang(ds, nds);
                giaiPhongDanhSachKhachHang(ds, nds);
                system("pause");
                break;
            }
            case 8: {
                break;
            }
            case 9: {
                system("cls");
                cout << "\n\t9. LUU THAY DOI\n";
                luuFile(thueNhieuMay, nhieuMay, n);
                fileSaved = true;
                system("pause");
                break;
            }
            case 10: {
                system("cls");
                cout << "\n\t10. MO MAY TRUC TIEP\n";
                if (hetMay(nhieuMay, n)) {  // nếu hết máy
                    system("cls");
                    cout << "\n\t(!) Het may (!)\n";
                } else {
                    xuatDanhSachCacMayTrong(nhieuMay, n);
                    cout << "\tNhap may can mo -> ";
                    thueNhieuMay.moMayTrucTiep(nhieuMay, n);
                    system("pause");
                }
                break;
            }
            case 11: {
                system("cls");
                cout << "\n\t11. THANH TOAN\n";
                if (thueNhieuMay.pHead == NULL)
                    cout << "\n\t(*) Danh sach tai khoan trong (*)\n";
                else {
                    thueNhieuMay.thanhToan(nhieuMay, n);
                    xuatDanhSachCacMayDay(nhieuMay, n);
                }
                system("pause");
                break;
            }
            case 0: {
                if (fileSaved) {
                    cout << "\n\t(*) Thoat chuong trinh 5s (*)\n";
                    Sleep(5000);
                    exit = true;
                } else {
                    system("cls");
                    cout << "\n\t0. THOAT CHUONG TRINH\n";
                    char c;
                    cout << "\n(!) Ban chua luu thay doi (!)\n";
                    do {
                        fflush(stdin);
                        cout << "\n(?) Xac nhan thoat ma khong luu thay doi (y/n) (?): ";
                        cin >> c;
                        if (c != 'y' && c != 'n')
                            cout << "\n(!) Lua chon khong hop le (!) - Nhap lai (!)";
                        else {
                            if (c == 'y') {
                                cout << "\n\t(*) Thoat chuong trinh sau 5s (*)\n";
                                Sleep(5000);
                                exit = true;
                            } else
                                break;
                        }
                    } while (c != 'y' && c != 'n');
                }
                break;
            }
            default:
                cout << "\n\t(!) Lua chon khong hop le (!)\n";
                system("pause");
                break;
        }
    } while (!exit);                      // exit == true
    delete[] nhieuMay;                    // giải phóng bộ nhớ của ds máy tính
    giaiPhongDanhSachKhachHang(ds, nds);  // giải phóng bộ nhớ của ds khách hàng
}

void nhapDuLieuNhieuMay(MayTinh nhieuMay[], int &n) {
    system("cls");
    cout << "\n\t(*) Dang nhap du lieu danh sach may tinh (*)\n";
    Sleep(1000);  // delay 2s
    docDanhSachCacMay(nhieuMay, n);
}

void nhapDuLieuDanhSachKhachHang(DanhSachKhachHang &dskh) {
    system("cls");
    cout << "\n\t(*) Dang nhap du lieu danh sach khach hang (*)\n";
    Sleep(1000);  // delay 2s
    docDanhSachKhachHang(dskh);
}

void nhapDuLieuDanhSachNguoiThueTrucTiep(ThueNhieuMay &thueNhieuMay, MayTinh nhieuMay[], int n) {
    thueNhieuMay.createList();
    system("cls");
    cout << "\n\t(*) Dang nhap du lieu danh sach nguoi thue truc tiep (*)\n";
    Sleep(1000);  // delay 2s
    docDanhSachNguoiThueTrucTiep(thueNhieuMay, nhieuMay, n);
}

void luuFile(ThueNhieuMay thueNhieuMay, MayTinh nhieuMay[], int n) {
    cout << "\n\t(*) Dang luu du lieu danh sach may tinh (*)\n";
    Sleep(1000);  // delay 2s
    ghiDanhSachCacMay(nhieuMay, n);
    cout << "\n\n\t(*) Dang luu du lieu danh sach nguoi thue (*)\n";
    Sleep(1000);  // delay 2s
    ghiDanhSachNguoiThueTrucTiep(thueNhieuMay);
    system("cls");
    cout << "\n\t(*) Luu thanh cong (*)\n";
}
