#ifndef mip_defines_included
#define mip_defines_included
//----------------------------------------------------------------------


//----------------------------------------------------------------------
//
//
//
//----------------------------------------------------------------------

#ifdef __gnu_linux__
  #define MIP_LINUX
#endif

#ifdef _WIN32
  #define  MIP_WIN32
#endif

//----------

#if defined  (__i386__) || defined (_X86_) || defined (__X86__)
  #define MIP_32BIT
#endif

#if defined (__x86_64) || (__LP64__)
  #define MIP_64BIT
#endif

//----------

#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
  #define MIP_BIG_ENDIAN
#endif

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
  #define MIP_LITTLE_ENDIAN
#endif

//----------

#if (__cplusplus >= 201103L)
  #define MIP_CPP11
#endif

//----------------------------------------------------------------------
//
// debug
//
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//
// gui
//
//----------------------------------------------------------------------


#undef MIP_GUI_DEFINED
#undef MIP_PAINTER_DEFINED

//----------

#ifdef MIP_NO_GUI
  #define MIP_GUI_DEFINED
  #undef MIP_GUI_XCB
  #undef MIP_USE_XCB
  #undef MIP_USE_CAIRO
  #undef MIP_USE_OPENGL
  #undef MIP_USE_NANOVG
#endif

#ifdef MIP_GUI_XCB
  #define MIP_USE_XCB
  #define MIP_GUI_DEFINED
#endif

#ifdef MIP_PAINTER_XCB
  #define MIP_USE_XCB
  #define MIP_PAINTER_DEFINED
#endif

#ifdef MIP_PAINTER_CAIRO
  #define MIP_USE_CAIRO
  #define MIP_PAINTER_DEFINED
#endif

#ifdef MIP_PAINTER_OPENGL
  #define MIP_USE_OPENGL
  #define MIP_PAINTER_DEFINED
#endif

//----------

#ifndef MIP_GUI_DEFINED
  #warning No Gui defined (MIP_GUI_*)
  #define MIP_NO_GUI
#endif

#ifndef MIP_PAINTER_DEFINED
  #warning No Painter defined (MIP_PAINTER_*)
  #define MIP_NO_GUI
#endif

//----------------------------------------------------------------------
//
// plugin
//
//----------------------------------------------------------------------

//----------------------------------------------------------------------
#endif
