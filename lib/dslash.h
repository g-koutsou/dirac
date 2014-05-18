#ifndef _DSLASH_H 
#define _DSLASH_H 1
#include <defs.h>
void dslash_init_sp(lattice *);
void dslash_init_dp(lattice *);
void dslash_finalize_sp(void);
void dslash_finalize_dp(void);
void dslash_dp(spinor_field_dp *, spinor_field_dp *, gauge_field_dp *, double);
void dslash_sp(spinor_field_sp *, spinor_field_sp *, gauge_field_sp *, double);
#endif /* _DSLASH_H */
