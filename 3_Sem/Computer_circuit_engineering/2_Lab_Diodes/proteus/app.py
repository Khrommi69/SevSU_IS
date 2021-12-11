#!/bin/python3

import math

U_in   = float(input ("Введите значение входного напряжения, В:  "))
dU_in  = float(input ("Введите изменение входного напряжения, В: "))
U_out  = float(input ("Введите значение выходного напряжения, В: "))
dU_out = float(input ("Введите изменение ходного напряжения, В:  "))

K_st = (dU_in * U_out) / (dU_out * U_in)

print("Получен коэффициент стабилизации:  %.4f." % (K_st))