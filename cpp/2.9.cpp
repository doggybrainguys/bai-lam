// Dùng C-Free 5
// Giải thuật Tham lam

#include <iostream> // cin, cout, cerr, endl
#include <algorithm> // swap

using namespace std;

/* CÁC HÀM CẦN XÂY DỰNG */

// Chương trình chính
int main ();

// Nhập, xuất
void nhap (unsigned & sotien, unsigned * & menhgia, unsigned & soloai);
void xuat (bool dutien, unsigned * menhgia, unsigned * soto, unsigned soloai);

// Chia tiền
bool chiatien (unsigned * & soto, unsigned * menhgia, unsigned & soloaican, unsigned soloai, unsigned sotien);

// Tiện ích
void sapxep (unsigned * menhgia, unsigned soluong);

/* NỘI DUNG */

int main () {
  unsigned sotien, soloai, soloaican, * menhgia, * soto;
  nhap(sotien, menhgia, soloai);
  bool dutien = chiatien(soto, menhgia, soloaican, soloai, sotien);
  xuat(dutien, menhgia, soto, soloaican);
  delete [] menhgia;
  delete [] soto;
  cin.get();
  return 0;
}

void nhap (unsigned & sotien, unsigned * & menhgia, unsigned & soloai) {
  cout << "Nhap so tien: ";
  cin >> sotien;
  cout << "Nhap so menh gia: ";
  cin >> soloai;
  cout << "Nhap tung menh gia: ";
  menhgia = new unsigned[soloai];
  for (unsigned i = 0; i != soloai; ++i) {
    cin >> menhgia[i];
  }
}

void xuat (bool dutien, unsigned * menhgia, unsigned * soto, unsigned soloai) {
  unsigned tongsoto = 0;
  cout << "Danh sach cac to can doi (MenhGia x SoTo):\n";
  for (unsigned i = 0; i != soloai; ++i) {
    unsigned & mg = menhgia[i], & st = soto[i];
    cout << " + " << mg << " x " << st << " = " << (mg * st) << endl;
    tongsoto += st;
  }
  if (! dutien) {
    cerr << "Het tien le!\n";
  }
  cout << "Tong so to: " << tongsoto << endl;
}

bool chiatien (unsigned * & soto, unsigned * menhgia, unsigned & soloaican, unsigned soloai, unsigned sotien) {
  soloaican = 0;
  soto = new unsigned[soloai];
  sapxep(menhgia, soloai);
  while (sotien && soloaican != soloai) {
    soto[soloaican] = sotien / menhgia[soloaican];
    sotien %= menhgia[soloaican];
    ++soloaican;
  }
  return ! sotien;
}

void sapxep (unsigned * menhgia, unsigned soloai) {
  for (unsigned i = 0; i != soloai; ++i)
    for (unsigned j = i; j != soloai; ++j)
      if (menhgia[i] < menhgia[j])
        swap(menhgia[i], menhgia[j]);
}
