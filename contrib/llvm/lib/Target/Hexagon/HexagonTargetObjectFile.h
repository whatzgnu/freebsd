//===-- HexagonTargetObjectFile.h -----------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_HEXAGON_HEXAGONTARGETOBJECTFILE_H
#define LLVM_LIB_TARGET_HEXAGON_HEXAGONTARGETOBJECTFILE_H

#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"
#include "llvm/MC/MCSectionELF.h"

namespace llvm {

  class HexagonTargetObjectFile : public TargetLoweringObjectFileELF {
  public:
    void Initialize(MCContext &Ctx, const TargetMachine &TM) override;

    MCSection *SelectSectionForGlobal(const GlobalValue *GV, SectionKind Kind,
        Mangler &Mang, const TargetMachine &TM) const override;

    MCSection *getExplicitSectionGlobal(const GlobalValue *GV, SectionKind Kind,
        Mangler &Mang, const TargetMachine &TM) const override;

    bool isGlobalInSmallSection(const GlobalValue *GV, const TargetMachine &TM)
        const;

    bool isSmallDataEnabled() const;

    unsigned getSmallDataSize() const;

  private:
    MCSectionELF *SmallDataSection;
    MCSectionELF *SmallBSSSection;

    unsigned getSmallestAddressableSize(const Type *Ty, const GlobalValue *GV,
        const TargetMachine &TM) const;

    MCSection *selectSmallSectionForGlobal(const GlobalValue *GV,
        SectionKind Kind, Mangler &Mang, const TargetMachine &TM) const;
  };

} // namespace llvm

#endif
