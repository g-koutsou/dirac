#!/usr/bin/python
import sympy as sy
import textwrap
I = sy.I
wrap = textwrap.wrap
NWRAP = 72
NS = 4
inline_tag = "INLINE"

filename = __file__
fp = open(filename.replace(".py", ".pytmpl.h"), "r")
tmpl = fp.read()
fp.close()

body = "/* BEGIN python generated segment */\n"
for NC in [3]:
    body += "#if NC == %d\n" % NC
    xr = sy.zeros((NC, NC))
    xi = sy.zeros((NC, NC))
    yr = sy.zeros((NC, NC))
    yi = sy.zeros((NC, NC))
    for i in range(NC):
        for j in range(NC):
            k = (j + i*NC)
            xr[k] = sy.Symbol('x[%2d+0]' % (2*k), real=True)
            xi[k] = sy.Symbol('x[%2d+1]' % (2*k), real=True)
            yr[k] = sy.Symbol('y[%2d+0]' % (2*k), real=True)
            yi[k] = sy.Symbol('y[%2d+1]' % (2*k), real=True)
    x = sy.Matrix(NC, NC, lambda i, j: xr[j+i*NC] + xi[j+i*NC]*I)
    y = sy.Matrix(NC, NC, lambda i, j: yr[j+i*NC] + yi[j+i*NC]*I)
    
    ### U * U
    body += "%s void\n" % inline_tag
    body += "su3_mul_uu(qReal *z, qReal *x, qReal *y)\n{\n"
    z = (x*y).expand()
    for i in range(NC):
        for j in range(NC):
            k = j + i*NC            
            reim = z[i, j].as_real_imag()
            body += "  z[%2d+0] = /* (%d,%d), re */\n" % (2*k, i, j)
            for line in wrap(str(reim[0])+";", NWRAP):
                body += "\t%s\n" % line
            body += "  z[%2d+1] = /* (%d,%d), im */\n" % (2*k, i, j)
            for line in wrap(str(reim[1])+";", NWRAP):
                body += "\t%s\n" % line
        body += "\n"
    body += "  return;\n}\n\n"

    ### U * U^+
    body += "%s void\n" % inline_tag
    body += "su3_mul_ud(qReal *z, qReal *x, qReal *y)\n{\n"
    z = (x*y.transpose().conjugate()).expand()
    for i in range(NC):
        for j in range(NC):
            k = j + i*NC            
            reim = z[i, j].as_real_imag()
            body += "  z[%2d+0] = /* (%d,%d), re */\n" % (2*k, i, j)
            for line in wrap(str(reim[0])+";", NWRAP):
                body += "\t%s\n" % line
            body += "  z[%2d+1] = /* (%d,%d), im */\n" % (2*k, i, j)
            for line in wrap(str(reim[1])+";", NWRAP):
                body += "\t%s\n" % line
        body += "\n"
    body += "  return;\n}\n\n"

    ### U^+ * U
    body += "%s void\n" % inline_tag
    body += "su3_mul_du(qReal *z, qReal *x, qReal *y)\n{\n"
    z = (x.transpose().conjugate()*y).expand()
    for i in range(NC):
        for j in range(NC):
            k = j + i*NC            
            reim = z[i, j].as_real_imag()
            body += "  z[%2d+0] = /* (%d,%d), re */\n" % (2*k, i, j)
            for line in wrap(str(reim[0])+";", NWRAP):
                body += "\t%s\n" % line
            body += "  z[%2d+1] = /* (%d,%d), im */\n" % (2*k, i, j)
            for line in wrap(str(reim[1])+";", NWRAP):
                body += "\t%s\n" % line
        body += "\n"
    body += "  return;\n}\n\n"

    ### U^+ * U^+
    body += "%s void\n" % inline_tag
    body += "su3_mul_dd(qReal *z, qReal *x, qReal *y)\n{\n"
    z = (x.transpose().conjugate()*y).expand()
    for i in range(NC):
        for j in range(NC):
            k = j + i*NC            
            reim = z[i, j].as_real_imag()
            body += "  z[%2d+0] = /* (%d,%d), re */\n" % (2*k, i, j)
            for line in wrap(str(reim[0])+";", NWRAP):
                body += "\t%s\n" % line
            body += "  z[%2d+1] = /* (%d,%d), im */\n" % (2*k, i, j)
            for line in wrap(str(reim[1])+";", NWRAP):
                body += "\t%s\n" % line
        body += "\n"
    body += "  return;\n}\n\n"
body += "#endif /* NC */\n"
print tmpl.replace("XXXBODYXXX", body)
