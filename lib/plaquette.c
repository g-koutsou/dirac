#include <defs.h>
#include <precision.h>
#include <su3linalg.h>

double
PR(plaquette)(PR(gauge_field) *U)
{
  lattice *lat = U->L;
  int (*nn)[2*ND] = lat->nn;
  int vol = 1;
  for(int i=0; i<ND; i++)
    vol *= lat->dims[i];
  
  qReal a[2*NC*NC];
  qReal b[2*NC*NC];
  qReal plaq = 0.0;
  for(int d0=0; d0<ND; d0++) 
    for(int d1=d0+1; d1<ND; d1++) 
      for(int v=0; v<vol; v++) {
	qReal *q, *p;
	q = (qReal *)U->u[v + d0*vol];
	p = (qReal *)U->u[nn[d0][v] + d1*vol];
	su3_mul_uu(a,q,p);
	q = (qReal *)U->u[nn[d1][v] + d0*vol];
	su3_mul_ud(b,a,q);
	p = (qReal *)U->u[v + d1*vol];
	su3_mul_ud(a,b,p);
	plaq += (a[0] + a[8] + a[16])/3.0;
      }
  plaq /= ((double)vol*(ND-1)*ND/2.0);
  return plaq;
}
