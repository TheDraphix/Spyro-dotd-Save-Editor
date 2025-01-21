
#include <wx/wx.h>
#include <wx/notebook.h>

#include "gui.hpp"


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
}

Slot::Slot(wxWindow *parent)
	: wxScrolledWindow(parent)
{
	dummy = new wxCheckBox(this, wxID_ANY, "Dummy Slot");
	spawn_uuid = new SpawnUUID(this);
	
	sizer= new wxBoxSizer(wxVERTICAL);
	sizer->Add(dummy,1,wxEXPAND);
	sizer->Add(spawn_uuid,1,wxEXPAND);
	
	SetScrollbars(0,16,0,16);
	SetMinSize(wxSize(-1,100));
	this->SetSizer(sizer);
}

SpawnUUID::SpawnUUID(wxWindow *parent)
	: wxPanel(parent)
{
	chapter_str.Add("no_name");
	chapter_str.Add("The Catacombs");
	chapter_str.Add("Twighlight Falls");
	chapter_str.Add("Valley of Avalar");
	chapter_str.Add("Dragon City");
	chapter_str.Add("Attack of the Golem");
	chapter_str.Add("Ruins of Warfang");
	chapter_str.Add("The Dam");
	chapter_str.Add("The Destroyer");
	chapter_str.Add("Burned Lands");
	chapter_str.Add("Floating Islands");
	chapter_str.Add("Malefor's Lair");
	
	title = new wxStaticText(this, wxID_ANY, "Spawn Point UUID");
	chapter = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, chapter_str);
	location = new wxSpinCtrl(this);
	
	main_sizer = new wxBoxSizer(wxVERTICAL);
	control_sizer = new wxBoxSizer(wxHORIZONTAL);
	main_sizer->Add(title,0,wxEXPAND);
	main_sizer->Add(control_sizer,0,wxEXPAND);
	control_sizer->Add(chapter,1,wxEXPAND);
	control_sizer->Add(location,0,wxEXPAND);
	
	chapter->Bind(wxEVT_CHOICE, &SpawnUUID::OnChapterChange, this);

	SetSizerAndFit(main_sizer);
	
	chapter->SetSelection(static_cast<int>(Chapter::THE_CATACOMBS));
	SetLocationRange(Chapter::THE_CATACOMBS);
}
void SpawnUUID::SetLocationRange(Chapter chapter)
{
	int number_of_locations;
	switch (chapter)
	{
		case Chapter::NO_NAME:
			number_of_locations = 0;
			break;
		case Chapter::THE_CATACOMBS:
			number_of_locations = 11;
			break;
		case Chapter::TWILIGHT_FALLS:
			number_of_locations = 3;
			break;
		case Chapter::VALLEY_OF_AVALAR:
			number_of_locations = 13;
			break;
		case Chapter::DRAGON_CITY:
			number_of_locations = 11;
			break;
		case Chapter::ATTACK_OF_THE_GOLEM:
			number_of_locations = 8;
			break;
		case Chapter::RUINS_OF_WARFANG:
			number_of_locations = 20;
			break;
		case Chapter::THE_DAM:
			number_of_locations = 12;
			break;
		case Chapter::THE_DESTROYER:
			number_of_locations = 14;
			break;
		case Chapter::BURNED_LANDS:
			number_of_locations = 8;
			break;
		case Chapter::FLOATING_ISLANDS:
			number_of_locations = 4;
			break;
		case Chapter::MALEFORS_LAIR:
			number_of_locations = 3;
			break;
	}
	location->SetRange(0,number_of_locations);
}
void SpawnUUID::OnChapterChange(wxCommandEvent& event)
{
	SetLocationRange(static_cast<Chapter>(event.GetInt()));
}
