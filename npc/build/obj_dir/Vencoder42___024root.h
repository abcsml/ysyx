// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vencoder42.h for the primary calling header

#ifndef VERILATED_VENCODER42___024ROOT_H_
#define VERILATED_VENCODER42___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class Vencoder42__Syms;
class Vencoder42_VerilatedVcd;


//----------

VL_MODULE(Vencoder42___024root) {
  public:

    // PORTS
    VL_IN8(x,3,0);
    VL_IN8(en,0,0);
    VL_OUT8(y,1,0);

    // INTERNAL VARIABLES
    Vencoder42__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vencoder42___024root);  ///< Copying not allowed
  public:
    Vencoder42___024root(const char* name);
    ~Vencoder42___024root();

    // INTERNAL METHODS
    void __Vconfigure(Vencoder42__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
