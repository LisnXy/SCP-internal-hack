#include "includes.h"
#include "hack.h"
#include "hooks.h"
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
bool show = true;
bool enable_noCameraShake = true;
bool enable_ArmSet = true;
namespace UI {
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
			}

			else
				return oPresent(pSwapChain, SyncInterval, Flags);
		}

		// toggle the visibility of the cheat menu
		if (GetAsyncKeyState(VK_INSERT) & 1) {
			show = !show;
		}

		if (show) {
			ImGui_ImplDX11_NewFrame();
			ImGui_ImplWin32_NewFrame();
			ImGui::NewFrame();
			ImGui::Begin("Lisn SCP Internal Hack");
			ImGui::Text("press INSERT to toggle menu");
			ImGui::Checkbox("No Camera Shake", &enable_noCameraShake);
			ImGui::Checkbox("Arm Settings enable", &enable_ArmSet);
			//ImGui::SliderFloat("Health", &hack::health, 0, 100);
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

			checkFeatures();
			ImGui::End();
			ImGui::Render();

			pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
			ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
		}

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
			}
		} while (!init_hook);
		return TRUE;
	}
}