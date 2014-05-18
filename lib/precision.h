#ifndef _PRECISION_H
#define _PRECISION_H 1

#ifdef SINGLE_PRECISION
#define PR(x) x ## _sp
typedef _Complex float qComplex;
typedef float qReal;
#else
#define PR(x) x ## _dp
typedef _Complex double qComplex;
typedef double qReal;
#endif

#endif /* _PRECISION_H */
