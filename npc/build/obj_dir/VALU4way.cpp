// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VALU4way.h"
#include "VALU4way__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VALU4way::VALU4way(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new VALU4way__Syms(_vcontextp__, _vcname__, this)}
    , a{vlSymsp->TOP.a}
    , b{vlSymsp->TOP.b}
    , sel{vlSymsp->TOP.sel}
    , out{vlSymsp->TOP.out}
    , cf{vlSymsp->TOP.cf}
    , of{vlSymsp->TOP.of}
    , zf{vlSymsp->TOP.zf}
    , rootp{&(vlSymsp->TOP)}
{
}

VALU4way::VALU4way(const char* _vcname__)
    : VALU4way(nullptr, _vcname__)
{
}

//============================================================
// Destructor

VALU4way::~VALU4way() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void VALU4way___024root___eval_initial(VALU4way___024root* vlSelf);
void VALU4way___024root___eval_settle(VALU4way___024root* vlSelf);
void VALU4way___024root___eval(VALU4way___024root* vlSelf);
QData VALU4way___024root___change_request(VALU4way___024root* vlSelf);
#ifdef VL_DEBUG
void VALU4way___024root___eval_debug_assertions(VALU4way___024root* vlSelf);
#endif  // VL_DEBUG
void VALU4way___024root___final(VALU4way___024root* vlSelf);

static void _eval_initial_loop(VALU4way__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    VALU4way___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        VALU4way___024root___eval_settle(&(vlSymsp->TOP));
        VALU4way___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VALU4way___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/home/ad/ysyx-workbench/npc/vsrc/exp3/ALU4way.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VALU4way___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VALU4way::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VALU4way::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VALU4way___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        VALU4way___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VALU4way___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/home/ad/ysyx-workbench/npc/vsrc/exp3/ALU4way.v", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VALU4way___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void VALU4way::final() {
    VALU4way___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* VALU4way::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* VALU4way::name() const {
    return vlSymsp->name();
}

//============================================================
// Trace configuration

void VALU4way___024root__traceInitTop(VALU4way___024root* vlSelf, VerilatedVcd* tracep);

static void traceInit(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VALU4way___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VALU4way___024root*>(voidSelf);
    VALU4way__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VALU4way___024root__traceInitTop(vlSelf, tracep);
    tracep->scopeEscape('.');
}

void VALU4way___024root__traceRegister(VALU4way___024root* vlSelf, VerilatedVcd* tracep);

void VALU4way::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, &(vlSymsp->TOP));
    VALU4way___024root__traceRegister(&(vlSymsp->TOP), tfp->spTrace());
}
