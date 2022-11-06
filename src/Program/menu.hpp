#pragma once
#include "NhieuMay.hpp"
#include "ThueNhieuMay.hpp"

void menu();
void nhapDuLieuNhieuMay(MayTinh nhieuMay[], int &n);
void nhapDuLieuDanhSachNguoiThueTrucTiep(ThueNhieuMay &thueNhieuMay, MayTinh nhieuMay[], int n);

void menu() {
    int choose, n;
    bool exit = false;
    MayTinh mt;
    MayTinh *nhieuMay = new MayTinh[200];  // tạo mảng động với 200 phần tử
    ThueNhieuMay thueNhieuMay;
    nhapDuLieuNhieuMay(nhieuMay, n);
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
            case 0: {
                break;
            }
            default:
                cout << "\n\t(!) Lua chon khong hop le (!)\n";
                system("pause");
                break;
        }
    } while (!exit);    // exit == true
    delete[] nhieuMay;  // giải phóng bộ nhớ của ds máy tính
}

void nhapDuLieuNhieuMay(MayTinh nhieuMay[], int &n) {
    system("cls");
    cout << "\n\t(*) Dang nhap du lieu danh sach may tinh (*)\n";
    Sleep(1000);  // delay 2s
    docDanhSachCacMay(nhieuMay, n);
}

void nhapDuLieuDanhSachNguoiThueTrucTiep(ThueNhieuMay &thueNhieuMay, MayTinh nhieuMay[], int n) {
    thueNhieuMay.createList();
    system("cls");
    cout << "\n\t(*) Dang nhap du lieu danh sach nguoi thue truc tiep (*)\n";
    Sleep(1000);  // delay 2s
    docDanhSachNguoiThueTrucTiep(thueNhieuMay, nhieuMay, n);
}