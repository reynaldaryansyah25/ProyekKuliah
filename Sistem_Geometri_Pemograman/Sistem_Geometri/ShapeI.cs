using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sistem_Geometri
{
    public interface Shape2DI 
    {
        string Nama { get; }
        double HitungLuas();
        double HitungKeliling();
    }

    public interface Shape3DI 
    {

        string Nama { get; }
        double HitungVolume();
    }
}
