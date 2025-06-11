using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sistem_Geometri
{
    public class Lingkaran : Shape
    {
        private double JariJari { get; set; }

        public Lingkaran(double jariJari) : base("Lingkaran")
        {
            JariJari = jariJari;
        }

        public override double HitungLuas()
        {
            return Math.PI * JariJari * JariJari;
        }

        public override double HitungKeliling()
        {
            return 2 * Math.PI * JariJari;
        }
    }

    public class Bola : Shape3D
    {
        private double jariJari;

        public Bola(double jariJari) : base("Bola")
        {
            this.jariJari = jariJari;
        }

        public override double HitungLuas()
        {
            return 4 * Math.PI * jariJari * jariJari;
        }

        public override double HitungKeliling()
        {
            return 2 * Math.PI * jariJari;
        }

        public override double HitungVolume()
        {
            return (4 / 3) * Math.PI * jariJari * jariJari * jariJari;
        }
    }
}
