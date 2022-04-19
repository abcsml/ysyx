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
    CData/*2:0*/ __Vdly__top__DOT__p2__DOT__p1__DOT__ps2_clk_sync;
    CData/*2:0*/ __Vdly__top__DOT__p2__DOT__p1__DOT__r_ptr;
    CData/*2:0*/ __Vdlyvdim0__top__DOT__p2__DOT__p1__DOT__fifo__v0;
    CData/*7:0*/ __Vdlyvval__top__DOT__p2__DOT__p1__DOT__fifo__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__p2__DOT__p1__DOT__fifo__v0;
    CData/*2:0*/ __Vdly__top__DOT__p2__DOT__p1__DOT__w_ptr;
    CData/*3:0*/ __Vdly__top__DOT__p2__DOT__p1__DOT__count;
    // Body
    __Vdly__top__DOT__p2__DOT__p1__DOT__ps2_clk_sync 
        = vlSelf->top__DOT__p2__DOT__p1__DOT__ps2_clk_sync;
    __Vdly__top__DOT__p2__DOT__p1__DOT__count = vlSelf->top__DOT__p2__DOT__p1__DOT__count;
    __Vdly__top__DOT__p2__DOT__p1__DOT__w_ptr = vlSelf->top__DOT__p2__DOT__p1__DOT__w_ptr;
    __Vdly__top__DOT__p2__DOT__p1__DOT__r_ptr = vlSelf->top__DOT__p2__DOT__p1__DOT__r_ptr;
    __Vdlyvset__top__DOT__p2__DOT__p1__DOT__fifo__v0 = 0U;
    __Vdly__top__DOT__p2__DOT__p1__DOT__ps2_clk_sync 
        = ((6U & ((IData)(vlSelf->top__DOT__p2__DOT__p1__DOT__ps2_clk_sync) 
                  << 1U)) | (IData)(vlSelf->ps2_clk));
    if (vlSelf->top__DOT__p2__DOT__ready) {
        if ((1U & (~ (IData)(vlSelf->top__DOT__p2__DOT__nextdata_n)))) {
            __Vdly__top__DOT__p2__DOT__p1__DOT__r_ptr 
                = (7U & ((IData)(1U) + (IData)(vlSelf->top__DOT__p2__DOT__p1__DOT__r_ptr)));
            if (((IData)(vlSelf->top__DOT__p2__DOT__p1__DOT__w_ptr) 
                 == (7U & ((IData)(1U) + (IData)(vlSelf->top__DOT__p2__DOT__p1__DOT__r_ptr))))) {
                vlSelf->top__DOT__p2__DOT__ready = 0U;
            }
        }
    }
    if ((IData)((4U == (6U & (IData)(vlSelf->top__DOT__p2__DOT__p1__DOT__ps2_clk_sync))))) {
        if ((0xaU == (IData)(vlSelf->top__DOT__p2__DOT__p1__DOT__count))) {
            if (VL_UNLIKELY((((~ (IData)(vlSelf->top__DOT__p2__DOT__p1__DOT__buffer)) 
                              & (IData)(vlSelf->ps2_data)) 
                             & VL_REDXOR_32((0x1ffU 
                                             & ((IData)(vlSelf->top__DOT__p2__DOT__p1__DOT__buffer) 
                                                >> 1U)))))) {
                VL_WRITEF("receive %x\n",8,(0xffU & 
                                            ((IData)(vlSelf->top__DOT__p2__DOT__p1__DOT__buffer) 
                                             >> 1U)));
                __Vdlyvval__top__DOT__p2__DOT__p1__DOT__fifo__v0 
                    = (0xffU & ((IData)(vlSelf->top__DOT__p2__DOT__p1__DOT__buffer) 
                                >> 1U));
                __Vdlyvset__top__DOT__p2__DOT__p1__DOT__fifo__v0 = 1U;
                __Vdlyvdim0__top__DOT__p2__DOT__p1__DOT__fifo__v0 
                    = vlSelf->top__DOT__p2__DOT__p1__DOT__w_ptr;
                vlSelf->top__DOT__p2__DOT__ready = 1U;
                __Vdly__top__DOT__p2__DOT__p1__DOT__w_ptr 
                    = (7U & ((IData)(1U) + (IData)(vlSelf->top__DOT__p2__DOT__p1__DOT__w_ptr)));
                vlSelf->top__DOT__p2__DOT__overflow 
                    = ((IData)(vlSelf->top__DOT__p2__DOT__overflow) 
                       | ((IData)(vlSelf->top__DOT__p2__DOT__p1__DOT__r_ptr) 
                          == (7U & ((IData)(1U) + (IData)(vlSelf->top__DOT__p2__DOT__p1__DOT__w_ptr)))));
            }
            __Vdly__top__DOT__p2__DOT__p1__DOT__count = 0U;
        } else {
            vlSelf->top__DOT__p2__DOT__p1__DOT____Vlvbound1 
                = vlSelf->ps2_data;
            if ((9U >= (IData)(vlSelf->top__DOT__p2__DOT__p1__DOT__count))) {
                vlSelf->top__DOT__p2__DOT__p1__DOT__buffer 
                    = (((~ ((IData)(1U) << (IData)(vlSelf->top__DOT__p2__DOT__p1__DOT__count))) 
                        & (IData)(vlSelf->top__DOT__p2__DOT__p1__DOT__buffer)) 
                       | (0x3ffU & ((IData)(vlSelf->top__DOT__p2__DOT__p1__DOT____Vlvbound1) 
                                    << (IData)(vlSelf->top__DOT__p2__DOT__p1__DOT__count))));
            }
            __Vdly__top__DOT__p2__DOT__p1__DOT__count 
                = (0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__p2__DOT__p1__DOT__count)));
        }
    }
    vlSelf->top__DOT__p2__DOT__p1__DOT__ps2_clk_sync 
        = __Vdly__top__DOT__p2__DOT__p1__DOT__ps2_clk_sync;
    vlSelf->top__DOT__p2__DOT__p1__DOT__w_ptr = __Vdly__top__DOT__p2__DOT__p1__DOT__w_ptr;
    vlSelf->top__DOT__p2__DOT__p1__DOT__count = __Vdly__top__DOT__p2__DOT__p1__DOT__count;
    vlSelf->top__DOT__p2__DOT__p1__DOT__r_ptr = __Vdly__top__DOT__p2__DOT__p1__DOT__r_ptr;
    if (__Vdlyvset__top__DOT__p2__DOT__p1__DOT__fifo__v0) {
        vlSelf->top__DOT__p2__DOT__p1__DOT__fifo[__Vdlyvdim0__top__DOT__p2__DOT__p1__DOT__fifo__v0] 
            = __Vdlyvval__top__DOT__p2__DOT__p1__DOT__fifo__v0;
    }
    vlSelf->top__DOT__p2__DOT__data = vlSelf->top__DOT__p2__DOT__p1__DOT__fifo
        [vlSelf->top__DOT__p2__DOT__p1__DOT__r_ptr];
}

extern const VlUnpacked<CData/*6:0*/, 16> Vtop__ConstPool__TABLE_982ef378_0;

VL_INLINE_OPT void Vtop___024root___combo__TOP__4(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___combo__TOP__4\n"); );
    // Variables
    CData/*6:0*/ top__DOT____Vcellout__b1__h;
    CData/*6:0*/ top__DOT____Vcellout__b2__h;
    CData/*6:0*/ top__DOT____Vcellout__b3__h;
    CData/*6:0*/ top__DOT____Vcellout__b4__h;
    CData/*6:0*/ top__DOT____Vcellout__b5__h;
    CData/*6:0*/ top__DOT____Vcellout__b6__h;
    CData/*3:0*/ __Vtableidx1;
    CData/*3:0*/ __Vtableidx2;
    CData/*3:0*/ __Vtableidx3;
    CData/*3:0*/ __Vtableidx4;
    CData/*3:0*/ __Vtableidx5;
    CData/*3:0*/ __Vtableidx6;
    // Body
    if ((1U == vlSelf->top__DOT__p2__DOT__over)) {
        vlSelf->top__DOT__p2__DOT__over = 0U;
        vlSelf->top__DOT__num = 0U;
        vlSelf->top__DOT__p2__DOT__ifpress = 0U;
    } else if ((0xf0U == (IData)(vlSelf->top__DOT__p2__DOT__data))) {
        vlSelf->top__DOT__p2__DOT__over = 1U;
    } else if ((0U == vlSelf->top__DOT__p2__DOT__ifpress)) {
        vlSelf->top__DOT__num = vlSelf->top__DOT__p2__DOT__data;
        vlSelf->top__DOT__p2__DOT__ifpress = 1U;
    } else if (((IData)(vlSelf->top__DOT__p2__DOT__data) 
                != (IData)(vlSelf->top__DOT__num))) {
        vlSelf->top__DOT__num = vlSelf->top__DOT__p2__DOT__data;
        vlSelf->top__DOT__sum = 0xf1U;
    }
    __Vtableidx5 = (0xfU & (IData)(vlSelf->top__DOT__sum));
    top__DOT____Vcellout__b5__h = Vtop__ConstPool__TABLE_982ef378_0
        [__Vtableidx5];
    __Vtableidx6 = (0xfU & ((IData)(vlSelf->top__DOT__sum) 
                            >> 4U));
    top__DOT____Vcellout__b6__h = Vtop__ConstPool__TABLE_982ef378_0
        [__Vtableidx6];
    __Vtableidx1 = (0xfU & (IData)(vlSelf->top__DOT__num));
    top__DOT____Vcellout__b1__h = Vtop__ConstPool__TABLE_982ef378_0
        [__Vtableidx1];
    __Vtableidx2 = (0xfU & ((IData)(vlSelf->top__DOT__num) 
                            >> 4U));
    top__DOT____Vcellout__b2__h = Vtop__ConstPool__TABLE_982ef378_0
        [__Vtableidx2];
    if ((0U == (IData)(vlSelf->top__DOT__num))) {
        vlSelf->top__DOT__ascii = 0x30U;
    }
    if ((0U == (IData)(vlSelf->top__DOT__num))) {
        vlSelf->top__DOT__ascii = 0x31U;
    }
    if ((0U == (IData)(vlSelf->top__DOT__num))) {
        vlSelf->top__DOT__ascii = 0x32U;
    }
    if ((0U == (IData)(vlSelf->top__DOT__num))) {
        vlSelf->top__DOT__ascii = 0x33U;
    }
    if ((0U == (IData)(vlSelf->top__DOT__num))) {
        vlSelf->top__DOT__ascii = 0x34U;
    }
    if ((0U == (IData)(vlSelf->top__DOT__num))) {
        vlSelf->top__DOT__ascii = 0x35U;
    }
    if ((0U == (IData)(vlSelf->top__DOT__num))) {
        vlSelf->top__DOT__ascii = 0x36U;
    }
    if ((0U == (IData)(vlSelf->top__DOT__num))) {
        vlSelf->top__DOT__ascii = 0x37U;
    }
    if ((0U == (IData)(vlSelf->top__DOT__num))) {
        vlSelf->top__DOT__ascii = 0x38U;
    }
    if ((0U == (IData)(vlSelf->top__DOT__num))) {
        vlSelf->top__DOT__ascii = 0x39U;
    }
    if ((0U == (IData)(vlSelf->top__DOT__num))) {
        vlSelf->top__DOT__ascii = 0x61U;
    }
    if ((0U == (IData)(vlSelf->top__DOT__num))) {
        vlSelf->top__DOT__ascii = 0x62U;
    }
    if ((0U == (IData)(vlSelf->top__DOT__num))) {
        vlSelf->top__DOT__ascii = 0x63U;
    }
    if ((0U == (IData)(vlSelf->top__DOT__num))) {
        vlSelf->top__DOT__ascii = 0x64U;
    }
    if ((0U == (IData)(vlSelf->top__DOT__num))) {
        vlSelf->top__DOT__ascii = 0x65U;
    }
    if ((0U == (IData)(vlSelf->top__DOT__num))) {
        vlSelf->top__DOT__ascii = 0x66U;
    }
    if ((0U == (IData)(vlSelf->top__DOT__num))) {
        vlSelf->top__DOT__ascii = 0x67U;
    }
    if ((0U == (IData)(vlSelf->top__DOT__num))) {
        vlSelf->top__DOT__ascii = 0x68U;
    }
    if ((0U == (IData)(vlSelf->top__DOT__num))) {
        vlSelf->top__DOT__ascii = 0x69U;
    }
    if ((0U == (IData)(vlSelf->top__DOT__num))) {
        vlSelf->top__DOT__ascii = 0x6aU;
    }
    if ((0U == (IData)(vlSelf->top__DOT__num))) {
        vlSelf->top__DOT__ascii = 0x6bU;
    }
    if ((0U == (IData)(vlSelf->top__DOT__num))) {
        vlSelf->top__DOT__ascii = 0x6cU;
    }
    if ((0U == (IData)(vlSelf->top__DOT__num))) {
        vlSelf->top__DOT__ascii = 0x6dU;
    }
    if ((0U == (IData)(vlSelf->top__DOT__num))) {
        vlSelf->top__DOT__ascii = 0x6eU;
    }
    if ((0U == (IData)(vlSelf->top__DOT__num))) {
        vlSelf->top__DOT__ascii = 0x6fU;
    }
    if ((0U == (IData)(vlSelf->top__DOT__num))) {
        vlSelf->top__DOT__ascii = 0x70U;
    }
    if ((0U == (IData)(vlSelf->top__DOT__num))) {
        vlSelf->top__DOT__ascii = 0x71U;
    }
    if ((0U == (IData)(vlSelf->top__DOT__num))) {
        vlSelf->top__DOT__ascii = 0x72U;
    }
    if ((0U == (IData)(vlSelf->top__DOT__num))) {
        vlSelf->top__DOT__ascii = 0x73U;
    }
    if ((0U == (IData)(vlSelf->top__DOT__num))) {
        vlSelf->top__DOT__ascii = 0x74U;
    }
    if ((0U == (IData)(vlSelf->top__DOT__num))) {
        vlSelf->top__DOT__ascii = 0x75U;
    }
    if ((0U == (IData)(vlSelf->top__DOT__num))) {
        vlSelf->top__DOT__ascii = 0x76U;
    }
    if ((0U == (IData)(vlSelf->top__DOT__num))) {
        vlSelf->top__DOT__ascii = 0x77U;
    }
    if ((0U == (IData)(vlSelf->top__DOT__num))) {
        vlSelf->top__DOT__ascii = 0x78U;
    }
    if ((0U == (IData)(vlSelf->top__DOT__num))) {
        vlSelf->top__DOT__ascii = 0x79U;
    }
    if ((0U == (IData)(vlSelf->top__DOT__num))) {
        vlSelf->top__DOT__ascii = 0x7aU;
    }
    vlSelf->seg4 = ((1U & (IData)(vlSelf->seg4)) | 
                    ((IData)(top__DOT____Vcellout__b5__h) 
                     << 1U));
    vlSelf->seg5 = ((1U & (IData)(vlSelf->seg5)) | 
                    ((IData)(top__DOT____Vcellout__b6__h) 
                     << 1U));
    vlSelf->seg0 = ((1U & (IData)(vlSelf->seg0)) | 
                    ((IData)(top__DOT____Vcellout__b1__h) 
                     << 1U));
    vlSelf->seg1 = ((1U & (IData)(vlSelf->seg1)) | 
                    ((IData)(top__DOT____Vcellout__b2__h) 
                     << 1U));
    __Vtableidx3 = (0xfU & (IData)(vlSelf->top__DOT__ascii));
    top__DOT____Vcellout__b3__h = Vtop__ConstPool__TABLE_982ef378_0
        [__Vtableidx3];
    __Vtableidx4 = (0xfU & ((IData)(vlSelf->top__DOT__ascii) 
                            >> 4U));
    top__DOT____Vcellout__b4__h = Vtop__ConstPool__TABLE_982ef378_0
        [__Vtableidx4];
    vlSelf->seg2 = ((1U & (IData)(vlSelf->seg2)) | 
                    ((IData)(top__DOT____Vcellout__b3__h) 
                     << 1U));
    vlSelf->seg3 = ((1U & (IData)(vlSelf->seg3)) | 
                    ((IData)(top__DOT____Vcellout__b4__h) 
                     << 1U));
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vtop___024root___sequent__TOP__1(vlSelf);
    }
    Vtop___024root___combo__TOP__4(vlSelf);
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
    __req |= ((vlSelf->top__DOT__p2__DOT__over ^ vlSelf->__Vchglast__TOP__top__DOT__p2__DOT__over));
    VL_DEBUG_IF( if(__req && ((vlSelf->top__DOT__p2__DOT__over ^ vlSelf->__Vchglast__TOP__top__DOT__p2__DOT__over))) VL_DBG_MSGF("        CHANGE: /home/ad/ysyx-workbench/npc/vsrc/exp7/ps2_ascii.v:17: top.p2.over\n"); );
    // Final
    vlSelf->__Vchglast__TOP__top__DOT__p2__DOT__over 
        = vlSelf->top__DOT__p2__DOT__over;
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
