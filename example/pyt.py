from ctypes import *

_sum = CDLL('./sum_numbers.so')
_sum.sum_numbers.argtypes = (c_int, POINTER(c_int), c_void_p)
def print_number(number):
    print("Calling from within Python. Woo")
    print(number)
    return 0

def our_function(numbers):
    global _sum
    num_numbers = len(numbers)
    array_type = c_int *num_numbers
    func = CFUNCTYPE(c_int, c_int)(print_number)
    func.restype = None
    result = _sum.sum_numbers(c_int(num_numbers), array_type(*numbers), func)
    return int(result)

print(our_function([1,2,3,4]))

