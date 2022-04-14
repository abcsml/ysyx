// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VALU4way.h for the primary calling header

#include "VALU4way___024root.h"
#include "VALU4way__Syms.h"

//==========


void VALU4way___024root___ctor_var_reset(VALU4way___024root* vlSelf);

VALU4way___024root::VALU4way___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VALU4way___024root___ctor_var_reset(this);
}

void VALU4way___024root::__Vconfigure(VALU4way__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VALU4way___024root::~VALU4way___024root() {
}

void VALU4way___024root___eval_initial(VALU4way___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU4way___024root___eval_initial\n"); );
}

void VALU4way___024root___combo__TOP__1(VALU4way___024root* vlSelf);

void VALU4way___024root___eval_settle(VALU4way___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU4way___024root___eval_settle\n"); );
    // Body
    VALU4way___024root___combo__TOP__1(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

void VALU4way___024root___final(VALU4way___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU4way___024root___final\n"); );
}

void VALU4way___024root___ctor_var_reset(VALU4way___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU4way___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->a = 0;
    vlSelf->b = 0;
    vlSelf->sel = 0;
    vlSelf->out = 0;
    vlSelf->cf = 0;
    vlSelf->of = 0;
    vlSelf->zf = 0;
    vlSelf->ALU4way__DOT__add = 0;
    vlSelf->ALU4way__DOT__sub = 0;
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
