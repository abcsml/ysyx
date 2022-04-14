// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VALU4way.h for the primary calling header

#ifndef VERILATED_VALU4WAY___024ROOT_H_
#define VERILATED_VALU4WAY___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class VALU4way__Syms;
class VALU4way_VerilatedVcd;


//----------

VL_MODULE(VALU4way___024root) {
  public:

    // PORTS
    VL_IN8(a,3,0);
    VL_IN8(b,3,0);
    VL_IN8(sel,2,0);
    VL_OUT8(out,3,0);
    VL_OUT8(cf,0,0);
    VL_OUT8(of,0,0);
    VL_OUT8(zf,0,0);

    // LOCAL SIGNALS
    CData/*3:0*/ ALU4way__DOT__add;
    CData/*3:0*/ ALU4way__DOT__sub;

    // LOCAL VARIABLES
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;

    // INTERNAL VARIABLES
    VALU4way__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VALU4way___024root);  ///< Copying not allowed
  public:
    VALU4way___024root(const char* name);
    ~VALU4way___024root();

    // INTERNAL METHODS
    void __Vconfigure(VALU4way__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
