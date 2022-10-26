#pragma once
#include "cautrucdulieu.hpp"

void xoaMotKyTu(string &s, int vitrixoa);
void chuanHoaTenTaiKhoan(string &s);

void xoaMotKyTu(string &s, int vitrixoa) {
    int length = s.length();
    for (int i = vitrixoa + 1; i < length; i++)
        s[i - 1] = s[i];
    s[length - 1] = '\0';
}

void chuanHoaTenTaiKhoan(string &s) {
    int length = s.length();
    // Chạy từ đầu đến cuối gặp 2 khoảng trắng liên tiếp thì xóa đi 1
    for (int i = 0; i < length; i++) {
        if (s[i] == ' ') {
            xoaMotKyTu(s, i);
            i--;       // Xóa xong thì i-- xuống
            length--;  // Giảm độ dài length xuống
        }
    }
    if (s[0] == ' ') {
        xoaMotKyTu(s, 0);
        length--;
    }
    if (s[length - 1] == ' ') {
        xoaMotKyTu(s, length - 1);
        length--;
    }
    for (int i = 0; i < length; i++)
        if (s[i] >= 65 && s[i] <= 90)
            s[i] += 32;
}