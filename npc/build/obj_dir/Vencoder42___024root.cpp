// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vencoder42.h for the primary calling header

#include "Vencoder42___024root.h"
#include "Vencoder42__Syms.h"

//==========

VL_INLINE_OPT void Vencoder42___024root___combo__TOP__1(Vencoder42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencoder42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencoder42___024root___combo__TOP__1\n"); );
    // Body
    vlSelf->y = ((2U & (IData)(vlSelf->y)) | ((IData)(
                                                      (2U 
                                                       == 
                                                       (0xfU 
                                                        & (IData)(vlSelf->x)))) 
                                              & (IData)(vlSelf->en)));
    vlSelf->y = ((2U & (IData)(vlSelf->y)) | ((IData)(
                                                      (8U 
                                                       == 
                                                       (0xfU 
                                                        & (IData)(vlSelf->x)))) 
                                              & (IData)(vlSelf->en)));
    vlSelf->y = ((1U & (IData)(vlSelf->y)) | (((IData)(
                                                       (4U 
                                                        == 
                                                        (0xfU 
                                                         & (IData)(vlSelf->x)))) 
                                               & (IData)(vlSelf->en)) 
                                              << 1U));
    vlSelf->y = ((1U & (IData)(vlSelf->y)) | (((IData)(
                                                       (8U 
                                                        == 
                                                        (0xfU 
                                                         & (IData)(vlSelf->x)))) 
                                               & (IData)(vlSelf->en)) 
                                              << 1U));
}

void Vencoder42___024root___eval(Vencoder42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencoder42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencoder42___024root___eval\n"); );
    // Body
    Vencoder42___024root___combo__TOP__1(vlSelf);
}

QData Vencoder42___024root___change_request_1(Vencoder42___024root* vlSelf);

VL_INLINE_OPT QData Vencoder42___024root___change_request(Vencoder42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencoder42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencoder42___024root___change_request\n"); );
    // Body
    return (Vencoder42___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData Vencoder42___024root___change_request_1(Vencoder42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencoder42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencoder42___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vencoder42___024root___eval_debug_assertions(Vencoder42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencoder42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencoder42___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->x & 0xf0U))) {
        Verilated::overWidthError("x");}
    if (VL_UNLIKELY((vlSelf->en & 0xfeU))) {
        Verilated::overWidthError("en");}
}
#endif  // VL_DEBUG
