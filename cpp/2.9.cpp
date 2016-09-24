#include <iostream> // cin, cout, endl
#include <algorithm> // swap

using namespace std;

struct GiayBac {
  unsigned LoaiTien[50]; // Lưu trữ mệnh giá các loại tiền
	unsigned SoTo[50]; // Số tờ tiền của mỗi mệnh giá 
	unsigned SoLuong; // Số lượng các loại tiền
	unsigned SoTienKhachHang; // Số tiền khách hàng
	bool KiemTra;
};

// Chương trình chính 
int main ();

// Hàm nhập
void nhap (GiayBac &); // 

// Hàm xuất
void xuat (GiayBac); // 

// Hàm tính toán số tiền ít nhất 
void chiatien (GiayBac &, GiayBac); 

// Hàm sắp xếp mênh giá các tờ tiền từ lớn > thấp
void sapxep (GiayBac &);

// Hàm Khởi tạo
void khoitao (GiayBac &); 

/* NỘI DUNG */ 

int main () {
  GiayBac Tien, SoTienRut; 
	khoitao(Tien);
	khoitao(SoTienRut);
	nhap(Tien);
	sapxep(Tien);
	chiatien(SoTienRut, Tien);
	xuat(SoTienRut);
}

void nhap (GiayBac & Tien) {
	unsigned MenhGia;
	cout<<"Nhap so loai giay bac: ";
	cin>>Tien.SoLuong;
	cout<<"Nhap menh gia tung loai\n";
	for(unsigned i = 0; i < Tien.SoLuong; ++i) {
		cout<<"Gia loai "<<i<<": ";
		cin>>MenhGia;
		Tien.LoaiTien[i] = MenhGia;
	}
	cout << "Nhap so tien khach hang: ";
	cin >> Tien.SoTienKhachHang;
}

void xuat (GiayBac SoTienRut) {
	if (SoTienRut.KiemTra == true ) {
	  for(int i = 0; i < SoTienRut.SoLuong; i++){
	  	if ( SoTienRut.SoTo[i] == 0 ) continue;
	  	cout<<"Menh gia:"<<SoTienRut.LoaiTien[i];
		  cout<<" - So To :"<<SoTienRut.SoTo[i];
		  cout<<endl;
  	}
	}
	else 
  	cout << "Khong doi duoc\n";
}

void sapxep (GiayBac & Tien) {
	for(unsigned i = 0; i != Tien.SoLuong; ++i)
		for(unsigned j = i; j != Tien.SoLuong; ++j)
			if(Tien.LoaiTien[i] < Tien.LoaiTien[j])
			  swap(Tien.LoaiTien[i], Tien.LoaiTien[j])
}

void khoitao (GiayBac & Tien) {
	Tien.SoLuong = Tien.SoTienKhachHang = 0;
}


void chiatien (GiayBac & SoTienRut, GiayBac Tien) {
	SoTienRut.KiemTra = true;
	int tiengoc = Tien.SoTienKhachHang;
	for(unsigned i = 0; tiengoc != 0; ++i){
		SoTienRut.SoTo[i] = tiengoc / Tien.LoaiTien[i];
		SoTienRut.LoaiTien[i] = Tien.LoaiTien[i];
		SoTienRut.SoLuong++;
		tiengoc -= SoTienRut.SoTo[i] * Tien.LoaiTien[i];
		if (SoTienRut.SoLuong == Tien.SoLuong)
			if (tiengoc > 0) {
				SoTienRut.KiemTra = false;
			 	return;
			}
	}
}
