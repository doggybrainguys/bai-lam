// Sử dụng C-Free 5

#include <iostream>

using namespace std;

/* HẰNG SỐ */

const unsigned SO_CHU_SO_NGUYEN_TO = 3;
const unsigned CHU_SO_NGUYEN_TO[SO_CHU_SO_NGUYEN_TO] = {3, 5, 7};
const unsigned SO_LUONG_TOI_DA = 256;

/* CÁC HÀM CẦN XÂY DỰNG */

// Chương trình chính
int main ();

// Hàm nhập
unsigned nhap ();

// Hàm xuất
void xuat (unsigned * danhsach, unsigned soluong);

// Hàm tách và xuất các siêu nguyên tố
void xuat (unsigned sieunguyento);

// Hàm kiểm tra siêu nguyên tố
void sieunguyento (unsigned * danhsach, unsigned & soluong, unsigned sochuso);

/* NỘI DUNG */

int main () {
  unsigned sochuso = nhap();
  unsigned danhsach[SO_LUONG_TOI_DA];
  unsigned soluong;
  sieunguyento(danhsach, soluong, sochuso);
  xuat(danhsach, soluong);
  return 0;
}

unsigned nhap () {
  unsigned n;
  cout << "Nhap so chu so: ";
  cin >> n;
  return n;
}

void xuat (unsigned * danhsach, unsigned soluong) {
  for (unsigned i = 0; i != soluong; ++i) {
    xuat(danhsach[i]);
  }
}

void xuat (unsigned sieunguyento) {
  while (sieunguyento) {
    cout << sieunguyento << ' ';
    sieunguyento /= 10;
  }
  cout << endl;
}
