#include "UI.h"

ImVec2 Btnsize(150, 60);

enum Menu {
	a1,
	a2,
	a3,
	a4
};

static Menu m = a1;

void UI::ui()
{
	ImGui::SetNextWindowSize({580,350});
	ImGui::Begin("¿Õ°×", nullptr, ImGuiWindowFlags_NoCollapse + ImGuiWindowFlags_NoResize + ImGuiWindowFlags_NoTitleBar + ImGuiWindowFlags_NoScrollbar);

	auto draw = ImGui::GetWindowDrawList();
	ImVec2 WPos = ImGui::GetWindowPos();
	draw->AddText(font, 19.f, {WPos.x + 14,WPos.y + 12}, ImColor(255, 255, 255), "¿Õ°×¸¨Öú");
	draw->AddRectFilled({ WPos.x + 170,WPos.y+35 }, { WPos.x + 550,WPos.y + 325 }, ImColor(51,51,51), 5);
	ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 30);
	if (ImGui::Button("Êý¾Ý±éÀú", Btnsize)) m = a1;
	ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 10);
	if (ImGui::Button("2", Btnsize))m = a2;
	ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 10);
	if (ImGui::Button("3", Btnsize))m = a3;
	ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 10);
	if (ImGui::Button("4", Btnsize))m = a4;

	switch (m)
	{
	case a1:	
		ImGui::SetCursorPos({ 180,45 });
		ImGui::BeginGroup();

		ImGui::EndGroup();
		break;
	case a2:
		break;
	case a3:
		break;
	case a4:
		break;
	default:
		break;
	}

	ImGui::End();
}
