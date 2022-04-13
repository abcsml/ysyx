// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vencoder42p.h for the primary calling header

#include "Vencoder42p___024root.h"
#include "Vencoder42p__Syms.h"

//==========


void Vencoder42p___024root___ctor_var_reset(Vencoder42p___024root* vlSelf);

Vencoder42p___024root::Vencoder42p___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vencoder42p___024root___ctor_var_reset(this);
}

void Vencoder42p___024root::__Vconfigure(Vencoder42p__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vencoder42p___024root::~Vencoder42p___024root() {
}

void Vencoder42p___024root___eval_initial(Vencoder42p___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencoder42p__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencoder42p___024root___eval_initial\n"); );
}

void Vencoder42p___024root___combo__TOP__1(Vencoder42p___024root* vlSelf);

void Vencoder42p___024root___eval_settle(Vencoder42p___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencoder42p__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencoder42p___024root___eval_settle\n"); );
    // Body
    Vencoder42p___024root___combo__TOP__1(vlSelf);
}

void Vencoder42p___024root___final(Vencoder42p___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencoder42p__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencoder42p___024root___final\n"); );
}

void Vencoder42p___024root___ctor_var_reset(Vencoder42p___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencoder42p__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencoder42p___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->x = 0;
    vlSelf->en = 0;
    vlSelf->y = 0;
    vlSelf->encoder42p__DOT__i = 0;
}
