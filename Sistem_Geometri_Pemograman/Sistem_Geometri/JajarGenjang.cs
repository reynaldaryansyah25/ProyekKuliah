using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sistem_Geometri
{
    public class JajarGenjang : Shape
    {
        private double Alas;
        private double Tinggi;

        public JajarGenjang(double alas, double tinggi) : base("JajarGenjang")          {
            this.Alas = alas;
            this.Tinggi = tinggi;
        }

        public override double HitungLuas()
        {
            return Alas * Tinggi;
        }

        public override double HitungKeliling()
        {
            return 2 * (Alas + Tinggi);
        }
    }
}
