using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sistem_Geometri
{
    public class Persegi : Shape
    {
        private double sisi;

        public Persegi(double sisi) : base("Persegi")
        {
            this.sisi = sisi;
        }

        public override double HitungLuas()
        {
            return sisi * sisi;
        }

        public override double HitungKeliling()
        {
            return 4 * sisi;
        }
    }

    public class Kubus : Shape3D 
    {
        private double sisi;

        public Kubus(double sisi) : base("Kubus")
        {
            this.sisi = sisi;
        }

        public override double HitungLuas()
        {
            return 6 * sisi * sisi;
        }

        public override double HitungKeliling()
        {
            return 12 * sisi;
        }

        public override double HitungVolume()
        {
            return sisi * sisi * sisi;
        }
    }
}
