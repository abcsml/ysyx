// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VALU4way__Syms.h"


void VALU4way___024root__traceInitSub0(VALU4way___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VALU4way___024root__traceInitTop(VALU4way___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VALU4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VALU4way___024root__traceInitSub0(vlSelf, tracep);
    }
}

void VALU4way___024root__traceInitSub0(VALU4way___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VALU4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBus(c+4,"a", false,-1, 3,0);
        tracep->declBus(c+5,"b", false,-1, 3,0);
        tracep->declBus(c+6,"sel", false,-1, 2,0);
        tracep->declBus(c+7,"out", false,-1, 3,0);
        tracep->declBit(c+8,"cf", false,-1);
        tracep->declBit(c+9,"of", false,-1);
        tracep->declBit(c+10,"zf", false,-1);
        tracep->declBus(c+4,"ALU4way a", false,-1, 3,0);
        tracep->declBus(c+5,"ALU4way b", false,-1, 3,0);
        tracep->declBus(c+6,"ALU4way sel", false,-1, 2,0);
        tracep->declBus(c+7,"ALU4way out", false,-1, 3,0);
        tracep->declBit(c+8,"ALU4way cf", false,-1);
        tracep->declBit(c+9,"ALU4way of", false,-1);
        tracep->declBit(c+10,"ALU4way zf", false,-1);
        tracep->declBus(c+1,"ALU4way add", false,-1, 3,0);
        tracep->declBus(c+2,"ALU4way sub", false,-1, 3,0);
        tracep->declBus(c+11,"ALU4way a1 n", false,-1, 31,0);
        tracep->declBus(c+4,"ALU4way a1 x", false,-1, 3,0);
        tracep->declBus(c+5,"ALU4way a1 y", false,-1, 3,0);
        tracep->declBus(c+1,"ALU4way a1 s", false,-1, 3,0);
        tracep->declBit(c+8,"ALU4way a1 c", false,-1);
        tracep->declBit(c+9,"ALU4way a1 o", false,-1);
        tracep->declBit(c+10,"ALU4way a1 z", false,-1);
        tracep->declBus(c+11,"ALU4way a2 n", false,-1, 31,0);
        tracep->declBus(c+4,"ALU4way a2 x", false,-1, 3,0);
        tracep->declBus(c+3,"ALU4way a2 y", false,-1, 3,0);
        tracep->declBus(c+2,"ALU4way a2 s", false,-1, 3,0);
        tracep->declBit(c+8,"ALU4way a2 c", false,-1);
        tracep->declBit(c+9,"ALU4way a2 o", false,-1);
        tracep->declBit(c+10,"ALU4way a2 z", false,-1);
    }
}

void VALU4way___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void VALU4way___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void VALU4way___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void VALU4way___024root__traceRegister(VALU4way___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VALU4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&VALU4way___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&VALU4way___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&VALU4way___024root__traceCleanup, vlSelf);
    }
}

void VALU4way___024root__traceFullSub0(VALU4way___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VALU4way___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    VALU4way___024root* const __restrict vlSelf = static_cast<VALU4way___024root*>(voidSelf);
    VALU4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VALU4way___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void VALU4way___024root__traceFullSub0(VALU4way___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VALU4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullCData(oldp+1,(vlSelf->ALU4way__DOT__add),4);
        tracep->fullCData(oldp+2,(vlSelf->ALU4way__DOT__sub),4);
        tracep->fullCData(oldp+3,(vlSelf->ALU4way__DOT____Vcellinp__a2____pinNumber2),4);
        tracep->fullCData(oldp+4,(vlSelf->a),4);
        tracep->fullCData(oldp+5,(vlSelf->b),4);
        tracep->fullCData(oldp+6,(vlSelf->sel),3);
        tracep->fullCData(oldp+7,(vlSelf->out),4);
        tracep->fullBit(oldp+8,(vlSelf->cf));
        tracep->fullBit(oldp+9,(vlSelf->of));
        tracep->fullBit(oldp+10,(vlSelf->zf));
        tracep->fullIData(oldp+11,(4U),32);
    }
}
