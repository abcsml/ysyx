// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop___024root.h"
#include "Vtop__Syms.h"

//==========

VL_INLINE_OPT void Vtop___024root___sequent__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__1\n"); );
    // Variables
    CData/*2:0*/ __Vdly__top__DOT__inst__DOT__ps2_clk_sync;
    CData/*2:0*/ __Vdly__top__DOT__inst__DOT__r_ptr;
    CData/*2:0*/ __Vdlyvdim0__top__DOT__inst__DOT__fifo__v0;
    CData/*7:0*/ __Vdlyvval__top__DOT__inst__DOT__fifo__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__inst__DOT__fifo__v0;
    CData/*2:0*/ __Vdly__top__DOT__inst__DOT__w_ptr;
    CData/*3:0*/ __Vdly__top__DOT__inst__DOT__count;
    // Body
    __Vdly__top__DOT__inst__DOT__ps2_clk_sync = vlSelf->top__DOT__inst__DOT__ps2_clk_sync;
    __Vdly__top__DOT__inst__DOT__count = vlSelf->top__DOT__inst__DOT__count;
    __Vdly__top__DOT__inst__DOT__w_ptr = vlSelf->top__DOT__inst__DOT__w_ptr;
    __Vdly__top__DOT__inst__DOT__r_ptr = vlSelf->top__DOT__inst__DOT__r_ptr;
    __Vdlyvset__top__DOT__inst__DOT__fifo__v0 = 0U;
    __Vdly__top__DOT__inst__DOT__ps2_clk_sync = ((6U 
                                                  & ((IData)(vlSelf->top__DOT__inst__DOT__ps2_clk_sync) 
                                                     << 1U)) 
                                                 | (IData)(vlSelf->ps2_clk));
    if ((1U & (IData)(vlSelf->sw))) {
        if (vlSelf->top__DOT____Vcellout__inst__ready) {
            if ((1U & (~ ((IData)(vlSelf->sw) >> 1U)))) {
                __Vdly__top__DOT__inst__DOT__r_ptr 
                    = (7U & ((IData)(1U) + (IData)(vlSelf->top__DOT__inst__DOT__r_ptr)));
                if (((IData)(vlSelf->top__DOT__inst__DOT__w_ptr) 
                     == (7U & ((IData)(1U) + (IData)(vlSelf->top__DOT__inst__DOT__r_ptr))))) {
                    vlSelf->top__DOT____Vcellout__inst__ready = 0U;
                }
            }
        }
        if ((IData)((4U == (6U & (IData)(vlSelf->top__DOT__inst__DOT__ps2_clk_sync))))) {
            if ((0xaU == (IData)(vlSelf->top__DOT__inst__DOT__count))) {
                if (VL_UNLIKELY((((~ (IData)(vlSelf->top__DOT__inst__DOT__buffer)) 
                                  & (IData)(vlSelf->ps2_data)) 
                                 & VL_REDXOR_32((0x1ffU 
                                                 & ((IData)(vlSelf->top__DOT__inst__DOT__buffer) 
                                                    >> 1U)))))) {
                    VL_WRITEF("receive %x\n",8,(0xffU 
                                                & ((IData)(vlSelf->top__DOT__inst__DOT__buffer) 
                                                   >> 1U)));
                    __Vdlyvval__top__DOT__inst__DOT__fifo__v0 
                        = (0xffU & ((IData)(vlSelf->top__DOT__inst__DOT__buffer) 
                                    >> 1U));
                    __Vdlyvset__top__DOT__inst__DOT__fifo__v0 = 1U;
                    __Vdlyvdim0__top__DOT__inst__DOT__fifo__v0 
                        = vlSelf->top__DOT__inst__DOT__w_ptr;
                    vlSelf->top__DOT____Vcellout__inst__ready = 1U;
                    __Vdly__top__DOT__inst__DOT__w_ptr 
                        = (7U & ((IData)(1U) + (IData)(vlSelf->top__DOT__inst__DOT__w_ptr)));
                    vlSelf->top__DOT____Vcellout__inst__overflow 
                        = ((IData)(vlSelf->top__DOT____Vcellout__inst__overflow) 
                           | ((IData)(vlSelf->top__DOT__inst__DOT__r_ptr) 
                              == (7U & ((IData)(1U) 
                                        + (IData)(vlSelf->top__DOT__inst__DOT__w_ptr)))));
                }
                __Vdly__top__DOT__inst__DOT__count = 0U;
            } else {
                vlSelf->top__DOT__inst__DOT____Vlvbound1 
                    = vlSelf->ps2_data;
                if ((9U >= (IData)(vlSelf->top__DOT__inst__DOT__count))) {
                    vlSelf->top__DOT__inst__DOT__buffer 
                        = (((~ ((IData)(1U) << (IData)(vlSelf->top__DOT__inst__DOT__count))) 
                            & (IData)(vlSelf->top__DOT__inst__DOT__buffer)) 
                           | (0x3ffU & ((IData)(vlSelf->top__DOT__inst__DOT____Vlvbound1) 
                                        << (IData)(vlSelf->top__DOT__inst__DOT__count))));
                }
                __Vdly__top__DOT__inst__DOT__count 
                    = (0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__inst__DOT__count)));
            }
        }
    } else {
        __Vdly__top__DOT__inst__DOT__count = 0U;
        __Vdly__top__DOT__inst__DOT__w_ptr = 0U;
        __Vdly__top__DOT__inst__DOT__r_ptr = 0U;
        vlSelf->top__DOT____Vcellout__inst__overflow = 0U;
        vlSelf->top__DOT____Vcellout__inst__ready = 0U;
    }
    vlSelf->top__DOT__inst__DOT__ps2_clk_sync = __Vdly__top__DOT__inst__DOT__ps2_clk_sync;
    vlSelf->top__DOT__inst__DOT__w_ptr = __Vdly__top__DOT__inst__DOT__w_ptr;
    vlSelf->top__DOT__inst__DOT__count = __Vdly__top__DOT__inst__DOT__count;
    vlSelf->top__DOT__inst__DOT__r_ptr = __Vdly__top__DOT__inst__DOT__r_ptr;
    if (__Vdlyvset__top__DOT__inst__DOT__fifo__v0) {
        vlSelf->top__DOT__inst__DOT__fifo[__Vdlyvdim0__top__DOT__inst__DOT__fifo__v0] 
            = __Vdlyvval__top__DOT__inst__DOT__fifo__v0;
    }
    vlSelf->ledr = ((0xfc00U & (IData)(vlSelf->ledr)) 
                    | (((IData)(vlSelf->top__DOT____Vcellout__inst__overflow) 
                        << 9U) | (((IData)(vlSelf->top__DOT____Vcellout__inst__ready) 
                                   << 8U) | vlSelf->top__DOT__inst__DOT__fifo
                                  [vlSelf->top__DOT__inst__DOT__r_ptr])));
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vtop___024root___sequent__TOP__1(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
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
