/*******************************************************************************
 *
 * (c) Copyright IBM Corp. 2000, 2016
 *
 *  This program and the accompanying materials are made available
 *  under the terms of the Eclipse Public License v1.0 and
 *  Apache License v2.0 which accompanies this distribution.
 *
 *      The Eclipse Public License is available at
 *      http://www.eclipse.org/legal/epl-v10.html
 *
 *      The Apache License v2.0 is available at
 *      http://www.opensource.org/licenses/apache2.0.php
 *
 * Contributors:
 *    Multiple authors (IBM Corp.) - initial implementation and documentation
 *******************************************************************************/

#ifndef OMR_i386_CODEGENERATOR_INCL
#define OMR_i386_CODEGENERATOR_INCL

#include "compiler/x/codegen/OMRCodeGenerator.hpp"

#include "codegen/RegisterConstants.hpp"  // for TR_GlobalRegisterNumber

class TR_RegisterCandidate;
namespace TR { class Block; }
namespace TR { class Node; }
template <class T> class TR_LinkHead;

namespace OMR
{

namespace X86
{

namespace i386
{

class OMR_EXTENSIBLE CodeGenerator : public OMR::X86::CodeGenerator
   {

   public:

   CodeGenerator();

   virtual TR::Register *longClobberEvaluate(TR::Node *node);

   TR_GlobalRegisterNumber pickRegister(TR_RegisterCandidate *, TR::Block * *, TR_BitVector &, TR_GlobalRegisterNumber &, TR_LinkHead<TR_RegisterCandidate> *candidates);
   int32_t getVMThreadGlobalRegisterNumber() {return 6;}

   using OMR::X86::CodeGenerator::getMaximumNumberOfGPRsAllowedAcrossEdge;
   int32_t getMaximumNumberOfGPRsAllowedAcrossEdge(TR::Node *);

   bool internalPointerSupportImplemented() {return true;}
   uint32_t getRegisterMapInfoBitsMask() {return 0x00ff0000;}

   bool codegenMulDecomposition(int64_t multiplier);

   };

} // namespace i386

} // namespace X86

} // namespace OMR

#endif
