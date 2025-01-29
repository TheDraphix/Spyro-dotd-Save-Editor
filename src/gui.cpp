
#include <wx/wx.h>
#include <wx/notebook.h>

#include "uuid.hpp"
#include "gui.hpp"

Slot::Slot(wxWindow *parent)
	: wxScrolledWindow(parent)
{
	readable_slot = new wxCheckBox(this, wxID_ANY, "Readable Slot");
	dummy = new wxCheckBox(this, wxID_ANY, "Dummy Slot");
	spawn_uuid = new SpawnUUID(this);
	
	sizer= new wxBoxSizer(wxVERTICAL);
	sizer->Add(readable_slot,1,wxEXPAND);
	sizer->Add(dummy,1,wxEXPAND);
	sizer->Add(spawn_uuid,1,wxEXPAND);
	
	SetScrollbars(0,16,0,16);
	SetMinSize(wxSize(-1,100));
	this->SetSizer(sizer);
	
	dummy->Bind(wxEVT_CHECKBOX, &Slot::OnDummy, this);
}
void Slot::OnDummy(wxCommandEvent& event) { spawn_uuid->Enable(!event.IsChecked()); }

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
}
void SpawnUUID::SetLocationRange(uuid::spawn::Chapter chapter) { location->SetRange(0, uuid::spawn::number_of_locations[chapter]-1); }
void SpawnUUID::OnChapterChange(wxCommandEvent& event) { SetLocationRange(static_cast<uuid::spawn::Chapter>(event.GetInt())); }
