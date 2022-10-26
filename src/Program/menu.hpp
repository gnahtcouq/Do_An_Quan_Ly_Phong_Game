#include "khachhang.hpp"
#include "maytinh.hpp"

void menu();
void nhapDuLieuDanhSachMayTinh(DanhSachMayTinh &dsmt);

void menu() {
    int choose, nds;
    bool exit = false;
    KhachHang *ds[100];
    DanhSachMayTinh dsmt;
    DanhSachKhachHang dskh;
    nhapDuLieuDanhSachMayTinh(dsmt);
    do {
        system("cls");
        cout << "\n*--------------------------------------------------*";
        cout << "\n|               QUAN LY PHONG GAME                 |";
        cout << "\n*--------------------------------------------------*";
        cout << "\n|  1. Them may tinh                                |";
        cout << "\n|  2. In danh sach may tinh                        |";
        cout << "\n|  3. Xoa may tinh                                 |";
        cout << "\n|  4. Chinh sua thong tin may tinh                 |";
        cout << "\n|  5. Nhap khach hang                              |";
        cout << "\n|  6. In danh sach khach hang tang dan theo ma so  |";
        cout << "\n|  7. Xoa khach hang                               |";
        cout << "\n*--------------------------------------------------*";
        cout << "\n|             0. Thoat chuong trinh                |";
        cout << "\n*--------------------------------------------------*";
        cout << "\n\t-> Lua chon cua ban: ";
        cin >> choose;
        switch (choose) {
            case 1:
                system("cls");
                cout << "\n\t1. THEM MAY TINH\n";
                if (dsmt.soLuong == 100) {
                    cout << "\n(!) Them khong thanh cong (Du lieu day)";
                    system("pause");
                } else
                    themMayTinh(dsmt);
                break;
            case 2:
                system("cls");
                cout << "\n\t2. DANH SACH MAY TINH\n";
                inMotMayTheoChieuNgang(dsmt);
                system("pause");
                break;
            case 3:
                system("cls");
                cout << "\n\t3. XOA MAY TINH\n";
                if (dsmt.soLuong == 0) {
                    cout << "\n(!) Xoa khong thanh cong (Du lieu trong)";
                    system("pause");
                } else
                    xoaMayTinh(dsmt);
                break;
            case 4:
                system("cls");
                cout << "\n\t4. CHINH SUA THONG TIN MAY TINH\n";
                if (dsmt.soLuong == 0) {
                    cout << "\n(!) Du lieu rong";
                    system("pause");
                } else
                    chinhSuaMayTinh(dsmt);
                break;
            case 5:
                system("cls");
                cout << "\n\t5. NHAP KHACH HANG\n";
                nhapMotKhachHang(dskh);
                break;
            case 6:
                system("cls");
                nds = 0;
                cout << "\n\t6. DANH SACH KHACH HANG\n";
                chuyenCaySangMang(dskh.TREE, ds, nds);
                sapXepDanhSachKhachHang(ds, nds);
                inDanhSachKhachHangTheoChieuNgang(ds, nds);
                giaiPhongDanhSachKhachHang(ds, nds);
                system("pause");
                break;
            case 7:
                system("cls");
                nds = 0;
                cout << "\n\t7. XOA KHACH HANG\n";
                chuyenCaySangMang(dskh.TREE, ds, nds);
                sapXepDanhSachKhachHang(ds, nds);
                inDanhSachKhachHangTheoChieuNgang(ds, nds);
                xoaKhachHang(dskh);
                giaiPhongDanhSachKhachHang(ds, nds);
                break;
            case 0:
                break;
            default:
                cout << "\n\t(!) Lua chon khong hop le\n";
                system("pause");
                break;
        }
    } while (!exit);
}

void nhapDuLieuDanhSachMayTinh(DanhSachMayTinh &dsmt) {
    system("cls");
    cout << "\n\t(*) Dang nhap du lieu danh sach may tinh (*)\n";
    Sleep(1000);  // delay 2s
    docDanhSachMayTinh(dsmt);
}