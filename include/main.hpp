#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#define MARGIN 20
#define OFFSET 10

class MyApp : public wxApp {
public:
  virtual bool OnInit();
};

class MyFrame : public wxFrame {
public:
  MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size);
private:
  wxStaticText* positionLabel;
  void onMove(wxMouseEvent &evt);
};

enum {
  ID_IMAGE = 1,
  ID_POSITION_LABEL
};

wxString getPath(const char* path);