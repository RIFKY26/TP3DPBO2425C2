// Minuman.java
public class Minuman extends Menu {
    private String ukuran;
    private String suhu;

    public Minuman(String nama, int harga, String kodeMenu, String deskripsi, String ukuran, String suhu) {
        // Memanggil constructor dari superclass (Menu)
        super(nama, harga, kodeMenu, deskripsi);
        this.ukuran = ukuran;
        this.suhu = suhu;
    }

    // Getter untuk atribut spesifik Minuman
    public String getUkuran() { return ukuran; }
    public String getSuhu() { return suhu; }

    @Override
    public void tampilkanDetail() {
        System.out.printf("[%s] %s - Rp%,d\n", this.kodeMenu, this.nama, this.harga);
        System.out.printf("    Deskripsi: %s\n", this.deskripsi);
        System.out.printf("    Info: Ukuran %s, Suhu: %s\n", this.ukuran, this.suhu);
    }
}