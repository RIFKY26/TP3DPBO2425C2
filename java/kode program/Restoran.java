// Restoran.java
import java.util.ArrayList;
import java.util.List;

public class Restoran {
    private String nama;
    private String alamat;
    private String jamOperasional;
    private List<Menu> menuList;

    public Restoran(String nama, String alamat, String jamOperasional) {
        this.nama = nama;
        this.alamat = alamat;
        this.jamOperasional = jamOperasional;
        this.menuList = new ArrayList<>(); // Composition & Array of Object
    }

    public void tambahMenu(Menu menu) {
        this.menuList.add(menu);
    }

    public void tampilkanMenu() {
        System.out.println("============================================================");
        System.out.printf("Selamat Datang di Restoran %s\n", this.nama);
        System.out.printf("Alamat: %s | Buka: %s\n", this.alamat, this.jamOperasional);
        System.out.println("============================================================");

        if (this.menuList.isEmpty()) {
            System.out.println("\nBelum ada menu yang terdaftar.");
            return;
        }
        
        // Header Tabel
        System.out.println("\n" + "-".repeat(145));
        System.out.printf("| %-5s | %-20s | %12s | %-10s | %-45s | %-35s |\n", "KODE", "NAMA MENU", "HARGA", "KATEGORI", "DETAIL", "DESKRIPSI");
        System.out.println("-".repeat(145));
        
        // Body Tabel
        for (Menu menu : this.menuList) {
            String kode = menu.getKodeMenu();
            String nama = menu.getNama();
            String harga = String.format("Rp %,d", menu.getHarga());
            String deskripsi = menu.getDeskripsi();
            
            String kategori = "";
            String detail = "";

            // Cek tipe objek untuk mengisi kolom Kategori dan Detail
            if (menu instanceof Makanan) {
                Makanan m = (Makanan) menu; // Type casting
                kategori = "Makanan";
                detail = String.format("Pedas: %s, Jenis: %s", m.getPedas(), m.getJenisMasakan());
            } else if (menu instanceof Minuman) {
                Minuman m = (Minuman) menu; // Type casting
                kategori = "Minuman";
                detail = String.format("Ukuran: %s, Suhu: %s", m.getUkuran(), m.getSuhu());
            }
            
            // Mencetak baris tabel
            System.out.printf("| %-5s | %-20s | %12s | %-10s | %-45s | %-35s |\n", kode, nama, harga, kategori, detail, deskripsi);
        }

        System.out.println("-".repeat(145));
    }
}