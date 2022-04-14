// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadder4way.h for the primary calling header

#include "Vadder4way___024root.h"
#include "Vadder4way__Syms.h"

//==========


void Vadder4way___024root___ctor_var_reset(Vadder4way___024root* vlSelf);

Vadder4way___024root::Vadder4way___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vadder4way___024root___ctor_var_reset(this);
}

void Vadder4way___024root::__Vconfigure(Vadder4way__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vadder4way___024root::~Vadder4way___024root() {
}

void Vadder4way___024root___eval_initial(Vadder4way___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadder4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder4way___024root___eval_initial\n"); );
}

void Vadder4way___024root___combo__TOP__1(Vadder4way___024root* vlSelf);

void Vadder4way___024root___eval_settle(Vadder4way___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadder4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder4way___024root___eval_settle\n"); );
    // Body
    Vadder4way___024root___combo__TOP__1(vlSelf);
}

void Vadder4way___024root___final(Vadder4way___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadder4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder4way___024root___final\n"); );
}

void Vadder4way___024root___ctor_var_reset(Vadder4way___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadder4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder4way___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->x = 0;
    vlSelf->y = 0;
    vlSelf->s = 0;
    vlSelf->c = 0;
    vlSelf->o = 0;
    vlSelf->z = 0;
}
