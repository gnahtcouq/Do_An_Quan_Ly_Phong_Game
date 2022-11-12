#pragma once
#include "KhachHang.hpp"
#include "NhieuMay.hpp"
#include "QuanLy.hpp"
#include "ThueNhieuMay.hpp"

#define MAX 200

void menu();
void nhapDuLieuGiaTien(MayTinh &mt);
void nhapDuLieuNhieuMay(MayTinh nhieuMay[], int &n);
void nhapDuLieuDanhSachKhachHang(DanhSachKhachHang &dskh);
void nhapDuLieuDanhSachNguoiThueTrucTiep(ThueNhieuMay &thueNhieuMay, MayTinh nhieuMay[], int n);
void luuFile(ThueNhieuMay thueNhieuMay, MayTinh nhieuMay[], int n);

void menu() {
    int luaChon, n, nds;
    bool thoat = false, fileSaved = false;
    MayTinh mt;
    ThueNhieuMay thueNhieuMay;
    MayTinh *nhieuMay = new MayTinh[MAX];  // tạo mảng động với MAX phần tử
    KhachHang *ds[MAX];
    DanhSachKhachHang dskh;
    // dangNhap();
    nhapDuLieuGiaTien(mt);
    nhapDuLieuNhieuMay(nhieuMay, n);
    nhapDuLieuDanhSachKhachHang(dskh);
    nhapDuLieuDanhSachNguoiThueTrucTiep(thueNhieuMay, nhieuMay, n);
    cout << "\n";
    do {
        system("cls");
        cout << "*--------------------------------------------------*\n";
        cout << "|              ~  QUAN LY STU CYBER  ~             |\n";
        cout << "*--------------------------------------------------*\n";
        cout << "|    1. Quan ly may tinh                           |\n";
        cout << "|    2. Quan ly khach hang                         |\n";
        cout << "|    3. Xem tinh trang may                         |\n";
        cout << "|    4. Nap tien                                   |\n";
        cout << "|    9. Luu thay doi                               |\n";
        cout << "|    10. Mo may truc tiep                          |\n";
        cout << "|    11. Thanh toan                                |\n";
        cout << "|    12. Thiet lap gia tien                        |\n";
        cout << "|    0. Thoat chuong trinh                         |\n";
        cout << "*--------------------------------------------------*\n";
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
                            cout << "\nMENU/QUAN LY MAY TINH/THEM MAY TINH";
                            cout << "\n*---------------------------------*\n";
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
                            cout << "\nMENU/QUAN LY MAY TINH/XOA MAY TINH";
                            cout << "\n*--------------------------------*\n";
                            xuatDanhSachCacMay(nhieuMay, n);
                            mt.xoaMayTinh(nhieuMay, n);
                            sapXepDanhSachMayTinh(nhieuMay, n);
                            thueNhieuMay.removeNodeInTail();
                            luuFile(thueNhieuMay, nhieuMay, n);
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
                    cout << "\nMENU/QUAN LY KHACH HANG\n";
                    cout << "*----------------------------------------*\n";
                    cout << "|      1. Them khach hang                |\n";
                    cout << "|      2. Xoa khach hang                 |\n";
                    cout << "|      3. Chinh sua thong tin            |\n";
                    cout << "|      4. Kiem tra so du                 |\n";
                    cout << "|      5. Xem danh sach                  |\n";
                    cout << "|      0. Tro ve                         |\n";
                    cout << "*----------------------------------------*\n";
                    cout << "\tLua chon cua ban -> ";
                    cin >> luaChon;
                    switch (luaChon) {
                        case 1: {
                            system("cls");
                            nds = 0;
                            cout << "\nMENU/QUAN LY KHACH HANG/THEM KHACH HANG";
                            cout << "\n*-------------------------------------*\n";
                            chuyenCaySangMang(dskh.TREE, ds, nds);
                            nhapMotKhachHang(dskh);
                            sapXepDanhSachKhachHang(ds, nds);
                            ghiDanhSachKhachHang(ds, nds);
                            break;
                        }
                        case 2: {
                            system("cls");
                            nds = 0;
                            cout << "\nMENU/QUAN LY KHACH HANG/XOA KHACH HANG";
                            cout << "\n*------------------------------------*\n";
                            chuyenCaySangMang(dskh.TREE, ds, nds);
                            sapXepDanhSachKhachHang(ds, nds);
                            inDanhSachKhachHangTheoChieuNgang(ds, nds);
                            xoaKhachHang(dskh);
                            giaiPhongDanhSachKhachHang(ds, nds);
                            break;
                        }
                        case 3: {
                            system("cls");
                            cout << "\nMENU/QUAN LY KHACH HANG/CHINH SUA THONG TIN";
                            cout << "\n*------------------------------------------*\n";
                            chinhSuaThongTinKhachHang(dskh);
                            break;
                        }
                        case 4: {
                            system("cls");
                            cout << "\nMENU/QUAN LY KHACH HANG/KIEM TRA SO DU";
                            cout << "\n*------------------------------------*\n";
                            nds = 0;
                            chuyenCaySangMang(dskh.TREE, ds, nds);
                            sapXepDanhSachKhachHang(ds, nds);
                            inDanhSachKhachHangTheoChieuNgang(ds, nds);
                            giaiPhongDanhSachKhachHang(ds, nds);
                            xuatThongTinKhachHangTheoTenTaiKhoan();
                            system("pause");
                            break;
                        }
                        case 5: {
                            system("cls");
                            nds = 0;
                            cout << "\nMENU/QUAN LY KHACH HANG/XEM DANH SACH";
                            cout << "\n*-----------------------------------*\n";
                            chuyenCaySangMang(dskh.TREE, ds, nds);
                            sapXepDanhSachKhachHang(ds, nds);
                            inDanhSachKhachHangTheoChieuNgang(ds, nds);
                            giaiPhongDanhSachKhachHang(ds, nds);
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
                            cout << "\nMENU/TINH TRANG MAY/MAY TRONG";
                            cout << "\n*---------------------------*\n";
                            xuatDanhSachCacMayTrong(nhieuMay, n);
                            system("pause");
                            break;
                        }
                        case 2: {
                            system("cls");
                            cout << "\nMENU/TINH TRANG MAY/MAY DAY";
                            cout << "\n*-------------------------*\n";
                            xuatDanhSachCacMayDay(nhieuMay, n);
                            system("pause");
                            break;
                        }
                        case 3: {
                            system("cls");
                            cout << "\nMENU/TINH TRANG MAY/TAT CA";
                            cout << "\n*------------------------*\n";
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
                cout << "\nMENU/NAP TIEN";
                cout << "\n*-----------*\n";
                nds = 0;
                chuyenCaySangMang(dskh.TREE, ds, nds);
                sapXepDanhSachKhachHang(ds, nds);
                inDanhSachKhachHangTheoChieuNgang(ds, nds);
                giaiPhongDanhSachKhachHang(ds, nds);
                napTien();
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
                system("cls");
                cout << "\n\t9. LUU THAY DOI\n";
                luuFile(thueNhieuMay, nhieuMay, n);
                fileSaved = true;
                system("pause");
                break;
            }
            case 10: {
                system("cls");
                cout << "\nMENU/MO MAY TRUC TIEP";
                cout << "\n*-------------------*\n";
                if (hetMay(nhieuMay, n)) {  // nếu hết máy
                    system("cls");
                    cout << "\n\t(!) Het may\n";
                } else {
                    thueNhieuMay.moMayTrucTiep(nhieuMay, n);
                    luuFile(thueNhieuMay, nhieuMay, n);
                }
                system("pause");
                break;
            }
            case 11: {
                system("cls");
                cout << "\nMENU/THANH TOAN";
                cout << "\n*-------------*\n";
                bool kiemTra = kiemTraTrangThai(nhieuMay, n);
                if (kiemTra == true) {
                    thueNhieuMay.thanhToan(nhieuMay, n);
                    system("pause");
                    luuFile(thueNhieuMay, nhieuMay, n);
                } else
                    cout << "\n(!) Khong co may dang duoc su dung\n";
                system("pause");
                break;
            }
            case 12: {
                system("cls");
                cout << "\nMENU/THIET LAP GIA TIEN";
                cout << "\n*---------------------*\n";
                mt.thietLapGiaTien();
                system("pause");
                break;
            }
            case 0: {
                if (fileSaved) {
                    cout << "\n\t(*) Thoat chuong trinh sau 5s (*)\n";
                    Sleep(5000);
                    thoat = true;
                } else {
                    system("cls");
                    cout << "\n\t0. THOAT CHUONG TRINH\n";
                    char c;
                    cout << "\n(!) Ban chua luu thay doi\n";
                    do {
                        fflush(stdin);
                        cout << "\n(?) Xac nhan thoat ma khong luu thay doi (y/n) (?): ";
                        cin >> c;
                        if (c != 'y' && c != 'n')
                            cout << "\n(!) Lua chon khong hop le. Hay nhap lai";
                        else {
                            if (c == 'y') {
                                cout << "\n\t(*) Thoat chuong trinh sau 5s (*)\n";
                                Sleep(5000);
                                thoat = true;
                            } else
                                break;
                        }
                    } while (c != 'y' && c != 'n');
                }
                break;
            }
            default:
                cout << "\n\t(!) Lua chon khong hop le\n";
                system("pause");
                break;
        }
    } while (!thoat);                     // thoat == true
    delete[] nhieuMay;                    // giải phóng bộ nhớ của ds máy tính
    giaiPhongDanhSachKhachHang(ds, nds);  // giải phóng bộ nhớ của ds khách hàng
}

void nhapDuLieuGiaTien(MayTinh &mt) {
    system("cls");
    mt.docGiaTien();
    if (mt.giaTienThuong == 0 || mt.giaTienCaoCap == 0) {
        cout << "\n(!) Chua thiet lap gia tien. Hay thiet lap gia tien bay gio\n";
        system("pause");
        mt.thietLapGiaTien();
    }
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
    // cout << "\n\t(*) Dang luu du lieu danh sach may tinh (*)\n";
    // Sleep(1000);  // delay 2s
    ghiDanhSachCacMay(nhieuMay, n);
    // cout << "\n\n\t(*) Dang luu du lieu danh sach nguoi thue (*)\n";
    // Sleep(1000);  // delay 2s
    ghiDanhSachNguoiThueTrucTiep(thueNhieuMay, n);
    system("cls");
    cout << "\n\t\t(*) Luu thanh cong (*)\n";
}
