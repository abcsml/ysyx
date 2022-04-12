// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop___024root.h"
#include "Vtop__Syms.h"

//==========

VL_INLINE_OPT void Vtop___024root___combo__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___combo__TOP__1\n"); );
    // Variables
    CData/*1:0*/ top__DOT____Vcellout__m1__y;
    CData/*1:0*/ top__DOT__m1__DOT__m0__DOT__i0__DOT__lut_out;
    SData/*15:0*/ top__DOT__m1__DOT____Vcellinp__m0____pinNumber3;
    // Body
    top__DOT__m1__DOT____Vcellinp__m0____pinNumber3 
        = (0x48cU | ((0x3000U & ((IData)(vlSelf->sw) 
                                 << 0xaU)) | ((0x300U 
                                               & ((IData)(vlSelf->sw) 
                                                  << 4U)) 
                                              | ((0x30U 
                                                  & ((IData)(vlSelf->sw) 
                                                     >> 2U)) 
                                                 | (3U 
                                                    & ((IData)(vlSelf->sw) 
                                                       >> 8U))))));
    vlSelf->top__DOT__m1__DOT__m0__DOT__i0__DOT__pair_list[0U] 
        = (0xfU & (IData)(top__DOT__m1__DOT____Vcellinp__m0____pinNumber3));
    vlSelf->top__DOT__m1__DOT__m0__DOT__i0__DOT__pair_list[1U] 
        = (0xfU & ((IData)(top__DOT__m1__DOT____Vcellinp__m0____pinNumber3) 
                   >> 4U));
    vlSelf->top__DOT__m1__DOT__m0__DOT__i0__DOT__pair_list[2U] 
        = (0xfU & ((IData)(top__DOT__m1__DOT____Vcellinp__m0____pinNumber3) 
                   >> 8U));
    vlSelf->top__DOT__m1__DOT__m0__DOT__i0__DOT__pair_list[3U] 
        = (0xfU & ((IData)(top__DOT__m1__DOT____Vcellinp__m0____pinNumber3) 
                   >> 0xcU));
    vlSelf->top__DOT__m1__DOT__m0__DOT__i0__DOT__data_list[0U] 
        = (3U & vlSelf->top__DOT__m1__DOT__m0__DOT__i0__DOT__pair_list
           [0U]);
    vlSelf->top__DOT__m1__DOT__m0__DOT__i0__DOT__key_list[0U] 
        = (3U & (vlSelf->top__DOT__m1__DOT__m0__DOT__i0__DOT__pair_list
                 [0U] >> 2U));
    vlSelf->top__DOT__m1__DOT__m0__DOT__i0__DOT__data_list[1U] 
        = (3U & vlSelf->top__DOT__m1__DOT__m0__DOT__i0__DOT__pair_list
           [1U]);
    vlSelf->top__DOT__m1__DOT__m0__DOT__i0__DOT__key_list[1U] 
        = (3U & (vlSelf->top__DOT__m1__DOT__m0__DOT__i0__DOT__pair_list
                 [1U] >> 2U));
    vlSelf->top__DOT__m1__DOT__m0__DOT__i0__DOT__data_list[2U] 
        = (3U & vlSelf->top__DOT__m1__DOT__m0__DOT__i0__DOT__pair_list
           [2U]);
    vlSelf->top__DOT__m1__DOT__m0__DOT__i0__DOT__key_list[2U] 
        = (3U & (vlSelf->top__DOT__m1__DOT__m0__DOT__i0__DOT__pair_list
                 [2U] >> 2U));
    vlSelf->top__DOT__m1__DOT__m0__DOT__i0__DOT__data_list[3U] 
        = (3U & vlSelf->top__DOT__m1__DOT__m0__DOT__i0__DOT__pair_list
           [3U]);
    vlSelf->top__DOT__m1__DOT__m0__DOT__i0__DOT__key_list[3U] 
        = (3U & (vlSelf->top__DOT__m1__DOT__m0__DOT__i0__DOT__pair_list
                 [3U] >> 2U));
    top__DOT__m1__DOT__m0__DOT__i0__DOT__lut_out = 
        ((- (IData)(((3U & (IData)(vlSelf->sw)) == 
                     vlSelf->top__DOT__m1__DOT__m0__DOT__i0__DOT__key_list
                     [0U]))) & vlSelf->top__DOT__m1__DOT__m0__DOT__i0__DOT__data_list
         [0U]);
    top__DOT__m1__DOT__m0__DOT__i0__DOT__lut_out = 
        ((IData)(top__DOT__m1__DOT__m0__DOT__i0__DOT__lut_out) 
         | ((- (IData)(((3U & (IData)(vlSelf->sw)) 
                        == vlSelf->top__DOT__m1__DOT__m0__DOT__i0__DOT__key_list
                        [1U]))) & vlSelf->top__DOT__m1__DOT__m0__DOT__i0__DOT__data_list
            [1U]));
    top__DOT__m1__DOT__m0__DOT__i0__DOT__lut_out = 
        ((IData)(top__DOT__m1__DOT__m0__DOT__i0__DOT__lut_out) 
         | ((- (IData)(((3U & (IData)(vlSelf->sw)) 
                        == vlSelf->top__DOT__m1__DOT__m0__DOT__i0__DOT__key_list
                        [2U]))) & vlSelf->top__DOT__m1__DOT__m0__DOT__i0__DOT__data_list
            [2U]));
    top__DOT__m1__DOT__m0__DOT__i0__DOT__lut_out = 
        ((IData)(top__DOT__m1__DOT__m0__DOT__i0__DOT__lut_out) 
         | ((- (IData)(((3U & (IData)(vlSelf->sw)) 
                        == vlSelf->top__DOT__m1__DOT__m0__DOT__i0__DOT__key_list
                        [3U]))) & vlSelf->top__DOT__m1__DOT__m0__DOT__i0__DOT__data_list
            [3U]));
    top__DOT____Vcellout__m1__y = top__DOT__m1__DOT__m0__DOT__i0__DOT__lut_out;
    vlSelf->ledr = ((0xfffcU & (IData)(vlSelf->ledr)) 
                    | (IData)(top__DOT____Vcellout__m1__y));
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Body
    Vtop___024root___combo__TOP__1(vlSelf);
}

QData Vtop___024root___change_request_1(Vtop___024root* vlSelf);

VL_INLINE_OPT QData Vtop___024root___change_request(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___change_request\n"); );
    // Body
    return (Vtop___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData Vtop___024root___change_request_1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->ps2_clk & 0xfeU))) {
        Verilated::overWidthError("ps2_clk");}
    if (VL_UNLIKELY((vlSelf->ps2_data & 0xfeU))) {
        Verilated::overWidthError("ps2_data");}
}
#endif  // VL_DEBUG
