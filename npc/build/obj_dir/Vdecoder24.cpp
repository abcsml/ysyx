// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vdecoder24.h"
#include "Vdecoder24__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vdecoder24::Vdecoder24(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vdecoder24__Syms(_vcontextp__, _vcname__, this)}
    , x{vlSymsp->TOP.x}
    , en{vlSymsp->TOP.en}
    , y{vlSymsp->TOP.y}
    , rootp{&(vlSymsp->TOP)}
{
}

Vdecoder24::Vdecoder24(const char* _vcname__)
    : Vdecoder24(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vdecoder24::~Vdecoder24() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vdecoder24___024root___eval_initial(Vdecoder24___024root* vlSelf);
void Vdecoder24___024root___eval_settle(Vdecoder24___024root* vlSelf);
void Vdecoder24___024root___eval(Vdecoder24___024root* vlSelf);
QData Vdecoder24___024root___change_request(Vdecoder24___024root* vlSelf);
#ifdef VL_DEBUG
void Vdecoder24___024root___eval_debug_assertions(Vdecoder24___024root* vlSelf);
#endif  // VL_DEBUG
void Vdecoder24___024root___final(Vdecoder24___024root* vlSelf);

static void _eval_initial_loop(Vdecoder24__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vdecoder24___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vdecoder24___024root___eval_settle(&(vlSymsp->TOP));
        Vdecoder24___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vdecoder24___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/home/ad/ysyx-workbench/npc/vsrc/exp2/decoder.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vdecoder24___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vdecoder24::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vdecoder24::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vdecoder24___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vdecoder24___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vdecoder24___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/home/ad/ysyx-workbench/npc/vsrc/exp2/decoder.v", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vdecoder24___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void Vdecoder24::final() {
    Vdecoder24___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* Vdecoder24::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vdecoder24::name() const {
    return vlSymsp->name();
}

//============================================================
// Trace configuration

void Vdecoder24___024root__traceInitTop(Vdecoder24___024root* vlSelf, VerilatedVcd* tracep);

static void traceInit(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vdecoder24___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdecoder24___024root*>(voidSelf);
    Vdecoder24__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vdecoder24___024root__traceInitTop(vlSelf, tracep);
    tracep->scopeEscape('.');
}

void Vdecoder24___024root__traceRegister(Vdecoder24___024root* vlSelf, VerilatedVcd* tracep);

void Vdecoder24::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, &(vlSymsp->TOP));
    Vdecoder24___024root__traceRegister(&(vlSymsp->TOP), tfp->spTrace());
}
