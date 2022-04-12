// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmux2.h for the primary calling header

#ifndef VERILATED_VMUX2___024ROOT_H_
#define VERILATED_VMUX2___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class Vmux2__Syms;
class Vmux2_VerilatedVcd;


//----------

VL_MODULE(Vmux2___024root) {
  public:

    // PORTS
    VL_IN8(a,0,0);
    VL_IN8(b,0,0);
    VL_IN8(s,0,0);
    VL_OUT8(y,0,0);

    // INTERNAL VARIABLES
    Vmux2__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vmux2___024root);  ///< Copying not allowed
  public:
    Vmux2___024root(const char* name);
    ~Vmux2___024root();

    // INTERNAL METHODS
    void __Vconfigure(Vmux2__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
