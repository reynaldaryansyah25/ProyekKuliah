using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sistem_Geometri
{
    public class PersegiPanjang : Shape
    {
        private double panjang;
        private double lebar;

        public double Panjang
        {
            get { return panjang; }
            set { panjang = value; }
        }

        public double Lebar
        {
            get { return lebar; }
            set { lebar = value; }
        }

        public PersegiPanjang(double panjang, double lebar) : base("Persegi Panjang")
        {
            Panjang = panjang;
            Lebar = lebar;
        }

        public override double HitungLuas()
        {
            return Panjang * Lebar;
        }

        public override double HitungKeliling()
        {
            return 2 * (Panjang + Lebar);
        }
    }

    public class Balok : Shape3D
    {
        private double panjang;
        private double lebar;
        private double tinggi;

        public Balok(double panjang, double lebar, double tinggi) : base("Balok")
        {
            this.panjang = panjang;
            this.lebar = lebar;
            this.tinggi = tinggi;
        }

        public override double HitungLuas()
        {
            return 2 * (panjang * lebar + panjang * tinggi + lebar * tinggi);
        }

        public override double HitungKeliling()
        {
            return 4 * (panjang + lebar + tinggi);
        }

        public override double HitungVolume()
        {
            return panjang * lebar * tinggi;
        }
    }
}
