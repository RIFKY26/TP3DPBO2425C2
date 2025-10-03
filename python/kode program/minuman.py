# minuman.py

from menu import Menu

class Minuman(Menu):
    def __init__(self, nama, harga, kode_menu, deskripsi, ukuran, suhu):
        super().__init__(nama, harga, kode_menu, deskripsi)
        self.ukuran = ukuran  # kecil / sedang / besar
        self.suhu = suhu # Panas / Dingin

    def tampilkan(self):
        # Memanggil metode tampilkan dari parent class dan menambahkan info spesifik
        super().tampilkan()
        print(f"    Info: Ukuran {self.ukuran}, Suhu: {self.suhu}")