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
    for NS in [2,4]:
        if NS == 2:
            n = "hspinor"
        else:
            n = "spinor"
        xr = sy.zeros((NS, NC))
        xi = sy.zeros((NS, NC))
        yr = sy.zeros((NC, NC))
        yi = sy.zeros((NC, NC))
        for i in range(NS):
            for j in range(NC):
                k = (j + i*NC)
                xr[k] = sy.Symbol('x[%2d+0]' % (2*k), real=True)
                xi[k] = sy.Symbol('x[%2d+1]' % (2*k), real=True)
        for i in range(NC):
            for j in range(NC):
                k = (j + i*NC)
                yr[k] = sy.Symbol('y[%2d+0]' % (2*k), real=True)
                yi[k] = sy.Symbol('y[%2d+1]' % (2*k), real=True)
        x = sy.Matrix(NS, NC, lambda i, j: xr[j+i*NC] + xi[j+i*NC]*I)
        y = sy.Matrix(NC, NC, lambda i, j: yr[j+i*NC] + yi[j+i*NC]*I)

        ### U*psi
        body += "static %s void\n" % inline_tag
        body += "su3_%s(qReal *z, qReal *y, qReal *x)\n{\n" % n
        z = ((y*x.T).T).expand()
        for i in range(NS):
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

        ### U^+*psi
        body += "static %s void\n" % inline_tag
        body += "su3_%s_dag(qReal *z, qReal *y, qReal *x)\n{\n" % n
        z = ((y.transpose().conjugate()*x.T).T).expand()
        for i in range(NS):
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
