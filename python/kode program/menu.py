# menu.py

class Menu:
    def __init__(self, nama, harga, kode_menu, deskripsi):
        self.nama = nama
        self.harga = harga
        self.kode_menu = kode_menu
        self.deskripsi = deskripsi

    def tampilkan(self):
        print(f"[{self.kode_menu}] {self.nama} - Rp{self.harga}")
        print(f"    Deskripsi: {self.deskripsi}")