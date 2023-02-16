#include "main.hpp"

wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit() {
  MyFrame *frame = new MyFrame("Coordenadas", wxPoint(50, 50), wxSize(450, 340));
  frame->Show(true);
  return true;
}

MyFrame::MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size): wxFrame(NULL, wxID_ANY, title, pos, size) {

  wxImage::AddHandler(new wxPNGHandler);
  wxStaticBitmap* image = new wxStaticBitmap((wxFrame*)this, wxID_ANY, wxBitmap(getPath("images/campo.png")));
  image->SetSize(wxSize(640, 480));
  image->Connect(wxID_ANY, wxEVT_MOTION, wxMouseEventHandler(MyFrame::onMove),NULL,this);

  positionLabel = new wxStaticText(this, wxID_ANY, "");
  positionLabel->SetForegroundColour("red");
  auto font = positionLabel->GetFont();
  font.SetWeight(wxFONTWEIGHT_EXTRABOLD);
  font.SetPointSize(12);
  positionLabel->SetFont(font);

  wxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
  mainSizer->Add(image, 0, wxALIGN_CENTER | wxALL, MARGIN);
  SetSizerAndFit(mainSizer);
}

void MyFrame::onMove(wxMouseEvent &evt) {
  auto x = evt.GetPosition().x;
  auto y = evt.GetPosition().y;
  int finalX = (float(x)/640.0) * 1700.0;
  int finalY = ((480.0 - float(y))/480.0) * 1300.0;
  positionLabel->SetLabelText(wxString::Format("(%d,%d)", finalX, finalY));
  positionLabel->SetPosition(wxPoint(x + MARGIN + OFFSET, y + MARGIN + OFFSET));

  auto pos = positionLabel->GetPosition();
  if (x >= 500)
    pos.x = x - 6 * OFFSET;
  if (y >= 400)
    pos.y = y - 0.8 * OFFSET;
  positionLabel->SetPosition(pos);
}

wxString getPath(const char* path) {
  wxString str(PROJECT_ROOT);
  str.append("/");
  str.append(path);
  return str;
}