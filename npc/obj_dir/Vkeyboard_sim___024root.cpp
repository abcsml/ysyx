// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vkeyboard_sim.h for the primary calling header

#include "Vkeyboard_sim___024root.h"
#include "Vkeyboard_sim__Syms.h"

//==========

void Vkeyboard_sim___024root___eval(Vkeyboard_sim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vkeyboard_sim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeyboard_sim___024root___eval\n"); );
    // Final
    vlSelf->__Vclklast__TOP__keyboard_sim__DOT__clk 
        = vlSelf->keyboard_sim__DOT__clk;
}

QData Vkeyboard_sim___024root___change_request_1(Vkeyboard_sim___024root* vlSelf);

VL_INLINE_OPT QData Vkeyboard_sim___024root___change_request(Vkeyboard_sim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vkeyboard_sim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeyboard_sim___024root___change_request\n"); );
    // Body
    return (Vkeyboard_sim___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData Vkeyboard_sim___024root___change_request_1(Vkeyboard_sim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vkeyboard_sim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeyboard_sim___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vkeyboard_sim___024root___eval_debug_assertions(Vkeyboard_sim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vkeyboard_sim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeyboard_sim___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
