// Menu.java
public abstract class Menu {
    // Atribut 'protected' agar bisa diakses oleh kelas turunan
    protected String nama;
    protected int harga;
    protected String kodeMenu;
    protected String deskripsi;

    public Menu(String nama, int harga, String kodeMenu, String deskripsi) {
        this.nama = nama;
        this.harga = harga;
        this.kodeMenu = kodeMenu;
        this.deskripsi = deskripsi;
    }
    
    // Getter methods untuk diakses oleh kelas Restoran
    public String getNama() { return nama; }
    public int getHarga() { return harga; }
    public String getKodeMenu() { return kodeMenu; }
    public String getDeskripsi() { return deskripsi; }

    // Method abstract untuk menampilkan detail, jika diperlukan di luar tabel
    public abstract void tampilkanDetail();
}