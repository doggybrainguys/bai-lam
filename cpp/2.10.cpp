// Sử dụng C-Free 5
// Giải thuật Tham lam

#include <iostream> // cin, cout, endl
#include <algorithm> // swap

using namespace std;

struct TapGoiKeo {
  unsigned goikeo[50]; // N < 50
  unsigned soluong; // Số lượng gói
  unsigned tongsokeo; // Tổng số kẹo
};

/* CÁC HÀM CẦN XÂY DỰNG */

// Chương trình chính
int main ();

// Hàm nhập: Nhập số lượng và các gói kẹo được chia
void nhap (TapGoiKeo & nguon);

// Hàm xuất
void xuat (TapGoiKeo nguoinhan1, TapGoiKeo nguoinhan2);

// Hàm xuất một người nhận
void xuat (TapGoiKeo nguoinhan);

// Hàm chia kẹo theo Giải thuật Tham lam
void chiakeo (TapGoiKeo & nguoinhan1, TapGoiKeo & nguoinhan2, TapGoiKeo nguon);

// Hàm sắp xếp theo thứ tự giảm dần
void sapxep (TapGoiKeo & mang);

// Hàm khởi tạo
void khoitao (TapGoiKeo &);

// Hàm thêm kẹo
void themkeo (TapGoiKeo & nguoinhan, unsigned sokeo);

// Trị tuyệt đối
unsigned trituyetdoi (int n);

/* NỘI DUNG */

int main () {
  TapGoiKeo nguon, nguoinhan1, nguoinhan2;
  nhap(nguon);
  sapxep(nguon);
  khoitao(nguoinhan1);
  khoitao(nguoinhan2);
  chiakeo(nguoinhan1, nguoinhan2, nguon);
  xuat(nguoinhan1, nguoinhan2);
  cin.get();
  return 0;
}

void chiakeo (TapGoiKeo & nguoinhan1, TapGoiKeo & nguoinhan2, TapGoiKeo nguon) {
  for (unsigned i = 0; i != nguon.soluong; ++i) {
    if (nguoinhan1.tongsokeo < nguoinhan2.tongsokeo) {
      themkeo(nguoinhan1, nguon.goikeo[i]);
    } else {
      themkeo(nguoinhan2, nguon.goikeo[i]);
    }
  }
}

void sapxep (TapGoiKeo & mang) {
	for(unsigned i = 0; i != mang.soluong; ++i)
		for(unsigned j = i; j != mang.soluong; ++j)
		  if(mang.goikeo[i] < mang.goikeo[j])
			  swap(mang.goikeo[i], mang.goikeo[j]);
}

void khoitao (TapGoiKeo & keo) {
  keo.soluong = keo.tongsokeo = 0;
}

void themkeo (TapGoiKeo & nguoinhan, unsigned sokeo) {
  unsigned vitri = nguoinhan.soluong;
  nguoinhan.tongsokeo += sokeo;
  nguoinhan.goikeo[vitri] = sokeo;
  nguoinhan.soluong = vitri + 1;
}

void nhap (TapGoiKeo &nguon) {
  cout << "Nhap so goi keo (<50): ";
  cin >> nguon.soluong;
  for (unsigned i = 0; i < nguon.soluong; i++) {
    unsigned goikeo;
    cout <<"Nhap so luong goi keo thu " << i << ": ";
    cin >> goikeo;
    nguon.goikeo[i] = goikeo;
    nguon.tongsokeo += goikeo;
  }
}

void xuat (TapGoiKeo nguoinhan1, TapGoiKeo nguoinhan2) {
  cout << endl;
  cout << "Chenh lech: " << trituyetdoi(nguoinhan1.tongsokeo - nguoinhan2.tongsokeo) << endl << endl;
  cout << "Nguoi nhan 1:\n";
  xuat(nguoinhan1);
  cout << endl;
  cout << "Nguoi nhan 2:\n";
  xuat(nguoinhan2);
  cout << endl;
}

void xuat (TapGoiKeo nguoinhan) {
  cout << " - Tong so goi: " << nguoinhan.soluong << endl;
  cout << " - Tong so keo: " << nguoinhan.tongsokeo << endl;
  cout << " - Goi keo da nhan:";
  for (unsigned i = 0; i != nguoinhan.soluong; ++i) {
    cout << ' ' << nguoinhan.goikeo[i];
  }
  cout << endl;
}

unsigned trituyetdoi (int n) {
  return n > 0 ? n : -n;
}
