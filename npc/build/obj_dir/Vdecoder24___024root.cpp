// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdecoder24.h for the primary calling header

#include "Vdecoder24___024root.h"
#include "Vdecoder24__Syms.h"

//==========

VL_INLINE_OPT void Vdecoder24___024root___combo__TOP__1(Vdecoder24___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdecoder24__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecoder24___024root___combo__TOP__1\n"); );
    // Body
    vlSelf->y = ((0xeU & (IData)(vlSelf->y)) | (((~ (IData)(vlSelf->x)) 
                                                 & (IData)(vlSelf->en)) 
                                                & (~ 
                                                   ((IData)(vlSelf->x) 
                                                    >> 1U))));
    vlSelf->y = ((0xdU & (IData)(vlSelf->y)) | ((((IData)(vlSelf->x) 
                                                  & (IData)(vlSelf->en)) 
                                                 & (~ 
                                                    ((IData)(vlSelf->x) 
                                                     >> 1U))) 
                                                << 1U));
    vlSelf->y = ((0xbU & (IData)(vlSelf->y)) | (0xfffffffcU 
                                                & ((((~ (IData)(vlSelf->x)) 
                                                     & (IData)(vlSelf->en)) 
                                                    << 2U) 
                                                   & ((IData)(vlSelf->x) 
                                                      << 1U))));
    vlSelf->y = ((7U & (IData)(vlSelf->y)) | (0xfffffff8U 
                                              & ((((IData)(vlSelf->x) 
                                                   & (IData)(vlSelf->en)) 
                                                  << 3U) 
                                                 & ((IData)(vlSelf->x) 
                                                    << 2U))));
}

void Vdecoder24___024root___eval(Vdecoder24___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdecoder24__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecoder24___024root___eval\n"); );
    // Body
    Vdecoder24___024root___combo__TOP__1(vlSelf);
}

QData Vdecoder24___024root___change_request_1(Vdecoder24___024root* vlSelf);

VL_INLINE_OPT QData Vdecoder24___024root___change_request(Vdecoder24___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdecoder24__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecoder24___024root___change_request\n"); );
    // Body
    return (Vdecoder24___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData Vdecoder24___024root___change_request_1(Vdecoder24___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdecoder24__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecoder24___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vdecoder24___024root___eval_debug_assertions(Vdecoder24___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdecoder24__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecoder24___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->x & 0xfcU))) {
        Verilated::overWidthError("x");}
    if (VL_UNLIKELY((vlSelf->en & 0xfeU))) {
        Verilated::overWidthError("en");}
}
#endif  // VL_DEBUG
