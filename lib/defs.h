#ifndef _DEFS_H
#define _DEFS_H 1
#include <complex.h>

#define ND 4
#define NS 4
#define NC 3

typedef struct {
  int dims[ND];  
  int (*nn)[2*ND];
} lattice;

typedef struct {
  _Complex float (*u)[NC*NC];
  lattice *L;
} gauge_field_sp;

typedef struct {
  _Complex double (*u)[NC*NC];
  lattice *L;
} gauge_field_dp;

typedef struct {
  _Complex float (*s)[NC*NS];
  lattice *L;
} spinor_field_sp;

typedef struct {
  _Complex double (*s)[NC*NS];
  lattice *L;
} spinor_field_dp;

#endif /* _DEFS_H */
