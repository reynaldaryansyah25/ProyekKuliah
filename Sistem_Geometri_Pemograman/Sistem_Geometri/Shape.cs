using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sistem_Geometri
{
    public abstract class Shape
    {
        public string Nama { get; private set; }

        protected Shape(string nama)
        {
            Nama = nama;
        }

        public abstract double HitungLuas();
        public abstract double HitungKeliling();
    }

    public abstract class Shape3D : Shape
    {
        protected Shape3D(string nama) : base(nama)
        {
        }

        public abstract double HitungVolume();
    }


}
