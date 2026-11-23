set(LLVM_LINK_COMPONENTS
  FrontendOpenMP
  Support
  )

add_clang_library(clangTidyTinyLintModule STATIC
  TinyLintTidyModule.cpp

  LINK_LIBS
  clangTidy

  DEPENDS
  omp_gen
  ClangDriverOptions
  )

clang_target_link_libraries(clangTidyTinyLintModule
  PRIVATE
  clangAST
  clangASTMatchers
  clangBasic
  clangLex
  )
