// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vkeyboard_sim.h for the primary calling header

#ifndef VERILATED_VKEYBOARD_SIM___024ROOT_H_
#define VERILATED_VKEYBOARD_SIM___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class Vkeyboard_sim__Syms;

//----------

VL_MODULE(Vkeyboard_sim___024root) {
  public:

    // LOCAL SIGNALS
    CData/*0:0*/ keyboard_sim__DOT__clk;

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__keyboard_sim__DOT__clk;

    // INTERNAL VARIABLES
    Vkeyboard_sim__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vkeyboard_sim___024root);  ///< Copying not allowed
  public:
    Vkeyboard_sim___024root(const char* name);
    ~Vkeyboard_sim___024root();

    // INTERNAL METHODS
    void __Vconfigure(Vkeyboard_sim__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
