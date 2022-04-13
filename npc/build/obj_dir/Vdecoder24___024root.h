// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdecoder24.h for the primary calling header

#ifndef VERILATED_VDECODER24___024ROOT_H_
#define VERILATED_VDECODER24___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class Vdecoder24__Syms;
class Vdecoder24_VerilatedVcd;


//----------

VL_MODULE(Vdecoder24___024root) {
  public:

    // PORTS
    VL_IN8(x,1,0);
    VL_IN8(en,0,0);
    VL_OUT8(y,3,0);

    // INTERNAL VARIABLES
    Vdecoder24__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vdecoder24___024root);  ///< Copying not allowed
  public:
    Vdecoder24___024root(const char* name);
    ~Vdecoder24___024root();

    // INTERNAL METHODS
    void __Vconfigure(Vdecoder24__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
