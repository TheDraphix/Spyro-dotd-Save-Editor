#include <iostream>
#include <tuple>
#include <cstdint>
#include <cstring>
#include <wx/wx.h>

#include "uuid.hpp"
#include "byte_utils.hpp"
#include "save_data.hpp"
#include "gui.hpp"

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
		void OnOpen(wxCommandEvent& event);
		
		save_data::GameSave game_save;
		void ShowSaveData();
};

class Main : public wxApp
{
	public:
		virtual bool OnInit();
};
wxIMPLEMENT_APP(Main);

bool Main::OnInit()
{
	MainFrame *frame = new MainFrame();
	frame->Show(true);
	return true;
}

MainFrame::MainFrame()
	: wxFrame(NULL, wxID_ANY, "Spyro DOTD Save Editor")
{
	file_menu = new wxMenu();
	file_menu->Append(wxID_OPEN, "Open");
	file_menu->Append(wxID_SAVE, "Save");
	
	menu_bar = new wxMenuBar();
	menu_bar->Append(file_menu, "File");
	SetMenuBar(menu_bar);
	
	panel = new wxPanel(this, wxID_ANY);
	notebook = new wxNotebook(panel, wxID_ANY);
	
	// Temporary. Slots should be added to the notebook when version is determined. They are here just to fill space.
	slot[0] = new Slot(notebook);
	slot[1] = new Slot(notebook);
	slot[2] = new Slot(notebook);
	slot[3] = new Slot(notebook);
	slot[4] = new Slot(notebook);
	notebook->AddPage(slot[0], "Slot 0");
	notebook->AddPage(slot[1], "Slot 1");
	notebook->AddPage(slot[2], "Slot 2");
	notebook->AddPage(slot[3], "Slot 3");
	notebook->AddPage(slot[4], "Slot 4");
	
	
	panel_sizer = new wxBoxSizer(wxHORIZONTAL);
	panel_sizer->Add(notebook,1,wxEXPAND);
	panel->SetSizer(panel_sizer);
	
	wxBoxSizer *top_sizer = new wxBoxSizer(wxHORIZONTAL);
	top_sizer->Add(panel, 1, wxEXPAND);
	SetSizerAndFit(top_sizer);
	
	Bind(wxEVT_MENU, &MainFrame::OnOpen, this, wxID_OPEN);
	
	notebook->Disable();
}

void MainFrame::OnOpen(wxCommandEvent& event)
{
	wxFileDialog open_file_dialog(this);
	if (open_file_dialog.ShowModal() == wxID_CANCEL)
		return;
		
	if (true) // TODO: read the file path and continue if successfull
	{
		game_save.Read(static_cast<std::string>(open_file_dialog.GetPath()));
		ShowSaveData();
		
		notebook->Enable();
	}
}

void MainFrame::ShowSaveData()
{
	int number_of_slots;
	if (game_save.GetVersion()==save_data::PS2 || game_save.GetVersion()==save_data::WII)
		number_of_slots = 5;
	else
		number_of_slots = 1;
		
	for (int i=0; i<number_of_slots; i++)
	{
		slot[i]->dummy->SetValue(game_save.slot[i].dummy);
		if (game_save.slot[i].dummy)
		{
			slot[i]->spawn_uuid->Disable();
		}
		else
		{
			auto [chapter,location] = uuid::spawn::MatchUUID(game_save.slot[i].spawn_point_uuid);
			slot[i]->spawn_uuid->chapter->SetSelection(static_cast<int>(chapter));
			slot[i]->spawn_uuid->location->SetValue(location);
		}
	}
}
