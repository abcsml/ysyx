// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vencoder42p.h for the primary calling header

#include "Vencoder42p___024root.h"
#include "Vencoder42p__Syms.h"

//==========

extern const VlUnpacked<CData/*1:0*/, 32> Vencoder42p__ConstPool__TABLE_865ffb6b_0;
extern const VlUnpacked<CData/*1:0*/, 32> Vencoder42p__ConstPool__TABLE_e3e536ad_0;
extern const VlUnpacked<IData/*31:0*/, 32> Vencoder42p__ConstPool__TABLE_1cbc8a47_0;

VL_INLINE_OPT void Vencoder42p___024root___combo__TOP__1(Vencoder42p___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencoder42p__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencoder42p___024root___combo__TOP__1\n"); );
    // Variables
    CData/*4:0*/ __Vtableidx1;
    // Body
    __Vtableidx1 = (((IData)(vlSelf->x) << 1U) | (IData)(vlSelf->en));
    vlSelf->y = Vencoder42p__ConstPool__TABLE_865ffb6b_0
        [__Vtableidx1];
    if ((2U & Vencoder42p__ConstPool__TABLE_e3e536ad_0
         [__Vtableidx1])) {
        vlSelf->encoder42p__DOT__i = Vencoder42p__ConstPool__TABLE_1cbc8a47_0
            [__Vtableidx1];
    }
}

void Vencoder42p___024root___eval(Vencoder42p___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencoder42p__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencoder42p___024root___eval\n"); );
    // Body
    Vencoder42p___024root___combo__TOP__1(vlSelf);
}

QData Vencoder42p___024root___change_request_1(Vencoder42p___024root* vlSelf);

VL_INLINE_OPT QData Vencoder42p___024root___change_request(Vencoder42p___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencoder42p__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencoder42p___024root___change_request\n"); );
    // Body
    return (Vencoder42p___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData Vencoder42p___024root___change_request_1(Vencoder42p___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencoder42p__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencoder42p___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vencoder42p___024root___eval_debug_assertions(Vencoder42p___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencoder42p__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencoder42p___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->x & 0xf0U))) {
        Verilated::overWidthError("x");}
    if (VL_UNLIKELY((vlSelf->en & 0xfeU))) {
        Verilated::overWidthError("en");}
}
#endif  // VL_DEBUG
