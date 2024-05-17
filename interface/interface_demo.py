import taylor_cos
import taylor_sin
import taylor_asin
import taylor_atan
b = taylor_cos.initialize()
a = taylor_sin.initialize()
c = taylor_asin.initialize()
d = taylor_atan.initialize()

angle1 = 60.0
terms1 = 10.0
num = 0.50
terms2 = 20.0
sin_result = a.taylor_sin(angle1, terms1)
cos_result = b.taylor_cos(angle1, terms1)
asin_result = c.taylor_asin(num, terms2)
atan_result = d.taylor_atan(num, terms2)
print(sin_result)
print(cos_result)
print(asin_result)
print(atan_result)