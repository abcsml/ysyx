// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vadder4way.h for the primary calling header

#ifndef VERILATED_VADDER4WAY___024ROOT_H_
#define VERILATED_VADDER4WAY___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class Vadder4way__Syms;
class Vadder4way_VerilatedVcd;


//----------

VL_MODULE(Vadder4way___024root) {
  public:

    // PORTS
    VL_IN8(x,3,0);
    VL_IN8(y,3,0);
    VL_OUT8(s,3,0);
    VL_OUT8(c,0,0);
    VL_OUT8(o,0,0);
    VL_OUT8(z,0,0);

    // INTERNAL VARIABLES
    Vadder4way__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vadder4way___024root);  ///< Copying not allowed
  public:
    Vadder4way___024root(const char* name);
    ~Vadder4way___024root();

    // INTERNAL METHODS
    void __Vconfigure(Vadder4way__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
