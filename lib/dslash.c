#include <defs.h>
#include <precision.h>
#include <spinors.h>
#include <spinor_linalg.h>
#include <su3_spinor.h>

static PR(half_spinor_field) *hsp;

void
PR(dslash_init)(lattice *lat)
{
  hsp = PR(new_half_spinor_field)(lat);
  return;
}

void
PR(dslash)(PR(spinor_field) *out, PR(spinor_field) *in, PR(gauge_field) *U, double mass)
{
  lattice *lat = U->L;
  int (*nn)[2*ND] = lat->nn;
  int vol = 1;
  for(int i=0; i<ND; i++)
    vol *= lat->dims[i];
  for(int v=0; v<vol; v++) {
    qComplex *h = hsp->s[v];
    qComplex *s = in->s[v];
    qComplex *q = out->s[v];
    qComplex *u = U->u[v*ND];
    proj_one_p_gamma_x(h, s);
    su3_hspinor_dag((qReal *)h, (qReal *)u, (qReal *)h);
    recon_one_p_gamma_x(q, h);
  }
  return;
}

void
PR(dslash_finalize)(void)
{  
  PR(del_half_spinor_field)(hsp);
  return;
}

