#pragma once
#include "ThueMotMay.hpp"

class Node {
   public:
    ThueMotMay data;
    Node *pNext;
};

class ThueNhieuMay {
   public:
    Node *pHead;
    Node *pTail;
    void createList();
    void addNodeInTail(ThueMotMay);
    void removeNodeInHead();
    void removeNodeInTail();
    void moMayTrucTiep(MayTinh[], int);  // mở máy trực tiếp
    void thanhToan(MayTinh[], int);      // thanh toán
};

Node *createNode(ThueMotMay value);
void docDanhSachNguoiThueTrucTiep(ThueNhieuMay &thueNhieuMay, MayTinh nhieuMay[], int n);  // đọc danh sách người thuê trực tiếp từ file
void ghiDanhSachNguoiThueTrucTiep(ThueNhieuMay thueNhieuMay);                              // ghi danh sách người thuê trực tiếp ra file
int tinhSoNgay(int ngayBD, int thangBD, int namBD, int ngayKT, int thangKT, int namKT);    // tính số ngày sử dụng

void ThueNhieuMay::createList() {
    pHead = NULL;
    pTail = NULL;
}

Node *createNode(ThueMotMay value) {
    Node *p = new Node;
    if (p == NULL) {
        cout << "\n\t(!) Khong du bo nho (!)";
        return NULL;
    } else {
        p->data = value;
        p->pNext = NULL;
    }
    return p;
}

void ThueNhieuMay::addNodeInTail(ThueMotMay thueMotMay) {
    Node *p = createNode(thueMotMay);
    if (pHead == NULL)
        pHead = pTail = p;
    else {
        pTail->pNext = p;
        pTail = p;
    }
}

void ThueNhieuMay::removeNodeInHead() {
    if (pHead == NULL)  // không có phần tử nào
        return;
    else {
        Node *p = pHead;
        pHead = p->pNext;
        delete p;
    }
}

void ThueNhieuMay::removeNodeInTail() {
    if (pHead == NULL)
        return;
    // nếu phần tử nằm đầu cũng là phần tử nằm cuối
    else if (pHead == pTail)
        removeNodeInHead();
    else {
        for (Node *t = pHead; t != NULL; t = t->pNext) {
            if (t->pNext == pTail) {
                free(pTail);
                t->pNext = NULL;
                pTail = t;
                return;
            }
        }
    }
}

void ThueNhieuMay::moMayTrucTiep(MayTinh nhieuMay[], int n) {
    int gioBD = 0, phutBD = 0, giayBD = 0, ngayBD = 0, thangBD = 0, namBD = 0;
    ThueMotMay r;
    r.chonMay(nhieuMay, n);
    r.maytinh->tinhTrang = 1;  // cập nhật lại tình trạng máy -> 1 (máy đã có người sử dụng)
    layThoiGianHeThong(gioBD, phutBD, giayBD, ngayBD, thangBD, namBD);
    r.maytinh->gioBD = gioBD;
    r.maytinh->phutBD = phutBD;
    r.maytinh->giayBD = giayBD;
    r.maytinh->ngayBD = ngayBD;
    r.maytinh->thangBD = thangBD;
    r.maytinh->namBD = namBD;
    system("cls");
    cout << "\n\t(!) Mo may thanh cong (!)\n";
    addNodeInTail(r);
}

void docDanhSachNguoiThueTrucTiep(ThueNhieuMay &thueNhieuMay, MayTinh nhieuMay[], int n) {
    int count = 1;
    ifstream fileIn("../File/khachhang/momaytructiep.txt");
    if (fileIn.fail()) {
        cout << "\n(!) Loi khi doc file (!)\n";
        system("pause");
    } else {
        while (!fileIn.eof()) {
            ThueMotMay r;
            r.docMotNguoiThueTrucTiep(fileIn, nhieuMay, n);
            thueNhieuMay.addNodeInTail(r);
            Sleep(50);  // delay 0.05s
            cout << "\n(*) Doc ban ghi thu " << count++ << "(*)";
        }
    }
    fileIn.close();
}

void ghiDanhSachNguoiThueTrucTiep(ThueNhieuMay thueNhieuMay) {
    int count = 1;
    ofstream fileOut("../File/khachhang/momaytructiep.txt");
    if (fileOut.fail()) {
        cout << "\n(!) Loi khi mo file (!)\n";
        system("pause");
    } else {
        for (Node *t = thueNhieuMay.pHead; t != NULL; t = t->pNext) {
            t->data.ghiMotNguoiThueTrucTiep(fileOut);
            Sleep(50);  // delay 0.05s
            cout << "\n(*) Ban ghi thu " << count++ << "(*)";
            if (t->pNext != NULL)
                fileOut << endl;
        }
    }
    fileOut.close();
}

void ThueNhieuMay::thanhToan(MayTinh nhieuMay[], int n) {
    int gio = 0, phut = 0, giay = 0;
    int gioKT = 0, phutKT = 0, giayKT = 0, ngayKT = 0, thangKT = 0, namKT = 0;
    int soNgay = 0, thoiGian1 = 0, thoiGian2 = 0, tongThoiGian = 0;
    long thoiGianBatDau = 0, thoiGianKetThuc = 0;

    ThueMotMay r;
    r.chonMayCanThanhToan(nhieuMay, n);
    r.maytinh->tinhTrang = 0;  // cập nhật lại tình trạng máy -> 0 (máy trống)

    layThoiGianHeThong(gioKT, phutKT, giayKT, ngayKT, thangKT, namKT);
    r.maytinh->gioKT = gioKT;
    r.maytinh->phutKT = phutKT;
    r.maytinh->giayKT = giayKT;
    r.maytinh->ngayKT = ngayKT;
    r.maytinh->thangKT = thangKT;
    r.maytinh->namKT = namKT;
    //
    //
    if (r.maytinh->namBD == r.maytinh->namKT) {
        if (r.maytinh->thangBD == r.maytinh->thangKT) {
            if (r.maytinh->ngayBD == r.maytinh->ngayKT)
                thoiGianBatDau = 3600 * r.maytinh->gioBD + 60 * r.maytinh->phutBD + r.maytinh->giayBD;
            else
                thoiGianBatDau = 86400 - (3600 * r.maytinh->gioBD + 60 * r.maytinh->phutBD + r.maytinh->giayBD);
            if (r.maytinh->ngayBD < r.maytinh->ngayKT)
                thoiGianKetThuc = 3600 * r.maytinh->gioKT + 60 * r.maytinh->phutKT + r.maytinh->giayKT;
            else {
                thoiGianKetThuc = thoiGianBatDau - (3600 * r.maytinh->gioKT + 60 * r.maytinh->phutKT + r.maytinh->giayKT);
                if (thoiGianKetThuc < 0)
                    thoiGianKetThuc = -thoiGianKetThuc;
            }
        } else {
            thoiGianBatDau = 86400 - (3600 * r.maytinh->gioBD + 60 * r.maytinh->phutBD + r.maytinh->giayBD);
            thoiGianKetThuc = 3600 * r.maytinh->gioKT + 60 * r.maytinh->phutKT + r.maytinh->giayKT;
        }
    } else {
        thoiGianBatDau = 86400 - (3600 * r.maytinh->gioBD + 60 * r.maytinh->phutBD + r.maytinh->giayBD);
        thoiGianKetThuc = 3600 * r.maytinh->gioKT + 60 * r.maytinh->phutKT + r.maytinh->giayKT;
    }
    //
    //
    soNgay = tinhSoNgay(r.maytinh->ngayBD, r.maytinh->thangBD, r.maytinh->namBD, r.maytinh->ngayKT, r.maytinh->thangKT, r.maytinh->namKT);
    thoiGian1 = thoiGianBatDau + (86400 * (soNgay - 1));
    thoiGian2 = thoiGianKetThuc;
    tongThoiGian = thoiGian1 + thoiGian2;
    //
    //
    if (r.maytinh->namBD == r.maytinh->namKT) {
        if (r.maytinh->thangBD == r.maytinh->thangKT) {
            if (r.maytinh->ngayBD == r.maytinh->ngayKT) {
                gio = thoiGianKetThuc / 3600;
                phut = (thoiGianKetThuc % 3600) / 60;
                giay = (thoiGianKetThuc % 3600) % 60;
            } else {
                gio = tongThoiGian / 3600;
                phut = (tongThoiGian % 3600) / 60;
                giay = (tongThoiGian % 3600) % 60;
            }
        } else {
            gio = tongThoiGian / 3600;
            phut = (tongThoiGian % 3600) / 60;
            giay = (tongThoiGian % 3600) % 60;
        }
    } else {
        gio = tongThoiGian / 3600;
        phut = (tongThoiGian % 3600) / 60;
        giay = (tongThoiGian % 3600) % 60;
    }
    //
    //
    string thoiGianSuDung = to_string(gio) + ":" + to_string(phut) + ":" + to_string(giay);
    string thoiGianThanhToan = to_string(gioKT) + ":" + to_string(phutKT) + ":" + to_string(giayKT) + " - " + to_string(ngayKT) + "/" + to_string(thangKT) + "/" + to_string(namKT);

    system("cls");
    string loaiKieuMay;
    if (r.maytinh->kieuMay == 1)  // kieuMay == 1 -> Máy cao cấp
        loaiKieuMay = "Cao cap";
    else  // kieuMay == 0 -> Máy thường
        loaiKieuMay = "Thuong";

    cout << setw(30) << left << "So may: "
         << "\t";
    cout << setw(20) << right << r.maytinh->soMay << "\n";
    cout << setw(30) << left << "Kieu may: "
         << "\t";
    cout << setw(20) << right << loaiKieuMay << "\n";
    cout << setw(30) << left << "Thoi gian da su dung: "
         << "\t";
    cout << setw(20) << right << thoiGianSuDung << "\n";
    cout << setw(30) << left << "Xuat hoa don luc: "
         << "\t";
    cout << setw(20) << right << thoiGianThanhToan << "\n";

    removeNodeInHead();
}

int tinhSoNgay(int ngayBD, int thangBD, int namBD, int ngayKT, int thangKT, int namKT) {
    int soNgay = 0;
    while (namKT >= namBD) {
        if (namKT == namBD && thangKT == thangBD) {
            soNgay += ngayKT - ngayBD;
            break;
        } else {
            // Tháng 4, 6, 9, 11 có 30 ngày
            if (thangBD == 4 || thangBD == 6 || thangBD == 9 || thangBD == 11)
                soNgay += 30 - ngayBD;
            // Tháng 1, 3, 5, 7, 8, 10, 12 có 31 ngày
            if (thangBD == 1 || thangBD == 3 || thangBD == 5 || thangBD == 7 || thangBD == 8 || thangBD == 10 || thangBD == 12)
                soNgay += 31 - ngayBD;
            // Tháng 2 có 28 ngày (trừ năm nhuận có 29 ngày)
            if (thangBD == 2) {
                if ((namBD % 4 == 0) && (namBD % 100 != 0) || (namBD % 400 == 0))
                    soNgay += 29 - ngayBD;
                else
                    soNgay += 28 - ngayBD;
            }
            thangBD++, ngayBD = 0;
            if (thangBD == 13)  // tăng năm lên
                namBD++, thangBD = 1;
        }
    }
    return soNgay;
}