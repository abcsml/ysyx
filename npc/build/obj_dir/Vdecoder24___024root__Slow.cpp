// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdecoder24.h for the primary calling header

#include "Vdecoder24___024root.h"
#include "Vdecoder24__Syms.h"

//==========


void Vdecoder24___024root___ctor_var_reset(Vdecoder24___024root* vlSelf);

Vdecoder24___024root::Vdecoder24___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vdecoder24___024root___ctor_var_reset(this);
}

void Vdecoder24___024root::__Vconfigure(Vdecoder24__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vdecoder24___024root::~Vdecoder24___024root() {
}

void Vdecoder24___024root___eval_initial(Vdecoder24___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdecoder24__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecoder24___024root___eval_initial\n"); );
}

void Vdecoder24___024root___combo__TOP__1(Vdecoder24___024root* vlSelf);

void Vdecoder24___024root___eval_settle(Vdecoder24___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdecoder24__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecoder24___024root___eval_settle\n"); );
    // Body
    Vdecoder24___024root___combo__TOP__1(vlSelf);
}

void Vdecoder24___024root___final(Vdecoder24___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdecoder24__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecoder24___024root___final\n"); );
}

void Vdecoder24___024root___ctor_var_reset(Vdecoder24___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdecoder24__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecoder24___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->x = 0;
    vlSelf->en = 0;
    vlSelf->y = 0;
}
