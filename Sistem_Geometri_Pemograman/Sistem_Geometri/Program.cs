using System;
using System.Drawing.Printing;
using Sistem_Geometri;

public class Program
{
    public static void Main(string[] args)
    {
        while (true)
        {
            // Menampilkan menu utama
            TampilkanMenuUtama();

            // Membaca pilihan pengguna
            int pilihan = int.Parse(Console.ReadLine());
            Console.Clear();

            // Memproses pilihan dan menghitung bentuk geometri
            Shape bentuk = ProsesPilihan(pilihan);

            // Menampilkan hasil perhitungan
            if (bentuk != null)
            {
                TampilkanHasilPerhitungan(bentuk);
            }
            else
            {
                Console.WriteLine("Terjadi kesalahan, silakan coba lagi.");
            }

            Console.Write("Tekan enter untuk kembali ke menu utama...");
            Console.ReadLine();
            Console.Clear();
        }
    }

    private static void TampilkanMenuUtama()
    {
        Console.WriteLine("============================");
        Console.WriteLine("      Sistem Geometri       ");
        Console.WriteLine("============================");
        Console.WriteLine("Pilih bentuk geometri:");
        Console.WriteLine("1. Lingkaran ( Circle )");
        Console.WriteLine("2. Persegi Panjang ( Rectangle )");
        Console.WriteLine("3. Segitiga ( Triangle )");
        Console.WriteLine("4. Persegi ( Square )");
        Console.WriteLine("5. Jajar Genjang ( Parallelogram )");
        Console.WriteLine("6. Kubus ( Cube )");
        Console.WriteLine("7. Balok ( Rectangular Prism )");
        Console.WriteLine("8. Bola ( Sphere )");
        Console.Write("Pilihan : ");
    }

    private static Shape ProsesPilihan(int pilihan)
    {
        Shape bentuk = null;

        switch (pilihan)
        {
            case 1:
                bentuk = BuatLingkaran();
                Console.WriteLine();
                break;
            case 2:
                bentuk = BuatPersegiPanjang();
                Console.WriteLine();
                break;
            case 3:
                bentuk = BuatSegitiga();
                Console.WriteLine();
                break;
            case 4:
                bentuk = BuatPersegi();
                Console.WriteLine();
                break;
            case 5:
                bentuk = BuatJajarGenjang();
                Console.WriteLine();
                break;
            case 6:
                bentuk = BuatKubus();
                Console.WriteLine();
                break;
            case 7:
                bentuk = BuatBalok();
                Console.WriteLine();
                break;
            case 8:
                bentuk = BuatBola();
                Console.WriteLine();
                break;
            default:
                Console.WriteLine("Pilihan tidak valid. Silakan coba lagi.");
                break;
        }

        return bentuk;
    }

    private static void TampilkanHasilPerhitungan(Shape bentuk)
    {
        Console.WriteLine("=====Hasil Perhitungan=====");
        Console.WriteLine($"Luas: {bentuk.HitungLuas():F2} cm^2");
        Console.WriteLine($"Keliling: {bentuk.HitungKeliling():F2} cm");
        if (bentuk is Shape3D bentuk3D)
        {
            Console.WriteLine($"Volume: {bentuk3D.HitungVolume():F2} cm^3");

        }
        Console.WriteLine("===========================");
        Console.WriteLine() ;
        Console.WriteLine("Perhitungan selesai!");
    }

    private static Shape BuatLingkaran()
    {
        Console.Write("Masukkan jari-jari lingkaran (cm): ");
        double jariJari = BacaNilaiPositif();
        return new Lingkaran(jariJari);
    }

    private static Shape BuatPersegiPanjang()
    {
        Console.Write("Masukkan panjang persegi panjang (cm): ");
        double panjang = BacaNilaiPositif();
        Console.Write("Masukkan lebar persegi panjang (cm): ");
        double lebar = BacaNilaiPositif();
        return new PersegiPanjang(panjang, lebar);
    }

    private static Shape BuatSegitiga()
    {
        Console.Write("Masukkan alas segitiga (cm): ");
        double alas = BacaNilaiPositif();
        Console.Write("Masukkan tinggi segitiga (cm): ");
        double tinggi = BacaNilaiPositif();
        Console.Write("Masukkan sisi A segitiga (cm): ");
        double sisiA = BacaNilaiPositif();
        Console.Write("Masukkan sisi B segitiga (cm): ");
        double sisiB = BacaNilaiPositif();
        Console.Write("Masukkan sisi C segitiga (cm): ");
        double sisiC = BacaNilaiPositif();
        return new Segitiga(alas, tinggi, sisiA, sisiB, sisiC);

    }

    private static Shape BuatPersegi()  
    {
        Console.Write("Masukkan sisi persegi (cm): ");
        double sisi = BacaNilaiPositif();
        return new Persegi(sisi);
    }

    private static Shape BuatJajarGenjang()
    {
        Console.Write("Masukkan alas jajar genjang (cm): ");
        double alas = BacaNilaiPositif();
        Console.Write("Masukkan tinggi jajar genjang (cm): ");
        double tinggi = BacaNilaiPositif();
        return new JajarGenjang(alas, tinggi);
    }

    private static Shape BuatKubus()
    {
        Console.Write("Masukkan sisi kubus (cm): ");
        double sisi = BacaNilaiPositif();
        return new Kubus(sisi);
    }

    private static Shape BuatBalok()
    {
        Console.Write("Masukkan panjang balok (cm): ");
        double panjang = BacaNilaiPositif();
        Console.Write("Masukkan lebar balok (cm): ");
        double lebar = BacaNilaiPositif();
        Console.Write("Masukkan tinggi balok (cm): ");
        double tinggi = BacaNilaiPositif();
        return new Balok(panjang, lebar, tinggi);
    }

    private static Shape BuatBola()
    {
        Console.Write("Masukkan jari-jari bola (cm): ");
        double jariJari = BacaNilaiPositif();
        return new Bola(jariJari);
    }

    private static double BacaNilaiPositif()
    {
        double nilai;
        while (!double.TryParse(Console.ReadLine(), out nilai) || nilai <= 0)
        {
            Console.WriteLine("Input tidak valid, silakan masukkan nilai positif.");
            Console.Write("Masukkan nilai (cm): ");
        }
        return nilai;
    }
}
