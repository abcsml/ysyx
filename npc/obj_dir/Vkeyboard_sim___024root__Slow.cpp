// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vkeyboard_sim.h for the primary calling header

#include "Vkeyboard_sim___024root.h"
#include "Vkeyboard_sim__Syms.h"

//==========


void Vkeyboard_sim___024root___ctor_var_reset(Vkeyboard_sim___024root* vlSelf);

Vkeyboard_sim___024root::Vkeyboard_sim___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vkeyboard_sim___024root___ctor_var_reset(this);
}

void Vkeyboard_sim___024root::__Vconfigure(Vkeyboard_sim__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vkeyboard_sim___024root::~Vkeyboard_sim___024root() {
}

void Vkeyboard_sim___024root___initial__TOP__1(Vkeyboard_sim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vkeyboard_sim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeyboard_sim___024root___initial__TOP__1\n"); );
    // Body
    VL_STOP_MT("vsrc/exp7/keyboard_sim_tb.v", 51, "");
    vlSelf->keyboard_sim__DOT__clk = 0U;
    while (1U) {
        vlSelf->keyboard_sim__DOT__clk = (1U & (~ (IData)(vlSelf->keyboard_sim__DOT__clk)));
    }
}

void Vkeyboard_sim___024root___eval_initial(Vkeyboard_sim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vkeyboard_sim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeyboard_sim___024root___eval_initial\n"); );
    // Body
    Vkeyboard_sim___024root___initial__TOP__1(vlSelf);
    vlSelf->__Vclklast__TOP__keyboard_sim__DOT__clk 
        = vlSelf->keyboard_sim__DOT__clk;
}

void Vkeyboard_sim___024root___eval_settle(Vkeyboard_sim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vkeyboard_sim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeyboard_sim___024root___eval_settle\n"); );
}

void Vkeyboard_sim___024root___final(Vkeyboard_sim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vkeyboard_sim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeyboard_sim___024root___final\n"); );
}

void Vkeyboard_sim___024root___ctor_var_reset(Vkeyboard_sim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vkeyboard_sim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeyboard_sim___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->keyboard_sim__DOT__clk = VL_RAND_RESET_I(1);
}
