// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vencoder42.h for the primary calling header

#include "Vencoder42___024root.h"
#include "Vencoder42__Syms.h"

//==========


void Vencoder42___024root___ctor_var_reset(Vencoder42___024root* vlSelf);

Vencoder42___024root::Vencoder42___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vencoder42___024root___ctor_var_reset(this);
}

void Vencoder42___024root::__Vconfigure(Vencoder42__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vencoder42___024root::~Vencoder42___024root() {
}

void Vencoder42___024root___eval_initial(Vencoder42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencoder42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencoder42___024root___eval_initial\n"); );
}

void Vencoder42___024root___combo__TOP__1(Vencoder42___024root* vlSelf);

void Vencoder42___024root___eval_settle(Vencoder42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencoder42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencoder42___024root___eval_settle\n"); );
    // Body
    Vencoder42___024root___combo__TOP__1(vlSelf);
}

void Vencoder42___024root___final(Vencoder42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencoder42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencoder42___024root___final\n"); );
}

void Vencoder42___024root___ctor_var_reset(Vencoder42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencoder42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencoder42___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->x = 0;
    vlSelf->en = 0;
    vlSelf->y = 0;
}
