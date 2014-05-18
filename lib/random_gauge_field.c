#include <defs.h>
#include <string.h>
#include <stdlib.h>
#include <precision.h>
#include <su3linalg.h>
#include <math.h>

static void
exp_gell_mann(qComplex *u, double phi, int igm)
{
  switch(igm){
  case 1:
    u[0] = cos(phi) + 0.0*I;
    u[1] = 0.0 + sin(phi)*I;
    u[2] = 0.0 + 0.0*I;

    u[3] = 0.0 + sin(phi)*I;
    u[4] = cos(phi) + 0.0*I;
    u[5] = 0.0 + 0.0*I;

    u[6] = 0.0 + 0.0*I;
    u[7] = 0.0 + 0.0*I;
    u[8] = 1. + 0.0*I;
    break;
  case 2:
    u[0] = cos(phi) + 0.0*I;
    u[1] = sin(phi) + 0.0*I;
    u[2] = 0.0 + 0.0*I;

    u[3] =-sin(phi) + 0.0*I;
    u[4] = cos(phi) + 0.0*I;
    u[5] = 0.0 + 0.0*I;

    u[6] = 0.0 + 0.0*I;
    u[7] = 0.0 + 0.0*I;
    u[8] = 1. + 0.0*I;
    break;
  case 3:
    u[0] = cos(phi) + sin(phi)*I;
    u[1] = 0.0 + 0.0*I;
    u[2] = 0.0 + 0.0*I;

    u[3] = 0.0 + 0.0*I;
    u[4] = cos(phi) - sin(phi)*I;
    u[5] = 0.0 + 0.0*I;

    u[6] = 0.0 + 0.0*I;
    u[7] = 0.0 + 0.0*I;
    u[8] = 1. + 0.0*I;
    break;
  case 4:
    u[0] = cos(phi) + 0.0*I;
    u[1] = 0.0 + 0.0*I;
    u[2] = 0.0 + sin(phi)*I;

    u[3] = 0.0 + 0.0*I;
    u[4] = 1. + 0.0*I;
    u[5] = 0.0 + 0.0*I;

    u[6] = 0.0 + sin(phi)*I;
    u[7] = 0.0 + 0.0*I;
    u[8] = cos(phi) + 0.0*I;
    break;
  case 5:
    u[0] = cos(phi) + 0.0*I;
    u[1] = 0.0 + 0.0*I;
    u[2] = sin(phi) + 0.0*I;

    u[3] = 0.0 + 0.0*I;
    u[4] = 1. + 0.0*I;
    u[5] = 0.0 + 0.0*I;

    u[6] =-sin(phi) + 0.0*I;
    u[7] = 0.0 + 0.0*I;
    u[8] = cos(phi) + 0.0*I;
    break;
  case 6:
    u[0] = 1. + 0.0*I;
    u[1] = 0.0 + 0.0*I;
    u[2] = 0.0 + 0.0*I;

    u[3] = 0.0 + 0.0*I;
    u[4] = cos(phi) + 0.0*I;
    u[5] = 0.0 + sin(phi)*I;

    u[6] = 0.0 + 0.0*I;
    u[7] = 0.0 + sin(phi)*I;
    u[8] = cos(phi) + 0.0*I;
  case 7:
    u[0] = 1. + 0.0*I;
    u[1] = 0.0 + 0.0*I;
    u[2] = 0.0 + 0.0*I;

    u[3] = 0.0 + 0.0*I;
    u[4] = cos(phi) + 0.0*I;
    u[5] = sin(phi) + 0.0*I;

    u[6] = 0.0 + 0.0*I;
    u[7] =-sin(phi) + 0.0*I;
    u[8] = cos(phi) + 0.0*I;
  case 8:
    u[0] = cos(phi/sqrt(3.)) + sin(phi/sqrt(3.))*I;
    u[1] = 0.0 + 0.0*I;
    u[2] = 0.0 + 0.0*I;

    u[3] = 0.0 + 0.0*I;
    u[4] = cos(phi/sqrt(3.)) + sin(phi/sqrt(3.))*I;
    u[5] = 0.0 + 0.0*I;

    u[6] = 0.0 + 0.0*I;
    u[7] = 0.0 + 0.0*I;
    u[8] = cos(phi*2./sqrt(3.)) - sin(phi*2./sqrt(3.))*I;
    break;
  }
}

void
PR(random_gauge_field)(PR(gauge_field) *U)
{
  lattice *lat = U->L;
  int vol = 1;
  for(int i=0; i<ND; i++)
    vol *= lat->dims[i];
  double amp = 0.05;
  for(int v=0; v<vol*ND; v++) {
    qComplex u0[NC*NC];
    qComplex u1[NC*NC];
    qComplex u2[NC*NC];
    memset(u0,'\0',sizeof(qComplex)*NC*NC);
    u0[ 0] = 1.0;
    u0[ 4] = 1.0;
    u0[ 8] = 1.0;
    for(int i=0; i<8; i++) {
      int igm = (int)(8.0*drand48() + 1);
      double phi = M_PI*amp*(2.0*drand48()-1.0);
      exp_gell_mann(u1, phi, igm);
      su3_mul_uu((qReal *)u2, (qReal *)u1, (qReal *)u0);
      memcpy(u0,u2,sizeof(qComplex)*NC*NC);
    }
    for(int i=0; i<NC*NC; i++)
      U->u[v][i] = u0[i];
  }
  return;
}
