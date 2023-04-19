#include "hooks.h"
#include <stdio.h>
#include "includes.h"
#include <cmath>
#include <string>
#include <comutil.h>
#pragma comment(lib, "comsuppw.lib")

UnityEngine_Vector3_o localPlayerPosition = { {0,0,0} };
ImColor NTF = ImColor(112, 195, 255, 255);
ImColor Guard = ImColor(75, 86, 105, 255);
ImColor Sci = ImColor(255, 255, 124, 255);
ImColor Scp = ImColor(253, 0, 0, 255);
ImColor Chaos = ImColor(0, 143, 28, 255);
ImColor ClassD = ImColor(159, 82, 7, 255);
ImColor Others = ImColor(255, 255, 255, 255);
int localPlayerIndex = 0;
float distanceLimit = 2000;

float getDistance(UnityEngine_Vector3_o transformed_position);
ImColor getColor(System_String_Fields roleString,
	std::string& toShow);

std::string ws2s(const std::wstring& ws)
{
	_bstr_t t = ws.c_str();
	char* pchar = (char*)t;
	std::string result = pchar;
	return result;
}

void drawEsp() {
	// if instances is not initialized or the size of the list is 0, return
	if (hook::instances == nullptr) {
		return;
	}
	if (hook::instances->fields._size == 0) {
		return;
	}
	if (hook::camera == nullptr) {
		//try to get camera
		hook::camera = hook::GetMainCamera_hook(hook::GetMainCamera);
		if (hook::camera == nullptr) {
			// if failed to get the camera, then return.
			return;
		}
	}

	for (int i = 0; i < hook::instances->fields._size; ++i) {
		PlayerList_Instance_o* item = hook::instances->fields._items->m_Items[i];
		// get the transform of the player
		UnityEngine_Transform_o* transform = item->fields.owner->fields.PlayerCameraReference;
		// call the getPosition function to get the position of the player
		UnityEngine_Vector3_o position = hook::TransformGetPosition_hook(transform, hook::TransformGetPosition);
		// transform to screen coordinates
		position = hook::WorldToScreenPoint_hook(hook::camera, position, hook::WorldToScreenPoint);
		// if the player is local player, then save the position not cancel the drawing
		float distance = getDistance(position);

		printf("currentIndex:%d\n", i);
		printf("localPlayerIndex:%d\n", localPlayerIndex);

		if (distance > distanceLimit) {
			continue;
		}
		if (distance == 0.0f) {
			localPlayerIndex = i;
			continue;
		}
		if (i == localPlayerIndex) {
			continue;
		}
		// render the player
		ImVec2 renderPosition = ImVec2(position.fields.x, (ImGui::GetIO().DisplaySize.y - position.fields.y));
		System_String_Fields& fields = item->fields.owner->fields.nicknameSync->fields._myNickSync->fields;
		uint16_t* p = &fields.m_firstChar;
		std::wstring playerNameW = std::wstring((wchar_t*)p, fields.m_stringLength);
		std::string toShow = ws2s(playerNameW);

		printf("player name: %s, Distance%f\n", toShow.c_str(), distance);
		// try get the role
		PlayerRoles_PlayerRoleBase_o* role = item->fields.owner->fields.roleManager->fields._curRole;
		System_String_Fields& roleNameFields = hook::GetRoleName_hook(role, NULL)->fields;
		ImColor color = getColor(roleNameFields, toShow);
		ImVec2 textSize = ImGui::CalcTextSize(toShow.c_str());
		//render on the top-center of the player
		renderPosition.x -= textSize.x / 2;
		renderPosition.y += textSize.y;
		ImGui::GetBackgroundDrawList()->AddText(renderPosition, color, (toShow.c_str()));
	}
}

float getDistance(UnityEngine_Vector3_o transformed_position) {
	float x = transformed_position.fields.x;
	float y = transformed_position.fields.y;
	float z = transformed_position.fields.z;

	return std::sqrt(x * x + y * y + z * z);
}

ImColor getColor(System_String_Fields roleString, std::string& toShow) {
	wchar_t ch = (wchar_t)roleString.m_firstChar;
	std::string preFix;
	switch (ch) {
	case L'九':
		return NTF;
	case L'设':
		return Guard;
	case L'科':
		return Sci;
	case L'S':
		return Scp;
	case L'混':
		return Chaos;
	case L'D':
		return ClassD;
	default:
		return Others;
	}
}