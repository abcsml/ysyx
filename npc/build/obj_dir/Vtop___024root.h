// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class Vtop__Syms;

//----------

VL_MODULE(Vtop___024root) {
  public:

    // PORTS
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(ps2_clk,0,0);
    VL_IN8(ps2_data,0,0);
    VL_OUT8(VGA_CLK,0,0);
    VL_OUT8(VGA_HSYNC,0,0);
    VL_OUT8(VGA_VSYNC,0,0);
    VL_OUT8(VGA_BLANK_N,0,0);
    VL_OUT8(VGA_R,7,0);
    VL_OUT8(VGA_G,7,0);
    VL_OUT8(VGA_B,7,0);
    VL_OUT8(seg0,7,0);
    VL_OUT8(seg1,7,0);
    VL_OUT8(seg2,7,0);
    VL_OUT8(seg3,7,0);
    VL_OUT8(seg4,7,0);
    VL_OUT8(seg5,7,0);
    VL_OUT8(seg6,7,0);
    VL_OUT8(seg7,7,0);
    VL_IN16(sw,15,0);
    VL_OUT16(ledr,15,0);

    // LOCAL SIGNALS
    CData/*7:0*/ top__DOT__num;
    CData/*7:0*/ top__DOT__ascii;
    CData/*7:0*/ top__DOT__sum;
    CData/*7:0*/ top__DOT__p2__DOT__data;
    CData/*0:0*/ top__DOT__p2__DOT__ready;
    CData/*0:0*/ top__DOT__p2__DOT__overflow;
    CData/*0:0*/ top__DOT__p2__DOT__nextdata_n;
    CData/*2:0*/ top__DOT__p2__DOT__p1__DOT__w_ptr;
    CData/*2:0*/ top__DOT__p2__DOT__p1__DOT__r_ptr;
    CData/*3:0*/ top__DOT__p2__DOT__p1__DOT__count;
    CData/*2:0*/ top__DOT__p2__DOT__p1__DOT__ps2_clk_sync;
    SData/*9:0*/ top__DOT__p2__DOT__p1__DOT__buffer;
    IData/*31:0*/ top__DOT__p2__DOT__ifpress;
    IData/*31:0*/ top__DOT__p2__DOT__over;
    VlUnpacked<CData/*7:0*/, 8> top__DOT__p2__DOT__p1__DOT__fifo;

    // LOCAL VARIABLES
    CData/*0:0*/ top__DOT__p2__DOT__p1__DOT____Vlvbound1;
    CData/*0:0*/ __Vclklast__TOP__clk;
    IData/*31:0*/ __Vchglast__TOP__top__DOT__p2__DOT__over;

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtop___024root);  ///< Copying not allowed
  public:
    Vtop___024root(const char* name);
    ~Vtop___024root();

    // INTERNAL METHODS
    void __Vconfigure(Vtop__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
