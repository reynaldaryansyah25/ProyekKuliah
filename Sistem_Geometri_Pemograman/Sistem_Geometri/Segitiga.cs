using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sistem_Geometri
{
    public class Segitiga : Shape
    {
        private double Alas;
        private double Tinggi;
        private double SisiA;
        private double SisiB;
        private double SisiC;

        public Segitiga(double alas, double tinggi, double sisiA, double sisiB, double sisiC) : base("Segitiga")
        {
            Alas = alas;
            Tinggi = tinggi;
            SisiA = sisiA;
            SisiB = sisiB;
            SisiC = sisiC;
        }

        public override double HitungLuas()
        {
            return 0.5 * Alas * Tinggi;
        }

        public override double HitungKeliling()
        {
            return SisiA + SisiB + SisiC;
        }
    }
}
