//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "../ClangTidy.h"
#include "../ClangTidyModule.h"

namespace clang::tidy {
namespace tinylint {
namespace {

/// This module is for TinyLint checks.
class TinyLintModule : public ClangTidyModule {
public:
  void addCheckFactories(ClangTidyCheckFactories &CheckFactories) override {}
};

} // namespace

// Register the TinyLintTidyModule using this statically initialized variable.
static ClangTidyModuleRegistry::Add<TinyLintModule>
    X("tinylint-module", "Adds TinyLint checks.");
} // namespace tinylint

// This anchor is used to force the linker to link in the generated object file
// and thus register the TinyLintModule.
// NOLINTNEXTLINE(misc-use-internal-linkage)
volatile int TinyLintModuleAnchorSource = 0;

} // namespace clang::tidy
