#ifndef GUI_H
#define GUI_H

#include <wx/wx.h>
#include <wx/notebook.h>
#include <wx/spinctrl.h>

class SpawnUUID : public wxPanel {
	public:
		SpawnUUID(wxWindow *parent);
		
	private:
		wxBoxSizer *main_sizer;
		wxBoxSizer *control_sizer;
		wxStaticText *title;
		wxChoice *chapter;
		wxSpinCtrl *location;
		
		wxArrayString chapter_str;
		
		enum class Chapter {
			NO_NAME,
			THE_CATACOMBS,
			TWILIGHT_FALLS,
			VALLEY_OF_AVALAR,
			DRAGON_CITY,
			ATTACK_OF_THE_GOLEM,
			RUINS_OF_WARFANG,
			THE_DAM,
			THE_DESTROYER,
			BURNED_LANDS,
			FLOATING_ISLANDS,
			MALEFORS_LAIR
		};
		
		void OnChapterChange(wxCommandEvent& event);
		void SetLocationRange(Chapter chapter);
};

class Slot : public wxScrolledWindow {
	public:
		Slot(wxWindow *parent);
		
	private:
		wxBoxSizer *sizer;
		SpawnUUID *spawn_uuid;
		
		wxCheckBox *dummy;
};

class MainFrame : public wxFrame {
	public:
		MainFrame();
	private:
		wxMenu *file_menu;
		wxMenuBar *menu_bar;
		
		Slot *slot[5];
		
		wxPanel *panel;
		wxNotebook *notebook;
		
		wxBoxSizer *panel_sizer;
		wxBoxSizer *top_sizer;
};


#endif
