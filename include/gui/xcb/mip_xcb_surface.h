#ifndef mip_xcb_surface_included
#define mip_xcb_surface_included
//----------------------------------------------------------------------

#include "mip.h"
#include "gui/mip_paint_source.h"
#include "gui/mip_paint_target.h"
//#include "gui/mip_paint_target.h"
#include "gui/xcb/mip_xcb.h"
//#include "gui/xcb/mip_xcb_utils.h"

//#ifdef MIP_USE_CAIRO
//  #include "gui/cairo/mip_cairo.h"
//#endif

//----------------------------------------------------------------------
//
//
//
//----------------------------------------------------------------------

class MIP_XcbSurface
: public MIP_PaintSource
, public MIP_PaintTarget {

//------------------------------
private:
//------------------------------

  MIP_PaintTarget*  MTarget           = nullptr;
  xcb_connection_t* MConnection       = nullptr;
  xcb_visualid_t    MTargetVisual     = XCB_NONE;
  xcb_drawable_t    MTargetDrawable   = XCB_NONE;
  xcb_pixmap_t      MPixmap           = XCB_NONE;
  int32_t           MWidth            = 0;
  int32_t           MHeight           = 0;
  int32_t           MDepth            = 0;
  bool              MIsWindow         = false;
  xcb_window_t      MWindow           = XCB_NONE;

  //#ifdef MIP_USE_CAIRO
  //cairo_surface_t*  MCairoSurface     = nullptr;
  //cairo_device_t*   MCairoDevice      = nullptr;
  //#endif

//------------------------------
public:
//------------------------------

  MIP_XcbSurface(MIP_PaintTarget* ATarget, uint32_t AWidth, uint32_t AHeight, uint32_t ADepth=0) {
  //: MIP_BaseSurface() {
    // pixmap
    MConnection     = ATarget->paint_target_getXcbConnection();
    MTargetDrawable = ATarget->paint_target_getXcbDrawable();
    MTargetVisual   = ATarget->paint_target_getXcbVisual();
    MWidth          = AWidth;
    MHeight         = AHeight;
    if (ADepth  == 0) MDepth  = ATarget->paint_target_getDepth();
    else MDepth  = ADepth;
    //if (AOwner->isWindow()) {
    //  MIsWindow = true;
    //  MWindow = AOwner->getWindow();
    //}
    //else {
      MPixmap = xcb_generate_id(MConnection);
      xcb_create_pixmap(
        MConnection,
        MDepth,
        MPixmap,
        MTargetDrawable,
        AWidth,
        AHeight
      );
    //}
    xcb_flush(MConnection);
    #ifdef MIP_USE_CAIRO
    MCairoSurface = cairo_xcb_surface_create(
      MConnection,
      MPixmap,
      mip_xcb_find_visual(MConnection,MTargetVisual),
      MWidth,
      MHeight
    );
    //MCairoDevice = cairo_device_reference(cairo_surface_get_device(MCairoSurface));
    #endif
  }

  //----------

  /*
  virtual ~MIP_XcbSurface() {
    if (!MIsWindow) {
      xcb_free_pixmap(MConnection,MPixmap);
    }
    #ifdef MIP_USE_CAIRO
    cairo_surface_destroy(MCairoSurface);
    //cairo_device_finish(MCairoDevice);
    //cairo_device_destroy(MCairoDevice);
    #endif
  }
  */

  virtual ~MIP_XcbSurface() {
  }

//------------------------------
public: // paint_source
//------------------------------

  bool                paint_source_isSurface()         final { return true; }
  bool                paint_source_isDrawable()        final { return true; }

  uint32_t            paint_source_getWidth()          final { return MWidth; }
  uint32_t            paint_source_getHeight()         final { return MHeight; }
  uint32_t            paint_source_getDepth()          final { return MDepth; }

  xcb_connection_t*   paint_source_getXcbConnection()  final { return MConnection; }
  xcb_visualid_t      paint_source_getXcbVisual()      final { return MTargetVisual; }
  xcb_drawable_t      paint_source_getXcbDrawable()    final { return MPixmap; } //MTargetDrawable; }
  xcb_pixmap_t        paint_source_getXcbPixmap()      final { return MPixmap; }

  //#ifdef MIP_USE_CAIRO
  //bool                paint_source_isCairo()           final { return true; }
  //cairo_surface_t*    paint_source_getCairoSurface()   final { return MCairoSurface; }
  //#endif

//------------------------------
public: // paint_target
//------------------------------

  bool                paint_target_isSurface()         final { return true; }
  bool                paint_target_isDrawable()        final { return true; }

  uint32_t            paint_target_getWidth()          final { return MWidth; }
  uint32_t            paint_target_getHeight()         final { return MHeight; }
  uint32_t            paint_target_getDepth()          final { return MDepth; }

  xcb_connection_t*   paint_target_getXcbConnection()  final { return MConnection; }
  xcb_visualid_t      paint_target_getXcbVisual()      final { return MTargetVisual; }
  xcb_drawable_t      paint_target_getXcbDrawable()    final { return MPixmap; } //MTargetDrawable; }
  xcb_pixmap_t        paint_target_getXcbPixmap()      final { return MPixmap; }

  //#ifdef MIP_USE_CAIRO
  //bool                paint_target_isCairo()           final { return true; }
  //cairo_surface_t*    paint_target_getCairoSurface()   final { return MCairoSurface; }
  //#endif

//------------------------------
public:
//------------------------------

};

//----------------------------------------------------------------------
#endif

















  /*
    cairo_xcb_surface_create()

    Creates an XCB surface that draws to the given drawable. The way that
    colors are represented in the drawable is specified by the provided visual.

    Note: If drawable is a Window, then the function cairo_xcb_surface_set_size()
    must be called whenever the size of the window changes.

    When drawable is a Window containing child windows then drawing to the
    created surface will be clipped by those child windows. When the created
    surface is used as a source, the contents of the children will be included.

    Returns a pointer to the newly created surface. The caller owns the surface
    and should call cairo_surface_destroy() when done with it.

    This function always returns a valid pointer, but it will return a pointer
    to a "nil" surface if an error such as out of memory occurs. You can use
    cairo_surface_status() to check for this.
  */


  //void fill(MIP_Color AColor) override {}
  //void fill(int32_t AXpos, int32_t AYpos, int32_t AWidth, int32_t AHeight, MIP_Color AColor) override {}
  //void blit(int32_t ADstX, int32_t ADstY, MIP_Drawable* ASource) override {}
  //void blit(int32_t ADstX, int32_t ADstY, MIP_Drawable* ASource, int32_t ASrcX, int32_t ASrcY, int32_t ASrcW, int32_t ASrcH) override {}

