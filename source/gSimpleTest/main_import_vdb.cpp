#include "gvdb.h"
using namespace nvdb;

#include <stdlib.h>
#include <stdio.h>
#include "file_png.h"

VolumeGVDB gvdb;

int main (int argc, char* argv)
{

  printf ( "Starting GVDB .\n" );
  // Creación del volúmen GVDB
  // Inicialización
#ifdef _DEBUG
  gvdb.SetDebug(true);
#endif // #ifdef _DEBUG
  gvdb.SetVerbose ( true );
  gvdb.SetCudaDevice ( GVDB_DEV_FIRST );
  gvdb.Initialize ();
  gvdb.AddPath ( "../source/shared_assets/" );
  gvdb.AddPath ( ASSET_PATH );

  // Configurar la topología
  gvdb.Configure(3, 3, 3, 3, 4);
  gvdb.SetChannelDefault(32, 32, 1);
  //// Agregar canales
  gvdb.AddChannel( 0, T_FLOAT, 1, F_LINEAR );	
  gvdb.FillChannel( 0, Vector4DF(0, 0, 0, 0) );

  int numpnts = 1000;
  int pnt[1000] = {0};

  gvdb.ClearTopology ();
  for (int n=0; n < numpnts; n++ ) {
    gvdb.ActivateSpace ( pnt[n] );
  }
  gvdb.FinishTopology ();
  gvdb.UpdateAtlas ();
  gvdb.ClearAtlas ();


  // Allocate GPU and GPU memory
  // DataPtr pntpos, pntclr;

  // Posición de los puntos
  // gvdb.AllocData ( pntpos, numpnts, sizeof(Vector3DF), true);

  // Color de los puntos
  //gvdb.AllocData ( pntclr, numpnts, sizeof(uint), true );

  // Get CPU pointers
  //Vector3DF* pos = (Vector3DF*) gvdb.getDataPtr( 0, pntpos );
  // uint* clr = (uint*) gvdb.getDataPtr( 0, pntclr );

  // .. load points into CPU here ..
  // Commit point data to GPU
  // gvdb.CommitData ( pntpos, numpnts, (char*) m_pntpos.cpu, 0, sizeof(Vector3DF) );
  // gvdb.CommitData ( pntclr, numpnts, (char*) m_pntclr.cpu, 0, sizeof(uint) );

  // gvdb.SetPoints(pntpos, pntclr);
  int algo;
  printf("Waiting...");
  scanf("%d", &algo);


  gprintf ( "Done.\n" );
}
