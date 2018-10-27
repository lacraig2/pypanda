from ctypes import *
from common import *
papi = CDLL("panda_api.so")

class pypanda:
    def __init__(self):
        self.cmd_line_args = ""
        self.callbacks = {}
        self.papi_start = wrap_function(papi, "start", [c_int], c_int)
        self.papi_rr_instr_count = wrap_function(papi, "rr_instr_count", None, c_int)

    def init(cmd_line_args):
        # pass structure containing callbacks to lower structure
        self.cmd_line_args = cmd_line_args
    
    def register_callback(self, callback, function):
        if self.callbacks[callback]:
            self.callbacks[callback].append(function)
        else
            self.callbacks[callback] = [function]
    
    def start(self):
        # command line arg should probably be binary c_wchar_p 
        return self.papi_start(self.cmd_line_arg, structform(self.callbacks))
    
    def rr_instr_count():
        return self.papi_rr_instr_count()


'''
something here about loading from the API
'''
class callback:
    pass
