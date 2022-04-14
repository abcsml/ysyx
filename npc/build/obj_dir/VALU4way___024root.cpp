// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VALU4way.h for the primary calling header

#include "VALU4way___024root.h"
#include "VALU4way__Syms.h"

//==========

VL_INLINE_OPT void VALU4way___024root___combo__TOP__1(VALU4way___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU4way___024root___combo__TOP__1\n"); );
    // Body
    vlSelf->cf = (1U & (((IData)(vlSelf->a) + (IData)(vlSelf->b)) 
                        >> 4U));
    vlSelf->ALU4way__DOT__add = (0xfU & ((IData)(vlSelf->a) 
                                         + (IData)(vlSelf->b)));
    vlSelf->ALU4way__DOT____Vcellinp__a2____pinNumber2 
        = ((8U & (IData)(vlSelf->b)) | (7U & ((IData)(1U) 
                                              + (~ (IData)(vlSelf->b)))));
    vlSelf->zf = (1U & (~ (IData)((0U != (IData)(vlSelf->ALU4way__DOT__add)))));
    vlSelf->of = (1U & ((~ (((IData)(vlSelf->a) ^ (IData)(vlSelf->b)) 
                            >> 3U)) & (((IData)(vlSelf->ALU4way__DOT__add) 
                                        ^ (IData)(vlSelf->a)) 
                                       >> 3U)));
    vlSelf->cf = (1U & (((IData)(vlSelf->a) + (IData)(vlSelf->ALU4way__DOT____Vcellinp__a2____pinNumber2)) 
                        >> 4U));
    vlSelf->ALU4way__DOT__sub = (0xfU & ((IData)(vlSelf->a) 
                                         + (IData)(vlSelf->ALU4way__DOT____Vcellinp__a2____pinNumber2)));
    vlSelf->zf = (1U & (~ (IData)((0U != (IData)(vlSelf->ALU4way__DOT__sub)))));
    vlSelf->out = (0xfU & ((4U & (IData)(vlSelf->sel))
                            ? ((2U & (IData)(vlSelf->sel))
                                ? ((1U & (IData)(vlSelf->sel))
                                    ? (((IData)(vlSelf->a) 
                                        == (IData)(vlSelf->b))
                                        ? 1U : 0U) : 
                                   (((IData)(vlSelf->a) 
                                     < (IData)(vlSelf->b))
                                     ? 1U : 0U)) : 
                               ((1U & (IData)(vlSelf->sel))
                                 ? ((IData)(vlSelf->a) 
                                    ^ (IData)(vlSelf->b))
                                 : ((IData)(vlSelf->a) 
                                    | (IData)(vlSelf->b))))
                            : ((2U & (IData)(vlSelf->sel))
                                ? ((1U & (IData)(vlSelf->sel))
                                    ? ((IData)(vlSelf->a) 
                                       & (IData)(vlSelf->b))
                                    : (~ (IData)(vlSelf->a)))
                                : ((1U & (IData)(vlSelf->sel))
                                    ? (IData)(vlSelf->ALU4way__DOT__sub)
                                    : (IData)(vlSelf->ALU4way__DOT__add)))));
    vlSelf->of = (1U & ((~ (((IData)(vlSelf->a) ^ (IData)(vlSelf->ALU4way__DOT____Vcellinp__a2____pinNumber2)) 
                            >> 3U)) & (((IData)(vlSelf->ALU4way__DOT__sub) 
                                        ^ (IData)(vlSelf->a)) 
                                       >> 3U)));
}

void VALU4way___024root___eval(VALU4way___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU4way___024root___eval\n"); );
    // Body
    VALU4way___024root___combo__TOP__1(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
}

QData VALU4way___024root___change_request_1(VALU4way___024root* vlSelf);

VL_INLINE_OPT QData VALU4way___024root___change_request(VALU4way___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU4way___024root___change_request\n"); );
    // Body
    return (VALU4way___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData VALU4way___024root___change_request_1(VALU4way___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU4way___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VALU4way___024root___eval_debug_assertions(VALU4way___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU4way___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->a & 0xf0U))) {
        Verilated::overWidthError("a");}
    if (VL_UNLIKELY((vlSelf->b & 0xf0U))) {
        Verilated::overWidthError("b");}
    if (VL_UNLIKELY((vlSelf->sel & 0xf8U))) {
        Verilated::overWidthError("sel");}
}
#endif  // VL_DEBUG
