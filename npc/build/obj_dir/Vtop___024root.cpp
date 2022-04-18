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
    CData/*0:0*/ top__DOT____Vcellout__alu1__zf;
    CData/*3:0*/ top__DOT__alu1__DOT__add;
    CData/*3:0*/ top__DOT__alu1__DOT__sub;
    // Body
    if ((1U & (~ ((IData)(vlSelf->sw) >> 0xaU)))) {
        if ((1U & (~ ((IData)(vlSelf->sw) >> 9U)))) {
            vlSelf->top__DOT____Vcellout__alu1__cf 
                = (1U & ((0x100U & (IData)(vlSelf->sw))
                          ? (1U & (((IData)(1U) + (
                                                   (0xfU 
                                                    & ((IData)(vlSelf->sw) 
                                                       >> 4U)) 
                                                   + 
                                                   (0xfU 
                                                    & (~ (IData)(vlSelf->sw))))) 
                                   >> 4U)) : (1U & 
                                              (((0xfU 
                                                 & ((IData)(vlSelf->sw) 
                                                    >> 4U)) 
                                                + (0xfU 
                                                   & (IData)(vlSelf->sw))) 
                                               >> 4U))));
        }
    }
    top__DOT__alu1__DOT__add = (0xfU & (((IData)(vlSelf->sw) 
                                         >> 4U) + (IData)(vlSelf->sw)));
    top__DOT__alu1__DOT__sub = (0xfU & ((IData)(1U) 
                                        + (((IData)(vlSelf->sw) 
                                            >> 4U) 
                                           + (~ (IData)(vlSelf->sw)))));
    if ((1U & (~ ((IData)(vlSelf->sw) >> 0xaU)))) {
        if ((1U & (~ ((IData)(vlSelf->sw) >> 9U)))) {
            vlSelf->top__DOT____Vcellout__alu1__of 
                = (1U & ((0x100U & (IData)(vlSelf->sw))
                          ? ((~ (((IData)(vlSelf->sw) 
                                  >> 7U) ^ (~ ((IData)(vlSelf->sw) 
                                               >> 3U)))) 
                             & (((IData)(top__DOT__alu1__DOT__sub) 
                                 >> 3U) ^ ((IData)(vlSelf->sw) 
                                           >> 7U)))
                          : ((~ (((IData)(vlSelf->sw) 
                                  >> 7U) ^ ((IData)(vlSelf->sw) 
                                            >> 3U))) 
                             & (((IData)(top__DOT__alu1__DOT__add) 
                                 >> 3U) ^ ((IData)(vlSelf->sw) 
                                           >> 7U)))));
        }
    }
    if ((0x400U & (IData)(vlSelf->sw))) {
        vlSelf->top__DOT____Vcellout__alu1__out = (0xfU 
                                                   & ((0x200U 
                                                       & (IData)(vlSelf->sw))
                                                       ? 
                                                      ((0x100U 
                                                        & (IData)(vlSelf->sw))
                                                        ? 
                                                       (((0xfU 
                                                          & ((IData)(vlSelf->sw) 
                                                             >> 4U)) 
                                                         == 
                                                         (0xfU 
                                                          & (IData)(vlSelf->sw)))
                                                         ? 1U
                                                         : 0U)
                                                        : 
                                                       (1U 
                                                        & ((1U 
                                                            & VL_REDXOR_32(
                                                                           (0x88U 
                                                                            & (IData)(vlSelf->sw))))
                                                            ? 
                                                           ((IData)(vlSelf->sw) 
                                                            >> 7U)
                                                            : 
                                                           ((0x80U 
                                                             & (IData)(vlSelf->sw))
                                                             ? 
                                                            ((0xfU 
                                                              & ((IData)(vlSelf->sw) 
                                                                 >> 4U)) 
                                                             > 
                                                             (0xfU 
                                                              & (IData)(vlSelf->sw)))
                                                             : 
                                                            ((0xfU 
                                                              & ((IData)(vlSelf->sw) 
                                                                 >> 4U)) 
                                                             < 
                                                             (0xfU 
                                                              & (IData)(vlSelf->sw)))))))
                                                       : 
                                                      ((0x100U 
                                                        & (IData)(vlSelf->sw))
                                                        ? 
                                                       (((IData)(vlSelf->sw) 
                                                         >> 4U) 
                                                        ^ (IData)(vlSelf->sw))
                                                        : 
                                                       (((IData)(vlSelf->sw) 
                                                         >> 4U) 
                                                        | (IData)(vlSelf->sw)))));
    } else if ((0x200U & (IData)(vlSelf->sw))) {
        vlSelf->top__DOT____Vcellout__alu1__out = (0xfU 
                                                   & ((0x100U 
                                                       & (IData)(vlSelf->sw))
                                                       ? 
                                                      (((IData)(vlSelf->sw) 
                                                        >> 4U) 
                                                       & (IData)(vlSelf->sw))
                                                       : 
                                                      (~ 
                                                       ((IData)(vlSelf->sw) 
                                                        >> 4U))));
    } else if ((0x100U & (IData)(vlSelf->sw))) {
        vlSelf->top__DOT____Vcellout__alu1__out = top__DOT__alu1__DOT__sub;
        top__DOT____Vcellout__alu1__zf = (1U & (~ (0U 
                                                   != (IData)(top__DOT__alu1__DOT__sub))));
    } else {
        vlSelf->top__DOT____Vcellout__alu1__out = top__DOT__alu1__DOT__add;
        top__DOT____Vcellout__alu1__zf = (1U & (~ (0U 
                                                   != (IData)(top__DOT__alu1__DOT__add))));
    }
    top__DOT____Vcellout__alu1__zf = (1U & (~ (0U != (IData)(vlSelf->top__DOT____Vcellout__alu1__out))));
    vlSelf->ledr = ((0xff80U & (IData)(vlSelf->ledr)) 
                    | (((IData)(top__DOT____Vcellout__alu1__zf) 
                        << 6U) | (((IData)(vlSelf->top__DOT____Vcellout__alu1__of) 
                                   << 5U) | (((IData)(vlSelf->top__DOT____Vcellout__alu1__cf) 
                                              << 4U) 
                                             | (IData)(vlSelf->top__DOT____Vcellout__alu1__out)))));
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
