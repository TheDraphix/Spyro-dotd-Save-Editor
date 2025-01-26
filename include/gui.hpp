#ifndef GUI_H
#define GUI_H

#include <wx/wx.h>
#include <wx/notebook.h>
#include <wx/spinctrl.h>

class SpawnUUID : public wxPanel {
	public:
		SpawnUUID(wxWindow *parent);
		wxChoice *chapter;
		wxSpinCtrl *location;
		
	private:
		wxBoxSizer *main_sizer;
		wxBoxSizer *control_sizer;
		wxStaticText *title;
		
		wxArrayString chapter_str;
		
		void OnChapterChange(wxCommandEvent& event);
		void SetLocationRange(uuid::spawn::Chapter chapter);
};

class Slot : public wxScrolledWindow {
	public:
		Slot(wxWindow *parent);
		
		SpawnUUID *spawn_uuid;
		wxCheckBox *dummy;
		
	private:
		wxBoxSizer *sizer;
		
		void OnDummy(wxCommandEvent& event);
};


#endif
