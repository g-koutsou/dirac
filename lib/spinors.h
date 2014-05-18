#ifndef _SPINORS_H
#define _SPINORS_H 1
#include <defs.h>
spinor_field_sp * new_spinor_field_sp(lattice *);
spinor_field_dp * new_spinor_field_dp(lattice *);
void del_spinor_field_sp(spinor_field_sp *);
void del_spinor_field_dp(spinor_field_dp *);

half_spinor_field_sp * new_half_spinor_field_sp(lattice *);
half_spinor_field_dp * new_half_spinor_field_dp(lattice *);
void del_half_spinor_field_sp(half_spinor_field_sp *);
void del_half_spinor_field_dp(half_spinor_field_dp *);
#endif /* _SPINORS_H */
