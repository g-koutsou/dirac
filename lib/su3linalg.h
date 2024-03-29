#ifndef _SU3LINALG_H
#define _SU3LINALG_H 1
#include <precision.h>

#ifndef INLINE
#define INLINE inline
#endif

/* BEGIN python generated segment */
#if NC == 3
static INLINE void
su3_mul_uu(qReal *z, qReal *x, qReal *y)
{
  z[ 0+0] = /* (0,0), re */
	x[ 0+0]*y[ 0+0] - x[ 0+1]*y[ 0+1] + x[ 2+0]*y[ 6+0] - x[ 2+1]*y[ 6+1] +
	x[ 4+0]*y[12+0] - x[ 4+1]*y[12+1];
  z[ 0+1] = /* (0,0), im */
	x[ 0+0]*y[ 0+1] + x[ 0+1]*y[ 0+0] + x[ 2+0]*y[ 6+1] + x[ 2+1]*y[ 6+0] +
	x[ 4+0]*y[12+1] + x[ 4+1]*y[12+0];
  z[ 2+0] = /* (0,1), re */
	x[ 0+0]*y[ 2+0] - x[ 0+1]*y[ 2+1] + x[ 2+0]*y[ 8+0] - x[ 2+1]*y[ 8+1] +
	x[ 4+0]*y[14+0] - x[ 4+1]*y[14+1];
  z[ 2+1] = /* (0,1), im */
	x[ 0+0]*y[ 2+1] + x[ 0+1]*y[ 2+0] + x[ 2+0]*y[ 8+1] + x[ 2+1]*y[ 8+0] +
	x[ 4+0]*y[14+1] + x[ 4+1]*y[14+0];
  z[ 4+0] = /* (0,2), re */
	x[ 0+0]*y[ 4+0] - x[ 0+1]*y[ 4+1] + x[ 2+0]*y[10+0] - x[ 2+1]*y[10+1] +
	x[ 4+0]*y[16+0] - x[ 4+1]*y[16+1];
  z[ 4+1] = /* (0,2), im */
	x[ 0+0]*y[ 4+1] + x[ 0+1]*y[ 4+0] + x[ 2+0]*y[10+1] + x[ 2+1]*y[10+0] +
	x[ 4+0]*y[16+1] + x[ 4+1]*y[16+0];

  z[ 6+0] = /* (1,0), re */
	x[ 6+0]*y[ 0+0] - x[ 6+1]*y[ 0+1] + x[ 8+0]*y[ 6+0] - x[ 8+1]*y[ 6+1] +
	x[10+0]*y[12+0] - x[10+1]*y[12+1];
  z[ 6+1] = /* (1,0), im */
	x[ 6+0]*y[ 0+1] + x[ 6+1]*y[ 0+0] + x[ 8+0]*y[ 6+1] + x[ 8+1]*y[ 6+0] +
	x[10+0]*y[12+1] + x[10+1]*y[12+0];
  z[ 8+0] = /* (1,1), re */
	x[ 6+0]*y[ 2+0] - x[ 6+1]*y[ 2+1] + x[ 8+0]*y[ 8+0] - x[ 8+1]*y[ 8+1] +
	x[10+0]*y[14+0] - x[10+1]*y[14+1];
  z[ 8+1] = /* (1,1), im */
	x[ 6+0]*y[ 2+1] + x[ 6+1]*y[ 2+0] + x[ 8+0]*y[ 8+1] + x[ 8+1]*y[ 8+0] +
	x[10+0]*y[14+1] + x[10+1]*y[14+0];
  z[10+0] = /* (1,2), re */
	x[ 6+0]*y[ 4+0] - x[ 6+1]*y[ 4+1] + x[ 8+0]*y[10+0] - x[ 8+1]*y[10+1] +
	x[10+0]*y[16+0] - x[10+1]*y[16+1];
  z[10+1] = /* (1,2), im */
	x[ 6+0]*y[ 4+1] + x[ 6+1]*y[ 4+0] + x[ 8+0]*y[10+1] + x[ 8+1]*y[10+0] +
	x[10+0]*y[16+1] + x[10+1]*y[16+0];

  z[12+0] = /* (2,0), re */
	x[12+0]*y[ 0+0] - x[12+1]*y[ 0+1] + x[14+0]*y[ 6+0] - x[14+1]*y[ 6+1] +
	x[16+0]*y[12+0] - x[16+1]*y[12+1];
  z[12+1] = /* (2,0), im */
	x[12+0]*y[ 0+1] + x[12+1]*y[ 0+0] + x[14+0]*y[ 6+1] + x[14+1]*y[ 6+0] +
	x[16+0]*y[12+1] + x[16+1]*y[12+0];
  z[14+0] = /* (2,1), re */
	x[12+0]*y[ 2+0] - x[12+1]*y[ 2+1] + x[14+0]*y[ 8+0] - x[14+1]*y[ 8+1] +
	x[16+0]*y[14+0] - x[16+1]*y[14+1];
  z[14+1] = /* (2,1), im */
	x[12+0]*y[ 2+1] + x[12+1]*y[ 2+0] + x[14+0]*y[ 8+1] + x[14+1]*y[ 8+0] +
	x[16+0]*y[14+1] + x[16+1]*y[14+0];
  z[16+0] = /* (2,2), re */
	x[12+0]*y[ 4+0] - x[12+1]*y[ 4+1] + x[14+0]*y[10+0] - x[14+1]*y[10+1] +
	x[16+0]*y[16+0] - x[16+1]*y[16+1];
  z[16+1] = /* (2,2), im */
	x[12+0]*y[ 4+1] + x[12+1]*y[ 4+0] + x[14+0]*y[10+1] + x[14+1]*y[10+0] +
	x[16+0]*y[16+1] + x[16+1]*y[16+0];

  return;
}

static INLINE void
su3_mul_ud(qReal *z, qReal *x, qReal *y)
{
  z[ 0+0] = /* (0,0), re */
	x[ 0+0]*y[ 0+0] + x[ 0+1]*y[ 0+1] + x[ 2+0]*y[ 2+0] + x[ 2+1]*y[ 2+1] +
	x[ 4+0]*y[ 4+0] + x[ 4+1]*y[ 4+1];
  z[ 0+1] = /* (0,0), im */
	-x[ 0+0]*y[ 0+1] + x[ 0+1]*y[ 0+0] - x[ 2+0]*y[ 2+1] + x[ 2+1]*y[ 2+0] -
	x[ 4+0]*y[ 4+1] + x[ 4+1]*y[ 4+0];
  z[ 2+0] = /* (0,1), re */
	x[ 0+0]*y[ 6+0] + x[ 0+1]*y[ 6+1] + x[ 2+0]*y[ 8+0] + x[ 2+1]*y[ 8+1] +
	x[ 4+0]*y[10+0] + x[ 4+1]*y[10+1];
  z[ 2+1] = /* (0,1), im */
	-x[ 0+0]*y[ 6+1] + x[ 0+1]*y[ 6+0] - x[ 2+0]*y[ 8+1] + x[ 2+1]*y[ 8+0] -
	x[ 4+0]*y[10+1] + x[ 4+1]*y[10+0];
  z[ 4+0] = /* (0,2), re */
	x[ 0+0]*y[12+0] + x[ 0+1]*y[12+1] + x[ 2+0]*y[14+0] + x[ 2+1]*y[14+1] +
	x[ 4+0]*y[16+0] + x[ 4+1]*y[16+1];
  z[ 4+1] = /* (0,2), im */
	-x[ 0+0]*y[12+1] + x[ 0+1]*y[12+0] - x[ 2+0]*y[14+1] + x[ 2+1]*y[14+0] -
	x[ 4+0]*y[16+1] + x[ 4+1]*y[16+0];

  z[ 6+0] = /* (1,0), re */
	x[ 6+0]*y[ 0+0] + x[ 6+1]*y[ 0+1] + x[ 8+0]*y[ 2+0] + x[ 8+1]*y[ 2+1] +
	x[10+0]*y[ 4+0] + x[10+1]*y[ 4+1];
  z[ 6+1] = /* (1,0), im */
	-x[ 6+0]*y[ 0+1] + x[ 6+1]*y[ 0+0] - x[ 8+0]*y[ 2+1] + x[ 8+1]*y[ 2+0] -
	x[10+0]*y[ 4+1] + x[10+1]*y[ 4+0];
  z[ 8+0] = /* (1,1), re */
	x[ 6+0]*y[ 6+0] + x[ 6+1]*y[ 6+1] + x[ 8+0]*y[ 8+0] + x[ 8+1]*y[ 8+1] +
	x[10+0]*y[10+0] + x[10+1]*y[10+1];
  z[ 8+1] = /* (1,1), im */
	-x[ 6+0]*y[ 6+1] + x[ 6+1]*y[ 6+0] - x[ 8+0]*y[ 8+1] + x[ 8+1]*y[ 8+0] -
	x[10+0]*y[10+1] + x[10+1]*y[10+0];
  z[10+0] = /* (1,2), re */
	x[ 6+0]*y[12+0] + x[ 6+1]*y[12+1] + x[ 8+0]*y[14+0] + x[ 8+1]*y[14+1] +
	x[10+0]*y[16+0] + x[10+1]*y[16+1];
  z[10+1] = /* (1,2), im */
	-x[ 6+0]*y[12+1] + x[ 6+1]*y[12+0] - x[ 8+0]*y[14+1] + x[ 8+1]*y[14+0] -
	x[10+0]*y[16+1] + x[10+1]*y[16+0];

  z[12+0] = /* (2,0), re */
	x[12+0]*y[ 0+0] + x[12+1]*y[ 0+1] + x[14+0]*y[ 2+0] + x[14+1]*y[ 2+1] +
	x[16+0]*y[ 4+0] + x[16+1]*y[ 4+1];
  z[12+1] = /* (2,0), im */
	-x[12+0]*y[ 0+1] + x[12+1]*y[ 0+0] - x[14+0]*y[ 2+1] + x[14+1]*y[ 2+0] -
	x[16+0]*y[ 4+1] + x[16+1]*y[ 4+0];
  z[14+0] = /* (2,1), re */
	x[12+0]*y[ 6+0] + x[12+1]*y[ 6+1] + x[14+0]*y[ 8+0] + x[14+1]*y[ 8+1] +
	x[16+0]*y[10+0] + x[16+1]*y[10+1];
  z[14+1] = /* (2,1), im */
	-x[12+0]*y[ 6+1] + x[12+1]*y[ 6+0] - x[14+0]*y[ 8+1] + x[14+1]*y[ 8+0] -
	x[16+0]*y[10+1] + x[16+1]*y[10+0];
  z[16+0] = /* (2,2), re */
	x[12+0]*y[12+0] + x[12+1]*y[12+1] + x[14+0]*y[14+0] + x[14+1]*y[14+1] +
	x[16+0]*y[16+0] + x[16+1]*y[16+1];
  z[16+1] = /* (2,2), im */
	-x[12+0]*y[12+1] + x[12+1]*y[12+0] - x[14+0]*y[14+1] + x[14+1]*y[14+0] -
	x[16+0]*y[16+1] + x[16+1]*y[16+0];

  return;
}

static INLINE void
su3_mul_du(qReal *z, qReal *x, qReal *y)
{
  z[ 0+0] = /* (0,0), re */
	x[ 0+0]*y[ 0+0] + x[ 0+1]*y[ 0+1] + x[ 6+0]*y[ 6+0] + x[ 6+1]*y[ 6+1] +
	x[12+0]*y[12+0] + x[12+1]*y[12+1];
  z[ 0+1] = /* (0,0), im */
	x[ 0+0]*y[ 0+1] - x[ 0+1]*y[ 0+0] + x[ 6+0]*y[ 6+1] - x[ 6+1]*y[ 6+0] +
	x[12+0]*y[12+1] - x[12+1]*y[12+0];
  z[ 2+0] = /* (0,1), re */
	x[ 0+0]*y[ 2+0] + x[ 0+1]*y[ 2+1] + x[ 6+0]*y[ 8+0] + x[ 6+1]*y[ 8+1] +
	x[12+0]*y[14+0] + x[12+1]*y[14+1];
  z[ 2+1] = /* (0,1), im */
	x[ 0+0]*y[ 2+1] - x[ 0+1]*y[ 2+0] + x[ 6+0]*y[ 8+1] - x[ 6+1]*y[ 8+0] +
	x[12+0]*y[14+1] - x[12+1]*y[14+0];
  z[ 4+0] = /* (0,2), re */
	x[ 0+0]*y[ 4+0] + x[ 0+1]*y[ 4+1] + x[ 6+0]*y[10+0] + x[ 6+1]*y[10+1] +
	x[12+0]*y[16+0] + x[12+1]*y[16+1];
  z[ 4+1] = /* (0,2), im */
	x[ 0+0]*y[ 4+1] - x[ 0+1]*y[ 4+0] + x[ 6+0]*y[10+1] - x[ 6+1]*y[10+0] +
	x[12+0]*y[16+1] - x[12+1]*y[16+0];

  z[ 6+0] = /* (1,0), re */
	x[ 2+0]*y[ 0+0] + x[ 2+1]*y[ 0+1] + x[ 8+0]*y[ 6+0] + x[ 8+1]*y[ 6+1] +
	x[14+0]*y[12+0] + x[14+1]*y[12+1];
  z[ 6+1] = /* (1,0), im */
	x[ 2+0]*y[ 0+1] - x[ 2+1]*y[ 0+0] + x[ 8+0]*y[ 6+1] - x[ 8+1]*y[ 6+0] +
	x[14+0]*y[12+1] - x[14+1]*y[12+0];
  z[ 8+0] = /* (1,1), re */
	x[ 2+0]*y[ 2+0] + x[ 2+1]*y[ 2+1] + x[ 8+0]*y[ 8+0] + x[ 8+1]*y[ 8+1] +
	x[14+0]*y[14+0] + x[14+1]*y[14+1];
  z[ 8+1] = /* (1,1), im */
	x[ 2+0]*y[ 2+1] - x[ 2+1]*y[ 2+0] + x[ 8+0]*y[ 8+1] - x[ 8+1]*y[ 8+0] +
	x[14+0]*y[14+1] - x[14+1]*y[14+0];
  z[10+0] = /* (1,2), re */
	x[ 2+0]*y[ 4+0] + x[ 2+1]*y[ 4+1] + x[ 8+0]*y[10+0] + x[ 8+1]*y[10+1] +
	x[14+0]*y[16+0] + x[14+1]*y[16+1];
  z[10+1] = /* (1,2), im */
	x[ 2+0]*y[ 4+1] - x[ 2+1]*y[ 4+0] + x[ 8+0]*y[10+1] - x[ 8+1]*y[10+0] +
	x[14+0]*y[16+1] - x[14+1]*y[16+0];

  z[12+0] = /* (2,0), re */
	x[ 4+0]*y[ 0+0] + x[ 4+1]*y[ 0+1] + x[10+0]*y[ 6+0] + x[10+1]*y[ 6+1] +
	x[16+0]*y[12+0] + x[16+1]*y[12+1];
  z[12+1] = /* (2,0), im */
	x[ 4+0]*y[ 0+1] - x[ 4+1]*y[ 0+0] + x[10+0]*y[ 6+1] - x[10+1]*y[ 6+0] +
	x[16+0]*y[12+1] - x[16+1]*y[12+0];
  z[14+0] = /* (2,1), re */
	x[ 4+0]*y[ 2+0] + x[ 4+1]*y[ 2+1] + x[10+0]*y[ 8+0] + x[10+1]*y[ 8+1] +
	x[16+0]*y[14+0] + x[16+1]*y[14+1];
  z[14+1] = /* (2,1), im */
	x[ 4+0]*y[ 2+1] - x[ 4+1]*y[ 2+0] + x[10+0]*y[ 8+1] - x[10+1]*y[ 8+0] +
	x[16+0]*y[14+1] - x[16+1]*y[14+0];
  z[16+0] = /* (2,2), re */
	x[ 4+0]*y[ 4+0] + x[ 4+1]*y[ 4+1] + x[10+0]*y[10+0] + x[10+1]*y[10+1] +
	x[16+0]*y[16+0] + x[16+1]*y[16+1];
  z[16+1] = /* (2,2), im */
	x[ 4+0]*y[ 4+1] - x[ 4+1]*y[ 4+0] + x[10+0]*y[10+1] - x[10+1]*y[10+0] +
	x[16+0]*y[16+1] - x[16+1]*y[16+0];

  return;
}

static INLINE void
su3_mul_dd(qReal *z, qReal *x, qReal *y)
{
  z[ 0+0] = /* (0,0), re */
	x[ 0+0]*y[ 0+0] + x[ 0+1]*y[ 0+1] + x[ 6+0]*y[ 6+0] + x[ 6+1]*y[ 6+1] +
	x[12+0]*y[12+0] + x[12+1]*y[12+1];
  z[ 0+1] = /* (0,0), im */
	x[ 0+0]*y[ 0+1] - x[ 0+1]*y[ 0+0] + x[ 6+0]*y[ 6+1] - x[ 6+1]*y[ 6+0] +
	x[12+0]*y[12+1] - x[12+1]*y[12+0];
  z[ 2+0] = /* (0,1), re */
	x[ 0+0]*y[ 2+0] + x[ 0+1]*y[ 2+1] + x[ 6+0]*y[ 8+0] + x[ 6+1]*y[ 8+1] +
	x[12+0]*y[14+0] + x[12+1]*y[14+1];
  z[ 2+1] = /* (0,1), im */
	x[ 0+0]*y[ 2+1] - x[ 0+1]*y[ 2+0] + x[ 6+0]*y[ 8+1] - x[ 6+1]*y[ 8+0] +
	x[12+0]*y[14+1] - x[12+1]*y[14+0];
  z[ 4+0] = /* (0,2), re */
	x[ 0+0]*y[ 4+0] + x[ 0+1]*y[ 4+1] + x[ 6+0]*y[10+0] + x[ 6+1]*y[10+1] +
	x[12+0]*y[16+0] + x[12+1]*y[16+1];
  z[ 4+1] = /* (0,2), im */
	x[ 0+0]*y[ 4+1] - x[ 0+1]*y[ 4+0] + x[ 6+0]*y[10+1] - x[ 6+1]*y[10+0] +
	x[12+0]*y[16+1] - x[12+1]*y[16+0];

  z[ 6+0] = /* (1,0), re */
	x[ 2+0]*y[ 0+0] + x[ 2+1]*y[ 0+1] + x[ 8+0]*y[ 6+0] + x[ 8+1]*y[ 6+1] +
	x[14+0]*y[12+0] + x[14+1]*y[12+1];
  z[ 6+1] = /* (1,0), im */
	x[ 2+0]*y[ 0+1] - x[ 2+1]*y[ 0+0] + x[ 8+0]*y[ 6+1] - x[ 8+1]*y[ 6+0] +
	x[14+0]*y[12+1] - x[14+1]*y[12+0];
  z[ 8+0] = /* (1,1), re */
	x[ 2+0]*y[ 2+0] + x[ 2+1]*y[ 2+1] + x[ 8+0]*y[ 8+0] + x[ 8+1]*y[ 8+1] +
	x[14+0]*y[14+0] + x[14+1]*y[14+1];
  z[ 8+1] = /* (1,1), im */
	x[ 2+0]*y[ 2+1] - x[ 2+1]*y[ 2+0] + x[ 8+0]*y[ 8+1] - x[ 8+1]*y[ 8+0] +
	x[14+0]*y[14+1] - x[14+1]*y[14+0];
  z[10+0] = /* (1,2), re */
	x[ 2+0]*y[ 4+0] + x[ 2+1]*y[ 4+1] + x[ 8+0]*y[10+0] + x[ 8+1]*y[10+1] +
	x[14+0]*y[16+0] + x[14+1]*y[16+1];
  z[10+1] = /* (1,2), im */
	x[ 2+0]*y[ 4+1] - x[ 2+1]*y[ 4+0] + x[ 8+0]*y[10+1] - x[ 8+1]*y[10+0] +
	x[14+0]*y[16+1] - x[14+1]*y[16+0];

  z[12+0] = /* (2,0), re */
	x[ 4+0]*y[ 0+0] + x[ 4+1]*y[ 0+1] + x[10+0]*y[ 6+0] + x[10+1]*y[ 6+1] +
	x[16+0]*y[12+0] + x[16+1]*y[12+1];
  z[12+1] = /* (2,0), im */
	x[ 4+0]*y[ 0+1] - x[ 4+1]*y[ 0+0] + x[10+0]*y[ 6+1] - x[10+1]*y[ 6+0] +
	x[16+0]*y[12+1] - x[16+1]*y[12+0];
  z[14+0] = /* (2,1), re */
	x[ 4+0]*y[ 2+0] + x[ 4+1]*y[ 2+1] + x[10+0]*y[ 8+0] + x[10+1]*y[ 8+1] +
	x[16+0]*y[14+0] + x[16+1]*y[14+1];
  z[14+1] = /* (2,1), im */
	x[ 4+0]*y[ 2+1] - x[ 4+1]*y[ 2+0] + x[10+0]*y[ 8+1] - x[10+1]*y[ 8+0] +
	x[16+0]*y[14+1] - x[16+1]*y[14+0];
  z[16+0] = /* (2,2), re */
	x[ 4+0]*y[ 4+0] + x[ 4+1]*y[ 4+1] + x[10+0]*y[10+0] + x[10+1]*y[10+1] +
	x[16+0]*y[16+0] + x[16+1]*y[16+1];
  z[16+1] = /* (2,2), im */
	x[ 4+0]*y[ 4+1] - x[ 4+1]*y[ 4+0] + x[10+0]*y[10+1] - x[10+1]*y[10+0] +
	x[16+0]*y[16+1] - x[16+1]*y[16+0];

  return;
}

#endif /* NC */

#endif /* _SU3LINALG_H */

