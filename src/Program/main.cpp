#include "menu.hpp"

int main() {
    srand(time(NULL));                  // random
    SetConsoleOutputCP(65001);          // Hiển thị giao diện tiếng việt
    thietLapKichThuocManHinh(120, 30);  // thiết lập kích thước màn hình
    chanThayDoiKichThuocManHinh();      // chặn thay đổi kích thước màn hình
    chanNutCtrl(false, false, true);    // chặn nút Ctrl
    anThanhTruot(false);                // ẩn thanh trượt ngang
    menu();
    return 0;
}