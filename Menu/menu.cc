#include "../Header Files/menu.hh" 
using namespace ImGui;
#include "../Header Files/globals.hh"
#include "../imgui/imgui_internal.h"
#include "../imgui/imgui.h"
#include "../font/icons.h"

static void HelpMarker(const char* desc);
void CenterText(const char* text);

void ui::renderMenu() {
    if (!globals.active) return;

    ImGui::SetNextWindowPos(ImVec2(window_pos.x, window_pos.y), ImGuiCond_Once);
    ImGui::SetNextWindowSize(ImVec2(window_size.x, window_size.y));
    ImGui::SetNextWindowBgAlpha(1.0f);

    ImGui::Begin(window_title, &globals.active, window_flags);
    {
        BeginChild("##buttons" , ImVec2(100,265));
        {
            SetCursorPosX(20);
            SetCursorPosY(35);
            if (Button(" \n\n " ICON_FA_LIST " \n ##1", ImVec2(60, 60))) globals.page = 0;
            SetCursorPosX(20);
            if (Button(" \n\n  " ICON_FA_ADDRESS_CARD " \n ##2", ImVec2(60, 60))) globals.page = 1;
            SetCursorPosX(20);
            if (Button((" \n\n " ICON_FA_COGS" \n ##3"), ImVec2(60, 60)))
            {
                globals.page = 2;
                globals.subPage = 0;
            }
        }
        EndChild();
        SameLine();
        SetCursorPosX(110); 
        BeginChild("##pages", ImVec2(380, 265));
        {
            if (globals.page == 0)
            {

            }
            if (globals.page == 1)
            {
                
            }
            if (globals.page == 2)
            { // Settings 
                SetCursorPosX(5);
                SetCursorPosY(5);
                if (Button("Colors##subpage"))globals.subPage = 0;
                Separator();
                if (globals.subPage == 0)
                {// Colors
                    SetCursorPosX(60);
                    if (ColorPicker4("##Colors", (float*)&color.all, ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoSidePreview)) ui::RunStyle();
                }
            }
        }
        EndChild();
    }
    ImGui::End();
}

void ui::init(LPDIRECT3DDEVICE9 device) {
    dev = device;

    // style
    ui::RunStyle();

    // start threads
    

	if (window_pos.x == 0) {
    	RECT screen_rect{};
		GetWindowRect(GetDesktopWindow(), &screen_rect);
		screen_res = ImVec2(float(screen_rect.right), float(screen_rect.bottom));
		window_pos = (screen_res - window_size) * 0.5f;

		// init images here
        
	}
}

void ui::RunStyle()
{
    ImGuiStyle& style = ImGui::GetStyle();

    style.Colors[ImGuiCol_TitleBgActive] = ImColor(0, 0, 0, 155);
    style.Colors[ImGuiCol_WindowBg] = ImColor(color.all[0], color.all[1], color.all[2], color.all[3]);
    style.Colors[ImGuiCol_ChildBg] = ImColor(5, 5, 5, 255);
    style.Colors[ImGuiCol_Button] = ImColor(color.all[0], color.all[1], color.all[2], color.all[3]);
    style.Colors[ImGuiCol_ButtonActive] = ImColor(0, 0, 0, 255);
    style.Colors[ImGuiCol_ButtonHovered] = ImColor(color.all[0], color.all[1], color.all[2], color.all[3]);
    style.Colors[ImGuiCol_CheckMark] = ImColor(color.all[0], color.all[1], color.all[2], color.all[3]);
    style.Colors[ImGuiCol_FrameBg] = ImColor(30, 30, 30, 205);
    style.Colors[ImGuiCol_FrameBgHovered] = ImColor(35, 35, 35, 205);
    style.Colors[ImGuiCol_FrameBgActive] = ImColor(color.all[0], color.all[1], color.all[2], color.all[3]);
    style.Colors[ImGuiCol_SliderGrab] = ImColor(color.all[0], color.all[1], color.all[2], color.all[3]);
    style.Colors[ImGuiCol_SliderGrabActive] = ImColor(color.all[0], color.all[1], color.all[2], color.all[3]);
    style.Colors[ImGuiCol_Text] = ImColor(255, 255, 255, 255);
}

static void HelpMarker(const char* desc)
{
    ImGui::TextDisabled("(?)");
    if (ImGui::IsItemHovered())
    {
        ImGui::BeginTooltip();
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
        ImGui::TextUnformatted(desc);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
    }
}

void CenterText(const char* text)
{
    if (text == nullptr)
        return;

    ImGui::Spacing();
    ImGui::SameLine((ImGui::GetContentRegionAvail().x / 2) - (ImGui::CalcTextSize(text).x / 2));
    ImGui::Text(text);
    ImGui::Spacing();
}
