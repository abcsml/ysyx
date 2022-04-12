// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmux2.h for the primary calling header

#include "Vmux2___024root.h"
#include "Vmux2__Syms.h"

//==========


void Vmux2___024root___ctor_var_reset(Vmux2___024root* vlSelf);

Vmux2___024root::Vmux2___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vmux2___024root___ctor_var_reset(this);
}

void Vmux2___024root::__Vconfigure(Vmux2__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vmux2___024root::~Vmux2___024root() {
}

void Vmux2___024root___eval_initial(Vmux2___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux2___024root___eval_initial\n"); );
}

void Vmux2___024root___combo__TOP__1(Vmux2___024root* vlSelf);

void Vmux2___024root___eval_settle(Vmux2___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux2___024root___eval_settle\n"); );
    // Body
    Vmux2___024root___combo__TOP__1(vlSelf);
}

void Vmux2___024root___final(Vmux2___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux2___024root___final\n"); );
}

void Vmux2___024root___ctor_var_reset(Vmux2___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux2___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->a = 0;
    vlSelf->b = 0;
    vlSelf->s = 0;
    vlSelf->y = 0;
}
