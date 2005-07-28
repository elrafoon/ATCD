// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// be\be_codegen.cpp:153

#ifndef _TAO_IDL_ORIG_CONV_FRAMEC_H_
#define _TAO_IDL_ORIG_CONV_FRAMEC_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/TAO_Export.h"
#include "tao/ORB.h"
#include "tao/Environment.h"
#include "tao/Sequence_T.h"
#include "tao/Seq_Var_T.h"
#include "tao/Seq_Out_T.h"
#include "tao/VarOut_T.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Export

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:48

namespace CONV_FRAME
{

  // TAO_IDL - Generated from
  // be\be_visitor_typedef/typedef_ch.cpp:379

  typedef CORBA::ULong CodeSetId;
  typedef CORBA::ULong_out CodeSetId_out;

  // TAO_IDL - Generated from
  // be\be_visitor_sequence/sequence_ch.cpp:101

#if !defined (_CONV_FRAME_CODESETIDSEQ_CH_)
#define _CONV_FRAME_CODESETIDSEQ_CH_

  class CodeSetIdSeq;

  typedef
    TAO_FixedSeq_Var_T<
        CodeSetIdSeq,
        CodeSetId
      >
    CodeSetIdSeq_var;

  typedef
    TAO_Seq_Out_T<
        CodeSetIdSeq,
        CodeSetIdSeq_var,
        CodeSetId
      >
    CodeSetIdSeq_out;

  class TAO_Export CodeSetIdSeq
    : public
        TAO_Unbounded_Sequence<
            CodeSetId
          >
  {
  public:
    CodeSetIdSeq (void);
    CodeSetIdSeq (CORBA::ULong max);
    CodeSetIdSeq (
        CORBA::ULong max,
        CORBA::ULong length,
        CORBA::ULong* buffer,
        CORBA::Boolean release = 0
      );
    CodeSetIdSeq (const CodeSetIdSeq &);
    ~CodeSetIdSeq (void);

    static void _tao_any_destructor (void *);

    typedef CodeSetIdSeq_var _var_type;
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be\be_type.cpp:258

  struct CodeSetComponent;

  typedef
    TAO_Var_Var_T<
        CodeSetComponent
      >
    CodeSetComponent_var;

  typedef
    TAO_Out_T<
        CodeSetComponent,
        CodeSetComponent_var
      >
    CodeSetComponent_out;

  // TAO_IDL - Generated from
  // be\be_visitor_structure/structure_ch.cpp:52

  struct TAO_Export CodeSetComponent
  {
    typedef CodeSetComponent_var _var_type;

    static void _tao_any_destructor (void *);
    CONV_FRAME::CodeSetId native_code_set;
    CONV_FRAME::CodeSetIdSeq conversion_code_sets;
  };

  // TAO_IDL - Generated from
  // be\be_type.cpp:258

  struct CodeSetComponentInfo;

  typedef
    TAO_Var_Var_T<
        CodeSetComponentInfo
      >
    CodeSetComponentInfo_var;

  typedef
    TAO_Out_T<
        CodeSetComponentInfo,
        CodeSetComponentInfo_var
      >
    CodeSetComponentInfo_out;

  // TAO_IDL - Generated from
  // be\be_visitor_structure/structure_ch.cpp:52

  struct TAO_Export CodeSetComponentInfo
  {
    typedef CodeSetComponentInfo_var _var_type;

    static void _tao_any_destructor (void *);
    CONV_FRAME::CodeSetComponent ForCharData;
    CONV_FRAME::CodeSetComponent ForWcharData;
  };

  // TAO_IDL - Generated from
  // be\be_type.cpp:258

  struct CodeSetContext;

  typedef
    TAO_Fixed_Var_T<
        CodeSetContext
      >
    CodeSetContext_var;

  typedef
    CodeSetContext &
    CodeSetContext_out;

  // TAO_IDL - Generated from
  // be\be_visitor_structure/structure_ch.cpp:52

  struct TAO_Export CodeSetContext
  {
    typedef CodeSetContext_var _var_type;

    static void _tao_any_destructor (void *);
    CONV_FRAME::CodeSetId char_data;
    CONV_FRAME::CodeSetId wchar_data;
  };

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:66

} // module CONV_FRAME

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:61

// Traits specializations.
namespace TAO
{
}

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_ch.cpp:71

#if !defined _TAO_CDR_OP_CONV_FRAME_CodeSetIdSeq_H_
#define _TAO_CDR_OP_CONV_FRAME_CodeSetIdSeq_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CONV_FRAME::CodeSetIdSeq &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CONV_FRAME::CodeSetIdSeq &
  );

#endif /* _TAO_CDR_OP_CONV_FRAME_CodeSetIdSeq_H_ */

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_ch.cpp:54

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const CONV_FRAME::CodeSetComponent &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, CONV_FRAME::CodeSetComponent &);

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_ch.cpp:54

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const CONV_FRAME::CodeSetComponentInfo &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, CONV_FRAME::CodeSetComponentInfo &);

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_ch.cpp:54

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const CONV_FRAME::CodeSetContext &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, CONV_FRAME::CodeSetContext &);

// TAO_IDL - Generated from
// be\be_codegen.cpp:955

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"

#endif /* ifndef */


