#ifndef _SPINOR_LINALG_H
#define _SPINOR_LINALG_H 1

/*
 * Projections
 */
static INLINE void
proj_one_p_gamma_x(qComplex *out, qComplex *in)
{
  for(int c=0; c<NC; c++) {
    out[c+ 0] = in[c+ 0] + I*in[c+3*NS];
    out[c+NS] = in[c+NS] + I*in[c+2*NS];
  }
  return;
}

static INLINE void
proj_one_p_gamma_y(qComplex *out, qComplex *in)
{
  for(int c=0; c<NC; c++) {
    out[c+ 0] = in[c+ 0] + in[c+3*NS];
    out[c+NS] = in[c+NS] - in[c+2*NS];
  }
  return;
}

static INLINE void
proj_one_p_gamma_z(qComplex *out, qComplex *in)
{
  for(int c=0; c<NC; c++) {
    out[c+ 0] = in[c+ 0] + I*in[c+2*NS];
    out[c+NS] = in[c+NS] - I*in[c+3*NS];
  }
  return;
}

static INLINE void
proj_one_p_gamma_t(qComplex *out, qComplex *in)
{
  for(int c=0; c<NC; c++) {
    out[c+ 0] = 2*in[c+ 0];
    out[c+NS] = 2*in[c+NS];
  }

  return;
}

static INLINE void
proj_one_m_gamma_x(qComplex *out, qComplex *in)
{
  for(int c=0; c<NC; c++) {
    out[c+ 0] = in[c+ 0] - I*in[c+3*NS];
    out[c+NS] = in[c+NS] - I*in[c+2*NS];
  }
  return;
}

static INLINE void
proj_one_m_gamma_y(qComplex *out, qComplex *in)
{
  for(int c=0; c<NC; c++) {
    out[c+ 0] = in[c+ 0] - in[c+3*NS];
    out[c+NS] = in[c+NS] + in[c+2*NS];
  }
  return;
}

static INLINE void
proj_one_m_gamma_z(qComplex *out, qComplex *in)
{
  for(int c=0; c<NC; c++) {
    out[c+ 0] = in[c+ 0] - I*in[c+2*NS];
    out[c+NS] = in[c+NS] + I*in[c+3*NS];
  }
  return;
}

static INLINE void
proj_one_m_gamma_t(qComplex *out, qComplex *in)
{
  for(int c=0; c<NC; c++) {
    out[c+ 0] = 2*in[c+2*NS];
    out[c+NS] = 2*in[c+3*NS];
  }
  return;
}

/*
 * Reconstructions
 */

static INLINE void
recon_one_p_gamma_x(qComplex *out, qComplex *in)
{
  for(int c=0; c<NC; c++) {
    out[c+0] = in[c+0];
    out[c+NS] = in[c+NS];
    out[c+2*NS] = -I*in[c+NS];
    out[c+3*NS] = -I*in[c+0];
  }
  return;
}

static INLINE void
recon_one_p_gamma_y(qComplex *out, qComplex *in)
{
  for(int c=0; c<NC; c++) {
    out[c+0] = in[c+0];
    out[c+NS] = in[c+NS];
    out[c+2*NS] = -in[c+NS];
    out[c+3*NS] = in[c+0];
  }
  return;
}

static INLINE void
recon_one_p_gamma_z(qComplex *out, qComplex *in)
{
  for(int c=0; c<NC; c++) {
    out[c+0] = in[c+0];
    out[c+NS] = in[c+NS];
    out[c+2*NS] = -I*in[c+NS];
    out[c+3*NS] = I*in[c+0*NS];
  }
  return;
}

static INLINE void
recon_one_p_gamma_t(qComplex *out, qComplex *in)
{
  for(int c=0; c<NC; c++) {
    out[c+ 0] = in[c+ 0];
    out[c+NS] = in[c+NS];
    out[c+2*NS] = 0;
    out[c+3*NS] = 0;
  }

  return;
}

static INLINE void
recon_one_m_gamma_x(qComplex *out, qComplex *in)
{
  for(int c=0; c<NC; c++) {
    out[c+0] = in[c+0];
    out[c+NS] = in[c+NS];
    out[c+2*NS] = I*in[c+NS];
    out[c+3*NS] = I*in[c+0];
  }
  return;
}

static INLINE void
recon_one_m_gamma_y(qComplex *out, qComplex *in)
{
  for(int c=0; c<NC; c++) {
    out[c+ 0] = in[c+ 0];
    out[c+NS] = in[c+NS];
    out[c+2*NS] = in[c+NS];
    out[c+3*NS] = -in[c+0];
  }
  return;
}

static INLINE void
recon_one_m_gamma_z(qComplex *out, qComplex *in)
{
  for(int c=0; c<NC; c++) {
    out[c+ 0] = in[c+ 0];
    out[c+NS] = in[c+NS];
    out[c+2*NS] = I*in[c+ 0];
    out[c+3*NS] = -I*in[c+NS];
  }
  return;
}

static INLINE void
recon_one_m_gamma_t(qComplex *out, qComplex *in)
{
  for(int c=0; c<NC; c++) {
    out[c+ 0] = 0;
    out[c+NS] = 0;
    out[c+2*NS] = in[c+0];
    out[c+3*NS] = in[c+NS];
  }
  return;
}

#endif /* _SPINOR_LINALG_H */
