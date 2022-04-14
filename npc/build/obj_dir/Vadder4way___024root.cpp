// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadder4way.h for the primary calling header

#include "Vadder4way___024root.h"
#include "Vadder4way__Syms.h"

//==========

VL_INLINE_OPT void Vadder4way___024root___combo__TOP__1(Vadder4way___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadder4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder4way___024root___combo__TOP__1\n"); );
    // Body
    vlSelf->c = (1U & (((IData)(1U) + ((IData)(vlSelf->x) 
                                       + (0xfU & (~ (IData)(vlSelf->y))))) 
                       >> 4U));
    vlSelf->s = (0xfU & ((IData)(1U) + ((IData)(vlSelf->x) 
                                        + (~ (IData)(vlSelf->y)))));
    vlSelf->z = (1U & (~ (IData)((0U != (IData)(vlSelf->s)))));
    vlSelf->o = (1U & ((~ (((IData)(vlSelf->x) >> 3U) 
                           ^ (~ ((IData)(vlSelf->y) 
                                 >> 3U)))) & (((IData)(vlSelf->s) 
                                               ^ (IData)(vlSelf->x)) 
                                              >> 3U)));
}

void Vadder4way___024root___eval(Vadder4way___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadder4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder4way___024root___eval\n"); );
    // Body
    Vadder4way___024root___combo__TOP__1(vlSelf);
}

QData Vadder4way___024root___change_request_1(Vadder4way___024root* vlSelf);

VL_INLINE_OPT QData Vadder4way___024root___change_request(Vadder4way___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadder4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder4way___024root___change_request\n"); );
    // Body
    return (Vadder4way___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData Vadder4way___024root___change_request_1(Vadder4way___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadder4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder4way___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vadder4way___024root___eval_debug_assertions(Vadder4way___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadder4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadder4way___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->x & 0xf0U))) {
        Verilated::overWidthError("x");}
    if (VL_UNLIKELY((vlSelf->y & 0xf0U))) {
        Verilated::overWidthError("y");}
}
#endif  // VL_DEBUG
