bool kiemTraTaiKhoanDaTonTai(ThueNhieuMay thueNhieuMay, char *taiKhoan);
void themMotNguoiThueVaoDanhSach(ThueNhieuMay &thueNhieuMay, MayTinh nhieuMay[], int n);
void xuatDanhSachNguoiThue(ThueNhieuMay thueNhieuMay);

bool kiemTraTaiKhoanDaTonTai(ThueNhieuMay thueNhieuMay, char *taiKhoan) {
    for (Node *t = thueNhieuMay.pHead; t != NULL; t = t->pNext)
        if (strcmp(t->data.taiKhoan, taiKhoan) == 0)
            return 1;
    return 0;
}

void themMotNguoiThueVaoDanhSach(ThueNhieuMay &thueNhieuMay, MayTinh nhieuMay[], int n) {
    ThueMotMay r;
    nhapMotNguoiThue(r, nhieuMay, n);
    do {
        if (kiemTraTaiKhoanDaTonTai(thueNhieuMay, r.taiKhoan)) {
            cout << "\n\t(!) Da ton tai nguoi thue voi tai khoan nay (!)\n\a";
            cout << "\n(?) Nhap lai tai khoan khac: ";
            cin >> r.soDienThoai;
        }
    } while (kiemTraTaiKhoanDaTonTai(thueNhieuMay, r.taiKhoan));
    r.maytinh->tinhTrang = 1;
    cout << "\n\tTHONG TIN NGUOI THUE VUA NHAP\n";
    xuatMotNguoiThueTheoChieuDoc(r);
    addNodeInTail(thueNhieuMay, r);
}

void xuatDanhSachNguoiThue(ThueNhieuMay thueNhieuMay) {
    int count = 1;
    cout << "\n";
    cout << setw(10) << left << "STT"
         << "\t";
    cout << setw(30) << left << "Tai khoan"
         << "\t";
    cout << setw(30) << left << "Mat khau"
         << "\t";
    cout << setw(20) << left << "So dien thoai"
         << "\t";
    cout << setw(10) << left << "So may"
         << "\t" << endl;

    for (Node *t = thueNhieuMay.pHead; t != NULL; t = t->pNext) {
        cout << setw(10) << count++ << "\t";
        xuatMotNguoiThueTheoChieuNgang(t->data);
    }
}