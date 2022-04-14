// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VADDER4WAY__SYMS_H_
#define VERILATED_VADDER4WAY__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODEL CLASS

#include "Vadder4way.h"

// INCLUDE MODULE CLASSES
#include "Vadder4way___024root.h"

// SYMS CLASS (contains all model state)
class Vadder4way__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vadder4way* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vadder4way___024root           TOP;

    // CONSTRUCTORS
    Vadder4way__Syms(VerilatedContext* contextp, const char* namep, Vadder4way* modelp);
    ~Vadder4way__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
