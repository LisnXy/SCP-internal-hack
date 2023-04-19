#include "includes.h"
#include "hack.h"
#include "hooks.h"
#include "UI.h"
#include <string>
#include "Esp.h"
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

Present oPresent;
HWND window = NULL;
WNDPROC oWndProc;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* mainRenderTargetView;

/*
* configuration of the hack
*/
float hack::health = 100;
float hack::spreadMultiplier = 1;
// attachment value
float hack::AdsInaccuracyMultiplier = 1;
float hack::AdsRecoilMultiplier = 1;
float hack::AdsSpeedMultiplier = 1;
float hack::AmmoConsumptionMultiplier = 1;
float hack::BulletInaccuracyMultiplier = 1;
float hack::DamageMultiplier = 1;
float hack::FireRateMultiplier = 1;
float hack::HipInaccuracyMultiplier = 1;
float hack::OverallRecoilMultiplier = 1;
float hack::PenetrationMultiplier = 1;
float hack::ReloadSpeedMultiplier = 1;
float hack::SpreadMultiplier = 1;
float hack::SpreadPredictability = 1;

/*
* controller of the hack
*/
bool show = true; // whether to show the menu
bool showArmMenu = false;
bool enable_noCameraShake = true;
bool enable_ArmSet = true;
bool enable_Esp = true;
namespace UI {
	std::string Font_MSYH = "C:\\Windows\\Fonts\\msyh.ttc";

	void checkFeatures() {
		if (enable_noCameraShake) {
			hook::enableAddEffect();
		}
		else {
			hook::disableAddEffect();
		}
		if (enable_ArmSet) {
			hook::enableGetAttaValue();
		}
		else {
			hook::disableGetAttaValue();
		}
	}

	void InitImGui()
	{
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
		ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\msyh.ttc", 15.0f, nullptr, io.Fonts->GetGlyphRangesChineseFull());
		io.Fonts->Fonts[0] = font;
		// check if font is loaded
		if (font != NULL) {
			printf("[imgui]Font loaded!\n");
		}
		else {
			printf("[imgui]Font load failed!\n");
		}
		ImGui_ImplWin32_Init(window);
		ImGui_ImplDX11_Init(pDevice, pContext);
	}

	LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
		if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
			return true;

		return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
	}

	bool init = false;
	HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
	{
		if (!init)
		{
			if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice)))
			{
				pDevice->GetImmediateContext(&pContext);
				DXGI_SWAP_CHAIN_DESC sd;
				pSwapChain->GetDesc(&sd);
				window = sd.OutputWindow;
				ID3D11Texture2D* pBackBuffer;
				pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
				pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
				pBackBuffer->Release();
				oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
				InitImGui();
				init = true;
				printf("[imgui]ImGui initialized!\n");
			}
			else {
				return oPresent(pSwapChain, SyncInterval, Flags);
			}
		}

		// toggle the visibility of the cheat menu
		if (GetAsyncKeyState(VK_INSERT) & 1) {
			show = !show;
		}
		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();
		if (show) {
			drawImgui();
		}
		if (enable_Esp) {
			drawEsp();
		}
		ImGui::Render();
		pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
		// check if user change the config of the hack.
		checkFeatures();

		return oPresent(pSwapChain, SyncInterval, Flags);
	}

	DWORD WINAPI InitUI(LPVOID lpReserved)
	{
		bool init_hook = false;
		do
		{
			if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
			{
				kiero::bind(8, (void**)&oPresent, hkPresent);
				init_hook = true;
				printf("[imgui]d3D11 hooked!\n");
			}
		} while (!init_hook);
		return TRUE;
	}

	void drawImgui() {
		ImGui::Begin("Lisn SCP Internal Hack");
		ImGui::Text("press INSERT to toggle menu");
		ImGui::Checkbox("No Camera Shake", &enable_noCameraShake);
		ImGui::Checkbox("Arm Settings enable", &enable_ArmSet);
		ImGui::Checkbox("Open Arm Menu", &showArmMenu);
		ImGui::Checkbox("Esp", &enable_Esp);
		if (showArmMenu) {
			ImGui::Begin("Arm Setting");
			ImGui::SliderFloat("AdsInaccuracyMultiplier", &hack::AdsInaccuracyMultiplier, 0, 1);
			ImGui::SliderFloat("AdsRecoilMultiplier", &hack::AdsRecoilMultiplier, 0, 1);
			ImGui::SliderFloat("AdsSpeedMultiplier", &hack::AdsSpeedMultiplier, 1, 5);
			ImGui::SliderFloat("AmmoConsumptionMultiplier", &hack::AmmoConsumptionMultiplier, 0, 1);
			ImGui::SliderFloat("BulletInaccuracyMultiplier", &hack::BulletInaccuracyMultiplier, 0, 1);
			ImGui::SliderFloat("DamageMultiplier", &hack::DamageMultiplier, 1, 5);
			ImGui::SliderFloat("FireRateMultiplier", &hack::FireRateMultiplier, 1, 5);
			ImGui::SliderFloat("HipInaccuracyMultiplier", &hack::HipInaccuracyMultiplier, 0, 1);
			ImGui::SliderFloat("OverallRecoilMultiplier", &hack::OverallRecoilMultiplier, 0, 1);
			ImGui::SliderFloat("PenetrationMultiplier", &hack::PenetrationMultiplier, 1, 5);
			ImGui::SliderFloat("ReloadSpeedMultiplier", &hack::ReloadSpeedMultiplier, 1, 5);
			ImGui::SliderFloat("SpreadMultiplier", &hack::SpreadMultiplier, 0, 1);
			ImGui::SliderFloat("SpreadPredictability", &hack::SpreadPredictability, 0, 1);
			ImGui::End();
		}
		ImGui::End();
	}
}