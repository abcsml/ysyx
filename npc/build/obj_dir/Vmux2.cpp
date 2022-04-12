// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vmux2.h"
#include "Vmux2__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vmux2::Vmux2(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vmux2__Syms(_vcontextp__, _vcname__, this)}
    , a{vlSymsp->TOP.a}
    , b{vlSymsp->TOP.b}
    , s{vlSymsp->TOP.s}
    , y{vlSymsp->TOP.y}
    , rootp{&(vlSymsp->TOP)}
{
}

Vmux2::Vmux2(const char* _vcname__)
    : Vmux2(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vmux2::~Vmux2() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vmux2___024root___eval_initial(Vmux2___024root* vlSelf);
void Vmux2___024root___eval_settle(Vmux2___024root* vlSelf);
void Vmux2___024root___eval(Vmux2___024root* vlSelf);
QData Vmux2___024root___change_request(Vmux2___024root* vlSelf);
#ifdef VL_DEBUG
void Vmux2___024root___eval_debug_assertions(Vmux2___024root* vlSelf);
#endif  // VL_DEBUG
void Vmux2___024root___final(Vmux2___024root* vlSelf);

static void _eval_initial_loop(Vmux2__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vmux2___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vmux2___024root___eval_settle(&(vlSymsp->TOP));
        Vmux2___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vmux2___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/home/ad/ysyx-workbench/npc/vsrc/exp1/mux2.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vmux2___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vmux2::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmux2::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vmux2___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vmux2___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vmux2___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/home/ad/ysyx-workbench/npc/vsrc/exp1/mux2.v", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vmux2___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void Vmux2::final() {
    Vmux2___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* Vmux2::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vmux2::name() const {
    return vlSymsp->name();
}

//============================================================
// Trace configuration

void Vmux2___024root__traceInitTop(Vmux2___024root* vlSelf, VerilatedVcd* tracep);

static void traceInit(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vmux2___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmux2___024root*>(voidSelf);
    Vmux2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vmux2___024root__traceInitTop(vlSelf, tracep);
    tracep->scopeEscape('.');
}

void Vmux2___024root__traceRegister(Vmux2___024root* vlSelf, VerilatedVcd* tracep);

void Vmux2::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, &(vlSymsp->TOP));
    Vmux2___024root__traceRegister(&(vlSymsp->TOP), tfp->spTrace());
}
