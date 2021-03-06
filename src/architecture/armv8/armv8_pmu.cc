// EPOS ARMv8 PMU Events Declarations
/*
#include <architecture/pmu.h>

__BEGIN_SYS

const ARMv8_A_PMU::Reg32 ARMv8_A_PMU::_events[PMU_Event::LAST_EVENT] = {
    ARMv8_A_PMU::CYCLE,                                 // CPU_CYCLES
    ARMv8_A_PMU::EVENT_NOT_AVAILABLE,                   // UNHALTED_CYCLES
    ARMv8_A_PMU::INSTRUCTIONS_ARCHITECTURALLY_EXECUTED, // INSTRUCTIONS_RETIRED
    ARMv8_A_PMU::BUS_ACCESS_LD,                         // LOAD_INSTRUCTIONS_RETIRED
    ARMv8_A_PMU::BUS_ACCESS_ST,                         // STORE_INSTRUCTIONS_RETIRED,
    ARMv8_A_PMU::EVENT_NOT_AVAILABLE,                   // INTEGER_ARITHMETIC_INSTRUCTIONS_RETIRED
    ARMv8_A_PMU::EVENT_NOT_AVAILABLE,                   // INTEGER_MULTIPLICATION_INSTRUCTIONS_RETIRED
    ARMv8_A_PMU::EVENT_NOT_AVAILABLE,                   // INTEGER_DIVISION_INSTRUCTIONS_RETIRED
    ARMv8_A_PMU::EVENT_NOT_AVAILABLE,                   // FPU_INSTRUCTIONS_RETIRED
    ARMv8_A_PMU::INSTRUCTIONS_ARCHITECTURALLY_EXECUTED, // SIMD_INSTRUCTIONS_RETIRED,
    ARMv8_A_PMU::EVENT_NOT_AVAILABLE,                   // ATOMIC_MEMEMORY_INSTRUCTIONS_RETIRED,

    ARMv8_A_PMU::BRANCHES_ARCHITECTURALLY_EXECUTED,     // BRANCHES,
    ARMv8_A_PMU::CONDITIONAL_BRANCH_EXECUTED,           // CONDITIONAL_BRANCHES,                            // for some architectures BRANCHES = IMIDIATE + CONDITIONAL
    ARMv8_A_PMU::PREDICTABLE_BRANCH_EXECUTED,           // PREDICTABLE_BRANCHES
    ARMv8_A_PMU::IMMEDIATE_BRANCH,                      // IMIDIATE_BRANCHES
    ARMv8_A_PMU::MISPREDICTED_BRANCH,                   // BRANCH_MISPREDICTIONS
    ARMv8_A_PMU::IND_BR_MISP,                           // BRANCH_DIRECTION_MISPREDICTIONS
    ARMv8_A_PMU::CONDITIONAL_BRANCH_MISP,               // CONDITIONAL_BRANCH_MISPREDICTION
    
    ARMv8_A_PMU::EXCEPTION_TAKEN.                       // EXCEPTIONS,
    ARMv8_A_PMU::EXC_IRQ,                               // INTERRUPTS, 
            
    ARMv8_A_PMU::L1D_ACCESS,                            // L1_CACHE_HITS,
    ARMv8_A_PMU::L1D_REFILL,                            // L1_CACHE_MISSES,
    ARMv8_A_PMU::L1D_REFILL,                            // L1_DATA_CACHE_MISSES,
    ARMv8_A_PMU::L1D_WRITEBACK,                         // L1_DATA_CACHE_WRITEBACKS,
    ARMv8_A_PMU::L1I_REFILL                             // L1_INSTRUCTION_CACHE_MISSES,
    ARMv8_A_PMU::L2D_ACCESS,                            // L2_CACHE_HITS,
    ARMv8_A_PMU::L2D_REFILL,                            // L2_CACHE_MISSES,
    ARMv8_A_PMU::L2D_REFILL,                            // L2_DATA_CACHE_MISSES,
    ARMv8_A_PMU::L2D_WRITEBACK,                         // L2_DATA_CACHE_WRITEBACKS,
    ARMv8_A_PMU::L2D_WRITEBACK,                         // L2_DATA_CACHE_WRITEBACKS,
    ARMv8_A_PMU::L2D_ACCESS,                            // L3_CACHE_HITS,
    ARMv8_A_PMU::DATA_MEMORY_ACCESS,                    // L3_CACHE_MISSES,
    ARMv8_A_PMU::EXTERNAL_MEM_REQUEST_NON_CACHEABLE,    // UNCACHED_MEMORY_ACCESSES,
    ARMv8_A_PMU::UNALIGNED_LOAD_STORE,                  // UNALIGNED_MEMORY_ACCESSES,

    ARMv8_A_PMU::BUS_CYCLE,                             // BUS_CYCLES,
    ARMv8_A_PMU::BUS_ACCESS,                            // BUS_ACCESSES,
    ARMv8_A_PMU::TLB_MEM_ERROR,                         // TLB_MISSES, // TODO need to check
    ARMv8_A_PMU::L1I_TLB_REFILL,                        // INSTRUCTION_TLB_MISSES,
    ARMv8_A_PMU::L1D_TLB_REFILL,                        // DATA_TLB_MISSES = TLB_MISSES,
    ARMv8_A_PMU::LOCAL_MEMORY_ERROR,                    // MEMORY_ERRORS,

    ARMv8_A_PMU::EVENT_NOT_AVAILABLE,                   // STALL_CYCLES,
    ARMv8_A_PMU::EVENT_NOT_AVAILABLE,                   // STALL_CYCLES_CACHE,
    ARMv8_A_PMU::EVENT_NOT_AVAILABLE,                   // STALL_CYCLES_DATA_CACHE,
    ARMv8_A_PMU::EVENT_NOT_AVAILABLE,                   // STALL_CYCLES_TLB,
    ARMv8_A_PMU::DATA_WRITE_STALL_ST_BUFFER_FULL,       // STALL_CYCLES_MEMORY,
    ARMv8_A_PMU::EVENT_NOT_AVAILABLE,                   // PIPELINE_SERIALIZATIONS,    // ISB
    ARMv8_A_PMU::EVENT_NOT_AVAILABLE,                   // BUS_SERIALIZATION,          // DSB

    ARMv8_A_PMU::L1I_ACCESS,                            // ARCHITECTURE_DEPENDENT_EVENT1
    ARMv8_A_PMU::INSTRUCTION_SPECULATIVELY_EXECUTED,    // ARCHITECTURE_DEPENDENT_EVENT2
    ARMv8_A_PMU::CHAIN,                                 // ARCHITECTURE_DEPENDENT_EVENT3
    ARMv8_A_PMU::BR_INDIRECT_SPEC,                      // ARCHITECTURE_DEPENDENT_EVENT4
    ARMv8_A_PMU::EXC_FIQ,                               // ARCHITECTURE_DEPENDENT_EVENT5
    ARMv8_A_PMU::EXTERNAL_MEM_REQUEST,                  // ARCHITECTURE_DEPENDENT_EVENT6
    ARMv8_A_PMU::PREFETCH_LINEFILL,                     // ARCHITECTURE_DEPENDENT_EVENT7
    ARMv8_A_PMU::ICACHE_THROTTLE,                       // ARCHITECTURE_DEPENDENT_EVENT8
    ARMv8_A_PMU::ENTER_READ_ALLOC_MODE,                 // ARCHITECTURE_DEPENDENT_EVENT9
    ARMv8_A_PMU::READ_ALLOC_MODE,                       // ARCHITECTURE_DEPENDENT_EVENT10
    ARMv8_A_PMU::PRE_DECODE_ERROR,                      // ARCHITECTURE_DEPENDENT_EVENT11
    ARMv8_A_PMU::SCU_SNOOPED_DATA_FROM_OTHER_CPU,       // ARCHITECTURE_DEPENDENT_EVENT12
    ARMv8_A_PMU::IND_BR_MISP_ADDRESS_MISCOMPARE,        // ARCHITECTURE_DEPENDENT_EVENT13
    ARMv8_A_PMU::L1_ICACHE_MEM_ERROR,                   // ARCHITECTURE_DEPENDENT_EVENT14
    ARMv8_A_PMU::L1_DCACHE_MEM_ERROR,                   // ARCHITECTURE_DEPENDENT_EVENT15
    ARMv8_A_PMU::EMPTY_DPU_IQ_NOT_GUILTY,               // ARCHITECTURE_DEPENDENT_EVENT16
    ARMv8_A_PMU::EMPTY_DPU_IQ_ICACHE_MISS,              // ARCHITECTURE_DEPENDENT_EVENT17
    ARMv8_A_PMU::EMPTY_DPU_IQ_IMICRO_TLB_MISS,          // ARCHITECTURE_DEPENDENT_EVENT18
    ARMv8_A_PMU::EMPTY_DPU_IQ_PRE_DECODE_ERROR,         // ARCHITECTURE_DEPENDENT_EVENT19
    ARMv8_A_PMU::INTERLOCK_CYCLE_NOT_GUILTY,            // ARCHITECTURE_DEPENDENT_EVENT20
    ARMv8_A_PMU::INTERLOCK_CYCLE_LD_ST_WAIT_AGU_ADDRESS,// ARCHITECTURE_DEPENDENT_EVENT21
    ARMv8_A_PMU::INTERLOCK_CYCLE_ADV_SIMD_FP_INST,      // ARCHITECTURE_DEPENDENT_EVENT22
    ARMv8_A_PMU::INTERLOCK_CYCLE_WR_STAGE_STALL_BC_MISS,// ARCHITECTURE_DEPENDENT_EVENT23
    ARMv8_A_PMU::INTERLOCK_CYCLE_WR_STAGE_STALL_BC_STR  // ARCHITECTURE_DEPENDENT_EVENT24
};

__END_SYS
*/